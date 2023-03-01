#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void *function1();
void *function2();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int contor = 0;
int main()
{
    int rc1, rc2;
    pthread_t thread1, thread2;
    /* creare thread-uri */
    if( (rc1=pthread_create( &thread1, NULL, &function1, NULL)) )
    {
        printf("Eroare de creare thread-uri! %d \n", rc1);
    }
    if( (rc2=pthread_create( &thread2, NULL, &function2, NULL)) )
    {
        printf("Eroare de creare thread-uri! %d\n", rc2);
    }
    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL);
    printf("Sfarsit program!\n");
    exit(EXIT_SUCCESS);
}
void *function1()
{
    int i,n=200;
    for(i=1;i<=n;i++){
        pthread_mutex_lock( &mutex1 );
        contor++;
        printf("Accesare contor de catre thread 1!\n");
        printf("Valoare contor = %d\n",contor);
        pthread_mutex_unlock( &mutex1 );
        sleep(1);
    }
}
void *function2()
{
    int i,n=200;
    for(i=1;i<=n;i++){
        pthread_mutex_lock( &mutex1 );
        contor=contor+contor;

        printf("Accesare contor de catre thread 2!\n");
        printf("Valoare contor = %d\n",contor);
        pthread_mutex_unlock( &mutex1 );
        sleep(1);
    }
}
