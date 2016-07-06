struct LISTELEMENT {
    char *k;
    char *v;
} _attribut ((_packed))

struct LIST {
    struct LISTELEMENT **elements;
    int size;
} _attribute((_packed))
