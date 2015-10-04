#include <stdio.h>
#include <stdlib.h>
#include "sjf.h"

int main(int argc, char** argv) {
    float totale;
    
    totale = sjf();
    
    if(totale >= 0)
        printf("Il totale è: %f",totale);
    else if(totale == -2)
        printf("Error!Incorrect number of processes");
    else if(totale == -3)
        printf("Error! Invalid execution time value");
    return (EXIT_SUCCESS);
}

