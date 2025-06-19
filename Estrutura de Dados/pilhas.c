#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *proximo;
} No;

No* push();
No* pop();
No* peek();
void exibir();
void limpar();

void limpar(){
    system("cls");
}

No* push(No* topo, int valor){
    No* novo = (No*) malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao Alocar Memoria\n");
        return NULL;
    }
    novo -> valor = valor;
    novo -> proximo = topo;
    return novo;
}

No* pop(No* topo){
    if(topo == NULL){
        printf("Pilha Vazia");
        return NULL;
    }
    No* temp = topo;
    topo = topo->proximo;
    printf("Valor %d | Removido", temp -> valor);
    getchar();
    free(temp);
    return topo;
}

No* peek(No* topo){
    printf("Topo -> %d", topo -> valor);
    getchar();
}

void exibir(No* topo){
    printf("Topo -> ");
    while(topo != NULL){
        printf("%d -> ", topo ->valor);
        topo = topo -> proximo;
    }
    printf("NULL");
    getchar();
}

int main(){
    int opcao, valor;
    No *pilha = NULL;
    
    do{
        limpar();
        printf("---- MENU ----\n\n");

        printf("[1] Push\n");
        printf("[2] Pop\n");
        printf("[3] Peek\n");
        printf("[4] Exibir\n");
        printf("[5] Sair\n");

        printf("\n- Opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Valor: ");
            scanf("%d", &valor);
            getchar();
            pilha = push(pilha, valor);
            printf("Valor Adicionado com Sucesso");
            Sleep(500);
            break;
        case 2:
            pilha = pop(pilha);
            break;
        case 3:
            peek(pilha);
            break;
        case 4:
            exibir(pilha);
            break;
        default:
            break;
        }
    } while(opcao != 5);
    return 0;
}
