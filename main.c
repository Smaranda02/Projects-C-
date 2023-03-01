#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    int* v1=(int*)a;  //sau int v1=*(int*)a;
    int* v2=(int*)b;  //sau int v2=*(int*)b;

    if(*v1>*v2) return 1;
     else if(*v1<*v2) return -1;
      return 0;
}

int main() {

    int *v,nr;
    scanf("%d",&nr);
    v=(int*)malloc(sizeof(int)*nr);
    for(int i=0;i<nr;i++)
        scanf("%d",v+i);

    qsort(v,nr,sizeof(v[0]),cmp);

    for(int i=0;i<nr;i++)
        printf("%d ",v[i]);
    return 0;
}
