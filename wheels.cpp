#include <stdio.h>
#include <algorithm>

int draw_graph(bool *used, int initial, int target)
{
    int que[10000], counter[10000]{}, last(0);
    std::fill_n(que, 10000, -1);
    que[0] = initial;
    for(int i=0; i<10000 && que[i]!=-1; ++i)
    {
        int base = que[i];
        int d[4], dec = 1000;
        for(int k=0; k<4; ++k)
        {
            d[k] = base/dec;
            base -= d[k]*dec;
            dec /= 10;
        }
        for(int j=0; j<4; ++j)
        {
            d[j] = d[j]+1==10?0:d[j]+1;
            int s = d[0]*1000 + d[1]*100 + d[2]*10 + d[3];
            if(!used[s])
            {
                que[++last] = s;
                counter[s] = counter[que[i]]+1;
                used[s] = true;
            }
            if(s==target)
            {
                return counter[s];
            }
            d[j] = d[j]-1==-1?9:d[j]-1;
            d[j] = d[j]-1==-1?9:d[j]-1;
            s = d[0]*1000 + d[1]*100 + d[2]*10 + d[3];
            if(!used[s])
            {
                que[++last] = s;
                counter[s] = counter[que[i]]+1;
                used[s] = true;
            }
            if(s==target)
            {
                return counter[s];
            }
            d[j] = d[j]+1==10?0:d[j]+1;
        }
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        int a,b,c,d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int initial = a*1000 + b*100 + c*10 +d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int target = a*1000 + b*100 + c*10 +d;
        int forb;
        scanf("%d", &forb);
        bool used[10000] {};
        used[initial] = true;
        for(int j=0; j<forb; ++j)
        {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            used[a*1000 + b*100 + c*10 +d] = true;
        }
        printf("%d\n",draw_graph(used, initial, target));
    }
    return 0;
}
