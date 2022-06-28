#include <stdio.h>

int main(int argc, char **argv)
{
    int cases; 
    int bags, kids, total;
    int temp;

    scanf("%i\n", &cases);

    for (int i = 0; i < cases; i++)
    {
        total = 0;
        scanf("%i %i\n", &bags, &kids); 
        
        for (int j = 0; j < bags; j++)
        {
            scanf("%i", &temp);
            total += temp;
        }

        printf("Case #%i: %i\n", i + 1, total % kids);
    }

    return 0;
}
