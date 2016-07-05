#import <stdio.h>
#import <string.h>

int wmain(int argc, char **fname) {
    char buffer[1024];
    short machine[2];
    short numSections;
    long timestamp;
    long symbolTablePointer;
    long numSymbols;
    
    boolean isBigE;
    FILE *fptr;
    fptr = fopen(&&fname, "w");
    fseek(fptr, 0x3c, SEEK_SET);
    fread(buffer, 4, 1, fptr);
    if (memcmp(0x50450000, buffer, 4) == 0) {
        bigE = false;
    } else { //elseif (memcmp(0x
        printf("Invalid exe file\n");
        return -1;
    }
    fread(machine, 2, 1, fptr);
    fread(numSections, 2, 1, fptr);
    fread(
}
