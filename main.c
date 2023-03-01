#include <stdio.h>
#include <stdlib.h>
int **m,n,len,crt;

void div_et_imp(int lin_left, int col_left, int lin_right, int col_right, int l_empty, int c_empty)
{
    if(lin_right-lin_left==1 && col_right-col_left==1)  //our square is 2x2
    {
        //we fill only those 3 squares which are different form the 1X1 square with l_empty and c_empty
        if (m[lin_left][col_left] == 0) m[lin_left][col_left] = crt;
        if (m[lin_left][col_right] == 0) m[lin_left][col_right] = crt;
        if (m[lin_right][col_right] == 0) m[lin_right][col_right] = crt;
        if (m[lin_right][col_left] == 0) m[lin_right][col_left] = crt;
        crt++;
    }

    else
    {
        int l_mid=(lin_right+lin_left)/2;
        int c_mid=(col_left+col_right)/2;

        //the empty square is in the right down quadran
        if(l_empty>l_mid && c_empty>c_mid)
        {
            m[l_mid][c_mid]=crt;
            m[l_mid][c_mid+1]=crt;
            m[l_mid+1][c_mid]=crt;
            crt++;
            div_et_imp(l_mid+1,c_mid+1,len-1,len-1, l_empty,c_empty);
            div_et_imp(l_mid+1,0,len-1,c_mid, l_mid+1,c_mid);
            div_et_imp(0,0,l_mid,c_mid,l_mid,c_mid);
            div_et_imp(0,c_mid+1,l_mid,len-1,l_mid,c_mid+1);
        }

        //the empty square is in the left down quadran
            else if(l_empty>l_mid && c_empty<=c_mid)
        {
            m[l_mid][c_mid]=crt;
            m[l_mid][c_mid+1]=crt;
            m[l_mid+1][c_mid+1]=crt;
            crt++;
            div_et_imp(l_mid+1,c_mid+1,len-1,len-1, l_mid+1,c_mid+1);
            div_et_imp(l_mid+1,0,len-1,c_mid, l_empty,c_empty);
            div_et_imp(0,0,l_mid,c_mid,l_mid,c_mid);
            div_et_imp(0,c_mid+1,l_mid,len-1,l_mid,c_mid+1);
        }

            //the empty square is in the up left quadran
            else if(l_empty<=l_mid && c_empty<=c_mid)
        {
            m[l_mid+1][c_mid+1]=crt;
            m[l_mid][c_mid+1]=crt;
            m[l_mid+1][c_mid]=crt;
            crt++;
            div_et_imp(l_mid+1,c_mid+1,len-1,len-1, l_mid+1,c_mid+1);
            div_et_imp(l_mid+1,0,len-1,c_mid, l_mid+1,c_mid);
            div_et_imp(0,0,l_mid,c_mid,l_empty,c_empty);
            div_et_imp(0,c_mid+1,l_mid,len-1,l_mid,c_mid+1);
        }

            //the empty square is in the  up right quadran
            else if(l_empty<=l_mid && c_empty>c_mid)
        {
            m[l_mid][c_mid]=crt;
            m[l_mid][c_mid+1]=crt;
            m[l_mid+1][c_mid+1]=crt;
            crt++;
            div_et_imp(l_mid+1,c_mid+1,len-1,len-1, l_mid+1,c_mid+1);
            div_et_imp(l_mid+1,0,len-1,c_mid, l_mid+1,c_mid);
            div_et_imp(0,0,l_mid,c_mid,l_mid,c_mid);
            div_et_imp(0,c_mid+1,l_mid,len-1,l_empty,c_empty);
        }


    }

}


int main() {
    int l_empty,c_empty;
    //printf("Our square has the dimension of a side of 2^n, where n is :\n ");
    //fflush(stdout);
    scanf("%d", &n);
    //printf("The position of the empty square is : ");
    //fflush(stdout);
    scanf("%d %d", &l_empty,&c_empty);

    int len=(1<<n);  // 2^n
    m=(int**)malloc(sizeof(int*)*len);
    for(int i=0;i<len;i++)
        m[i]=(int*)calloc(len,sizeof(int));  //we intialize the matrix with zeros

    m[l_empty][c_empty]=-1;



    //starting positions are the left upper corner and the right down corner
    div_et_imp(len-1,0,0,len-1,l_empty,c_empty);

    for(int i=0;i<len;i++) {
        for (int j = 0; j < len; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
    return 0;
}
