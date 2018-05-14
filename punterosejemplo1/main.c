#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 15;
    int x;
    int *b = NULL;
    int *c;

    b = &a;

    c = b;

    a = 18;

    x = a;

    printf("A: %d\nB: %d\nC: %d\nx: %d\n",a, *b, *c, x);

    *b = 12;

    printf("\n\nA: %d\nB: %d\nC: %d\nx: %d\n",a, *b, *c, x);



    return 0;
}
