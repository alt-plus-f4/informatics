#include <stdio.h>
#include <stdlib.h>

struct snowmen_t{
    int* p;
    int* m;
};

int main(){
    struct snowmen_t* snowmen = (struct snowmen_t*)malloc(sizeof(struct snowmen_t));
    int n = 0, weight = 0;

    do{
        printf("Enter n: ");
        scanf("%d", &n);
    }while(1 > n > 1000001);

    int* copy_weight = (int*)malloc(sizeof(int) * n);
    snowmen->p, snowmen->m = (int*)malloc(sizeof(int) * n);
    copy_weight[0] = 0;

    for(int i = 0; i < n; i++){
        do{
            printf("[%d] Enter p, m: ", i);
            scanf("%d %d", &snowmen->p[i], &snowmen->m[i]);
        }while(snowmen->p[i] < 0 || snowmen->p[i] > i || snowmen->m[i] < 0);

        if(i >= 1 && snowmen->m[i] == 0){
            int temp = snowmen->p[snowmen->p[i]];
            snowmen->p[i] = snowmen->p[temp];
            snowmen->m[i] = snowmen->m[temp];
        }
        printf("%d", weight);
        copy_weight[i] = copy_weight[snowmen->p[i]] + snowmen->m[i];
        weight+= (snowmen->m[i] + copy_weight[i]);
    }

    printf("Total weight: %d\n", weight);

    return 0;
}