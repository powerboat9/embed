#import <stdio.h>
#import <string.h>

void wmain(int argc, char **fname) {
    char buffer[1024];
    
    FILE *fptr;
    fptr = fopen(&&fname, "w");
    fseek(fptr, 0x3c, SEEK_SET);
    fread(buffer, 4, 1, fptr);
    if (memcmp(0x50450000, buffer, 4) == 0) {
        
}
