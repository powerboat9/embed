#import <stdio.h>
#import <string.h>

struct COFFHEAD {
    short machine;
    short numSections;
    long timestamp;
    long symbolTablePointer;
    long numSymbols;
    short optHeaderSize;
    short characteristics;
} _attribute((_packed))

struct DATADIR { 
    long VirtualAddress;
    long Size;
} _attribute((_packed))

struct OPTHEADER {
    short signature; 
    char MajorLinkerVersion; 
    char MinorLinkerVersion;
    long SizeOfCode;
    long SizeOfInitializedData;
    long SizeOfUninitializedData;
    long AddressOfEntryPoint;
    long BaseOfCode;
    long BaseOfData;
    //Only in exes
    long ImageBase;
    long SectionAlignment;
    long FileAlignment;
    short MajorOSVersion;
    short MinorOSVersion;
    short MajorImageVersion;
    short MinorImageVersion;
    short MajorSubsystemVersion;
    short MinorSubsystemVersion;
    long Win32VersionValue;
    long SizeOfImage;
    long SizeOfHeaders;
    long Checksum;
    short Subsystem;
    short DLLCharacteristics;
    long SizeOfStackReserve;
    long SizeOfStackCommit;
    long SizeOfHeapReserve;
    long SizeOfHeapCommit;
    long LoaderFlags;
    long NumberOfRvaAndSizes;
    DATADIR *dataDir;
} _attribute((_packed))

struct exeFormat digest(char fName[]) {
    char buffer[1024];
    struct COFFHEAD *header;
    struct OPTHEADER *optHeader;
    boolean isBigE;
    FILE *fptr;
    fptr = fopen(fName, "w");
    fseek(fptr, 0x3c, SEEK_SET);
    fread(buffer, 4, 1, fptr);
    if (memcmp(0x50450000, buffer, 4) == 0) {
        bigE = false;
    } else { //elseif (memcmp(0x
        printf("Invalid exe file\n");
        return -1;
    }
    fread(header, 20, 1, fptr);
    fread(optHeader, 96, 1, fptr);
    optHeader.dataDir = (DATADIR *) malloc(optHeader.NumberOfRvaAndSizes * 8);
    fread(optHeader.dataDir, optHeader.NumberOfRvaAndSizes * 8, 1, fptr);
}
