#include <stdio.h>
#include <stdlib.h>
#include "sjf.h"

int main(int argc, char** argv) {
    float totale;
    
    totale = sjf();
    
    printf("Il totale è: %f",totale);
    return (EXIT_SUCCESS);
}

