#include "IO_System.h"


#include <iostream>


int main()
{   

    // All necessary preparetion for further work
    // Open file for write
    // Load Range and Validate Data
    // Calc number of steps between minimum and maximum 
    IO_System io("in.txt", "table.txt", 7, 10); 

    io.BuildTable();



    return 0;
}