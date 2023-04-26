#include <stdio.h>
#include <stdlib.h>

// pointer -> a (const)
int comp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}


int main(int argc, const char argv[]){
    int s[500];
    int cs, n, median, sum ;
    printf("Number of case:");
    scanf("%d", &cs);
    for(int i =0; i<cs; i++){
        printf("Number of stree's parent:");
        scanf("%d", &n);
        for(int k=0 ; k<n; k++){
            scanf("%d", &s[i]);
        }
        qsort(s, n, sizeof(int), comp);
        median = s[n/2];

        sum = 0;
        
    }

    return 0;

}