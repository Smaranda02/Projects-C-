#include <stdio.h>
#include <stdlib.h>
int main() {
    int nr,i,sum,mini=999999,j;
    //printf("The number of coins is : ");
    scanf("%d", &nr);
    int* coins;
    coins=(int*)malloc(nr*sizeof(int));

    for(i=0;i<nr;i++) {
        scanf("%d", &coins[i]);
        if (coins[i] < mini) mini = coins[i];
    }

    scanf("%d",&sum);

    int *sums,*prev,*freq;
    sums=(int*)calloc(sum+1,sizeof(int));
    prev=(int*)calloc(sum,sizeof(int));
    freq=(int*)calloc(sum,sizeof(int));

    for(i=0;i<nr;i++)
        sums[coins[i]]=1;

    for(i=mini+1;i<sum;i++)
    {
        int minim=999999;
        for(j=0;j<nr;j++)
        {
            if(i>coins[j]) {
                if (sums[sums[i] - coins[j]] < minim && sums[sums[i] - coins[j]] != 0) {
                    minim = sums[i] - coins[j] + 1;
                    prev[i] = coins[j];
                }
                if (sums[i] != 0)
                    freq[prev[i]]++;
                else prev[i]=0;
            }
        }

    }

    for(i=0;i<=sum;i++)
        printf("%d ", sums[i]);

    /*
    i=sum;
    while(i>=0){
        printf("%d ", prev[i]);
        i=sums[i]-prev[i];
    }
     */

    free(coins);
    free(freq);
    free(sums);
    free(prev);
    return 0;
}


/*
5
2 4 5 7 8
49
 */