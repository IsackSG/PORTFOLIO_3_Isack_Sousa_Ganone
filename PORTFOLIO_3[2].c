// PROGRAMA QUE CADASTRA PRODUTOS (Isack Sousa Ganone)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct Produto{
    int id_produto;
    char nome[50];
    float valor_produto;
    int estoque;
};

struct Vendas{
    int id_produto;
    int qtd_vendas;
    float valor_total;
};

float ValorTotal (int Vvendido, float Vunitario){
    float vt = Vvendido * Vunitario;
    return vt;
}

int main(){
    struct Produto p1[2];
    struct Vendas historico[2];
    float valorconfereP = 0;
    float valortotal;
    int cod_produto;
    int quantidade;
    int total_vendas = 0;
    int yesorno = 0;
    int valorconfereE = 0;
    int counter = 1;

    while (counter >=1){
        int sw = 0;
        printf("\n\n===== MENU =====\n\n1 - Cadastrar produto\n2 - Listar produtos\n3 - Vender produto\n4 - Listar Vendas\n5 - Sair\n\n");
        scanf("%d", &sw); 

        switch(sw){
            case 1:                
                for(int i=0;i<2;i++){
                    printf("\nInforme o Código do Produto [%d]: \n", i+1);
                    scanf("%d", &p1[i].id_produto);
                    printf("Digite o nome do Produto [%d]: \n", i+1);
                    scanf("%s", p1[i].nome);
                    printf("Informe o valor unitário do Produto [%d]: \n", i+1);
                    scanf("%f", &valorconfereP);
                        if(valorconfereP >0){
                            p1[i].valor_produto = valorconfereP;
                        }else{
                            p1[i].valor_produto = 1;
                            printf("\n\nValor inválido\n");
                        }
                    printf("Informe a quantidade em estoque: \n");
                    scanf("%d", &valorconfereE);
                        if(valorconfereE >=0){
                            p1[i].estoque = valorconfereE;
                        }else{
                             p1[i].estoque = 1;
                            printf("\n\nValor inválido\n");
                        }
                    }
                break;
            case 2:
                for(int i=0;i<2;i++){
                    printf("\nProduto [%d]: %s\n",i+1,p1[i].nome);
                    printf("Código [%d]\n",p1[i].id_produto);
                    printf("Valor: %.2f\n",p1[i].valor_produto);
                    printf("Qntd. [%d]\n",p1[i].estoque);
                }
                break;
            case 3:
                printf("Digite o código do produto: ");
                scanf("%d",&cod_produto);
                printf("Digite a quantidade vendida: ");
                scanf("%d",&quantidade);
                
                if(quantidade >0){
                    int achou;
                    for(int i=0;i<2;i++){
                        if(cod_produto == p1[i].id_produto){
                            if(quantidade<=p1[i].estoque){
                                achou = 1;
                                valortotal = ValorTotal(quantidade,p1[i].valor_produto);
                                p1[i].estoque = p1[i].estoque - quantidade;
                                printf("\n=== Venda Concluída ===\n\nProduto: %s\nQntd. Vendida: %d\nQntd. Disponível: %d\nValor Unitário: %.2f", p1[i].nome,quantidade,p1[i].estoque,p1[i].valor_produto);
                                printf("\nValor total: R$ %.2f", valortotal);
                                historico[total_vendas].id_produto = p1[i].id_produto;
                                historico[total_vendas].qtd_vendas = quantidade;
                                historico[total_vendas].valor_total = valortotal;
                                total_vendas++;
                            }else{
                                printf("\nQuantidade insuficiente.\n- O estoque não possui produtos suficientes para a venda.\n");
                                break;
                            }
                        }
                    }
                    if(achou == 0){
                        printf("\nProduto não cadastrado\n- Verifique o código e tente novamente.\n");
                    }
                }else{
                    printf("\nQuantidade inválida.\n- Tente não deixar vazio.\n");
                }
                break;
            case 4:
                if(total_vendas == 0){
                    printf("\nNenhuma venda realizada ainda.\n");
                }else{
                    for(int i=0;i<total_vendas;i++){
                        printf("\nVenda [%d]\nCód. Produto: %d\nQntd. [%d]\nTotal: %.2f\n\n", i+1,historico[i].id_produto,historico[i].qtd_vendas,historico[i].valor_total);
                    }
                }
                break;
            case 5:
                printf("\n\nDeseja sair?\n\n1) Sim\n2) Não\n\n");
                scanf("%d",&yesorno);
                if(yesorno ==1){
                    counter = 0; 
                    break;
                }if(yesorno ==2){
                    break;
                }else{
                    printf("\n\nOpção inválida!\n");
                }
                    break;
            default:
                printf("\n\nOpção inválida!");
                break;
            
        }
    }

    printf("- You left!\n(0w0)\n\n");

    return 0;
}
