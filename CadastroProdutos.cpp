#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <locale.h>
using namespace std;

struct produto{
    
    int codProd;
    char descProd[10];
    float valor;
    int qtde;
};

int zeraCod(produto *lista){
    
    int i; 
    
    for(i=0; i<20; i++){ 
        lista[i].codProd = 0;
    }
    return 0;
}

int cadastroProd(produto lis[20], int i){

        while(lis[i].codProd != 0){
            i++;
        }
        
        printf("\nColoque o codigo do produto: ");
        scanf("%i",&lis[i].codProd);
        printf("\nColoque a descricao do produto: ");
        scanf("%s",&lis[i].descProd);
        printf("\nColoque o valor do produto: ");
        scanf("%f",&lis[i].valor);
        printf("\nColoque a quantidade: ");
        scanf("%i",&lis[i].qtde);    
        return 0;
}

int pesqDesc(produto lis[20]){
        
        int i;
        char descNome[10];

        printf("\nColoque o nome da descricao do produto: ");
        scanf("%s",&descNome);
            
            for(i = 0; i < 20; i++){
                if(strcmp(lis[i].descProd, descNome) == 0){

                    printf("\nO produto que voce pesquisou no estoque: \n\n********* \nCodigo: %i \nDescricao: %s \nValor: %.2f \nQuantidade: %i \n\n*********",lis[i].codProd,lis[i].descProd,lis[i].valor,lis[i].qtde);
                }
            }
        return 0;
}

int zeraProdEstoq(produto *lis){
    
    int i = 0;
    int cod;

    printf("\nColoque o codigo do estoque que voce quer tirar: ");
    scanf("%i",&cod);
    for(i=0; i<20; i++){
    if (lis[i].codProd == cod){
        
        while (lis[i].codProd != 0){
            lis[i] = lis[i+1];
            i = i + 1;
        }
    }
}
printf("\n****\nProduto retirado!!\n****\n");
    return 0;
}

int totalLista(produto lis[20]){
    
    int i=0;
    int quant=0;

    while (lis[i].codProd != 0)
    {
        i++;
        quant = quant + 1;
    }
        printf("\n********** \n\nTotal de cadastros no estoque: %i \n\n**********",quant);

    return 0;
}

int produZero(produto lis[20]){

    int i;
    int contadorA = 0;
    int contadorB = 0;

    for (i=0; i<20; i++){
        contadorA = contadorA + 1;
        if ((lis[i].codProd != 0) && (lis[i].qtde == 0)){

            contadorB = contadorB + 1;
            printf("\n********** \n\nOs produtos com estoque zero: \n\n********* \nCodigo: %i \nDescricao: %s \nValor: %.2f \nQuantidade: %i \n\n*********",lis[i].codProd,lis[i].descProd,lis[i].valor,lis[i].qtde);
        }
        contadorA = contadorA - contadorB;
        if(contadorA == 20){
            printf("\n******\nNao a nenhum estoque zerado!!\n******\n");
        }
    }
    return 0;
}

int addQuant(produto lis[20]){

    int i;
    char descNome[10];
    int quant;

        printf("\nColoque o nome da descricao do produto: ");
        scanf("%s",&descNome);
            for(i = 0; i < 20; i++){
                if(strcmp(lis[i].descProd, descNome) == 0){

                    printf("\nColoque a quantidade de produtos: ");
                    scanf("%i",&quant);
                    
                    lis[i].qtde = lis[i].qtde + quant;
                    
                    printf("\n********\nAdicionado com sucesso!!\n");
                    printf("\nQuantidade agora: %i\n********\n",lis[i].qtde);
                }
            }
        return 0;
}

int remoQuant(produto lis[20]){

    int i;
    char descNome[10];
    int quant;

        printf("\nColoque o nome da descricao do produto: ");
        scanf("%s",&descNome);
            for(i = 0; i < 20; i++){
                if(strcmp(lis[i].descProd, descNome) == 0){

                    printf("\nColoque a quantidade de produtos retirados: ");
                    scanf("%i",&quant);
                    
                    lis[i].qtde = lis[i].qtde - quant;

                    printf("\n********\nRetirado com sucesso\n");
                    printf("\nQuantidade agora: %i \n********\n",lis[i].qtde);
                }
            }
    return 0;
}

int main(){
    
    int p = 0;
    int op;
    produto lista[20];
    zeraCod(lista);
        
        printf("\n***// BEM VINDO AO CADASTRO DE PRODUTOS NO ESTOQUE //***\n");
        printf("\nColoque o codigo do produto: ");
        scanf("%i",&lista[p].codProd);
        printf("\nColoque a descricao do produto: ");
        scanf("%s",&lista[p].descProd);
        printf("\nColoque o valor do produto: ");
        scanf("%f",&lista[p].valor);
        printf("\nColoque a quantidade: ");
        scanf("%i",&lista[p].qtde);
            
            do{    
                
                printf("\n\n----> Escolha uma opcao para continuar: <---- \n\n1- Cadastrar produto \n2- Pesquisar um produto \n3- Retirar um cadastro \n4- Mostrar o total de cadastros \n5- Produtos com estoque zerado \n6- Adicionar quantidade de produto \n7- Remover quantidade de produtos \n0- Sair do Programa \n---> ");
                scanf("%i",&op);
            
                switch(op){
                    case 1: 
                        cadastroProd(lista, p);
                    break;
                    case 2: 
                        pesqDesc(lista);
                    break;
                    case 3: 
                        zeraProdEstoq(lista);
                    break;
                    case 4: 
                        totalLista(lista);
                    break;
                    case 5: 
                        produZero(lista);
                    break;
                    case 6: 
                        addQuant(lista);
                    break;
                    case 7: 
                        remoQuant(lista);
                    break;
                }
            
            }while(op != 0);

}