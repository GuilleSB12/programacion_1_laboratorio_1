#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i = 1 , suma = 0;
    while ( i <= 100 )
    {
        suma = suma + i;
        i++;
    }

    printf ( "%d", suma );

    return 0;
}
