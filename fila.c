#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO{
    int valor;
    struct NO *proximo;
}NO;

void inserir_na_fila(NO **fila, int num){
    NO *auxi, *novo = (NO *)malloc(sizeof(NO));

    if(novo){
        novo->valor = num;

        if(*fila == NULL){
            *fila = novo;
            novo->proximo = NULL;
        } else {
            auxi = *fila;

            while (auxi->proximo){
                auxi = auxi->proximo;
            }
            if(auxi->proximo == NULL){
                auxi->proximo = novo;
            }
        }
        
    } else {
        printf("Erro ao alocar memória.\n");
    }
    
}

void remover_na_fila(NO **fila){
   NO *removido = NULL;

   if(*fila == NULL){
        printf("Fila vazia, nada para remover");
   } else {
        removido = *fila;
        *fila = removido->proximo;
        printf("O número %d foi removido ", removido->valor);
   }
   if(removido){
        free(removido);
   }
}

void imprimir_fila(NO **fila){
    NO *auxi = *fila;

    printf("Fila: ");
    if(auxi == NULL){
        printf("Fila vazia");
    } else {
        while (auxi){
            printf("%d ", auxi->valor);
            auxi = auxi->proximo;
        }
    }
    
    printf("\n");
}

int main(){
    NO *fila = NULL;
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
            printf("Digite o número a ser inserido: ");
            scanf("%d", &numero);
            inserir_na_fila(&fila, numero);
            break;
        case 2:
            imprimir_fila(&fila);
            printf("\n\n");
            break;
        case 3:
            remover_na_fila(&fila);
            break;
        default:
            printf("Número inválido.\n");
            exit(0);
        }
    } while (opcao);

    return 0;
}
