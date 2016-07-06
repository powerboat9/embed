#import <stdlib.h>

struct LISTELEMENT {
    char *k;
    char *v;
} _attribute((_packed))

struct LIST {
    struct LISTELEMENT **elements;
    int size;
    int pos;
} _attribute((_packed))

struct LIST* createList(int size) {
    struct LIST *list;
    if (size > 0) {
        list = (struct LIST *) malloc(size * 4);
        list.size = size;
        list.pos = 0;
    } else {
        return (struct LIST *) NULL
    }
}

void appendList(struct LIST *list, char *k, char *v) {
    if (list) {
        struct LISTELEMENT *element = list->elements + list->pos);
        element.k = k;
        element.v = v;
    }
}

void compress(struct LIST *list)
    if (list) {
        struct LIST *newList = createList(list->size)
        for (struct LISTELEMENT element = list->elements; element < (list->elements + list->pos); element++) {
            element.
