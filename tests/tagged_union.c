#include <stdio.h>
#include <stdbool.h>

enum tag {
    TAG_BOOL,
    TAG_INT,
    TAG_FLOAT,
};

typedef struct Dynamic {
    enum tag tag;
    union {
        bool b;
        int i;
        float f;
    } value;
    
} Dynamic;

int main(void) {
    Dynamic d;

    d.tag = TAG_FLOAT;
    d.value.f = 69.69699696;

    switch (d.tag) {
    case TAG_BOOL: printf("Bool: %d",d.value.b); break;
    case TAG_INT: printf("Int: %d",d.value.i); break;
    case TAG_FLOAT: printf("Float: %f",d.value.f); break;
    }

    printf("\nSize of Dynamic: %zu\n",sizeof(d));

    return 0;
}
