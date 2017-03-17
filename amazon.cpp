#include <stdio.h>
#include <algorithm>

bool scan(int plane[41][41], int *que, int n)
{
    int last(1), counter(0);
    for(int i=0; i<2*n && que[i]!=-1; ++i)
    {
        int layer = 1, x=que[i], y=que[++i];
        for(int j=y-layer; j>=0 && j<=y+layer && j<41; ++j)
        {
            if(x-layer>=0 && plane[x-layer][j] != 0)
            {
                if(++counter==n) return true;
                if(plane[x-layer][j]==2)
                {
                    plane[x-layer][j] = 3;
                    que[++last] = x-layer;
                    que[++last] = j;
                }
                if(counter%2==0) break;
            }
            if(x+layer<41 && plane[x+layer][j] != 0)
            {
                if(++counter==n) return true;
                if(plane[x-layer][j]==2)
                {
                    plane[x-layer][j] = 3;
                    que[++last] = x-layer;
                    que[++last] = j;
                }
                if(counter%2==0) break;
            }
        }
        for(int j=x-layer+1; j>=0 && j<x+layer && j<41; ++j){
            if(y-layer>=0 && plane[j][y-layer]!=0){
                if(++counter==n) return true;
                if(plane[j][y-layer]==2)
                {
                    plane[j][y-layer] = 3;
                    que[++last] = j;
                    que[++last] = y-layer;
                }
                if(counter%2==0) break;
            }
            if(y+layer<41 && plane[j][y+layer]!=0){
                if(++counter==n) return true;
                if(plane[j][y+layer]==2)
                {
                    plane[j][y+layer] = 3;
                    que[++last] = j;
                    que[++last] = y+layer;
                }
                if(counter%2==0) break;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    while(scanf("%d", &n) && n)
    {
        int plane[41][41] {};
        int que[2*n];
        std::fill_n(que, que+2*n, -1);
        scanf("%d %d", &que[0], &que[1]);
        plane[que[0]>0?20+que[0]:20-que[0]][que[1]>0?20+que[1]:20-que[1]] = 2;
        for(int i=1; i<n; ++i)
        {
            int x,y;
            scanf("%d %d", &x, &y);
            plane[x>0?20+x:20-x][y>0?20+y:20-y] = 2;
        }
        if(scan(plane, que, n))
            printf("All stations are reachable.");
        else
            printf("There are stations that are unreachable");
    }
    return 0;
}
