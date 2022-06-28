#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int cases; 
    int palindromes;
    int blocks, questions;
    char letters[1000001];
    int occurrences[90];
    int left, right;
    int odds;

    scanf("%i\n", &cases);

    for (int i = 0; i < cases; i++)
    {
        palindromes = 0;
        scanf("%i %i\n", &blocks, &questions); 
        scanf("%s\n", letters);

        for (int j = 0; j < questions; j++)
        {
            memset(occurrences, 0, sizeof occurrences);
            odds = 0;

            scanf("%i %i\n", &left, &right);    
            for(int k = left-1; k < right; k++)
            {
                printf("%i %c\n", k, letters[k]);
                occurrences[letters[k]]++;
            }
            for(int k = 65; k <= 90; k++)
            {
                printf("%c: %i\n", k, occurrences[k]);

                if (occurrences[k] % 2 != 0)
                    odds++;

                if (odds > 1)
                    continue;
            }
            palindromes++;
        }

        printf("Case #%i: %i\n", i + 1, palindromes);
        printf("-----------------------------\n");
    }

    return 0;
}
