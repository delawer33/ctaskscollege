Выведем таблицы символов файлов `fuel.o`, `navigation.o`, `main.o` и `ship`

```bash
╰─[:)] % nm fuel.o               
0000000000000000 T check_fuel
                 U printf

╰─[:)] % nm navigation.o 
0000000000000000 T calculate_distance
                 U exit
                 U puts

╰─[:)] % nm main.o      
                 U calculate_distance
                 U check_fuel
                 U __isoc99_scanf
0000000000000000 T main
                 U printf
                 U __stack_chk_fail

╰─[:)] % nm ship  
000000000000038c r __abi_tag
0000000000004010 B __bss_start
00000000000012d8 T calculate_distance
0000000000001327 T check_fuel
0000000000004010 b completed.0
                 w __cxa_finalize@GLIBC_2.2.5
0000000000004000 D __data_start
0000000000004000 W data_start
0000000000001110 t deregister_tm_clones
0000000000001180 t __do_global_dtors_aux
0000000000003da0 d __do_global_dtors_aux_fini_array_entry
0000000000004008 D __dso_handle
0000000000003da8 d _DYNAMIC
0000000000004010 D _edata
0000000000004018 B _end
                 U exit@GLIBC_2.2.5
0000000000001354 T _fini
00000000000011c0 t frame_dummy
0000000000003d98 d __frame_dummy_init_array_entry
0000000000002258 r __FRAME_END__
0000000000003f98 d _GLOBAL_OFFSET_TABLE_
                 w __gmon_start__
0000000000002128 r __GNU_EH_FRAME_HDR
0000000000001000 T _init
0000000000002000 R _IO_stdin_used
                 U __isoc99_scanf@GLIBC_2.7
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
                 U __libc_start_main@GLIBC_2.34
00000000000011c9 T main
                 U printf@GLIBC_2.2.5
                 U puts@GLIBC_2.2.5
0000000000001140 t register_tm_clones
                 U __stack_chk_fail@GLIBC_2.4
00000000000010e0 T _start
0000000000004010 D __TMC_END__
```

Мы можем увидеть, что функции `check_fuel` и `calculate_distance` имеют символ `T` в файлах `fuel.o` и `navigation.o`, т.к. эти функции определяются в них.

В файле `main.o` эти фукнции имеют флаг `U`, то есть эти функции неопределены и импортируются из других файлов. То же самое и с функциями `printf` и `puts`.

Перейдем к файлу `ship`. В нем функции `calculate_distance` и `check_fuel` имеют флаг `T`, то есть они определены в этом файле. Это показывает нам, что после этапа линковки все фукнции файлы и функции были связаны. Функции `printf` и `puts` также неопределены (флаг `U`), но в выводе мы можем увидеть запись типа `printf@GLIBC_2.2.5`. Это говорит о том, что функция `printf` будет загружена из GLIBC из какого-либо места в системе, и не определяется в собранном файле.

