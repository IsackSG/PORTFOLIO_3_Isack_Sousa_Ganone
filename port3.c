#include <stdio.h>
#include <string.h>

struct Funcionario{
    char nome_funcionario[50];
    float salario_funcionario;
    int quantidade_horas_funcionario;
};

float calcula_horas(float salario, int qnt_horas, float valor_das_horas){
    float salario_final = salario+(qnt_horas*valor_das_horas);
    return salario_final;
}

int main(){
    int swi=0;
    int contador=0;
    int total_cadastrados=0;
    int novos_cadastros=0;
    float salario_final_calculado[100];
    float salario_final;
    float valor_horas_extras=0;
    struct Funcionario F1[100];
    
    while(contador==0){
        printf("=== MENU ===\n\n1) Cadastrar funcionario\n2) Listar funcionários\n3) Calcular Salário com as Horas\n4) Classificação Salarial\n5) Sair\n\n");
        scanf("%d",&swi);

        switch(swi){
            case 1:
                printf("Quantidade de funcionários para cadastro: \n");
                scanf("%d",&novos_cadastros);

                for(int i=0;i<novos_cadastros;i++){
                    printf("\nNome funcionário [%d]:\n",total_cadastrados+1);
                    scanf("%s",F1[total_cadastrados].nome_funcionario);
                    printf("Salário base funcionário [%d]:\n",total_cadastrados+1);
                    scanf("%f",&F1[total_cadastrados].salario_funcionario);
                    printf("Quantidade de horas extras: \n");
                    scanf("%d",&F1[total_cadastrados].quantidade_horas_funcionario);
                    total_cadastrados++;
                }
                printf("\n\nFuncionário(s) cadastrado(s) com sucesso!\n\n");
                break;
            case 2:
                for(int i=0;i<total_cadastrados;i++){
                    printf("\n=========== Funcionário [%d] ===========\n",i+1);
                    printf("Nome funcionário [%d]: %s\n",i+1,F1[i].nome_funcionario);
                    printf("Salário base funcionário [%d]: %.2f\n",i+1,F1[i].salario_funcionario);
                    printf("Quantidade de horas extras: %d\n",F1[i].quantidade_horas_funcionario);
                    printf("=======================================\n");
                }
                break;
            case 3:
                printf("Digite o valor das horas extras: ");
                scanf("%f",&valor_horas_extras);

                if(valor_horas_extras<=0){
                    printf("Valor inválido\nTente novamente.");
                }else{
                    for(int i=0;i<total_cadastrados;i++){
                        printf("\nSalário base funcionário [%d]: %.2f\n",i+1,F1[i].salario_funcionario);
                        printf("Horas extras funcionário [%d]: %d\n",i+1,F1[i].quantidade_horas_funcionario);
                        salario_final = calcula_horas(F1[i].salario_funcionario,F1[i].quantidade_horas_funcionario,valor_horas_extras);
                        salario_final_calculado[i]=salario_final;
                        printf("Salário atualizado: R$ %.2f\n\n",salario_final);
                        }
                }
                break;
            case 4:
                if(valor_horas_extras==0){
                    printf("\n\nValor das horas extras indefinido.\nExecute PRIMEIRO a 'opção 3)' no MENU\n\n");
                }else{
                for(int i=0;i<total_cadastrados;i++){
                    if(salario_final_calculado[i]<=2000){
                        printf("\nSalário Funcionário [%d]: %.2f\nClassificação: BAIXO\n\n",i+1,salario_final_calculado[i]);
                    }else if(salario_final_calculado[i]>=2000.01 && salario_final_calculado[i]<=4000){
                        printf("\nSalário Funcionário [%d]: %.2f\nClassificação: MÉDIO\n\n",i+1,salario_final_calculado[i]);
                    }else if(salario_final_calculado[i]>4000){
                        printf("\nSalário Funcionário [%d]: %.2f\nClassificação: ALTO\n\n",i+1,salario_final_calculado[i]);
                    }}
                break;
            case 5:
                contador=10;
                printf("\n\n-> Você Saiu! (0w0)\n\n");
                break;
            default:
                printf("\nOpção inválida\nTENTE NOVAMENTE!\n");
                break;
            
            }}
        }

    return 0;
}
