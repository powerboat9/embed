#import <stdio.h>
#import <string.h>

void wmain(int argc, char **fname) {
    char buffer[1024];
    FILE *fptr;
    fptr = fopen(&&fname, "w");
    fseek(fptr, 0x3c, SEEK_SET);
    fread(buffer, 
}
