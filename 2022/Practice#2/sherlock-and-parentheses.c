#include <stdio.h>

// Recursive sum function
int sum(int a)
{
    if (a == 0)
        return 0;
    else
        return a + sum(a-1);
}

int main(int argc, char **argv)
{
    int cases; 
    int lefts, rights;
    int substrings;

    scanf("%i\n", &cases);

    for (int i = 0; i < cases; i++)
    {
        substrings = 0;
        scanf("%i %i\n", &lefts, &rights);

        // Find min value
        if (lefts < rights)
            substrings = sum(lefts);
        else
            substrings = sum(rights);

        printf("Case #%i: %i\n", i + 1, substrings);
    }

    return 0;
}
