#include <stdio.h>
using namespace std;

int main()
{
    int last = -1;
    int que[10000]{};
    for(int i=0; i<10000; ++i){
        printf("%d: %d\n", i,que[i]);
    }
    while(last<500){
        int s = 1+2+3+4+5+6;
        que[++last] = s;
    }


}

