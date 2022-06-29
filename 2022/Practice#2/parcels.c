#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cases; 
int rows;
int cols;
char grid[250][250];
int locations[62500][2]; 
int locations_counter;
int distance[250][250];
int max_distance;
int max_location[2];

void get_distances()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == '1')
            {
                distance[i][j] = 0;
                continue;
            }
            else
            {
                for(int k = 0; k < locations_counter; k++)
                {
                    int dis = abs(i - locations[locations_counter][0]) \
                               + abs(j - locations[locations_counter][1]);

                    if (dis > distance[i][j])
                        distance[i][j] = dis;

                    if (dis > max_distance)
                    {
                        max_distance = dis;
                        max_location[0] = i;
                        max_location[1] = j; 
                    }
                }
            }
        }
    }
    
    return;
}

int main(int argc, char **argv)
{
    scanf("%i\n", &cases);

    for (int i = 0; i < cases; i++)
    {
        memset(locations, 0, sizeof locations);
        locations_counter = 0;
        memset(distance, 0, sizeof distance);
        max_distance = 0;
        memset(max_location, 0, sizeof max_location);

        scanf("%i %i\n", &rows, &cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                scanf("%c", &grid[i][j]);
                if (grid[i][j] == '1')
                {
                    locations[locations_counter][0] = i - '0';
                    locations[locations_counter][1] = j - '0';
                    locations_counter++;
                }
            }
            getchar();
        }

        get_distances();

        grid[max_location[0]][max_location[1]] = '1';
        max_distance = 0;

        get_distances();

        printf("Case #%i: %i\n", i + 1, max_distance);
    }

    return 0;
}
