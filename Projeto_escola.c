#include <stdio.h>
#include <string.h>

#define TAM_ALUNO 3
#define LISTA_CHEIA -1
#define CAD_ALUNO_SUCESSO -2
#define MATRICULA_IVALIDA -3
#define NOME_INVALIDO -4
#define INFORMACAO_INVALIDA - 5

typedef struct {

    char nome[50];
    char cpf[15];
    int matricula;
    char sexo[10];
    char data_nasc[10];    

} aluno;

// protótipos das funções
void menuGeral();
void menuAluno();
int cadastrarAluno(aluno alunos[], int qtd_aluno);
void imprimeAluno(aluno alunos[], int qtd_aluno);
int excluirAluno(aluno alunos[], int qtd_aluno);
int atualizarAluno(aluno alunos[], int qtd_aluno);
int validarNome(char nome[]);
int validarCPF(char cpf[]);


 // typedef struct {

   // dados pessoa;  

//} professor;


int main() {

    int opcao, opcao_aluno;
    int sair = 0;
    int sair_aluno;
    int qtd_aluno = 0;
    aluno alunos[TAM_ALUNO];

    printf("-- Sistema Escolar --\n");

    while(sair != 1) {

        menuGeral();
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
                            int retorno = cadastrarAluno(alunos, qtd_aluno);
                            
                            if(retorno == LISTA_CHEIA) {
                            printf("Não será possível cadastrar o aluno.\nNúmero máximo de matrículas atingido.\n");
                        }   
                            else if(retorno == CAD_ALUNO_SUCESSO){
                            printf("Aluno matriculado com sucesso.\n");
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

                            int retorno = excluirAluno(alunos, qtd_aluno);
                            if(retorno == CAD_ALUNO_SUCESSO){
                                printf("Aluno excluído com sucesso.\n");
                                qtd_aluno--;
                            }
                            else if(retorno == MATRICULA_IVALIDA){
                                printf("Matrícula inválida ou inexistente.\n");
                            }
                            break;
                        }

                        case 4: {
                            int retorno = atualizarAluno(alunos, qtd_aluno);
                            
                            if(retorno == CAD_ALUNO_SUCESSO){
                            printf("Aluno atualizado com sucesso!\n");                   
                          }else if(retorno == MATRICULA_IVALIDA){
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
void menuGeral() {
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

int cadastrarAluno(aluno alunos[], int qtd_aluno){
    printf("---Matricular aluno---\n");

    if(qtd_aluno == TAM_ALUNO)
        return LISTA_CHEIA;
    else {
        int retorno = NOME_INVALIDO;
        while(retorno == NOME_INVALIDO){
        printf("Digite o nome do(a) aluno: \n");
        getchar();
        fgets(alunos[qtd_aluno].nome, sizeof(alunos[qtd_aluno].nome), stdin);

        for(int i= 0; alunos[qtd_aluno].nome[i] != '\0'; i++){
            if(alunos[qtd_aluno].nome[i]  == '\n'){
                alunos[qtd_aluno].nome[i] = '\0';
            }
        }
        retorno = validarNome(alunos[qtd_aluno].nome);
        if(retorno == NOME_INVALIDO){
            printf("Nome inválido\n");
        }
    }   
        retorno = INFORMACAO_INVALIDA;      
        while(retorno == INFORMACAO_INVALIDA){
        printf("Digite o CPF do(a) aluno: \n");
        scanf("%s", alunos[qtd_aluno].cpf);

        retorno = validarCPF(alunos[qtd_aluno].cpf);
        if(retorno == INFORMACAO_INVALIDA){
            printf("CPF inválido\n");
        }
    }

        printf("Digite a data de nascimento do(a) aluno: \n");
        scanf("%s", alunos[qtd_aluno].data_nasc);

        printf("Digite o sexo do(a) aluno: \n");
        scanf("%s", alunos[qtd_aluno].sexo);                           

        printf("Digite a matricula do(a) aluno: \n");
        scanf("%d", &alunos[qtd_aluno].matricula);

        return CAD_ALUNO_SUCESSO;
    }

}

void imprimeAluno(aluno alunos[], int qtd_aluno) {

    for(int icount = 0; icount < qtd_aluno; icount++) {
        printf("Nome: %s\n", alunos[icount].nome);
        printf("CPF %s\n", alunos[icount].cpf);
        printf("Data de nascimento: %s\n", alunos[icount].data_nasc);
        printf("Sexo: %s\n", alunos[icount].sexo);  
        printf("Matricula: %d\n", alunos[icount].matricula);      
    }    
}

int excluirAluno(aluno alunos[], int qtd_aluno)  {

    printf("---Excluir aluno---\n");
    int busca_matricula;

    printf("Digite a matrícula do aluno que deseja excluir: \n");
    scanf("%d", &busca_matricula);

    int aluno_ativo = -1;

    for(int i = 0; i < qtd_aluno; i++) {
        if(alunos[i].matricula == busca_matricula) {

            aluno_ativo = 1;

            for(int j = i; j < qtd_aluno - 1; j++) {
                alunos[j] = alunos[j + 1];
            }
            return CAD_ALUNO_SUCESSO;
            break;
        }
    }
    if(aluno_ativo == -1) {
        return MATRICULA_IVALIDA;
    }
}

int atualizarAluno(aluno alunos[], int qtd_aluno) {
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

         printf("Digite a data de nascimento do(a) aluno: \n");
        scanf("%s", alunos[aluno_ativo].data_nasc);

        printf("Digite o sexo do(a) aluno: \n");
        scanf("%s", alunos[aluno_ativo].sexo);                           

        printf("Digite a matricula do aluno: \n");
        scanf("%d", &alunos[aluno_ativo].matricula);

        return CAD_ALUNO_SUCESSO;
    }else {
        return MATRICULA_IVALIDA;
    } 
}

int validarNome(char nome[]){
    for(int i= 0; nome[i] != '\0'; i++){
        if(nome[i] >= '0' && nome[i] <= '9'){
            return NOME_INVALIDO;
        }
    }
    return CAD_ALUNO_SUCESSO;
}

int validarCPF(char cpf[]) {
    int tamanho = 0;
    for(int i= 0; cpf[i] != '\0'; i++){
        tamanho++;
        if(cpf[i] < '0' && cpf[i] > '9'){
            return INFORMACAO_INVALIDA;
        }
    }
    if(tamanho < 11){
        return INFORMACAO_INVALIDA;
    }
    return CAD_ALUNO_SUCESSO;
}

// typedef struct {

    //char nome[50];
    //char cpf[15];
    //char sexo[10];
    //char data_nasc[10];    

//} pessoa;

// typedef struct {

    //pessoa dados;
    //int matricula;
    
//} alunos;

// ***********************
// int cadastrarAluno(aluno alunos[], int qtd_aluno){
  //  printf("---Matricular aluno---\n");

    //if(qtd_aluno == TAM_ALUNO)
     //   return LISTA_CHEIA;
   // else {
    //    int retorno = NOME_INVALIDO;
    //    while(retorno == NOME_INVALIDO){
     //   printf("Digite o nome do(a) aluno: \n");
     //   getchar();
     //   fgets(alunos[qtd_aluno].dados.nome, sizeof(alunos[qtd_aluno].dados.nome), stdin);

      //  for(int i= 0; alunos[qtd_aluno]dados.nome[i] != '\0'; i++){
        //    if(alunos[qtd_aluno].dados.nome[i]  == '\n'){
          //      alunos[qtd_aluno].dados.nome[i] = '\0';
       //     }
      //  }
     //   retorno = validarNome(alunos[qtd_aluno].dados.nome);
     //   if(retorno == NOME_INVALIDO){
      //      printf("Nome inválido\n");
     //   }
   // }   

// ***************************
  // retorno = INFORMACAO_INVALIDA;      
    //    while(retorno == INFORMACAO_INVALIDA){
      //  printf("Digite o CPF do(a) aluno: \n");
       // scanf("%s", alunos[qtd_aluno].dados.cpf);

        //retorno = validarCPF(alunos[qtd_aluno].dados.cpf);
        //if(retorno == INFORMACAO_INVALIDA){
          //  printf("CPF inválido\n");
        //}
    //}

    // **********************
   // typedef struct {
   //     char materia;
   //     char alunos;
   //     char professores;
  // } diciplina;