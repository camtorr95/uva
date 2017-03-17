#include <stdio.h>
using namespace std;

struct v{
    int x;
    bool m;
    v *n_v;
};

int main()
{
    v grafo[200];
    for(;;)
    {
        int n;
        scanf("%d\n", &n);
        if(n==0)break;
        for(int i=0; i<n; ++i)
        {
            int a,b;
            scanf("%d %d\n", &a,&b);
        }
    }
    return 0;
}
