#include<stdio.h>
#include<stdlib.h>

typedef struct aviao
{
    char airline[20];
    int flight;
    float time;
    int tam;
} Aviao;

typedef struct no
{
    struct no *prox;
    Aviao a;
} No;

Aviao criar_aviao()
{
    Aviao a;
    fflush(stdin);
    printf("\nNome do aviao: ");
    fgets(a.airline, 20, stdin);
    printf("\nNumero do voo: ");
    scanf("%d",&a.flight);
    printf("\nTempo: ");
    scanf("%f",&a.time);

    return a;
}

void adiciona_aviao(No **fila)
{
    system("cls");
    No *aux,*novo = malloc(sizeof(No));
    if(novo)
    {
        novo->a = criar_aviao();
        novo->prox = NULL;

        if(*fila==NULL)
            *fila = novo;
        else
        {
            aux = *fila;
            while(aux->prox)
            {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
        printf("\n\n*****Aviao adicionado a fila com sucesso*****\n\n");

    }
    else
        printf("erro na memoria");
}

No* remover_da_fila(No **fila)
{
    No *remover = NULL;
    if(*fila)
    {
        remover = *fila;
        *fila = remover->prox;
    }

    return remover;
}

void autorizar_decolagem(No **fila)
{
    system("cls");
    No *aux = NULL;
    if(*fila == NULL)
        printf("\nNao a aviao na fila\n\n");
    else
    {
        aux = *fila;
        printf("Aviao: %s\nNr Voo: %d\nAutorizado a decolar",aux->a.airline, aux->a.flight);

    }
}

void tamanho_fila(No **fila)
{
    system("cls");
    No *aux = malloc(sizeof(No));
    int i= 0;
    if(*fila)
    {
        aux = *fila;
        while(aux->prox)
        {
            aux = aux->prox;
            i++;
        }
        printf("A %d avioes na fila",i+1);
    }
    else
        printf("\nFila vazia");
}

void listar_aviao(No **fila)
{
    system("cls");
    No *aux = malloc(sizeof(No));
    int i=0;
    if(*fila)
    {
        aux=*fila;
        while(aux)
        {
            printf("\n%d - Aviao\n Nome: %s\nNum Voo: %d\nTempo: %2.f", i+1,aux->a.airline, aux->a.flight,aux->a.time);
            aux = aux->prox;
            i++;
        }
    }
    else
        printf("\nNao a avioes para listar");
}

void listar_caracteristica(No **fila)
{
    system("cls");
    No *aux = NULL;
    if(*fila)
    {
        aux = *fila;
        printf("\nPrimeiro voo: \nNome: %s\nNum voo: %d\nTempo: %2.f",aux->a.airline,aux->a.flight,aux->a.time);

    }
    else
        printf("\nNao a aviao na fila");
}
int main(void)
{
    int op;
    float tempo;
    No *fila = NULL;
    do
    {
        printf("\n\n\nSISTEMA DE VOOS CONGONHAS\n\n");
        printf("************************************\n");
        printf("\n1-Adicionar aviao na fila\n2-Autorizar decolagem do primeiro aviao\n3-Listar o numero de aviao aguardando\n4-Listar todos avioes\n5-Listar as caracteristicas do primeiro aviao");
        printf("\n\n************************************\nSelecione a opcao : ");
        scanf("%d",&op);

        switch(op)
        {
        case 1:

            adiciona_aviao(&fila);
            break;
        case 2:
            autorizar_decolagem(&fila);
            remover_da_fila(&fila);
            break;
        case 3:
            tamanho_fila(&fila);
            break;

        case 4:
            listar_aviao(&fila);
            break;
        case 5:
            listar_caracteristica(&fila);
            break;
        default:
            if(op!=0)
                printf("Opcao invalida");
        }
    }
    while(op!=0);

}
