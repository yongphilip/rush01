#include <stdlib.h>
#include <stdio.h>

// Functions To Be Used
int	ft_recursive_power(int nb, int power);
int	ft_sqrt(int nb);

int main(int argc, char *argv[])
{
    // Initialization
    char *clueArr[17] = { "0",
        // Up
        "3", "4", "1", "2",
        // Down
        "2", "1", "2", "2",
        // Left
        "2", "2", "1", "2",
        // Right
        "2", "1", "4", "3"};

    // Clues
    int **clue;

    // Size of Grid NxN
    int size = ft_sqrt(17 - 1);

    // Allocate Row for Clues
    clue = malloc(size * sizeof(*clue));

    int index = 1;

    for(int y = 0; y < size; y++)
    {
        // Allocate Columns For Each Row
        clue[y] = malloc(sizeof(*clue) * size);
        for (int x = 0; x < size; x++)
        {
            // Adding Data Into Each Column
            clue[y][x] = atoi(clueArr[index]);
            index++;
        }
    }

    // Grid
    int **grid;
    int ***gridRemains;

    // Allocate Row for Grid
    grid = malloc(size * sizeof(*grid));
    gridRemains = malloc(size * sizeof(*gridRemains));

    for(int y = 0; y < size; y++)
    {
        // Allocate Columns For Each Row
        grid[y] = malloc(sizeof(*grid) * size);
        gridRemains[y] = malloc(sizeof(*gridRemains) * size);
        for (int x = 0; x < size; x++)
        {
            // Adding Data Into Each Column
            grid[y][x] = 0;
            gridRemains[y][x] = malloc(sizeof(*gridRemains) * size);
            for (int i = 0; i < size; i++)
            {
                gridRemains[y][x][i] = 0;
            }
        }
    }

    // Used Number Index
    int ***usedIndex;

    // Allocate Row for usedIndex
    usedIndex = malloc(size * sizeof(*usedIndex));

    for(int y = 0; y < size; y++)
    {
        // Allocate Columns For Each Row
        usedIndex[y] = malloc(sizeof(*usedIndex) * 3);
        
        // Count
        usedIndex[y][0] = malloc(sizeof(*usedIndex));
        usedIndex[y][0][0] = 0;

        // Horizontal Used
        usedIndex[y][1] = malloc(size * sizeof(*usedIndex));
        for (int x = 0; x < size; x++)
        {
            // Adding Data Into Each Column
            usedIndex[y][1][x] = 0;
        }

        // Vertical Used
        usedIndex[y][2] = malloc(size * sizeof(*usedIndex));
        for (int x = 0; x < size; x++)
        {
            // Adding Data Into Each Column
            usedIndex[y][2][x] = 0;
        }
    }

    // Check Clues For 1 & 4

    // Check Through Every Side
    for(int y = 0; y < size; y++)
    {
        // Check Each Column
        for (int x = 0; x < size; x++)
        {
            // Check Clues == 1
            if (clue[y][x] == 1)
            {
                if (y == 0)
                {
                    if (usedIndex[4 - 1][0][0] < 4 && usedIndex[4 - 1][1][0] != 1 && usedIndex[4 - 1][2][x] != 1)
                    {
                        grid[0][x] = 4;
                        usedIndex[4 - 1][0][0]++;
                        usedIndex[4 - 1][1][0] = 1;
                        usedIndex[4 - 1][2][x] = 1;

                        int coordsY = 0;
                        int coordsX = x;

                        // Remove Remains Horizontal
                        for (int a = 0; a < size; a++)
                        {
                            if (a == coordsX)
                            {
                                for (int b = 0; b < size; b++)
                                {
                                    gridRemains[coordsY][a][b] = 1;
                                }
                            }
                            else
                            {
                                gridRemains[coordsY][a][3] = 1;
                            }
                        }

                        // Remove Remains Vertical
                        for (int a = 0; a < size; a++)
                        {
                            if (a == coordsY)
                            {
                                for (int b = 0; b < size; b++)
                                {
                                    gridRemains[a][coordsX][b] = 1;
                                }
                            }
                            else
                            {
                                gridRemains[a][coordsX][3] = 1;
                            }
                        }
                    }
                }
                else if (y == 1)
                {
                    if (usedIndex[4 - 1][0][0] < 4 && usedIndex[4 - 1][1][3] != 1 && usedIndex[4 - 1][2][x] != 1)
                    {
                        grid[x][3] = 4;
                        usedIndex[4 - 1][0][0]++;
                        usedIndex[4 - 1][1][x] = 1;
                        usedIndex[4 - 1][2][3] = 1;

                        int coordsY = x;
                        int coordsX = 3;

                        // Remove Remains Horizontal
                        for (int a = 0; a < size; a++)
                        {
                            if (a == coordsX)
                            {
                                for (int b = 0; b < size; b++)
                                {
                                    gridRemains[coordsY][a][b] = 1;
                                }
                            }
                            else
                            {
                                gridRemains[coordsY][a][3] = 1;
                            }
                        }

                        // Remove Remains Vertical
                        for (int a = 0; a < size; a++)
                        {
                            if (a == coordsY)
                            {
                                for (int b = 0; b < size; b++)
                                {
                                    gridRemains[a][coordsX][b] = 1;
                                }
                            }
                            else
                            {
                                gridRemains[a][coordsX][3] = 1;
                            }
                        }
                    }
                }
                else if (y == 2)
                {
                    if (usedIndex[4 - 1][0][0] < 4 && usedIndex[4 - 1][1][x] != 1 && usedIndex[4 - 1][2][0] != 1)
                    {
                        grid[x][0] = 4;
                        usedIndex[4 - 1][0][0]++;
                        usedIndex[4 - 1][1][x] = 1;
                        usedIndex[4 - 1][2][0] = 1;

                        int coordsY = x;
                        int coordsX = 0;

                        // Remove Remains Horizontal
                        for (int a = 0; a < size; a++)
                        {
                            if (a == coordsX)
                            {
                                for (int b = 0; b < size; b++)
                                {
                                    gridRemains[coordsY][a][b] = 1;
                                }
                            }
                            else
                            {
                                gridRemains[coordsY][a][3] = 1;
                            }
                        }

                        // Remove Remains Vertical
                        for (int a = 0; a < size; a++)
                        {
                            if (a == coordsY)
                            {
                                for (int b = 0; b < size; b++)
                                {
                                    gridRemains[a][coordsX][b] = 1;
                                }
                            }
                            else
                            {
                                gridRemains[a][coordsX][3] = 1;
                            }
                        }
                    }
                }
                else
                {
                    if (usedIndex[4 - 1][0][0] < 4 && usedIndex[4 - 1][1][x] != 1 && usedIndex[4 - 1][2][3] != 1)
                    {
                        grid[x][3] = 4;
                        usedIndex[4 - 1][0][0]++;
                        usedIndex[4 - 1][1][x] = 1;
                        usedIndex[4 - 1][2][3] = 1;

                        int coordsY = x;
                        int coordsX = 3;

                        // Remove Remains Horizontal
                        for (int a = 0; a < size; a++)
                        {
                            if (a == coordsX)
                            {
                                for (int b = 0; b < size; b++)
                                {
                                    gridRemains[coordsY][a][b] = 1;
                                }
                            }
                            else
                            {
                                gridRemains[coordsY][a][3] = 1;
                            }
                        }

                        // Remove Remains Vertical
                        for (int a = 0; a < size; a++)
                        {
                            if (a == coordsY)
                            {
                                for (int b = 0; b < size; b++)
                                {
                                    gridRemains[a][coordsX][b] = 1;
                                }
                            }
                            else
                            {
                                gridRemains[a][coordsX][3] = 1;
                            }
                        }
                    }
                }
            }
            // Check Clues == 4
            else if (clue[y][x] == 4)
            {
                if (y == 0)
                {
                    for (int i = 1; i <= 4; i++)
                    {
                        if (usedIndex[i - 1][0][0] < 4 && usedIndex[i - 1][1][i - 1] != 1 && usedIndex[i - 1][2][x] != 1)
                        {
                            grid[i - 1][x] = i;
                            usedIndex[i - 1][0][0]++;
                            usedIndex[i - 1][1][i - 1] = 1;
                            usedIndex[i - 1][2][x] = 1;

                            int coordsY = i - 1;
                            int coordsX = x;

                            // Remove Remains Horizontal
                            for (int a = 0; a < size; a++)
                            {
                                if (a == coordsX)
                                {
                                    for (int b = 0; b < size; b++)
                                    {
                                        gridRemains[coordsY][a][b] = 1;
                                    }
                                }
                                else
                                {
                                    gridRemains[coordsY][a][i - 1] = 1;
                                }
                            }

                            // Remove Remains Vertical
                            for (int a = 0; a < size; a++)
                            {
                                if (a == coordsY)
                                {
                                    for (int b = 0; b < size; b++)
                                    {
                                        gridRemains[a][coordsX][b] = 1;
                                    }
                                }
                                else
                                {
                                    gridRemains[a][coordsX][i - 1] = 1;
                                }
                            }
                        }
                    }
                }
                else if (y == 1)
                {
                    for (int i = 1; i <= 4; i++)
                    {
                        if (usedIndex[i - 1][0][0] < 4 && usedIndex[i - 1][1][4 - i] != 1 && usedIndex[i - 1][2][x] != 1)
                        {
                            grid[4 - i][x] = i;
                            usedIndex[i - 1][0][0]++;
                            usedIndex[i - 1][1][4 - i] = 1;
                            usedIndex[i - 1][2][x] = 1;

                            int coordsY = 4 - i;
                            int coordsX = x;

                            // Remove Remains Horizontal
                            for (int a = 0; a < size; a++)
                            {
                                if (a == coordsX)
                                {
                                    for (int b = 0; b < size; b++)
                                    {
                                        gridRemains[coordsY][a][b] = 1;
                                    }
                                }
                                else
                                {
                                    gridRemains[coordsY][a][i - 1] = 1;
                                }
                            }

                            // Remove Remains Vertical
                            for (int a = 0; a < size; a++)
                            {
                                if (a == coordsY)
                                {
                                    for (int b = 0; b < size; b++)
                                    {
                                        gridRemains[a][coordsX][b] = 1;
                                    }
                                }
                                else
                                {
                                    gridRemains[a][coordsX][i - 1] = 1;
                                }
                            }
                        }
                    }
                }
                else if (y == 2)
                {
                    for (int i = 1; i <= 4; i++)
                    {
                        if (usedIndex[i - 1][0][0] < 4 && usedIndex[i - 1][1][x] != 1 && usedIndex[i - 1][2][i - 1] != 1)
                        {
                            grid[x][i - 1] = i;
                            usedIndex[i - 1][0][0]++;
                            usedIndex[i - 1][1][x] = 1;
                            usedIndex[i - 1][2][i - 1] = 1;

                            int coordsY = x;
                            int coordsX = i - 1;

                            // Remove Remains Horizontal
                            for (int a = 0; a < size; a++)
                            {
                                if (a == coordsX)
                                {
                                    for (int b = 0; b < size; b++)
                                    {
                                        gridRemains[coordsY][a][b] = 1;
                                    }
                                }
                                else
                                {
                                    gridRemains[coordsY][a][i - 1] = 1;
                                }
                            }

                            // Remove Remains Vertical
                            for (int a = 0; a < size; a++)
                            {
                                if (a == coordsY)
                                {
                                    for (int b = 0; b < size; b++)
                                    {
                                        gridRemains[a][coordsX][b] = 1;
                                    }
                                }
                                else
                                {
                                    gridRemains[a][coordsX][i - 1] = 1;
                                }
                            }
                        }
                    }
                }
                else
                {
                    for (int i = 1; i <= 4; i++)
                    {
                        if (usedIndex[i - 1][0][0] < 4 && usedIndex[i - 1][1][x] != 1 && usedIndex[i - 1][2][4 - i] != 1)
                        {
                            grid[x][4 - i] = i;
                            usedIndex[i - 1][0][0]++;
                            usedIndex[i - 1][1][x] = 1;
                            usedIndex[i - 1][2][4 - i] = 1;

                            int coordsY = x;
                            int coordsX = 4 - i;

                            // Remove Remains Horizontal
                            for (int a = 0; a < size; a++)
                            {
                                if (a == coordsX)
                                {
                                    for (int b = 0; b < size; b++)
                                    {
                                        gridRemains[coordsY][a][b] = 1;
                                    }
                                }
                                else
                                {
                                    gridRemains[coordsY][a][i - 1] = 1;
                                }
                            }

                            // Remove Remains Vertical
                            for (int a = 0; a < size; a++)
                            {
                                if (a == coordsY)
                                {
                                    for (int b = 0; b < size; b++)
                                    {
                                        gridRemains[a][coordsX][b] = 1;
                                    }
                                }
                                else
                                {
                                    gridRemains[a][coordsX][i - 1] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    //  // Check gridRemains
    // for (int y = 0; y < size; y++)
    // {
    //     for (int x = 0; x < size; x++)
    //     {
    //         printf("Remains: x - %d | y - %d\n", x, y);
    //         for (int a = 0; a < size; a++)
    //         {
    //             printf("%d ", gridRemains[y][x][a]);
    //         }
    //         printf("\n");
    //     }
    //     printf("Remains: End\n\n");
    // }

    // grid[0][3] = 2;
    // usedIndex[1][0][0]++;
    // usedIndex[1][1][0] = 1;
    // usedIndex[1][2][3] = 1;

    // grid[1][2] = 3;
    // usedIndex[2][0][0]++;
    // usedIndex[2][1][1] = 1;
    // usedIndex[2][2][2] = 1;

    // while(1)
    // {
        // Check usedIndex
        int completedLines = 0;
        for (int i = 0; i < size; i++)
        {
            if (usedIndex[i][0][0] == 3)
            {
                int x = 0;
                int y = 0;

                for (int n = 0; n < size; n++)
                {
                    if (usedIndex[i][1][n] == 0)
                    {
                        x = n;
                    }

                    if (usedIndex[i][2][n] == 0)
                    {
                        y = n;
                    }
                }

                grid[x][y] = i + 1;
                usedIndex[i][0][0]++;
                usedIndex[i][1][x] = 1;
                usedIndex[i][2][x] = 1;
            }
            else if (usedIndex[i][0][0] == 4)
            {
                completedLines++;
            }
        }

        // if (completedLines == 4)
        // {
        //     break;
        // }

        // Check Horizontal
        for(int y = 0; y < size; y++)
        {
            int empty = 0;
            int filled[size];

            for (int x = 0; x < size; x++)
            {
                filled[x] = 0;
            }

            for (int x = 0; x < size; x++)
            {
                if (grid[y][x] == 0)
                {
                    empty++;
                }
                else
                {
                    filled[grid[y][x] - 1] = 1;
                }
            }

            if (empty == 1)
            {
                for (int x = 0; x < size; x++)
                {
                    if (filled[x] == 0)
                    {
                        for (int i = 0; i < size; i++)
                        {
                            if (grid[y][i] == 0)
                            {
                                grid[y][i] = x + 1;
                                usedIndex[x][0][0]++;
                                usedIndex[x][1][y] = 1;
                                usedIndex[x][2][i] = 1;
                            }
                        }
                    }
                }
            }
        }

        // Check Vertical
        for(int x = 0; x < size; x++)
        {
            int empty = 0;
            int filled[size];

            for (int y = 0; y < size; y++)
            {
                filled[y] = 0;
            }

            for (int y = 0; y < size; y++)
            {
                if (grid[y][x] == 0)
                {
                    empty++;
                }
                else
                {
                    filled[grid[y][x] - 1] = 1;
                }
            }

            if (empty == 1)
            {
                for (int y = 0; y < size; y++)
                {
                    if (filled[y] == 0)
                    {
                        for (int i = 0; i < size; i++)
                        {
                            if (grid[i][x] == 0)
                            {
                                grid[i][x] = y + 1;
                                usedIndex[y][0][0]++;
                                usedIndex[y][1][i] = 1;
                                usedIndex[y][2][x] = 1;
                            }
                        }
                    }
                }
            }
        }

        // Check Clues
        // for (int a = 0; a < size; a++)
        // {
        //     for (int b = 0; b < size; b++)
        //     {
        //         if (a == 0)
        //         {
        //             if (clue[a][b] == size - 1)
        //             {
        //                 for (int i = (size - clue[a][b]) + 1; i < size; i++)
        //                 {
        //                     gridRemains[0][b][i] = 1;
        //                 }
                        
        //                 if (grid[0][b] == size - 2 && grid[2][b] == size)
        //                 {
        //                     printf("yes1\n");
        //                     grid[1][b] = size - 1;

        //                     usedIndex[size - 2][0][0]++;
        //                     usedIndex[size - 2][1][b] = 1;
        //                     usedIndex[size - 2][2][a] = 1;
        //                 }
        //             }  
        //         }
        //         else if (a == 1)
        //         {
        //             if (clue[a][b] == size - 1)
        //             {
        //                 for (int i = (size - clue[a][b]) + 1; i < size; i++)
        //                 {
        //                     gridRemains[3][b][i] = 1;
        //                 }
        //             }
        //         }
        //         else if (a == 2)
        //         {
        //             if (clue[a][b] == size - 1)
        //             {
        //                 for (int i = (size - clue[a][b]) + 1; i < size; i++)
        //                 {
        //                     gridRemains[b][0][i] = 1;
        //                 }
        //             }
        //         }
        //         else
        //         {
        //             if (clue[a][b] == size - 1)
        //             {
        //                 for (int i = (size - clue[a][b]) + 1; i < size; i++)
        //                 {
        //                     gridRemains[b][3][i] = 1;
        //                 }
        //             }
        //         }

        //         int countRemains = 0;

        //         for (int i = 0; i < size; i++)
        //         {
        //             if (gridRemains[a][b][i] == 1)
        //             {
        //                 countRemains++;
        //             }
        //         }

        //         if (countRemains == 3)
        //         {
        //             for (int i = 0; i < size; i++)
        //             {
        //                 if (gridRemains[a][b][i] == 0)
        //                 {
        //                     grid[a][b] = i + 1;
        //                     gridRemains[a][b][i] = 1;
        //                     usedIndex[i][0][0]++;
        //                     usedIndex[i][1][b] = 1;
        //                     usedIndex[i][2][a] = 1;

        //                     int coordsX = a;
        //                     int coordsY = b;
                            
        //                     // Add Remains To Horizontal
        //                     for(int x = 0; x < size; x++)
        //                     {
        //                         if(x == coordsX)
        //                         {
        //                             for(int y = 0; y < size; y++)
        //                             {
        //                                 gridRemains[x][coordsY][y] = 1;
        //                             }
        //                         }
        //                         else
        //                         {
        //                             gridRemains[x][coordsY][i] = 1;
        //                         }
        //                     }

        //                     // Add Remains to Vertical
        //                     for(int x = 0; x < size; x++)
        //                     {
        //                         if(x == coordsY)
        //                         {
        //                             for(int y = 0; y < size; y++)
        //                             {
        //                                 gridRemains[coordsX][x][y] = 1;
        //                             }
        //                         }
        //                         else
        //                         {
        //                             gridRemains[coordsX][x][i] = 1;
        //                         }
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
    // }

    // Check usedIndex
    for (int y = 0; y < size; y++)
    {
        printf("Used: Num   - %d\n", y + 1);
        printf("Used: Count - %d\n", usedIndex[y][0][0]);
        for (int x = 0; x < size; x++)
        {
            printf("%d | %d\n", usedIndex[y][1][x], usedIndex[y][2][x]);
        }
        printf("Used: End\n\n");
    }

    // // Check gridRemains
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            printf("Remains: x - %d | y - %d\n", x, y);
            for (int a = 0; a < size; a++)
            {
                printf("%d ", gridRemains[y][x][a]);
            }
            printf("\n");
        }
        printf("Remains: End\n\n");
    }

    // Output
    for(int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            // Printing Out Data For Each Column
            printf("%d", grid[y][x]);
        }
        printf("\n");

        // Freeing All Columns For Each Row
        for (int x = 0; x < 3; x++)
        {
            free(usedIndex[y][x]);
        }

        for (int x = 0; x < size; x++)
        {
            free(gridRemains[y][x]);
        }
        free(usedIndex[y]);
        free(gridRemains[y]);
        free(clue[y]);
        free(grid[y]);
    }
    
    // Freeing All Rows
    free(usedIndex);
    free(gridRemains);
    free(clue);
    free(grid);
}

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

int	ft_sqrt(int nb)
{
	int	i;
	int	x;

	i = 0;
	while (1)
	{
		x = ft_recursive_power(i, 2);
		if (nb == x)
			return (i);
		if (nb < x)
			return (0);
		i++;
	}
}