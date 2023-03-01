/*
 *Alice s-a pierdut din nou în labirint. Labirintul este de forma unui triunghi dreptunghicîmpărțit în camere organizate pe linii
 * și coloane. Pe prima linie este o singurăcameră, pe a doua sunt două camere, etc. Pe ultima linie sunt n camere.
 *Din fiecarecameră se poate merge în camerele situate pe linia următoare și pe aceeași coloană,sau pe coloane cu 1 mai mari sau
 * mai mici decât coloana curentă, dar fără să sepărăsească labirintul. Astfel din camera (i,j) se poate merge în camerele
 *(i+1,j-1),(i+1,j) și (i+1,j+1), dacă acestea există. Alice se află în camera de pe prima linia și depe prima coloana (1,1).
 * Ca să iasă din labirint, Alice trebuie să ajungă într-o cameră de pe ultima linie.Calculați și afișați numărul de trasee pe
 * care poate Alice să iasă din labirint.
 */
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,i,j;
    //printf("Number of lines of the labirinth is : ");
    scanf("%d", &n);
    int** m;
    m=(int**)calloc(n,sizeof(int*));
    for(i=0;i<n;i++)
        m[i]=calloc(i+1,sizeof(int));

    m[0][0]=1;

        for (i = 1; i < n; i++)
        {
            for (j = 0; j < i; j++)
            {
                m[i][j] += m[i - 1][j];
                if (j - 1 >= 0)
                    m[i][j] += m[i - 1][j - 1];
                if (j  <= i-2)
                    m[i][j]+=m[i-1][j+1];
            }
        m[i][i]=1;
    }

    for(i=0;i<n;i++) {
        for (j = 0; j <= i; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }

    for(i=0;i<n;i++)
        free(m[i]);
    free(m);

    int s=0;
    for(j=0;j<n;j++)
        s+=m[n-1][j];
    printf("Alice cand escape the maze in a total of %d ways", s);
    return 0;
}
