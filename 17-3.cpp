#include <pthread.h>
#include <stdio.h>

// Variável global utilizada durante e após o processo;
int variavelGlobal = 1;

// Executa a função quando a thread for criada;
void *IdThread(void *threadid){
  long id;
  id = (long)threadid; // Conversão de void pra long;
  printf("Thread ID %ld criada\n", id); // Print do ID da thread criada;
  pthread_exit(NULL); // Finalização da thread;
}

int main(){
    long num;
    for(num=1; num <= 5; num++)
    {    
        pthread_t num; // Cria a thread utilizando como nome o valor do loop;
        printf("Processo principal criando a thread: %ld\n", num);
        pthread_create(&num, NULL, IdThread, (void *)num); // Criando thread num;
        printf("Variável global alterada para %d \n", variavelGlobal++); // Mostra a mudança da variável global durante o processo
    }
    printf("Processo principal finalizado\n");
    printf("Variável global pós término do processo: %d \n", variavelGlobal); // Mostra o valor da variável global após a finalização
    return 0;
}