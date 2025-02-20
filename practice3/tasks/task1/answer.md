```c
#include <stdio.h>
#include <stdlib.h>

// Глобальные переменные
int global_var = 42; 
int uninitialized_global_var; 

// Статическая переменная
static int static_var = 10;

// Структура
struct Point {
    int x;
    int y;
};

struct Point global_point = {1, 2};

// Функция
void print_message() {
    static int static_local_var = 5;
    int local_var = 3;
    printf("Message from function!\n");
}

int main() {
    int auto_var = 100;
    int *dynamic_var = malloc(4);
    if (dynamic_var) {
        *dynamic_var = 200;
    }

    struct Point stack_point = {3, 4};

    print_message();

    free(dynamic_var); 

    return 0;
}


```
1. В какой секции ELF-файла будет находиться global_var?
2. В какой секции ELF-файла будет храниться uninitialized_global_var?
3. Где находится static_var?
4. Где будет размещена global_point?
5. Где будут расположены:
    local_var из функции print_message?
    static_local_var из той же функции?
6. Где будет храниться auto_var из функции main?
7. Где будет выделена память для dynamic_var?
8. Где будет создана stack_point?




Выведем таблицу символов с помощью **nm**

```bash
╰─[:(] % nm ./a.out               
000000000000038c r __abi_tag
0000000000004024 B __bss_start
0000000000004024 b completed.0
                 w __cxa_finalize@GLIBC_2.2.5
0000000000004000 D __data_start
0000000000004000 W data_start
00000000000010d0 t deregister_tm_clones
0000000000001140 t __do_global_dtors_aux
0000000000003db0 d __do_global_dtors_aux_fini_array_entry
0000000000004008 D __dso_handle
0000000000003db8 d _DYNAMIC
0000000000004024 D _edata
0000000000004030 B _end
000000000000120c T _fini
0000000000001180 t frame_dummy
0000000000003da8 d __frame_dummy_init_array_entry
0000000000002120 r __FRAME_END__
                 U free@GLIBC_2.2.5
0000000000003fa8 d _GLOBAL_OFFSET_TABLE_
0000000000004018 D global_point
0000000000004010 D global_var
                 w __gmon_start__
000000000000201c r __GNU_EH_FRAME_HDR
0000000000001000 T _init
0000000000002000 R _IO_stdin_used
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
                 U __libc_start_main@GLIBC_2.34
00000000000011ae T main
                 U malloc@GLIBC_2.2.5
0000000000001189 T print_message
                 U puts@GLIBC_2.2.5
0000000000001100 t register_tm_clones
00000000000010a0 T _start
0000000000004020 d static_local_var.0
0000000000004014 d static_var
0000000000004028 D __TMC_END__
0000000000004028 B uninitialized_global_var
```

1. `global var` имеет символ D, то есть лежит в секции **.data** как инициализировання глобальная переменная.
2. `uninitialized_global_var` имеет символ b, то есть лежит в секции **.bss** как неинициализированная глобальная переменная.
3. `static_var` с символом d лежить в **.data**.
4. `global_point` с символом d лежить в **.data**.
5. a) `local_var` нет в выводе, т.к. она создается при выполнении функции и помещается в стек во время выполнения программы.
b) `static_local_var` имеет символ d, то есть хранится в **data** как инициализированая статическая переменная
6. `auto_var` нет в таблице символов, т.к. она создается при выполнении функции и помещается в стек во время выполнения программы.
7. `dynamic_var` нет в таблице символов, т.к. она создается при выполнении функции и помещается в кучу (динамическая память) во время выполнения программы.
8. `stack_point` нет в таблице символов, т.к. она создается при выполнении функции и помещается в стек во время выполнения программы.