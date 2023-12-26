#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO{
    int valor;
    struct NO *proximo;
}NO;

void inserir_na_pilha(NO **pilha, int num){
    NO *novo = (NO *) malloc(sizeof(NO));

    if(novo){
        novo->valor = num;

        if(*pilha == NULL){
            novo->proximo = NULL;
            *pilha = novo;
        } else {
            novo->proximo = *pilha;
            *pilha = novo;
        }
        
    } else {
        printf("Erro ao alocar memória.\n");
    }
    
}

void remover_na_pilha(NO **pilha){
    NO *removido = *pilha;
    if (*pilha == NULL){
        printf("Pilha vazia, nada para remover");
    } else {
        removido = *pilha;
        *pilha = removido->proximo;
        printf("O número %d foi removido\n", removido->valor);
    }
    if(removido){
        free(removido);
    }
}

void imprimir_pilha(NO **pilha){
    NO *auxi = *pilha;

    if(*pilha == NULL){
        printf("Vazia");
    } else {
        while (auxi){
            printf("\n%d", auxi->valor);
            auxi = auxi->proximo;
        }
    }
    
    printf("\n");
}

int main(){

    NO *pilha = NULL;
    int opcao, numero;

    do{
        printf("MENU: \n");
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Remover\n");
        scanf("%d", &opcao);

        switch (opcao){
        case 0:
            exit(0);
            break;
        case 1:
            printf("Digite o número aser inserido: ");
            scanf("%d", &numero);
            inserir_na_pilha(&pilha, numero);
            break;
        case 2:
            printf("PILHA:");
            imprimir_pilha(&pilha);
            printf("\n");
            break;
        case 3:
            remover_na_pilha(&pilha);
            break;
        default :
            printf("Número inválido.\n");
            exit(0);
            break;
        }
    } while (opcao);
    

    return 0;
}