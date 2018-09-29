#include <stdbool.h>
#define N 8 
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
int count = 0;

struct points
{
    int i;
    int j;
};

int rows[] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 
int cols[] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 

struct points getcurrpoints(uint64_t board)
{
    int i = 0;
    struct points points;
    u_int8_t temp = 0;

    while (!temp)
    {
        temp = (u_int8_t)board;
        board >>= 8;
        i++;
    }
    points.i = i - 1;
    points.j = ffs(temp) - 1;
    return(points);
}

bool inside(int x, int y) 
{ 
    return (x >= 0 && x < N && y >= 0 && y < N); 
} 

int getInitialPos(uint64_t board)
{
	int	pos = 0;
	while (!(board >> pos & 1)) pos++;
	return (pos);
}

double findProb(int now_x, int now_y, int steps) 
{ 
    double dp1[N][N][steps];
	int x;
	int y;
	int i;
	int nx; 
	int ny; 
	double prob; 

    for (i = 0; i < N; ++i) 
        for (int j = 0; j < N; ++j) 
            dp1[i][j][0] = 1; 
    for (int s = 1; s <= steps; ++s) 
    {
        for (x = 0; x < N; ++x) 
        {
            for (y = 0; y < N; ++y) 
            {
				prob = 0.0;
                for (i = 0; i < 8; ++i) 
                {
					nx = x + rows[i];
					ny = y + cols[i];
                    if (inside(nx, ny)) 
                        prob += dp1[nx][ny][s-1] / 8.0; 
                }
                dp1[x][y][s] = prob; 
            } 
        } 
    } 
    return dp1[now_x][now_y][steps]; 
} 

double knightOut(uint64_t board, int n)
{
    struct points currpoints = getcurrpoints(board);
    return 1 - findProb(currpoints.i, currpoints.j, n);
}