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

struct EXEFORMAT {
    struct COFFHEADER;
    struct OTHERHEADER;
} _attribute((_packed))

struct LISTELEMENT {
    char *k;
    char *v;
} _attribut ((_packed))

struct LIST {
    struct LISTELEMENT **elements;
    int size;
} _attribute((_packed))

struct EXEFORMAT digest(char fName[]) {
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

struct LIST* createList(int size) {
    struct LIST *list;
    if (size > 0) {
        list = (struct LIST *) malloc(size * 4);
        list
    } else {
        return (struct LIST *) NULL
    }
}

void appendList(struct LIST *list, char *k, char *v) {
    if 

char* getCPUType(struct EXEFORMAT exeFormat) {
    0x14c	Intel 386
    0x8664	x64
    0x162	MIPS R3000
    0x168	MIPS R10000
    0x169	MIPS little endian WCI v2
0x183	old Alpha AXP
0x184	Alpha AXP
0x1a2	Hitachi SH3
0x1a3	Hitachi SH3 DSP
0x1a6	Hitachi SH4
0x1a8	Hitachi SH5
0x1c0	ARM little endian
0x1c2	Thumb
0x1d3	Matsushita AM33
0x1f0	PowerPC little endian
0x1f1	PowerPC with floating point support
0x200	Intel IA64
0x266	MIPS16
0x268	Motorola 68000 series
0x284	Alpha AXP 64-bit
0x366	MIPS with FPU
0x466	MIPS16 with FPU
0xebc	EFI Byte Code
0x8664	AMD AMD64
0x9041	Mitsubishi M32R little endian
0xc0ee	clr pure MSIL
