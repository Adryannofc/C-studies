#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct No{
    int valor;
    struct No* proximo;
} No;

typedef struct Fila{
    No* inicio;
    No* fim;
} Fila;

void inicializar(Fila* fila){
    fila -> inicio = NULL;
    fila -> fim = NULL;
}

void enqueue(Fila *fila, int valor){
    No* novo = (No*) malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao Alocar Memoria!\n");
        return;
    }

    novo -> valor = valor;
    novo -> proximo = NULL;

    if(fila -> fim == NULL){
        fila -> inicio = novo;
        fila -> fim = novo;
    } else {
        fila -> fim -> proximo = novo;
    }
    fila -> fim = novo;
}

void dequeue(Fila* fila){
    if(fila ->inicio == NULL){
        printf("Fila Vazia\n");
        return;
    }
    No* remover = fila -> inicio;
    printf("Valor: %d | REMOVIDO", remover -> valor);
    fila -> inicio = fila -> inicio -> proximo;
    free(remover);

    if(fila -> inicio == NULL){
        fila -> fim = NULL;
    }
}

void exibir(Fila *fila){
    if(fila -> inicio == NULL){
        printf("Fila Vazia!\n");
        return;
    }
    No* atual = fila -> inicio;

    printf("INICIO -> ");
    while(atual != NULL){
        printf("%d -> ", atual -> valor);
        atual = atual -> proximo;
    }
    printf("FIM\n");
}

int main(){
    int opcao, valor;
    Fila fila;
    inicializar(&fila);
    do{
    system("cls"); 
    printf("---- MENU ----\n\n");
    printf("[1] Enqueue\n");
    printf("[2] Dequeue\n");
    printf("[3] Peek\n");
    printf("[4] Exibir\n");
    printf("[5] Sair\n");

    printf("\n- Opcao: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao){
    case 1:
        printf("Valor: ");
        scanf("%d", &valor);
        getchar();
        enqueue(&fila, valor);
        break;
    case 2:
        dequeue(&fila);
        getchar();
        break;
    case 3: 
        printf("Inicio -> %d", &fila.inicio -> valor);
        getchar();
        break;
    case 4:
        exibir(&fila);
        getchar();
        break;
    default:
        printf("Opcao Invalida!");
        break;
    }
    } while (opcao != 5);
    
    return 0;
}
