#include <stdio.h>
#include <stdlib.h>

int holes;
int *x_hole;
int* y_hole;


void divi(int x_left, int y_left, int x_right, int y_right,int* max_area,int* xm_left, int* ym_left, int* xm_right,int* ym_right)
{
    int i;
    for(i=0;i<holes;i++)
        if(x_hole[i]>x_left && x_hole[i]<x_right && y_hole[i]>y_left && y_hole[i]<y_right)
            break;


    if(i<holes)
    {
        divi(x_left,y_left,x_right,y_hole[i],max_area,xm_left, ym_left, xm_right, ym_right);
        divi(x_left,y_hole[i],x_right,y_right,max_area,xm_left, ym_left, xm_right, ym_right);
        divi(x_left,y_left,x_hole[i],y_right,max_area,xm_left, ym_left, xm_right, ym_right);
        divi(x_hole[i],y_left,x_right,y_right,max_area,xm_left, ym_left, xm_right, ym_right);
    }

    else {
        int area=(x_right-x_left)*(y_right-y_left);
        if(area>(*max_area))
        {
            *max_area=area;
            *xm_left=x_left;
            *ym_left=y_left;
            *xm_right=x_right;
            *ym_right=y_right;
        }
    }
}

int main() {
    int x_left, y_left,x_right, y_right,i, max_area=0;
    int xm_left=0, ym_left=0, xm_right=0, ym_right=0; //thr coordinates of the rectangle with the maximum area

    scanf("%d %d %d %d", &x_left, &y_left, &x_right, & y_right);
    scanf("%d", &holes);
    x_hole=(int*)malloc(holes*sizeof(int));
    y_hole=(int*)malloc(sizeof(int)*holes);
    for(i=0;i<holes;i++)
        scanf("%d %d", &x_hole[i], &y_hole[i]);

    divi(x_left,y_left,x_right,y_right,&max_area,&xm_left, &ym_left, &xm_right, &ym_right);

    printf("The coordintes of the recatange with the max area are : (%d,%d) , (%d,%d) and its area is: %d ",
           xm_left, ym_left, xm_right, ym_right, max_area);

    free(x_hole);
    free(y_hole);
    return 0;
}


/*
2 1 8 5
4
3 2
4 4
5 3
7 4

 */