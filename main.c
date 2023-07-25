#include "hypr.h"
#include <stdlib.h>

int main(int argc, char **argv) {
    setArgv(argc, argv);
    newWindow("A animated cube", 1000, 800);
    mainloop();
}