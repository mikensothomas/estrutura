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

void inserir_no_final(NO **lista, int num){
    NO *auxi, *novo = (NO *) malloc(sizeof(NO));

    if(novo){
        novo->valor = num;

        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } else {
            auxi = *lista;

            while (auxi->proximo){
                auxi = auxi->proximo;
            }
            auxi->proximo = novo;
            novo->proximo = NULL;
        }
    } else {
        printf("Erro ao alocar memória.\n");
    } 
}

void remover_na_lista(NO** lista, int num) {
    NO* removido;
    NO* auxi;

    if (*lista == NULL) {
        printf("Lista vazia, nada para remover.\n");
    } else {
        if ((*lista)->valor == num) {
            removido = *lista;
            *lista = removido->proximo;
        } else {
            auxi = *lista;
            while (auxi->proximo && auxi->proximo->valor != num) {
                auxi = auxi->proximo;
            }

            if (auxi->proximo->valor == num) {
                removido = auxi->proximo;
                auxi->proximo = removido->proximo;
            } else {
                printf("Elemento %d nao encontrado na lista.\n", num);
                return;
            }
        }
        free(removido);
    }
}

/*void inserir_no_meio_da_lista(NO **lista, int ant, int num){
    NO *auxi, *novo = (NO *) malloc(sizeof(NO));
    
    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            printf("Lista vaizia não tem como inseri no meio.\n");
        } else {
            if((*lista)->valor == ant){
                (*lista)->proximo = novo;
                if(novo->proximo)
                    novo->proximo = (*lista)->proximo;
            } else {
                auxi = *lista;
                while (auxi->proximo && auxi->proximo->valor != ant){
                    auxi = auxi->proximo;
                }
                auxi->proximo = novo;
            }
        }
    } else {
        printf("Erro ao alocar memória.\n");
    }
}*/

void inserir_no_meio_da_lista(NO** lista, int ant, int num) {
    NO *auxi, *novo;

    novo = (NO*)malloc(sizeof(NO));

    if (novo) {
        novo->valor = num;

        if (*lista == NULL) {
            *lista = novo;
            novo->proximo = NULL;
        } else {
            auxi = *lista;
            while (auxi->valor != ant && auxi->proximo) {
                auxi = auxi->proximo;
            }

            if (auxi->valor == ant) {
                novo->proximo = auxi->proximo;
                auxi->proximo = novo;
            } else {
                printf("Nó com valor %d não encontrado na lista.\n", ant);
            }
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
    int opcao, ant, numero;

    do{
        printf("MENU: \n");
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Remover\n\t4 - InserirF\n\t5 - InserirM\n");
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
            printf("LISTA: ");
            imprimr_lista(&lista);
            printf("\n");
            break;
        case 3:
            printf("Digite o número a ser removido: ");
            scanf("%d", &numero);
            remover_na_lista(&lista, numero);
            break;
        case 4:
            printf("Digite o número a ser inserido: ");
            scanf("%d", &numero);
            inserir_no_final(&lista, numero);
            break;
        case 5:
            printf("Digite o número da referência e o número a ser inserido: ");
            scanf("%d%d", &ant, &numero);
            inserir_no_meio_da_lista(&lista, ant, numero);
            break;
        default :
            printf("Número inválido.\n");
            exit(0);
            break;
        }
    } while (opcao);


    return 0;
}