#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a>b?a:b;
}

typedef struct {
    int weight;
    int value;
} obj;

int main() {
    int G,n,i,j;
    //printf("The maximum weight of the backpack is : ");
    scanf("%d", &G);
    //printf("The number ob objects is : ");
    scanf("%d", &n);

    obj* objects;
    objects=(int*)malloc(sizeof(int)*(n+1));

    for(i=1;i<=n;i++)
        //the weight of each single object is :
    {
        scanf("%d", &objects[i].value);
        scanf("%d", &objects[i].weight);
    }

    int** m;
    m=(int**)calloc((n+1),sizeof(int*));
    for(i=0;i<=n;i++)
        m[i]=(int*)calloc((G+1),sizeof(int));

    for(i=0;i<=n;i++) m[i][0]=0;
    for(i=0;i<=G;i++) m[0][i]=0;


    for(i=1;i<=n;i++)
            for (j = 1; j <= G; j++) {
                if(objects[i].weight>j)
                  m[i][j] = m[i - 1][j];
                else
                    m[i][j] = max(m[i][j - 1], m[i][j - objects[i].weight] + objects[i].value);
                }



    printf("%d", m[n][G]);


    for(i=0;i<=n;i++) {
        for (j = 0; j <= G; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }

    free(objects);
    for(i=0;i<=n;i++)
        free(m[i]);
    free(m);

    return 0;
}


/*
10
5
80 5
50 2
400 20
60 3
70 4
 */
