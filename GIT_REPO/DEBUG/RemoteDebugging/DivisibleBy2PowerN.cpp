#include <iostream>
using namespace std;

bool isDividibleBy2PowerN(int n)
{
    if(n > 0) {
        return !(n & (n - 1));
    }
    return false;
}

int main()
{
    int n;
    std::cout << "Enter n : ";
    cin >> n;

    isDividibleBy2PowerN(n) ? (cout << "YES\n") : (cout << "NO\n");
    
    return 0;
}

/************************************************************
PROCEDURE FOR DEBUGGING
--------------------------

__SERVER__ :::

ratan@ratan-pc ~/Desktop/DEBUGING_C_CPP/DEBUG/RemoteDebugging $ gdbserver 127.0.0.1:8000 ./DivisibleBy2PowerN
Process ./DivisibleBy2PowerN created; pid = 16199
Listening on port 8000
Remote debugging from host 127.0.0.1
Enter n : 100
NO
Child exited with status 0
ratan@ratan-pc ~/Desktop/DEBUGING_C_CPP/DEBUG/RemoteDebugging $ 

-------------------------------------------

__CLIENT__ :::
ratan@ratan-pc ~/Desktop/DEBUGING_C_CPP/DEBUG/RemoteDebugging $ gdb

(gdb) 
(gdb) target remote 127.0.0.1:8000
Remote debugging using 127.0.0.1:8000

(gdb) b main
Breakpoint 1 at 0x40088e
(gdb) info br
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x000000000040088e <main+4>
(gdb) tui enable

 ──DivisibleBy2PowerN.cpp─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
   │1       #include <iostream>                                                                                                                                                                                                          │
   │2       using namespace std;                                                                                                                                                                                                         │
   │3                                                                                                                                                                                                                                    │
   │4       bool isDividibleBy2PowerN(int n)                                                                                                                                                                                             │
   │5       {                                                                                                                                                                                                                            │
   │6           if(n > 0) {                                                                                                                                                                                                              │
   │7               return !(n & n - 1);                                                                                                                                                                                                 │
   │8           }                                                                                                                                                                                                                        │
   │9           return false;                                                                                                                                                                                                            │
   │10      }                                                                                                                                                                                                                            │
   │11                                                                                                                                                                                                                                   │
   │12      int main()                                                                                                                                                                                                                   │
B+ │13      {                                                                                                                                                                                                                            │
   │14          int n;                                                                                                                                                                                                                   │
   │15          std::cout << "Enter n : ";                                                                                                                                                                                               │
   │16          cin >> n;                                                                                                                                                                                                                │
   │17                                                                                                                                                                                                                                   │
   │18          isDividibleBy2PowerN(n) ? (cout << "YES") : (cout << "NO");                                                                                                                                                              │
   │19                                                                                                                                                                                                                                   │
   │20          return 0;                                                                                                                                                                                                                │
   │21      }                                                                                                                                                                                                                            │
   │22                                                                                                                                                                                                                                   │
   │23      ************************************************************                                                                                                                                                                │
   │24      PROCEDURE FOR DEBUGGING                                                                                                                                                                                                      │
   │25      --------------------------                                                                                                                                                                                                   │
   │26                                                                                                                                                                                                                                   │
   │27      __SERVER__ :::                                                                                                                                                                                                               │
   │28                                                                                                                                                                                                                                   │
   │29      ratan@ratan-pc ~/Desktop/DEBUGING_C_CPP/DEBUG/RemoteDebugging $ gdbserver 127.0.0.1:8000 ./DivisibleBy2PowerN                                                                                                                │
   │30      Process ./DivisibleBy2PowerN created; pid = 16199                                                                                                                                                                            │
   │31      Listening on port 8000                                                                                                                                                                                                       │
   │32      Remote debugging from host 127.0.0.1                                                                                                                                                                                         │
   │33      Enter n : 100                                                                                                                                                                                                                │
   │34      NO                                                                                                                                                                                                                           │
   │35      Child exited with status 0                                                                                                                                                                                                   │
   │36      ratan@ratan-pc ~/Desktop/DEBUGING_C_CPP/DEBUG/RemoteDebugging $                                                                                                                                                              │
   │37                                                                                                                                                                                                                                   │
   │38      -------------------------------------------                                                                                                                                                                                  │
   └─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
exec No process In:                                                                                                                                                                                                          L??   PC: ?? 

Breakpoint 1, main () at DivisibleBy2PowerN.cpp:13



(gdb) n
__libc_start_main (main=0x40088a <main()>, argc=1, argv=0x7fffffffe018, init=<optimized out>, fini=<optimized out>, rtld_fini=<optimized out>, stack_end=0x7fffffffe008) at ../csu/libc-start.c:325
(gdb) n
[Inferior 1 (process 16199) exited normally]


***********************************************************/
