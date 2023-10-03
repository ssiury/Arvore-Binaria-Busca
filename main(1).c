#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *esquerda;
    struct no *direita;
}No;
typedef struct elemento{
    No *no;
    struct elemento *proximo;
}Elemento;
typedef struct fila{
    Elemento *topo;
    Elemento *fim;
    int quantidade;
}Fila;
void inicializarFila(Fila *fila){
    fila->topo=NULL;
    fila->fim=NULL;
    fila->quantidade = 0;
}
void inserirFila(Fila *fila, No **pRaiz){
    Elemento *novo = malloc(sizeof(Elemento));
    novo->no=pRaiz;
    novo->proximo=NULL;
    if(fila->topo==NULL){
        fila->topo=novo;
    }else{
        fila->fim->proximo=novo;
    }
    fila->fim=novo;
    fila->quantidade++;
}
void removerFila(Fila *fila){
            Elemento *aux = malloc(sizeof(Elemento));
            aux = fila->topo;
            if(fila->topo->proximo==NULL){
                fila->topo=NULL;
                fila->fim=NULL;
            }else{
                fila->topo = aux->proximo;
            }
            fila->quantidade--;
            printf("%d ", aux->no->chave);
            free(aux);
}

//ponteiro duplo, aponta para o ponteiro paraa raiz
void inicializarABB(No **pRaiz){
    *pRaiz = NULL;
}
void inserirABB(No **pRaiz, int chave){
    if(*pRaiz == NULL){
        *pRaiz = (No *) malloc(sizeof(No));
        (*pRaiz)->chave = chave;
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        printf("inserido\n");
    }else{
        if(chave < (*pRaiz)->chave) inserirABB(&(*pRaiz)->esquerda, chave);
        if(chave > (*pRaiz)->chave) inserirABB(&(*pRaiz)->direita, chave);
    }
}
void buscarABB(No **pRaiz, int chave){
    if((*pRaiz)->chave == chave) printf("encontrado\n");
    else if((*pRaiz)->chave > chave && (*pRaiz)->esquerda != NULL) buscarABB(&(*pRaiz)->esquerda, chave);
    else if((*pRaiz)->chave < chave && (*pRaiz)->direita != NULL) buscarABB(&(*pRaiz)->direita, chave);
    else printf("nao encontrado\n");
}
No* maiorABB(No **pRaiz){
    if((*pRaiz)->direita == NULL) return *pRaiz;
    else if((*pRaiz)->direita !=NULL ) maiorABB(&(*pRaiz)->direita);
}
void removerABB(No **pRaiz, int chave){
    if((*pRaiz)->chave == chave){
        if((*pRaiz)->direita == NULL && (*pRaiz)->esquerda == NULL){
            free(*pRaiz);
        }
        else if((*pRaiz)->direita != NULL && (*pRaiz)->esquerda == NULL){
            *pRaiz = (*pRaiz)->direita;
            free((*pRaiz)->direita);
            (*pRaiz)->direita = NULL;
        }
        else if((*pRaiz)->direita == NULL && (*pRaiz)->esquerda != NULL){
            *pRaiz = (*pRaiz)->esquerda;
            free((*pRaiz)->esquerda);
            (*pRaiz)->esquerda = NULL;
        }
        else if((*pRaiz)->direita != NULL && (*pRaiz)->esquerda != NULL){
            (*pRaiz) = maiorABB((*pRaiz)->esquerda);
            free(maiorABB((*pRaiz)->esquerda));
        }
        printf("removido\n");
    }
    else if((*pRaiz)->chave > chave && (*pRaiz)->esquerda != NULL) removerABB(&(*pRaiz)->esquerda, chave);
    else if((*pRaiz)->chave < chave && (*pRaiz)->direita != NULL) removerABB(&(*pRaiz)->direita, chave);
    else printf("nao encontrado\n");
}
void nivelABB(Fila *fila,No **pRaiz){
    inserirFila(&fila, &(pRaiz));
    if((*pRaiz)->esquerda!=NULL){
        inserirFila(&fila,(*pRaiz)->esquerda);
    }
    if((*pRaiz)->direita!=NULL){
        inserirFila(&fila,(*pRaiz)->direita);
    }
    while(fila->quantidade>0){
        removerFila(&fila);
    }
}
void preordemABB(No **pRaiz){
    if((*pRaiz)->esquerda == NULL && (*pRaiz)->direita == NULL) printf("%d ",(*pRaiz)->chave);
    else if((*pRaiz)->esquerda != NULL && (*pRaiz)->direita == NULL){
        printf("%d ",(*pRaiz)->chave);
        preordemABB(&(*pRaiz)->esquerda);
    }else if((*pRaiz)->esquerda == NULL && (*pRaiz)->direita != NULL){
        printf("%d ",(*pRaiz)->chave);
        preordemABB(&(*pRaiz)->direita);
    }else{
        printf("%d ",(*pRaiz)->chave);
        preordemABB(&(*pRaiz)->esquerda);
        preordemABB(&(*pRaiz)->direita);
    }
}
void emordemABB(No **pRaiz){
    if((*pRaiz)->esquerda == NULL && (*pRaiz)->direita == NULL) printf("%d ",(*pRaiz)->chave);
    else if((*pRaiz)->esquerda != NULL && (*pRaiz)->direita == NULL){
        emordemABB(&(*pRaiz)->esquerda);
        printf("%d ",(*pRaiz)->chave);
    }else if((*pRaiz)->esquerda == NULL && (*pRaiz)->direita != NULL){
        emordemABB(&(*pRaiz)->direita);
        printf("%d ",(*pRaiz)->chave);
    }else{
        emordemABB(&(*pRaiz)->esquerda);
        printf("%d ",(*pRaiz)->chave);
        emordemABB(&(*pRaiz)->direita);
    }
}
void posordemABB(No **pRaiz){
    if((*pRaiz)->esquerda == NULL && (*pRaiz)->direita == NULL) printf("%d ",(*pRaiz)->chave);
    else if((*pRaiz)->esquerda != NULL && (*pRaiz)->direita == NULL){
        posordemABB(&(*pRaiz)->esquerda);
     }
    else if((*pRaiz)->esquerda == NULL && (*pRaiz)->direita != NULL){
        posordemABB(&(*pRaiz)->direita);
    }
    else{
        posordemABB(&(*pRaiz)->esquerda);
        posordemABB(&(*pRaiz)->direita);
        printf("%d ",(*pRaiz)->chave);
    }
}

//alteração de remoção
//1-folha->só da free
//2-1filho->ele fica no lugar do pai
//3-2filho->ou o menor dos maiores ou o maior dos menores para substitui-lo e entt da free

int main()
{
    No **pRaiz;
    inicializarABB(&pRaiz);
    Fila *fila;
    inicializarFila(&fila);
    int op=0, valor;
    do{
        scanf("%d",&op);
        switch(op){
            case 1:
                scanf("%d",&valor);
                inserirABB(&(pRaiz), valor);
                break;
            case 2:
                scanf("%d",&valor);
                removerABB(&(pRaiz), valor);
                break;
            case 3:
                scanf("%d",&valor);
                buscarABB(&(pRaiz), valor);
                break;
            case 4:
                nivelABB(&fila,&(pRaiz));
                printf("\n");
                break;
            case 5:
                emordemABB(&(pRaiz));
                printf("\n");
                break;
            case 6:
                preordemABB(&(pRaiz));
                printf("\n");
                break;
            case 7:
                posordemABB(&(pRaiz));
                printf("\n");
                break;
        }
    }while(op!=-1);

    return 0;
}
