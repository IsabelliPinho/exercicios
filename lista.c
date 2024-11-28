/*
#include <stdio.h>
#include <conio.h>

//Questão 1 -----------------------------------------------------------

/*passagem por valor pois é apenas necessário a cópia dos valores das 
variáveis*/

void troca(int *ptrx, int *ptry){
     int aux;
     aux = *ptrx;
    *ptrx = *ptry;
    *ptry = aux;
    getch();
}

int main()
{
    int x = 10, y = 20;
     printf("Valor de x inicial = %d e valor de y inicial = %d\n",x,y);
    troca(&x,&y);
    printf("Valor de x = %d e valor de y = %d\n",x,y);

    return 0;
}
------------------------------------------------------------------------*/
#include<stdio.h>
int main()
{
        
        int i = 5, *p;
        
        p= &i;
        
        int **pp = &p;
        
        printf("%d %d %d %d %d", p , *p+2 , **&p,  3**p,  **&p+4);
   // p = é o endereço de i , *p+2 = valor da variável i + 2, **&p = aponta o valor armazenado no endereço de p, ou seja o valor de i 3**p = valor que p aponta multiplicado por 3, valor no endereço que p aponta adicionado 4.      
    return 0;
}

a, Por que vetores de strings são finalizados com o caractere nulo \0.
b, v+4: Considera a posição inicial do vetor adiante 4 elementos v[0] então v[4]. O *(v+4): 
consideraria o valor adiante 4 elementos de v, já *v+4: exibiria o valor de
v[0] adicionado 4

c,void inverterVetor(char v[], int tamanho) {
    int i, temp;
    for (i = 0; i < tamanho / 2; i++) {
       
        temp = v[i];
        v[i] = v[tamanho - 1 - i];
        v[tamanho - 1 - i] = temp;
    }
}

d, ??? = 0.
//4
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int idade;
    int anoNascimento;
    int anoAtual;
} Idade;

Idade* criar(int idade, int anoN, int anoA) {
    Idade* novaIdade = (Idade*)malloc(sizeof(Idade));
    if (novaIdade == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    novaIdade->idade = idade;
    novaIdade->anoNascimento = anoN;
    novaIdade->anoAtual = anoA;
    return novaIdade;
}

int calcular(Idade* idade) {
    if (idade->anoAtual >= (idade->anoNascimento + idade->idade)) {
        return 1;
    }
    return 0;
}

void libera(Idade* idade) {
    free(idade);
}

int main() {
    Idade* pessoa = criar(25, 1998, 2024);
    if (pessoa != NULL) {
        printf("Idade: %d\n", pessoa->idade);
        printf("Ano de nascimento: %d\n", pessoa->anoNascimento);
        printf("Ano atual: %d\n", pessoa->anoAtual);
        if (calcular(pessoa)) {
            printf("A pessoa já fez aniversário esse
//lista 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    char nome[100];
    int idade;
    float nota;
} Aluno;

void listarAlunos(Aluno *alunos, int tamanho) {
    if (tamanho == 0) {
        printf("Nao ha alunos cadastrados.\n");
        return;
    }
    printf("Lista de Alunos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d. Nome: %s, Idade: %d, Nota: %.2f\n", i + 1, alunos[i].nome, alunos[i].idade, alunos[i].nota);
    }
}

void adicionarAluno(Aluno *alunos, int *tamanho) {
    if (*tamanho >= MAX) {
        printf("Nao e possivel adicionar mais alunos. Limite atingido.\n");
        return;
    }
    
    Aluno novoAluno;
    
    printf("Digite o nome do aluno: ");
    getchar();  
    fgets(novoAluno.nome, 50, stdin);
    novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0';  
    
    printf("Digite a idade do aluno: ");
    scanf("%d", &novoAluno.idade);
    
    printf("Digite a nota do aluno: ");
    scanf("%f", &novoAluno.nota);
    
    alunos[*tamanho] = novoAluno;
    (*tamanho)++;
    
    printf("Aluno adicionado com sucesso!\n");
}

void editarAluno(Aluno *alunos, int tamanho) {
    if (tamanho == 0) {
        printf("Nao ha alunos cadastrados para editar.\n");
        return;
    }
    
    listarAlunos(alunos, tamanho);
    
    int indice;
    printf("Digite o numero do aluno que deseja editar (1 a %d): ", tamanho);
    scanf("%d", &indice);
    
    if (indice < 1 || indice > tamanho) {
        printf("Indice invalido.\n");
        return;
    }
    
    Aluno *aluno = &alunos[indice - 1];
    
    printf("Digite o novo nome do aluno: ");
    getchar(); 
    fgets(aluno->nome, 50, stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = '\0'; 
    
    printf("Digite a nova idade do aluno: ");
    scanf("%d", &aluno->idade);
    
    printf("Digite a nova nota do aluno: ");
    scanf("%f", &aluno->nota);
    
    printf("Dados do aluno atualizados com sucesso!\n");
}

void removerAluno(Aluno *alunos, int *tamanho) {
    if (*tamanho == 0) {
        printf("Nao ha alunos cadastrados para remover.\n");
        return;
    }
    
    listarAlunos(alunos, *tamanho);
    
    int indice;
    printf("Digite o numero do aluno que deseja remover (1 a %d): ", *tamanho);
    scanf("%d", &indice);
    
    if (indice < 1 || indice > *tamanho) {
        printf("Indice invalido.\n");
        return;
    }
    
    for (int i = indice - 1; i < *tamanho - 1; i++) {
        alunos[i] = alunos[i + 1];
    }
    
    (*tamanho)--;
    
    printf("Aluno removido com sucesso!\n");
}

int main() {
    Aluno *alunos = (Aluno *)malloc(MAX * sizeof(Aluno));
    int tamanho = 0;
    int opcao;
    
    do {
        printf("\nSISTEMA DE CADASTRO DE ALUNOS\n");
        printf("1. Listar Alunos\n");
        printf("2. Adicionar Aluno\n");
        printf("3. Editar Aluno\n");
        printf("4. Remover Aluno\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                listarAlunos(alunos, tamanho);
                break;
            case 2:
                adicionarAluno(alunos, &tamanho);
                break;
            case 3:
                editarAluno(alunos, tamanho);
                break;
            case 4:
                removerAluno(alunos, &tamanho);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while(opcao != 5);
    
    free(alunos);
    
    return 0;
}
