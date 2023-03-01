#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int days;
    float profit;
    int id;
} project;

int cmp(const void* a, const void* b)
{
    project p1=*(project*)a;
    project p2=*(project*)b;

    if(p1.profit>p2.profit)
        return -1;
    else if(p1.profit<p2.profit)
        return 1;
   return 0;
}

int main() {
    int n,j,max_day=0,i;
    float total=0;
    scanf("%d", &n);
    project* p;
    p=(project*)malloc(n*sizeof(project));

    for(int i=0;i<n;i++) {
        scanf("%d %f", &p[i].days, &p[i].profit);
        if (p[i].days > max_day) max_day = p[i].days;
        p[i].id=i+1;
    }

    qsort(p,n,sizeof(project),cmp);

    project* plan;
    plan=(project*)calloc(max_day+1,sizeof(project));


    for(i=0;i<n;i++)
     for(j=p[i].days;j>=1;j--)
      if(plan[j].id==0) {
            plan[j] = p[i];
            total += p[i].profit;
            break;
        }


    for(i=1;i<=max_day;i++)
    {
        if(plan[i].id!=0)
            printf("In the %d day we planned project %d with the profit %f \n", i, plan[i].id, plan[i].profit);
    }


    printf("Total/Maximum profit is : %f\n", total);

    return 0;
}


/*
 *
8
2 800
5 700.75
1 150
2 900
1 850
3 1000
3 950.50
2 900

 */