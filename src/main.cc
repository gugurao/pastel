#include <iostream>
#include "app/window.hh"
#undef main
int main(int argc, char *argv[])
{    
    auto win = new Window(argc, argv);    
    win->run();
    return 0;
}