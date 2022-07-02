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
            int points[9][2] = {{i-1, j-1}, {i-1, j}, {i-1,j+1}, 
                {i, j-1}, {i, j}, {i, j+1}, {i+1, j-1}, {i+1, j}, {i+1, j+1}};
            int total = 0;

            for (int m = 0; m < 9; m++)
            {
                if ((points[m][0] >= 0 && points[m][0] < rows) && \
                        (points[m][1] >= 0 && points[m][1] < cols))
                {
                    total += distance[points[m][0]][points[m][1]]; 
                }
            }

            if (total > max_distance)
            {
                max_distance = total;
                max_location[0] = i;
                max_location[1] = j;
            }
        }
    }

    if (max_location[0] == 0 && max_location[1] == 0)
    {
        max_location[0] = rows / 2;
        max_location[1] = cols / 2;
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

        printf("Case #%i: %i\n", i + 1, 
                distance[max_location[0]][max_location[1]]);
    }

    return 0;
}
