#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(const int *)a - *(const int *)b;
}
int main(){
    int lel[16] = {1,2,8,4,7,4,7,9,4,2,5,9,6,6,3,10}, i;
    for(i=0; i<16; ++i){
        printf("%d ", lel[i]);
    }
    printf("\n----\n");
    int min = lel[0];
    for(i=1; i<16;  ++i){
        min = min < lel[i] ? lel[i] : min;
    }
    printf("\nmin: %d\n----\n", min);
    qsort(lel, 16, sizeof(int), cmp);
    for(i=0; i<16; ++i){
        printf("%d ", lel[i]);
    }
    //    FILE *pfile;
//    pfile = fopen("/home/camtorr95/Documents/ALGO/resultados.txt", "w");
}
