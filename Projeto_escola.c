#include <stdio.h>
#include <string.h>

// protótipos das funções
void munuGeral();
void menuAluno();

typedef struct {

    char nome[50];
    char cpf[15];
    int matricula;
    char sexo[10];
    char data_nasc[10];    

} aluno;

 // typedef struct {

    //char nome[50];
    //char cpf[15];
    //int matricula;
    //char sexo[10];
    //char data_nasc[10];    

//} professor;

void imprimeAluno(aluno alunos[], int qtd_aluno) {

    for(int icount = 0; icount < qtd_aluno; icount++) {
        printf("Nome: %s\n", alunos[icount].nome);
        printf("CPF %s\n", alunos[icount].cpf);
        printf("Data de nascimento: %s\n", alunos[icount].data_nasc);
        printf("Sexo: %s\n", alunos[icount].sexo);  
        printf("Matricula: %d\n", alunos[icount].matricula);      
    }    
}

#define TAM_ALUNO 3

int main() {

    int opcao, opcao_aluno;
    int sair = 0;
    int sair_aluno;
    int qtd_aluno = 0;
    aluno alunos[TAM_ALUNO];

    printf("-- Sistema Escolar --\n");

    while(sair != 1) {

        munuGeral();
        scanf("%d", &opcao);

        switch(opcao) {

            
            case 1:
                printf("Módulo Aluno\n");
                sair_aluno = 0;

                while(sair_aluno != 1) {

                    menuAluno();
                    scanf("%d", &opcao_aluno);

                    switch(opcao_aluno) {

                        case 1: {
                            printf("---Matricular aluno---\n");

                            if(qtd_aluno == TAM_ALUNO)
                                printf("Não será possível cadastrar o aluno.\nNúmero máximo de matriculas atingido.\n");

                            else {
                                printf("Digite o nome do(a) aluno: \n");
                                scanf("%s", alunos[qtd_aluno].nome);

                                printf("Digite o CPF do(a) aluno: \n");
                                scanf("%s", alunos[qtd_aluno].cpf);

                                printf("Digite a data de nascimento do(a) aluno: \n");
                                scanf("%s", alunos[qtd_aluno].data_nasc);

                                printf("Digite o sexo do(a) aluno: \n");
                                scanf("%s", alunos[qtd_aluno].sexo);                           

                                printf("Digite a matricula do(a) aluno: \n");
                                scanf("%d", &alunos[qtd_aluno].matricula);

                                printf("Aluno cadastrado com sucesso!\n");
                                qtd_aluno++;
                            }

                            break;
                        }

                        case 2: {
                            printf("---Listar alunos---\n");

                            if(qtd_aluno == 0) {
                                printf("Lista de alunos vazia\n");
                            }

                            else {
                                imprimeAluno(alunos, qtd_aluno);
                            }

                            break;
                        }

                        case 3: {
                            printf("---Excluir aluno---\n");

                            int busca_matricula;

                            printf("Digite a matrícula do aluno que deseja excluir: \n");
                            scanf("%d", &busca_matricula);

                            int aluno_ativo = 0;

                            for(int i = 0; i < qtd_aluno; i++) {

                                if(alunos[i].matricula == busca_matricula) {

                                    aluno_ativo = 1;

                                    for(int jcount = i; jcount < qtd_aluno - 1; jcount++) {
                                        alunos[jcount] = alunos[jcount + 1];
                                    }

                                    qtd_aluno--;

                                    printf("Aluno excluído com sucesso.\n");

                                    break;
                                }
                            }

                            if(aluno_ativo == 0) {
                                printf("Matrícula inválida ou inexistente.\n");
                            }

                            break;
                        }

                        case 4: {
                            printf("---Atualizar Aluno---\n");                        

                            int busca_matricula;

                            printf("Digite a matrícula do aluno que deseja atualizar: \n");
                            scanf("%d", &busca_matricula);

                            int aluno_ativo = -1;

                            for(int i = 0; i < qtd_aluno; i++) {

                                if(alunos[i].matricula == busca_matricula) {

                                    aluno_ativo = i;
                                    break;
                             }
                          }                       
                            if(aluno_ativo != -1){
                                
                              printf("Digite o novo nome: \n");
                              scanf("%s", alunos[aluno_ativo].nome);                            

                              printf("Digite o CPF do aluno: \n");
                              scanf("%s", alunos[aluno_ativo].cpf);

                              printf("Digite a matricula do aluno: \n");
                              scanf("%d", &alunos[aluno_ativo].matricula);

                              printf("Aluno atualizado com sucesso!\n");
                          
                          }else {
                              printf("Matricula inválida ou inexistente\n");
                            } 
                                                                                  
                            break;
                        }  

                        case 0: {
                            printf("Programa finalizado\n");
                            sair_aluno = 1;
                            break;
                        }                            

                        default:
                            printf("Opção selecionada inválida");
                    }
                }

                break;

            case 2:
                printf("Módulo Professor\n");
                break;

            case 3:
                printf("Módulo Diciplina\n");
                break;

            case 0:
                printf("Programa finalizado\n");
                sair = 1;
                break;

            default:
                printf("Opção selecionada inválida");
        }
    }

    return 0;
}

// funções
void munuGeral() {
    printf("Digite o número de acordo com a opção desejada: \n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Diciplina\n");
    printf("0 - Sair\n");
}

void menuAluno(){
    printf("Digite o número de acordo com a opção desejada: \n");
    printf("1 - Matricular aluno\n");
    printf("2 - Listar aluno\n");
    printf("3 - Excluir aluno\n");
    printf("4 - Atualizar aluno\n");                   
    printf("0 - Sair\n");
}