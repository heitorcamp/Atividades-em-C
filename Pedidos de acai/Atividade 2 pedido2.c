#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>



typedef struct
{
    int numero;
    char rua[10];
    char bairro[10];
    char complemento[10];
} endereco;

typedef struct
{
    char* sabor[20];
    char* tamanho[10];
    float quantidade;
} item [10];

typedef struct
{
    char* formaPg[20];
    float valorPedido;
} pagamento;

struct pedido
{
    int numPedido;
    char nomeCliente[10];
    int fone;
    endereco end;
    item nitem;
    pagamento pag;
};

int main (void)
{
    setlocale(LC_ALL,"Portuguese");
    struct pedido pedN1;
    int c,i=0;

    int cadcliente,contSab,contTam,contPag;

    char resp;
    printf (".:::Bem Vindo ao açai :::.");
    printf("\nCadastro de pedido \n\nNumero do pedido: ");
    scanf("%i",& pedN1.numPedido);
    fflush(stdin);
    printf ("[1] - Cadastrar Cliente \n[2] - Somente Pedido \n");
    scanf("%i",&cadcliente);
    fflush(stdin);

    if (cadcliente == 1)
    {
//dados cliente
        printf("\n.:::Cadastro de cliente:::.\n");
        printf("Referente ao Pedido : %i",pedN1.numPedido);
        printf("\nCliente: ");
        scanf("%s",&pedN1.nomeCliente);
        printf("Tel/Cel: ");
        scanf("%d",&pedN1.fone);
//cadastro endereco
        printf("\n.:::ENDERECO:::.\n\nRua: ");
        scanf("%s",&pedN1.end.rua);
        printf("Numero: ");
        scanf("%d",&pedN1.end.numero);
        printf("Bairro: ");
        scanf("%s",&pedN1.end.bairro);
        printf("Complemento: ");
        scanf("%s",&pedN1.end.complemento);
    }
    printf(".:::Pedido:::.");
    printf("\nReferente ao Pedido : %i",pedN1.numPedido);
    do
    {

        printf("\nEscolha o sabor\n[1]-Açai com nutella\n[2]-Açai com ninho\n[3]-Açai com morango\n");
        scanf("%i",&contSab);
        fflush(stdin);
        while(contSab !=1 && contSab!= 2 && contSab!= 3){
            printf("CODIGO INVALIDO \nDigite um valor valido: ");
            scanf("%i",&contSab);
            fflush(stdin);
        }
        if(contSab==1)
        {
            pedN1.nitem[i].sabor[20]=("Açai com nutella");
        }
        else if(contSab==2)
        {
            pedN1.nitem[i].sabor[20]=("Açai com ninho");
        }
        else if(contSab==3)
        {
            pedN1.nitem[i].sabor[20]=("Açai com morango");
        }
        //calculo de preço e tamanho do item
        printf("Escolha o tamanho\n[1]-Pequeno - R$10.00\n[2]-Medio - R$15.00\n[3]-Grande - R$20.00\n");
        scanf("%i",&contTam);
        while(contTam !=1 && contTam!= 2 && contTam!= 3){
            printf("CODIGO INVALIDO \nDigite um valor valido: ");
            scanf("%i",&contTam);
            fflush(stdin);
        }
        if(contTam==1)
        {
            pedN1.nitem[i].tamanho[10]=("Pequeno ");
            pedN1.pag.valorPedido+= 10;
        }
        else if(contTam==2)
        {
            pedN1.nitem[i].tamanho[10]=("Medio");
            pedN1.pag.valorPedido+= 15;
        }
        else if(contTam==3)
        {
            pedN1.nitem[i].tamanho[10]=("Grande");
            pedN1.pag.valorPedido+= 20;
        }
        printf("\n***%s",pedN1.nitem[i].sabor[20]);
        printf(" - %s***",pedN1.nitem[i].tamanho[10]);
        printf("\n\nMais itens ao Pedido: %d",pedN1.numPedido);
        printf("\n[S] - Sim [N] - Nao\n");
        scanf("%s",&resp);
        fflush(stdin);
        i++;
    }
    while(resp=='s');





    //imprimir dados do pedido
    system("cls");
    printf("\n+--------+---------+---------+---------+\n");
    printf("|       .::Detalhes do pedido::.       |\n");
    printf("+--------+---------+---------+---------+\n");

    if(cadcliente == 1)
    {
        printf("\nCliente: ");
        printf("%s",pedN1.nomeCliente);
        printf("\nTel/Cel: ");
        printf("%d",pedN1.fone);
//cadastro endereco
        printf("\n.:::ENDERECO:::.");
        printf("\nRua: %s",pedN1.end.rua);
        printf("\nNumero: ");
        printf("%d",pedN1.end.numero);
        printf("\nBairro: ");
        printf("%s",pedN1.end.bairro);
        printf("\nComplemento: ");
        printf("%s\n",pedN1.end.complemento);

    }
    printf("\n            **Itens**                 \n");
    for(c=0; c<i; c++)
    {
    printf(" %d)- ***%s",c+1,pedN1.nitem[c].sabor[20]);
    printf(" - %s***     \n",pedN1.nitem[c].tamanho[10]);
    }
    printf("\n+--------+---------+---------+---------+");
     printf("\n|                                      |");
    printf("\n|         valor TOTAL: R$%.2f         |", pedN1.pag.valorPedido);
    printf("\n|                                      |");
    printf("\n+--------+---------+---------+---------+\n");
    printf("\n\nForma de pagamento: \n[1]-Debito\n[2]-Credito\n[3]-Dinheiro\n");
    scanf("%d",&contPag);
    if(contPag==1)
        {
            pedN1.pag.formaPg[20]=("Debito");
        }
        else if(contPag==2)
        {
            pedN1.pag.formaPg[20]=("Credito");
        }
        else if(contPag==3)
        {
            pedN1.pag.formaPg[20]=("Dinheiro");
        }

        printf("\nPagamento: %s",pedN1.pag.formaPg[20]);
        printf("\n\n\nObrigado e volte sempre !!!!\n\n\n\n");



}
