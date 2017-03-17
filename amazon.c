#include <stdio.h>
#include <string.h>

typedef struct point
{
    int i,x,y;
} point;

int pow2(int a)
{
    return a*a;
}

int dist(point *a, point *b)
{
    return pow2(a->x - b->x)+pow2(a->y - b->y);
}

point *base;

int cmp(point *a, point *b)
{
    int dist_a = dist(base, a), dist_b = dist(base, b);
    if(dist_a == dist_b)
    {
        if(a->x == b->x)
        {
            return a->y - b->y < 0 ? -1 : 1;
        }
        return a->x - b->x < 0 ? -1 : 1;
    }
    return dist_a - dist_b < 0 ? -1 : 1;
}

char draw_graph(point *plane, int n)
{
    int i,j;
    int grafo[n][2];
    for(i=0; i<n; ++i)
    {
        base = plane+i;
        grafo[i][0] = -1;
        grafo[i][1] = -1;
        for(j=0; j<n; ++j)
        {
            if(j==i) continue;
            grafo[i][0] = grafo[i][0] == -1 ? plane[j].i : cmp(&plane[grafo[i][0]], &plane[j]) < 0 ? grafo[i][0] : plane[j].i;
        }
        for(j=0; j<n; ++j)
        {
            if(j==i || j==grafo[i][0]) continue;
            grafo[i][1] = grafo[i][1] == -1 ? plane[j].i : cmp(&plane[grafo[i][1]], &plane[j]) < 0 ? grafo[i][1] : plane[j].i;
        }
    }
    int que[n], last = 0;
    memset(que, -1, 4*n);
    char visited[n];
    memset(visited, 0, n);
    que[0] = 0;
    visited[0] = 1;
    for(i=0; que[i]!=-1; ++i)
    {
        int a = grafo[que[i]][0], b = grafo[que[i]][1];
        if(!visited[a])
        {
            que[++last] = a;
            visited[a] = 1;
        }
        if(!visited[b])
        {
            que[++last] = b;
            visited[b] = 1;
        }
        if(last==n-1)return 1;
    }
    return 0;
}

int main()
{
    int n, i;
    while(scanf("%d", &n) && n)
    {
        point plane[n];
        for(i=0; i<n; ++i)
        {
            plane[i].i = i;
            scanf("%d %d", &plane[i].x, &plane[i].y);
        }
        if(n<=3)
            printf("All stations are reachable.\n");
        else
        {
            if(draw_graph(plane, n))
                printf("All stations are reachable.\n");
            else
                printf("There are stations that are unreachable.\n");
        }
    }
    return 0;
}
