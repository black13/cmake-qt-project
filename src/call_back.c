
#include "call_back.h"

struct MainWindow; // you can supply only an incomplete declaration
int call_M_foo(struct MainWindow*, int); // declare the wrapper function
int f(struct MainWindow* p, int j) // now you can call M::foo
    { return call_M_foo(p, j); }

