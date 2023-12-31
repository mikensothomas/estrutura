#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 31

typedef struct NO{
    int chave;
    struct NO *proximo;
}NO;

typedef struct{
    struct NO *inicio;
    int tam;
}Lista;

void inicializa_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir_na_list(Lista *lista, int num){
    NO *novo = (NO *) malloc(sizeof(NO));

    if(novo){
        novo->chave = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
}

int busca_na_lista(Lista *lista, int num){
    NO *auxi = lista->inicio;

    while (auxi && auxi->chave != num){
        auxi = auxi->proximo;
    }
    if(auxi){
        return auxi->chave;
    }
    return 0;
}

void imprimir_lsita(Lista *lista){
    NO *auxi = lista->inicio;
    printf(" tam %d ", lista->tam);
    while (auxi){
        printf("%d ", auxi->chave);
        auxi = auxi->proximo;
    }
}

void inicializar_tabela(Lista t[]){
    for (int  i = 0; i < TAM; i++){
        inicializa_lista(&t[i]);
    }
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir_na_tabela(Lista t[], int valor){
    int id = funcaoHash(valor);
    inserir_na_list(&t[id], valor);
}

int buscar_na_tabela(Lista t[], int chave){
    int id = funcaoHash(chave);
    printf("O indice gerado é: %d \n", id);
    
    return busca_na_lista(&t[id], chave);
}

void imprimir_tabela(Lista t[]){
    for (int i = 0; i < TAM; i++){
        printf("\n%2d = ", i);
        imprimir_lsita(&t[i]);
    }
    printf("\n");
}

int main(){
    int opcao, numero,retorno;
    //int id = funcaoHash(numero);
    Lista tabela[TAM];
    inicializar_tabela(tabela);

    do{
      printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
      scanf("%d", &opcao);
      printf("\n");

      switch (opcao){
      case 0:
        exit(0);
        break;
    case 1:
        printf("Digite o número a ser inserido: ");
        scanf("%d", &numero);
        inserir_na_tabela(tabela, numero);
        break;
    case 2:
        printf("Digite o número a ser buscado: ");
        scanf("%d", &numero);
        retorno = buscar_na_tabela(tabela, numero);
        if(retorno != 0){
            printf("O número gerado é: %d ", retorno);
        } else {
            printf("O número %d não encotrado ", numero);
        }
        break;
    case 3:
        imprimir_tabela(tabela);
        printf("\n");
        break;
      default:
        printf("Valor inválido.\n");
        break;
      }
    } while (opcao);
    
    return 0;
}