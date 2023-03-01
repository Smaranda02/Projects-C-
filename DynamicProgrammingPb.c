//161_ANDRONIC_SMARANDA_7
// asupra unui nr se pot efectua doar operatiile : +1, *2, *3. sa se afle nr minim de op prin care se poate ajunge la un nr n

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


int prim(int x)
{
    for(int d=2;d<=sqrt(x);d++)
        if(x%d==0)
            return 0;
    return 1;
}

void afisare(int n,int* last,int* v,int* k)
{
    if(n>0) {
        afisare(last[n], last,v,k);
        v[++(*k)]=n;
        printf("%d ", n);
    }

}

int main() {

    int n;
    scanf("%d", &n);

    int x,i;
    int* steps;
    int* last;
    int* v;
    steps=(int*)calloc(n+1, sizeof(int));
    last=(int*)calloc(n+1, sizeof(int));
    v=(int*)calloc(n+1, sizeof(int));

    steps[2]=1;
    steps[3]=1;
    last[2]=1;
    last[3]=1;

    //mai adaug un vector care memeoreaza ultima pozitie
    for(x=4;x<=n;x++)
    {
        if(prim(x)==1) {
            steps[x] = steps[x - 1] + 1;
            last[x] = x - 1;
        }

        else {
            int mini;
            int ok2=0,ok3=0;  ///ok2 e 1 daca x e divizibil cu 2, respectiv ok3 e 1 daca e divizibil cu 3
            if(x%2==0) ok2=1;
            if(x%3==0) ok3=1;
            if(ok2==1 && ok3==1)
            {
                if(steps[x/2]<steps[x/3]) {
                    if (steps[x / 2] < steps[x - 1]) {
                        steps[x] = steps[x / 2] + 1;
                        last[x] = x / 2;
                    }
                    else {
                        steps[x] = steps[x - 1] + 1;
                        last[x] = x - 1;
                    }
                }
                else {
                    if (steps[x / 3] < steps[x - 1]) {
                        steps[x] = steps[x / 3] + 1;
                        last[x] = x / 3;
                    }
                    else {
                        steps[x] = steps[x - 1] + 1;
                        last[x] = x - 1;
                    }
                }

            }

            else if(ok2==0 && ok3==1)
            {
                if (steps[x / 3] < steps[x - 1]) {
                    steps[x] = steps[x / 3] + 1;
                    last[x] = x / 3;
                }
                else {
                    steps[x] = steps[x - 1] + 1;
                    last[x] = x - 1;
                }
            }

            else if(ok2==1 && ok3==0)
            {
                if (steps[x / 2] < steps[x - 1]) {
                    steps[x] = steps[x / 2] + 1;
                    last[x] = x / 2;
                }
                else {
                    steps[x] = steps[x - 1] + 1;
                    last[x] = x - 1;
                }
            }

            else
            {
                steps[x] = steps[x - 1] + 1;
                last[x] = x - 1;
            }

        }
    }

    int k=0;
    afisare(n,last,v,&k);


    int x_65[9]={1,2,6,7,21,63,64,65};
    int x_134[10]={1,2,6,7,21,22,66,67,134};

    for(i=7;i>=0;i--)
       x_65[i+1]=x_65[i];

    for(i=8;i>=0;i--)
        x_134[i+1]=x_134[i];


    if(n==65)
    {
        for(int i=1;i<=k;i++)
            assert(v[i]==x_65[i]);
    }

    else if(n==134)
    {
        for(int i=1;i<=k;i++)
            assert(v[i]==x_134[i]);
    }


    free(last);
    free(steps);
    free(v);
    return 0;
}
