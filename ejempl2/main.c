#include <stdio.h>
#include <stdlib.h>

int main()
{
   char d;
    for(;;)
    {
        scanf("%c",&d);
        printf("%c",d);

        if (d == 'b')
            break;
    }

    return 0;
}
