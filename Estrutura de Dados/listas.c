#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

typedef struct No{
    int valor;
    struct No* proximo;
} No;

void limparTela();
void pausa();
No* inserirInicio(No* lista, int valor);
No* inserirFinal(No* lista, int valor);
No* removerInicio(No* lista);
No* removerFinal(No* lista);
No* removerValor(No* lista, int valor);
void exibir(No* lista);
void liberarLista(No* lista);

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausa(int milissegundos) {
    #ifdef _WIN32
        Sleep(milissegundos);
    #else
        usleep(milissegundos * 1000);  // converte ms para µs
    #endif
}

No* inserirInicio(No* lista, int valor){
    No* novoNo = (No*) malloc(sizeof(No));
    if(novoNo == NULL){
        printf("Erro ao Alocar Memoria!\n");
        return NULL;
    }

    novoNo -> valor = valor;
    novoNo -> proximo = lista;
    printf("Valor: %d | ADICIONADO\n", novoNo -> valor);
    return novoNo;
}

No* inserirFinal(No* lista, int valor){
    No* novoNo = (No*) malloc(sizeof(No));
    if(novoNo == NULL){
        printf("Erro ao Alocar Memoria");
        return lista;
    }

    novoNo -> valor = valor;
    novoNo -> proximo = NULL;

    if(lista == NULL){
        return novoNo;
    }

    No* atual = lista;
    while (atual -> proximo != NULL){
        atual = atual -> proximo;
    }

    atual -> proximo = novoNo;
    return lista;
}

No* removerInicio(No* lista){
    if (lista == NULL){
        printf("Lista Vazia!\n");
        return NULL;
    }
    
    No* remover = lista;
    lista = lista -> proximo;
    printf("Valor: %d | REMOVIDO\n", remover -> valor);
    free(remover);
    return lista;
}

No* removerFinal(No* lista){
    if(lista == NULL){
        printf("Lista Vazia!\n");
        return NULL;
    }

    if(lista->proximo == NULL){
        printf("Valor %d | REMOVIDO\n", lista->valor);
        free(lista);
        return NULL;
    }

    No* atual = lista;
    while (atual -> proximo -> proximo != NULL){
        atual = atual -> proximo;
    }

    printf("Valor %d | REMOVIDO", atual -> proximo -> valor);
    free(atual -> proximo);
    atual -> proximo = NULL;
    return lista;
}

No* removerValor(No* lista, int valor){
    if(lista == NULL){
        printf("Lista Vazia!\n");
        return lista;
    }

    No* atual = lista;
    No* anterior = NULL;

    while (atual != NULL && atual -> valor != valor){
        anterior = atual;
        atual = atual -> proximo;
    }

    if(atual == NULL){
        printf("Valor: %d | Nao encontrado\n", valor);
        return lista;
    }

    if(anterior == NULL){
        lista = atual -> proximo;
    } else {
        anterior -> proximo = atual -> proximo;
    }

    printf("Valor: %d | REMOVIDO\n", atual -> valor);
    free(atual);
    return lista;
}

void exibirLista(No* lista){
    if(lista == NULL){
        printf("Lista Vazia!");
        return;
    }

    No* atual = lista;
    printf("INICIO -> ");
    while (atual != NULL){
        printf("%d -> ", atual -> valor);
        atual = atual -> proximo;
    }
    printf("FIM\n");
}

void liberarLista(No* lista) {
    No* atual = lista;
    No* proximoNo;
    while (atual != NULL) {
        proximoNo = atual->proximo; 
        free(atual);                
        atual = proximoNo;          
    }
}

int main(){
    No* lista = NULL;
    int opcao, valor = 0;
    
    do {
        limparTela();
        printf("---- MENU ----\n\n");
        printf("[1] Inserir Inicio\n");
        printf("[2] Inserir Final\n");
        printf("[3] Remover Inicio\n");
        printf("[4] Remover Final\n");
        printf("[5] Remover Valor\n");
        printf("[9] Exibir\n");
        printf("[0] Sair\n");

        printf("\n- Opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao){
        case 1:
            printf("- Valor: ");
            scanf("%d", &valor);
            getchar();
            lista = inserirInicio(lista, valor);
            pausa(500);
            break;
        case 2:
            printf("- Valor: ");
            scanf("%d", &valor);
            getchar();
            lista = inserirFinal(lista, valor);
            pausa(500);
            break;
        case 3:
            lista = removerInicio(lista);
            pausa(500);
            break;
        case 4:
            lista = removerFinal(lista);
            pausa(500);
            break;
        case 5:
            printf("- Valor: ");
            scanf("%d", &valor);
            getchar();
            lista = removerValor(lista, valor);
            pausa(500);
            break;
        case 9:
            exibirLista(lista);
            getchar();
            break;
        default:
            break;
        }
    } while (opcao != 0);

    liberarLista(lista);
    return 0;
}
