#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO{
    int valor;
    struct NO *proximo;
}NO;

void inserir_no_inicio_da_lista(NO **lista, int num){
    NO *novo = (NO *) malloc(sizeof(NO));

    if(novo){
        novo->valor = num;

        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } else {
            novo->proximo = *lista;
            *lista = novo;
        }
    } else {
        printf("Erro ao alocar memória.\n");
    }
}

void imprimr_lista(NO **lista){
    NO *auxi = *lista;

    if(*lista == NULL){
        printf("vazia");
    } else {
        while (auxi){
            printf("%d ", auxi->valor);
            auxi = auxi->proximo;
        }
    }
    printf("\n");
}

int main(){

    NO *lista = NULL;
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
            inserir_no_inicio_da_lista(&lista, numero);
            break;
        case 2:
            printf("LISTA:");
            imprimr_lista(&lista);
            printf("\n");
            break;
        /*case 3:
            remover_na_pilha(&pilha);
            break;*/
        default :
            printf("Número inválido.\n");
            exit(0);
            break;
        }
    } while (opcao);


    return 0;
}