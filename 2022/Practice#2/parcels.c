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
    memset(distance, 1, sizeof distance);
    max_distance = 0;
    memset(max_location, 0, sizeof max_location);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == '1')
            {
                distance[i][j] = 0;
            }
            else
            {
                for (int k = 0; k < locations_counter; k++)
                {
                    int dis = abs(i - locations[k][0]) \
                               + abs(j - locations[k][1]);

                    if (dis < distance[i][j])
                    {
                        distance[i][j] = dis;
                    }
                }
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (distance[i][j] > max_distance)
            {
                max_distance = distance[i][j];
                max_location[0] = i;
                max_location[1] = j;
            }
        }
    }
}

int main(int argc, char **argv)
{
    scanf("%i\n", &cases);

    for (int i = 0; i < cases; i++)
    {
        memset(grid, 0, sizeof grid);
        memset(locations, 0, sizeof locations);
        locations_counter = 0;
        
        scanf("%i %i\n", &rows, &cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                scanf("%c", &grid[i][j]);
                if (grid[i][j] == '1')
                {
                    locations[locations_counter][0] = i;
                    locations[locations_counter][1] = j;
                    locations_counter++;
                }
            }
            getchar();
        }

        get_distances();

        grid[max_location[0]][max_location[1]] = '1';
        locations[locations_counter][0] = max_location[0];
        locations[locations_counter][1] = max_location[1];
        locations_counter++;
        get_distances();

        printf("Case #%i: %i\n", i + 1, max_distance);
    }

    return 0;
}
