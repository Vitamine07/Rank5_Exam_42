#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac != 4)
        return (1);
    int width = atoi(av[1]);
    int height = atoi(av[2]);
    int ite = atoi(av[3]);

    if(width <= 0 || height <=0 || ite < 0)
        return (1);

    int size = (height + 2) * (width + 2);
    int *grid0 = calloc(size, sizeof(int));
    int *grid1 = calloc(size, sizeof(int));
    if(!grid0 || !grid1)
        return(1);

    int *grids[2] = {grid0, grid1};
    int x = 1, y = 1, pen = 0;
    char c;

    while(read(0, &c,1) > 0)
    {
        if(c == 'w' && y > 1) y--;
        else if(c == 's' && y < height) y++;
        else if(c == 'a' && x > 1) x--;
        else if(c == 'd' && x < width) x++;
        else if(c == 'x')pen = !pen;
        if(pen)
            grids[0][y * (width + 2) + x] = 1;
    }

    for (int it = 0; it < ite; it++)
    {
        int cur = it % 2;
        int next = (it + 1) % 2;
        for (int i = 1; i <= height; i++)
        {
            for (int j = 1; j <= width; j++)
            {
                int n = 0;
                for (int dy = -1; dy <= 1; dy++)
                {
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        if(dx != 0 || dy != 0)
                            n += grids[cur][(i + dy) * (width + 2) | (j + dx)];
                    }
                }
                int idx = i * (width + 2) + j;
                if(grids[cur][idx] == 1)
                    grids[next][idx] = (n == 2 || n == 3);
                else
                    grids[next][idx] = (n == 3);
            }
        }
    }
    int final = ite % 2;
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            if(grids[final][i * (width + 2) + j])
                putchar('0');
            else
                putchar(' ');
        }
        putchar('\n');
    }
    free(grid0);
    free(grid1);
    return (0);
}