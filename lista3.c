// Faça uma função que produza o inverso de uma string
#include <stdio.h>
#include <string.h>
char inverso(char *p){
   if(*p == '\0'){
       return 0; //  retorna nada
   }
   inverso(p+1); // desempilha
   
    printf("%c",*p);
    
}

int main() {
   char vetor[6] = "roma";
   inverso(vetor);
    return 0;
}
//  Faça uma função que retorna o tamanho de uma string passada como parâmetro.
#include <stdio.h>
#include <string.h>
char medir(char *p){
    int tamanho = 0;
  while(*p != '\0'){
      tamanho ++;
      p++;
  }
    return tamanho;
}

int main() {
    char palavra[] = "amarelinha";
    int tam = medir(palavra); 
   printf("%d",tam);
    return 0;
}
//  Faça uma função que mostre o n-ésimo termo da sequência de Fibonacci.

#include <stdio.h>
#include <string.h>

int fibo(int num){
    if (num == 0){
        return 0;
    }
    if (num == 1){
        return 1;
    }
    else{
        return fibo(num -1) + fibo(num-2);
    }
}

int main() {
    int numero;
    printf("Digite um num: \n");
    scanf("%d",&numero);
    printf("O %d-ésimo termo da sequência de Fibonacci é: %d\n", numero, fibo(numero));

    return 0;
}
/* Crie um função que conte os dígitos de um determinado número usando recursão.
Observação: se o usuário inserir o número 250, a saída esperada deve ser: o número
digitado tem 3 dígitos.*/

/* Crie um função que conte os dígitos de um determinado número usando recursão.
Observação: se o usuário inserir o número 250, a saída esperada deve ser: o número
digitado tem 3 dígitos.*/

#include <stdio.h>
#include <string.h>

int conta(int num){
    if(num == 0){
        return 0;
    }
    else{
        return 1+ conta(num /=10);
    }
    }


int main() {
    int numero;
     printf("Digite um num: \n");
    scanf("%d",&numero);
    printf("Os digitos de %d são: %d\n", numero, conta(numero));

    return 0;
}
/* 5. Faça uma função que encontre o maior elemento de um array de inteiros.
*/
#include <stdio.h>

int maior_elemento(int arr[], int tamanho) {
    if (tamanho == 1) {
        return arr[0];
    }

    int maior_restante = maior_elemento(arr + 1, tamanho - 1);

    if (arr[0] > maior_restante) {
        return arr[0];
    } else {
        return maior_restante;
    }
}

int main() {
    int arr[] = {3, 5, 7, 2, 8, 6, 4};
    int tamanho = sizeof(arr) / sizeof(arr[0]); 

    int maior = maior_elemento(arr, tamanho);
    printf("O maior elemento do array é: %d\n", maior);

    return 0;
}
/*Ocorrencia string
*/
#include <stdio.h>

int ocorre(char *str, char c) {
    if (*str == '\0') {
        return 0;
    }
    return (*str == c) + ocorre(str + 1, c);
}

int main() {
    char str[] = "batata";
    char c = 'a';
    printf("O caractere '%c' aparece %d vezes.\n", c, ocorre(str, c));
    return 0;
}

