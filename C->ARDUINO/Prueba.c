#include "arduino-serial-lib.c"
#include "arduino-serial-lib.h"

main(void)
{
    const char* mes = "b";
    int dev = serialport_init("/dev/ttyACM0", 9600);
    serialport_write(dev, mes);
    
}
