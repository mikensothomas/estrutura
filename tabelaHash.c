#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 31

void inicializar_tabela(int t[]){
    for (int  i = 0; i < TAM; i++){
        t[i] = 0;
    }
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir_na_tabela(int t[], int valor){
    int id = funcaoHash(valor);

    if(t[id] == 0){
        t[id] = valor;
    }
}

int buscar_na_tabela(int t[], int chave){
    int id = funcaoHash(chave);
    printf("O indice gerado é: %d \n", id);
    
    while (t[id] != 0){

        if(t[id] == chave){
            return chave;
        } else {
            id = funcaoHash(id + 1);
        }
    }
    return 0;
}

void imprimir_tabela(int t[]){
    for (int i = 0; i < TAM; i++){
        printf("%d = %d\n", i, t[i]);
    }
}

int main(){
    int opcao, numero, tabela[TAM],retorno;
    int id = funcaoHash(numero);
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