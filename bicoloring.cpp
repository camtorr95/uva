#include <stdio.h>
using namespace std;

struct node
{
    int val;
    node *next;
};

bool f(node **grafo, const int &n)
{
    bool visited[n] {0}, colored[n] {0};
    int que[n] {0}, last(0);
    for(int i=0; i<n; ++i)
    {
        node *ns = grafo[que[i]];
        visited[que[i]] = true;
        for(; ns; ns = ns->next)
        {
            if(visited[ns->val])
            {
                if(colored[que[i]] == colored[ns->val])
                    return false;
            }
            else
            {
                visited[ns->val] = true;
                que[++last] = ns->val;
                if(!colored[que[i]])
                {
                    colored[ns->val] = true;
                }
            }
        }
    }
    return true;
}

int main()
{
    int n;
    while(scanf("%d", &n) && n!=0)
    {
        int l;
        scanf("%d", &l);
        node *grafo[n] {0};
        node adlist[2*l] {0};
        for(int i=0; i<l; ++i)
        {
            int a,b,c((2*l)-(1+i));
            scanf("%d %d", &a, &b);
            adlist[i].val = a;
            adlist[c].val = b;
            adlist[c].next = grafo[a];
            adlist[i].next = grafo[b];
            grafo[b] = &adlist[i];
            grafo[a] = &adlist[c];
        }
        if(f(grafo, n))
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
