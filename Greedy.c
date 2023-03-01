#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start_h, start_min,stop_h,stop_min;
    int id;
    int final;
} event;


int cmp(const void*a, const void*b)
{
    event e1=*(event*)a;
    event e2=*(event*)b;
    return e1.final-e2.final;
}

int main() {

    int n,i;
    event* e;

    scanf("%d", &n);

    e=(int*)malloc(sizeof(event)*n);

    for(i=0;i<n;i++)
    {
        scanf("%d:%d %d:%d", &e[i].start_h, &e[i].start_min, &e[i].stop_h, &e[i].stop_min);
        e[i].id=i+1;
        e[i].final=e[i].stop_h*60+e[i].stop_min;
    }


    //we order the events in ascending order based on their finsihing time
    qsort(e,n,sizeof(event),cmp);

    int  nr=0;
    event *plan;
    plan=(event*)malloc(n*sizeof(event));
    plan[0]=e[0];

    //nr memorates the number of events planned

    for(i=1;i<n;i++)
    {
        if(e[i].start_h>plan[nr].stop_h)
            plan[++nr]=e[i];

        else if(e[i].start_h==plan[nr].stop_h)
        {
            if(e[i].start_min>=plan[nr].stop_min)
            plan[++nr]=e[i];
        }
    }

    printf("\nThe order of events that can be planned is order to have a maximum number of events planned is : ");
    for(i=0;i<=nr;i++)
        printf("%d  ", plan[i].id);

    free(e);
    free(plan);

    return 0;
}


/*
 *
7
10:0 11:20
9:30 12:10
8:20 9:50
11:30 14:0
12:10 13:10
14:0 16:0
15:0 15:30
 */
