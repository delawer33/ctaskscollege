1) Создадим объектные файлы командой `gcc -c file1.c file2.c main.c`


2)

```bash

nm file1.o
0000000000000000 D global_var
                 U printf
0000000000000000 T print_from_file1
0000000000000004 d static_var

nm file2.o
0000000000000000 D global_var
                 U printf
0000000000000000 T print_from_file2
                 U static_var

nm main.o 
                 U global_var
0000000000000000 T main
                 U printf
                 U print_from_file1
                 U print_from_file2

```

`static_var` и `global_var` в `file1.o` имеют флаг `D`, ведь они в нем определены и лежат в секции `.data`
`static_var` в файле `file2.o` имеет флаг `U`, т.к. будет подтянута из `file1.o` после линковки, а `global_var` имеет флаг `D`, то есть определена в этом файле. И вправду, в строке `int global_var = 30` мы переопределяем ее (но потом это выдаст ошибку)


3) Пробуем собрать программу: `gcc file1.o file2.0 main.o -o program`

```bash
gcc file1.o file2.o main.o -o program
/usr/bin/ld: file2.o:(.data+0x0): multiple definition of `global_var'; file1.o:(.data+0x0): first defined here
/usr/bin/ld: file2.o: warning: relocation against `static_var' in read-only section `.text'
/usr/bin/ld: file2.o: in function `print_from_file2':
file2.c:(.text+0x26): undefined reference to `static_var'
/usr/bin/ld: warning: creating DT_TEXTREL in a PIE
collect2: error: ld returned 1 exit status
```

Здесь мы видим 2 ошибки:
1. multiple definition of `global var` в файле 'file2.o'. Проблема в том, что в `file2.o` мы пытаемся переопределить переменную `global_var`, которая определена в `file1.0`, так мы делать не можем.
2. undefined reference to `static_var` в файле `file2.0`. Здесь мы пытаемся получить доступ к статической переменной `static_var` из другого файла, и компилятор его не видит, ведь эта переменная видна только внутри файла, в котором была создана.

4) Удалим строки `global_var = 30`, `extern int static_var` и `printf("file2.c -> static_var = %d\n", static_var)` из файла `file2.c` и снова запустим компиляцию. На этот раз она прошла успешно.


5) Просмотрим таблицу символов последних объектных файлов

```bash
nm file1.o file2.o main.o 

file1.o:
0000000000000000 D global_var
                 U printf
0000000000000000 T print_from_file1
0000000000000004 d static_var

file2.o:
                 U global_var
                 U printf
0000000000000000 T print_from_file2

main.o:
                 U global_var
0000000000000000 T main
                 U printf
                 U print_from_file1
                 U print_from_file2
```

Мы можем увидеть, что для файла `file1.o` переменные `global_var` и `static_var` имеют символы `D` и `d`, то есть хранятся в секции `.data`. В `file2.o` и `main.o` они имеют флаг `U`, т.к. будут подтянуты из `file1.o` после линковки.

6) Команда `strings` выводит текст из двоичного файла. Выведем текст из скомпилированной нами программы `strings program`.

```bash
strings program
/lib64/ld-linux-x86-64.so.2
go t
__libc_start_main
__cxa_finalize
printf
libc.so.6
GLIBC_2.2.5
GLIBC_2.34
_ITM_deregisterTMCloneTable
__gmon_start__
_ITM_registerTMCloneTable
PTE1
u+UH
file1.c -> global_var = %d
file1.c -> static_var = %d
file2.c -> global_var = %d
main.c -> global_var = %d
9*3$"
GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
Scrt1.o
__abi_tag
crtstuff.c
deregister_tm_clones
__do_global_dtors_aux
completed.0
__do_global_dtors_aux_fini_array_entry
frame_dummy
__frame_dummy_init_array_entry
file1.c
static_var
file2.c
main.c
__FRAME_END__
_DYNAMIC
__GNU_EH_FRAME_HDR
_GLOBAL_OFFSET_TABLE_
__libc_start_main@GLIBC_2.34
_ITM_deregisterTMCloneTable
print_from_file2
_edata
_fini
printf@GLIBC_2.2.5
global_var
__data_start
__gmon_start__
__dso_handle
_IO_stdin_used
_end
print_from_file1
__bss_start
main
__TMC_END__
_ITM_registerTMCloneTable
__cxa_finalize@GLIBC_2.2.5
_init
.symtab
.strtab
.shstrtab
.interp
.note.gnu.property
.note.gnu.build-id
.note.ABI-tag
.gnu.hash
.dynsym
.dynstr
.gnu.version
.gnu.version_r
.rela.dyn
.rela.plt
.init
.plt.got
.plt.sec
.text
.fini
.rodata
.eh_frame_hdr
.eh_frame
.init_array
.fini_array
.dynamic
.data
.bss
.comment
```

В выводе мы можем увидеть строки
```bash
file1.c -> global_var = %d
file1.c -> static_var = %d
file2.c -> global_var = %d
main.c -> global_var = %d
```
из `printf` в нашем коде


#### Дополнительные шаги

`objdump` используется для отображения информации об объектных файлах.

Скомпилируем нашу программу статически командой `gcc -static file1.c file2.c main.c`

Параметр -static связывает программу статически, то есть для ее запуска не требуется зависимость от динамических библиотек во время выполнения.

1) **Entry point** - с какого адреса начинается выполнение программы.

```bash
$ objdump -x program_static | grep 'start'     
start address 0x0000000000401740
```

Выполнение начинается с адреса 0x0000000000401740

2) Разделы памяти

В `.text` находятся, к примеру, функци из наших файлов:

```bash
% objdump -x program_static | grep 'print_from_file'
0000000000401865 g     F .text	0000000000000043 print_from_file1
00000000004018a8 g     F .text	0000000000000027 print_from_file2
```

В `.data` находятся `static_var` и `global_var`:

```bash
% objdump -x program_static | grep '.static_var'
00000000004aa0d4 l     O .data	0000000000000004 static_var
% objdump -x program_static | grep '.global_var'
00000000004aa0d0 g     O .data	0000000000000004 global_var
```

В `.bss` из нашей программы ничего, т.к. нет неинициализированных пременных.

В `.rodata` из нашей программы также ничего не лежить, т.к. неизменяемых переменных.


#### Дополнительный вопрос
Почему global_var есть в .data, а static_var нет в таблице символов?

В файле `file1.o` определены обе переменные, а вот в `main.o` и `file2.o` есть только `global_var`, т.к. `static_var` доступна только в пределах `file1.o`
