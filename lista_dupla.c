#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No{
    int valor;
    struct No *proximo;
    struct No *anterior;
}No;

void inserir_no_inicio(No **lista, int num){
    No *novo = (No *)malloc(sizeof(No));
    
    if(novo){
        novo->valor = num;

        if(*lista == NULL){
            novo->proximo = NULL;
            novo->anterior = NULL;
        } else {
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            novo->anterior = NULL;
        }
        *lista = novo;
    } else {
        printf("Erro ao alocar memória");
    }
}

void inserir_no_fim(No **lista, int num){
    No *auxi, *novo = (No *)malloc(sizeof(No));
    
    if(novo){
        novo->valor = num;

        if (*lista == NULL){
            *lista = novo;
            novo->anterior = NULL;
            novo->proximo = NULL;
        } else {
            auxi = *lista;
            while (auxi->proximo){
                auxi = auxi->proximo;
            }
            auxi->proximo = novo;
            novo->proximo = NULL;
            novo->anterior = auxi;
        }
    } else {
        printf("Erro ao alocar memória.");
    }
}

void inserirNoMeio(No **lista, int ant, int num) {
    No *aux, *novo = (No *)malloc(sizeof(No));

    if (novo) {
        novo->valor = num;
        if (*lista == NULL) {
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        } else {
            aux = *lista;
            while (aux->valor != ant && aux->proximo) {
                aux = aux->proximo;
            }
            if(aux->valor == ant){
                novo->proximo = aux->proximo;
                if(aux->proximo)
                    aux->proximo->anterior = novo;
                novo->anterior = aux;
                aux->proximo = novo;
            }
        }
    } else {
        printf("Erro ao alocar memória.\n");
    }
}

void buscar_na_lista(No **lista, int num){
    No *auxi = *lista;
    while (auxi->valor != num && auxi->proximo){
        auxi = auxi->proximo;
    }
    if(auxi->valor == num){
        printf("O número %d foi encontrado\n", auxi->valor);
    } else {
        printf("O número %d não foi encontrado\n", num);
        return;
    }
    
}

void inserir_ordenado(No **lista, int num){
    No *auxi, *novo = (No *)malloc(sizeof(No));

    if(novo){
        novo->valor = num;

        if(*lista == NULL){
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        } else {
            if(novo->valor < (*lista)->valor){
                novo->proximo = *lista;
                (*lista)->anterior = novo;
                *lista = novo;
            } else {
                auxi = *lista;
                while (auxi->proximo && novo->valor > auxi->proximo->valor){
                    auxi = auxi->proximo;
                }
                novo->proximo = auxi->proximo;
                if(auxi->proximo){
                    auxi->proximo->anterior = novo;
                }
                novo->anterior = auxi;
                auxi->proximo = novo;
            }
        } 
    } else {
        printf("Erro ao alocar memória");
    }
}

void imprimirLista(No **lista){
    No *auxi = *lista;

    printf("Lista: ");
    while (auxi){
        printf("%d ", auxi->valor);
        auxi = auxi->proximo;
    }
    printf("\n");
}

No* ultimo(No **lista){
    No *auxi = *lista;

    while (auxi->proximo){
        auxi = auxi->proximo;
    }
    return auxi;
}

void imprimir_contrario(No **lista){
    No *auxi = *lista;

    printf("Cntra: ");
    while (auxi){
        printf("%d ", auxi->valor);
        auxi = auxi->anterior;
    }
    printf("\n");
}

int main(){

    int opcao, numero, ant;
    No *ultimoNo, *lista = NULL;

        do{
            printf("Faça uma escolha: ");
            printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - InserirF\n\t3 - InserirM\n\t4 - Imprimir\n\t5 - ImprimirC\n\t6 - Buscar\n\t7 - InserirO\n");
            scanf("%d", &opcao);
            
            switch (opcao){
            case 0:
                exit(0);
                break;
            case 1:
                printf("Digite o número: ");
                scanf("%d", &numero);
                inserir_no_inicio(&lista, numero);
                break;
            case 2:
                printf("Digite o número: ");
                scanf("%d", &numero);
                inserir_no_fim(&lista, numero);
                break;
            case 3:
                printf("Digite o número e o número a da referencia: ");
                scanf("%d%d", &ant, &numero);
                inserirNoMeio(&lista, numero, ant);
                break;
            case 4:
                imprimirLista(&lista);
                break;
            case 5:
                ultimoNo = ultimo(&lista);
                imprimir_contrario(&ultimoNo);
                break;
            case 6:
                printf("Digite o número: ");
                scanf("%d", &numero);
                buscar_na_lista(&lista, numero);
                break;
            case 7:
                printf("Digite o número: ");
                scanf("%d", &numero);
                inserir_ordenado(&lista, numero);
                break;
            default:
                printf("Número inválido.\n");
                break;
            }
        } while (opcao);
    return 0;
}