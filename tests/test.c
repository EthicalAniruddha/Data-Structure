#include <stdio.h>
#include <stdlib.h>

typedef struct test1 {
    char a;
    char b;
    int c;
} test1;

typedef struct test2 {
    char a;
    int c;
    char b;
} test2;

typedef struct test3 {
    int c;
    char a;
    char b;
} test3;

typedef union test4 {
    char a;
    char b;
    int c;
}test4;


int main(void) {
    test1 test_1; test4 test_4;

    test_1.a = test_4.a = 'A';

    test_1.b = test_4.b = 'B';

    test_1.c = test_4.c = 69;

    printf("%zu\n",sizeof(test1));
    printf("%zu\n",sizeof(test2));
    printf("%zu\n",sizeof(test3));
    printf("%zu\n",sizeof(test4));

    printf("\n---Test1---\n");
    printf("Addr of test1 'a': %p || Value: %c\n",(void *)&test_1.a,test_1.a);
    printf("Addr of test1 'b': %p || Value: %c\n",(void *)&test_1.b,test_1.b);
    printf("Addr of test1 'c': %p || Value: %d\n",(void *)&test_1.c,test_1.c);
    printf("\n---Test4---\n");
    printf("Addr of test4 'a': %p || Value: %c\n",(void *)&test_4.a,test_4.a);
    printf("Addr of test4 'b': %p || Value: %c\n",(void *)&test_4.b,test_4.b);
    printf("Addr of test4 'c': %p || Value: %d\n",(void *)&test_4.c,test_4.c);
    return 0;
}