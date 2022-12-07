#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
   
    int id; //identificador unico de cada vertice
    
    //mecanismo p/ unir nos!
    struct Vertice * esq;
    struct Vertice * dir;
}VERTICE;

VERTICE * raiz = NULL;
int tam = 0;

VERTICE* buscar(int id, VERTICE *aux){
    
    if(aux != NULL){
        if(aux->id == id){
            return aux;
        }else if(id < aux->id){
            if(aux->esq != NULL){
                return buscar(id, aux->esq);
            }else{
                return aux;
            }
        }else if(id > aux->id){
            if(aux->dir != NULL){
                return buscar(id, aux->dir);
            }else{
                return aux;
            }
        }
    }else{
        return NULL;
    }
}

void adicionar(int id){
        //chamada da função
    VERTICE* aux = buscar(id, raiz);
    if(aux != NULL && aux->id == id){
        printf("erro");
    }
    else{
        VERTICE * novo = malloc(sizeof(VERTICE));
        novo->id=id;
        novo->dir=NULL;
        novo->esq=NULL;

        if(aux== NULL){
            raiz = novo;
        }else{
            if(id < aux->id){
                aux->esq = novo;
            }else{
                aux->dir = novo;
            }
        }
    }
}

VERTICE* remover(VERTICE *raiz, int valor){
    if(raiz==NULL){
        printf("\nA arvore esta vazia!!! %d");
        return raiz;
    }else if(valor < raiz->id){
        raiz->esq = remover(raiz->esq, valor);
    }else if(valor > raiz->id){
        raiz->dir = remover(raiz->dir, valor);
    }else{
        if(raiz->dir == NULL && raiz->esq == NULL){
            free(raiz);
            raiz=NULL;
            printf("\nIremos remover a folha %d",valor);
        }else if(raiz->esq == NULL){
            VERTICE*aux = raiz;
            raiz = raiz->dir;
            free(aux);
            printf("\nEncontramos aqui o filho %d, logo, removemos o vertice do lado esquerdo. \n",valor);
        }else if(raiz->dir == NULL){
            VERTICE*aux = raiz;
            raiz = raiz->esq;
            free(aux);
            printf("\nEncontramos Aqui o filho %d, logo removemos o vertice do lado direito.\n",valor);
        }else{
            VERTICE*aux = raiz->dir;
            raiz->id=aux->id;
            raiz->dir = remover(raiz->dir,aux->id);
            printf("\nIremover remover vertice com dois filhos %d\n",valor);
            }
        }
    return raiz;
}

void in_ordem(VERTICE *aux){
    
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    printf("  %d ", aux->id);
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}

int main(){
    adicionar(3);
    adicionar(7);
    adicionar(1);
    adicionar(2);
    adicionar(5);
    adicionar(4);
    adicionar(6);
    printf("---Ordenando a arvore---\n");
    in_ordem(raiz);
    return 0;
}
