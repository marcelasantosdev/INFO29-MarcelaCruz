#include <stdio.h>
#include <string.h>

#define TAM_ALUNO 3
#define TAM_PROFESSOR 3
#define TAM_DICIPLINA 3
#define LISTA_CHEIA -1
#define CAD_SUCESSO -2
#define MATRICULA_IVALIDA -3
#define NOME_INVALIDO -4
#define INFORMACAO_INVALIDA -5
#define SAINDO_MODULO -6
#define MODULO_ATIVO -7

typedef struct {

    char nome[50];
    char cpf[15];
    char sexo[10];
    char data_nasc[10];

} pessoa;

typedef struct {

    pessoa dados;
    int matricula;

} aluno;

typedef struct {

    pessoa dados;
    int matricula;

} professor;

typedef struct {

    char nome[50];
    int codigo;
    int semestre;
    int matricula_professor;
    int matricula_aluno[TAM_ALUNO];

} diciplina;


// protótipos das funções

void menuGeral();
void menuAluno();
void menuProfessor();
void menuDiciplina();

int cadastrarAluno(aluno alunos[], int qtd_aluno);
int cadastrarProfessor(professor professores[], int qtd_professor);
int cadastrarDiciplina(diciplina diciplinas[], int qtd_diciplina, professor professores[], int qtd_professor);

void imprimeAluno(aluno alunos[], int qtd_aluno);
void imprimeProfessor(professor professores[], int qtd_professor);
void imprimeDiciplina(diciplina diciplinas[], int qtd_diciplina, professor professores[], int qtd_professor);
void imprimeAlunosDiciplina(diciplina diciplinas[], int qtd_diciplina, aluno alunos[]);
void imprimeDiciplinacomAlunos(diciplina diciplinas[], int qtd_diciplina, aluno alunos[], int qtd_aluno, professor professores[], int qtd_diciplina);
void imprimeAlunosAniversariantes(aluno alunos[], int qtd_aluno);


int excluirAluno(aluno alunos[], int qtd_aluno);
int excluirProfessor(professor professores[], int qtd_professor);
int excluirDiciplina(diciplina diciplinas[], int qtd_diciplina);
int excluirAlunoDiciplina(diciplina diciplinas[]);

int atualizarAluno(aluno alunos[], int qtd_aluno);
int atualizarProfessor(professor professores[], int qtd_professor);
int atualizarProfessorDiciplina(professor professores[], int qtd_professor, diciplina diciplinas[], int qtd_diciplina);

int CadastrarAlunoDiciplina(diciplina diciplinas[], int qtd_diciplina, aluno alunos[], int qtd_aluno);

int validarNome(char nome[]);
int validarCPF(char cpf[]);
int validaDataNasc(char data_nasc[]);
void ordenaProfessor(professor professores[], int qtd_professor);
void ordenaAluno(aluno alunos[], int qtd_aluno);


int main() {

    int opcao, opcao_aluno, opcao_professor, opcao_diciplina;
    int sair = 0;

    int sair_aluno;
    int qtd_aluno = 0;

    int sair_professor;
    int qtd_professor = 0;

    int sair_diciplina;
    int qtd_diciplina = 0;

    aluno alunos[TAM_ALUNO];
    professor professores[TAM_PROFESSOR];
    diciplina diciplinas[TAM_DICIPLINA] = {0};


    printf("-- Sistema Escolar --\n");


    while(sair != 1) {

        menuGeral();
        scanf("%d", &opcao);


        switch(opcao) {

            // ALUNO
            case 1: {

                printf("Módulo Aluno\n");

                sair_aluno = MODULO_ATIVO;


                while(sair_aluno != SAINDO_MODULO) {

                    menuAluno();
                    scanf("%d", &opcao_aluno);

                    switch(opcao_aluno) {

                        case 1: {

                            int retorno = cadastrarAluno(alunos, qtd_aluno);

                            if(retorno == LISTA_CHEIA) {

                                printf("Não será possível cadastrar o aluno.\n");
                                printf("Número máximo de matrículas atingido.\n");

                            }

                            else if(retorno == CAD_SUCESSO) {

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

                            if(retorno == CAD_SUCESSO) {

                                printf("Aluno excluído com sucesso.\n");
                                qtd_aluno--;

                            }

                            else if(retorno == MATRICULA_IVALIDA) {

                                printf("Matrícula inválida ou inexistente.\n");

                            }

                            break;
                        }

                        case 4: {

                            int retorno = atualizarAluno(alunos, qtd_aluno);

                            if(retorno == CAD_SUCESSO) {

                                printf("Aluno atualizado com sucesso!\n");

                            }

                            else if(retorno == MATRICULA_IVALIDA) {

                                printf("Matrícula inválida ou inexistente\n");

                            }

                            break;
                        }

                        case 0: {

                            printf("Saindo do módulo Aluno...\n");
                            sair_aluno = SAINDO_MODULO;

                            break;
                        }

                        default: {

                            printf("Opção selecionada inválida\n");

                            break;
                        }

                        case 5: {

                            printf("---Listar alunos aniversariantes do mês---\n");

                            if(qtd_aluno == 0) {

                                printf("Lista de alunos vazia\n");
                            }
                            else {

                            imprimeAlunosAniversariantes(alunos, qtd_aluno);
                            }
                            break;
                        }
                    }
                }

                break;
            }


            // PROFESSOR
            case 2: {

                printf("Módulo Professor\n");

                sair_professor = MODULO_ATIVO;

                while(sair_professor != SAINDO_MODULO) {

                    menuProfessor();
                    scanf("%d", &opcao_professor);


                    switch(opcao_professor) {

                        case 1: {

                            int retorno = cadastrarProfessor(professores, qtd_professor);

                            if(retorno == LISTA_CHEIA) {

                                printf("Não será possível cadastrar o professor.\n");
                                printf("Número máximo de cadastros atingido.\n");

                            }

                            else if(retorno == CAD_SUCESSO) {

                                printf("Professor cadastrado com sucesso.\n");
                                qtd_professor++;

                            }

                            break;
                        }

                        case 2: {

                            printf("---Listar professores---\n");
                            printf("------------------------------------\n");

                            if(qtd_professor == 0) {

                                printf("Lista de professores vazia\n");

                            }

                            else {

                                imprimeProfessor(professores, qtd_professor);

                            }

                            break;
                        }

                        case 3: {

                            int retorno = excluirProfessor(professores, qtd_professor);

                            if(retorno == CAD_SUCESSO) {

                                printf("Professor excluído com sucesso.\n");
                                qtd_professor--;

                            }

                            else if(retorno == MATRICULA_IVALIDA) {

                                printf("Matrícula inválida ou inexistente.\n");

                            }

                            break;
                        }

                        case 4: {

                            int retorno = atualizarProfessor(professores, qtd_professor);

                            if(retorno == CAD_SUCESSO) {

                                printf("Professor atualizado com sucesso!\n");

                            }

                            else if(retorno == MATRICULA_IVALIDA) {

                                printf("Matrícula inválida ou inexistente\n");

                            }

                            break;
                        }

                        case 0: {

                            printf("Saindo do módulo Professor...\n");
                            sair_professor = SAINDO_MODULO;

                            break;
                        }

                        default: {

                            printf("Opção selecionada inválida\n");

                            break;
                        }
                    }
                }

                break;
            }


            // DICIPLINA
            case 3: {

                printf("Módulo Disciplina\n");

                sair_diciplina = MODULO_ATIVO;


                while(sair_diciplina != SAINDO_MODULO) {

                    menuDiciplina();
                    scanf("%d", &opcao_diciplina);

                    switch(opcao_diciplina) {

                        case 1: {

                            int retorno = cadastrarDiciplina(diciplinas, qtd_diciplina, professores, qtd_professor);

                            if(retorno == LISTA_CHEIA) {

                                printf("Não será possível cadastrar a diciplina.\n");
                                printf("Número máximo de cadastros atingido.\n");

                            }

                            else if(retorno == CAD_SUCESSO) {

                                printf("Diciplina cadastrada com sucesso\n");
                                qtd_diciplina++;

                            }

                            break;
                        }

                        case 2: {

                            printf("---Listar Diciplinas---\n");

                            if(qtd_diciplina == 0) {

                                printf("Lista de diciplinas vazia\n");

                            }

                            else {

                                imprimeDiciplina(diciplinas, qtd_diciplina, professores, qtd_professor );

                            }

                            break;
                        }

                        case 3: {

                            int retorno = excluirDiciplina(diciplinas, qtd_diciplina);

                            if(retorno == CAD_SUCESSO) {

                                printf("Diciplina excluída com sucesso.\n");
                                qtd_diciplina--;

                            }

                            else if(retorno == MATRICULA_IVALIDA) {

                                printf("Código inválido ou inexistente.\n");

                            }

                            break;
                        }

                        case 4: {

                            int retorno = atualizarProfessorDiciplina(professores, qtd_professor, diciplinas, qtd_diciplina
                            );

                            if(retorno == CAD_SUCESSO) {

                                printf("Professor atualizado com sucesso!\n");

                            }

                            else {

                                printf("Matrícula errada ou inexistente\n");

                            }

                            break;
                        }

                        case 5: {

                            int retorno = CadastrarAlunoDiciplina(diciplinas, qtd_diciplina, alunos, qtd_aluno);

                            if(retorno == CAD_SUCESSO) {

                                printf("Aluno cadastrado na Diciplina com sucesso\n");

                            }

                            else if(retorno == LISTA_CHEIA) {

                                printf("A diciplina está cheia, não será possível cadastrar mais alunos\n");

                            }

                            break;
                        }

                        case 6: {

                            int retorno = excluirAlunoDiciplina(diciplinas);
                            
                            if(retorno == CAD_SUCESSO){
                                printf("Aluno(a) excluído(a) com sucesso!\n");
                            }
                            else if(retorno == MATRICULA_IVALIDA){
                                printf("Aluno(a) não encontrado(a).");
                            }
                            else if(retorno == INFORMACAO_INVALIDA){
                                printf("Diciplina não encontrada.");
                            }
                            break;
                        }

                        case 7: {

                            imprimeAlunosDiciplina(diciplinas, qtd_diciplina, alunos);

                            break;
                        }

                        case 8: {

                            imprimeDiciplinacomAlunos(diciplinas, qtd_diciplina, alunos, qtd_aluno, professores, qtd_diciplina);

                            break;
                        }

                        case 0: {

                            printf("Saindo do módulo Disciplina...\n");
                            sair_diciplina = SAINDO_MODULO;

                            break;
                        }

                        default: {

                            printf("Opção selecionada inválida\n");

                            break;
                        }
                    }
                }

                break;
            }


            // SAIR DO PROGRAMA
            case 0: {

                printf("Programa finalizado\n");
                sair = 1;

                break;
            }


            default: {

                printf("Opção selecionada inválida\n");

                break;
            }
        }
    }

    return 0;
}



// MENUS

void menuGeral() {

    printf("Digite o número de acordo com a opção desejada: \n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    printf("0 - Sair\n");
}

void menuAluno() {

    printf("Digite o número de acordo com a opção desejada: \n");
    printf("1 - Matricular aluno(a)\n");
    printf("2 - Listar aluno(a)\n");
    printf("3 - Excluir aluno(a)\n");
    printf("4 - Atualizar aluno(a)\n");
    printf("5 - Listar alunos(as) aniversariantes do mês\n");
    printf("0 - Sair\n");

}

void menuDiciplina() {

    printf("Digite o número de acordo com a opção desejada: \n");
    printf("1 - Cadastrar diciplina\n");                            // 
    printf("2 - Listar diciplinas\n");                              //
    printf("3 - Excluir diciplina\n");                              //
    printf("4 - Atualizar professor(a) da diciplina\n");            //
    printf("5 - Cadastrar aluno(a) na diciplina\n");                //
    printf("6 - Excluir aluno da diciplina\n");
    printf("7 - Listar alunos(as) da diciplina\n");
    printf("8 - Listar dados e alunos(as) da diciplina\n");                // 
    printf("0 - Sair\n");

}

void menuProfessor() {

    printf("Digite o número de acordo com a opção desejada: \n");
    printf("1 - Cadastrar professor\n");
    printf("2 - Listar professores\n");
    printf("3 - Excluir professor\n");
    printf("4 - Atualizar professor\n");
    printf("0 - Sair\n");
}


// FUNÇÕES 

int cadastrarAluno(aluno alunos[], int qtd_aluno) {

    printf("---Matricular aluno---\n");

    if(qtd_aluno == TAM_ALUNO)

        return LISTA_CHEIA;

    else {

        int retorno = NOME_INVALIDO;

        while(retorno == NOME_INVALIDO) {

            printf("Digite o nome do(a) aluno: \n");
            getchar();

            fgets(
                alunos[qtd_aluno].dados.nome,
                sizeof(alunos[qtd_aluno].dados.nome),
                stdin
            );

            for(int i = 0;
                alunos[qtd_aluno].dados.nome[i] != '\0';
                i++) {

                if(alunos[qtd_aluno].dados.nome[i] == '\n') {

                    alunos[qtd_aluno].dados.nome[i] = '\0';

                }
            }

            retorno = validarNome(alunos[qtd_aluno].dados.nome);

            if(retorno == NOME_INVALIDO) {

                printf("Nome inválido\n");

            }
        }

        retorno = INFORMACAO_INVALIDA;

        while(retorno == INFORMACAO_INVALIDA) {

            printf("Digite o CPF do(a) aluno: \n");
            scanf("%s", alunos[qtd_aluno].dados.cpf);

            retorno = validarCPF(alunos[qtd_aluno].dados.cpf);

            if(retorno == INFORMACAO_INVALIDA) {

                printf("CPF inválido\n");

            }
        }
        retorno = INFORMACAO_INVALIDA;
        while(retorno == INFORMACAO_INVALIDA){

        printf("Digite a data de nascimento do(a) aluno (DD/MM/AAAA): \n");
        scanf("%s", alunos[qtd_aluno].dados.data_nasc);

        retorno = validaDataNasc(alunos[qtd_aluno].dados.data_nasc);

        if(retorno == INFORMACAO_INVALIDA){
            printf("Data inválida.\n");
        }
    }

        printf("Digite o sexo do(a) aluno: \n");
        scanf("%s", alunos[qtd_aluno].dados.sexo);

        int matricula_valida = 0;

        while(matricula_valida == 0){

        printf("Digite a matricula do(a) aluno: \n");
        scanf("%d", &alunos[qtd_aluno].matricula);

        if(alunos[qtd_aluno].matricula < 10){
            printf("Número de Mátricula inválido. Certifique-se de não ter digitado apenas um digito.");
        }
        else{
            matricula_valida = CAD_SUCESSO;
            }
        }
        return CAD_SUCESSO;
    }
}

int cadastrarProfessor(professor professores[], int qtd_professor) {

    printf("---Cadastrar Professor---\n");

    if(qtd_professor == TAM_PROFESSOR)

        return LISTA_CHEIA;

    else {

        int retorno = NOME_INVALIDO;

        while(retorno == NOME_INVALIDO) {

            printf("Digite o nome do(a) professor(a): \n");
            getchar();

            fgets(
                professores[qtd_professor].dados.nome,
                sizeof(professores[qtd_professor].dados.nome),
                stdin
            );

            for(int i = 0;
                professores[qtd_professor].dados.nome[i] != '\0';
                i++) {

                if(professores[qtd_professor].dados.nome[i] == '\n') {

                    professores[qtd_professor].dados.nome[i] = '\0';

                }
            }

            retorno = validarNome(
                professores[qtd_professor].dados.nome
            );

            if(retorno == NOME_INVALIDO) {

                printf("Nome inválido\n");

            }
        }

        retorno = INFORMACAO_INVALIDA;

        while(retorno == INFORMACAO_INVALIDA) {

            printf("Digite o CPF do(a) professor(a): \n");
            scanf("%s", professores[qtd_professor].dados.cpf);

            retorno = validarCPF(
                professores[qtd_professor].dados.cpf
            );

            if(retorno == INFORMACAO_INVALIDA) {

                printf("CPF inválido\n");

            }
        }

        printf("Digite a data de nascimento do(a) professor(a): \n");
        scanf("%s", professores[qtd_professor].dados.data_nasc);

        printf("Digite o sexo do(a) professor(a): \n");
        scanf("%s", professores[qtd_professor].dados.sexo);

        printf("Digite a matricula do(a) professor(a): \n");
        scanf("%d", &professores[qtd_professor].matricula);

        return CAD_SUCESSO;
    }
}

int cadastrarDiciplina(
    diciplina diciplinas[],
    int qtd_diciplina,
    professor professores[],
    int qtd_professor
 ) {

    printf("---Cadastrar Diciplina---\n");

    int busca_matricula;

    if(qtd_diciplina == TAM_DICIPLINA)

        return LISTA_CHEIA;

    else {

        printf("Digite o nome da diciplina: \n");
        getchar();

        fgets(
            diciplinas[qtd_diciplina].nome,
            sizeof(diciplinas[qtd_diciplina].nome),
            stdin
        );

        for(int i = 0;
            diciplinas[qtd_diciplina].nome[i] != '\0';
            i++) {

            if(diciplinas[qtd_diciplina].nome[i] == '\n') {

                diciplinas[qtd_diciplina].nome[i] = '\0';

            }
        }
    }

    printf("Digite o código da diciplina: \n");
    scanf("%d", &diciplinas[qtd_diciplina].codigo);

    printf("Digite o semestre da diciplina: \n");
    scanf("%d", &diciplinas[qtd_diciplina].semestre);

    int retorno = INFORMACAO_INVALIDA;

    while(retorno == INFORMACAO_INVALIDA) {

        printf("Digite a matrícula do(a) professor(a) da diciplina: \n");
        scanf("%d", &busca_matricula);

        int professor_ativo = 0;

        for(int i = 0; i < qtd_professor; i++) {

            if(professores[i].matricula == busca_matricula) {

                diciplinas[qtd_diciplina].matricula_professor =
                    busca_matricula;

                professor_ativo = 1;

                break;
            }
        }

        if(professor_ativo == 1) {

            return CAD_SUCESSO;

        }

        else {

            printf("Matrícula do(a) professor inválida ou inexistente\n");

        }
    }

    return INFORMACAO_INVALIDA;
}


void imprimeAluno(aluno alunos[], int qtd_aluno) {

    ordenaAluno(alunos, qtd_aluno);

    for(int icount = 0; icount < qtd_aluno; icount++) {

        printf("Nome: %s\n", alunos[icount].dados.nome);
        printf("CPF: %s\n", alunos[icount].dados.cpf);
        printf("Data de nascimento: %s\n", alunos[icount].dados.data_nasc);
        printf("Sexo: %s\n", alunos[icount].dados.sexo);
        printf("Matricula: %d\n", alunos[icount].matricula);

    }
}

void imprimeProfessor(professor professores[], int qtd_professor) {

    for(int icount = 0; icount < qtd_professor; icount++) {

        printf("Nome: %s\n", professores[icount].dados.nome);
        printf("CPF: %s\n", professores[icount].dados.cpf);
        printf("Data de nascimento: %s\n",
               professores[icount].dados.data_nasc);
        printf("Sexo: %s\n", professores[icount].dados.sexo);
        printf("Matricula: %d\n", professores[icount].matricula);

        printf("------------------------------------\n");
    }
}

void imprimeDiciplina(diciplina diciplinas[], int qtd_diciplina, professor professores[], int qtd_professor) {

    for(int icount = 0; icount < qtd_diciplina; icount++) {

        printf("Nome: %s\n", diciplinas[icount].nome);

        printf("Código: %d\n", diciplinas[icount].codigo);

        printf("%dº semestre\n", diciplinas[icount].semestre);

        for(int j = 0; j < qtd_professor; j++) {

            if(diciplinas[icount].matricula_professor ==
               professores[j].matricula) {

                printf("Professor(a): %s\n",
                       professores[j].dados.nome);

                break;
            }
        }
    }
}

void imprimeDiciplinacomAlunos(diciplina diciplinas[], int qtd_diciplina, aluno alunos[], int qtd_aluno, professor professores[], int qtd_professor){

        for(int icount = 0; icount < qtd_diciplina; icount++) {

        printf("Nome: %s\n", diciplinas[icount].nome);

        printf("Código: %d\n", diciplinas[icount].codigo);

        printf("%dº semestre\n", diciplinas[icount].semestre);

        for(int j = 0; j < qtd_professor; j++) {

            if(diciplinas[icount].matricula_professor ==
               professores[j].matricula) {

                printf("Professor(a): %s\n",
                       professores[j].dados.nome);

                break;
            }
        }

        for(int j = 0; j < qtd_aluno; j++) {

            for(int k = 0; k < TAM_ALUNO; k++){

            if(diciplinas[icount].matricula_aluno[j] == alunos[k].matricula) {

                printf("Aluno(a): %s\n", alunos[k].dados.nome);

                break;
              }
            }
        }
    }
}



int excluirAluno(aluno alunos[], int qtd_aluno) {

    printf("---Excluir aluno---\n");

    int busca_matricula;

    printf("Digite a matrícula do aluno que deseja excluir: \n");
    scanf("%d", &busca_matricula);

    for(int i = 0; i < qtd_aluno; i++) {

        if(alunos[i].matricula == busca_matricula) {

            for(int j = i; j < qtd_aluno - 1; j++) {

                alunos[j] = alunos[j + 1];

            }

            return CAD_SUCESSO;
        }
    }

    return MATRICULA_IVALIDA;
}

int excluirProfessor(professor professores[], int qtd_professor) {

    printf("---Excluir Professor---\n");

    int busca_matricula;

    printf("Digite a matrícula do professor que deseja excluir: \n");
    scanf("%d", &busca_matricula);

    for(int i = 0; i < qtd_professor; i++) {

        if(professores[i].matricula == busca_matricula) {

            for(int j = i; j < qtd_professor - 1; j++) {

                professores[j] = professores[j + 1];

            }

            return CAD_SUCESSO;
        }
    }

    return MATRICULA_IVALIDA;
}

int excluirDiciplina(
    diciplina diciplinas[],
    int qtd_diciplina
 ) {

    printf("---Excluir Diciplina---\n");

    int busca_codigo;

    printf("Digite o código da diciplina que deseja excluir: \n");
    scanf("%d", &busca_codigo);

    for(int i = 0; i < qtd_diciplina; i++) {

        if(diciplinas[i].codigo == busca_codigo) {

            for(int j = i; j < qtd_diciplina - 1; j++) {

                diciplinas[j] = diciplinas[j + 1];

            }

            return CAD_SUCESSO;
        }
    }

    return MATRICULA_IVALIDA;
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

    if(aluno_ativo != -1) {

        printf("Digite o novo nome: \n");
        scanf("%s", alunos[aluno_ativo].dados.nome);

        printf("Digite o CPF do aluno: \n");
        scanf("%s", alunos[aluno_ativo].dados.cpf);

        printf("Digite a data de nascimento do(a) aluno: \n");
        scanf("%s", alunos[aluno_ativo].dados.data_nasc);

        printf("Digite o sexo do(a) aluno: \n");
        scanf("%s", alunos[aluno_ativo].dados.sexo);

        printf("Digite a matricula do aluno: \n");
        scanf("%d", &alunos[aluno_ativo].matricula);

        return CAD_SUCESSO;
    }

    else {

        return MATRICULA_IVALIDA;
    }
}

int atualizarProfessor(
    professor professores[],
    int qtd_professor
 ) {

    printf("---Atualizar Professor---\n");

    int busca_matricula;

    printf("Digite a matrícula do professor que deseja atualizar: \n");
    scanf("%d", &busca_matricula);

    int professor_ativo = -1;

    for(int i = 0; i < qtd_professor; i++) {

        if(professores[i].matricula == busca_matricula) {

            professor_ativo = i;

            break;
        }
    }

    if(professor_ativo != -1) {

        printf("Digite o novo nome: \n");
        scanf("%s", professores[professor_ativo].dados.nome);

        printf("Digite o CPF do professor: \n");
        scanf("%s", professores[professor_ativo].dados.cpf);

        printf("Digite a data de nascimento do(a) professor(a): \n");
        scanf("%s", professores[professor_ativo].dados.data_nasc);

        printf("Digite o sexo do(a) professor(a): \n");
        scanf("%s", professores[professor_ativo].dados.sexo);

        printf("Digite a matricula do professor: \n");
        scanf("%d", &professores[professor_ativo].matricula);

        return CAD_SUCESSO;
    }

    else {

        return MATRICULA_IVALIDA;
    }
}

int atualizarProfessorDiciplina(
    professor professores[],
    int qtd_professor,
    diciplina diciplinas[],
    int qtd_diciplina
 ) {

    int busca_materia;
    int busca_matricula;
    int guarda_matricula;
    int materia_encontrada = INFORMACAO_INVALIDA;

    printf("---Atualizar professor(a) da Diciplina---\n");

    do {

        printf("Digite o código da Máteria: \n");
        scanf("%d", &busca_materia);

        for(int i = 0; i < qtd_diciplina; i++) {

            if(busca_materia == diciplinas[i].codigo) {

                guarda_matricula = i;
                materia_encontrada = 1;

                printf("Matéria: %s\n",
                       diciplinas[i].nome);

                break;
            }
        }

        if(materia_encontrada == INFORMACAO_INVALIDA) {

            printf("Matéria não encontrada\n");

        }

    } while(materia_encontrada == INFORMACAO_INVALIDA);


    int professor_ativo = INFORMACAO_INVALIDA;

    while(professor_ativo == INFORMACAO_INVALIDA) {

        printf("********************************\n");
        printf("Professores disponíveis na instituição\n");
        printf("********************************\n");

        imprimeProfessor(professores, qtd_professor);

        printf("Digite a matrícula do(a) novo(a) professor(a): \n");
        scanf("%d", &busca_matricula);

        for(int i = 0; i < qtd_professor; i++) {

            if(professores[i].matricula == busca_matricula) {

                diciplinas[guarda_matricula].matricula_professor =
                    busca_matricula;

                professor_ativo = CAD_SUCESSO;

                break;
            }
        }

        if(professor_ativo == INFORMACAO_INVALIDA) {

            printf("Matrícula não encontrada. Tente novamente\n");

        }
    }

    return CAD_SUCESSO;
}



int validarNome(char nome[]) {

    for(int i = 0; nome[i] != '\0'; i++) {

        if(nome[i] >= '0' && nome[i] <= '9') {

            return NOME_INVALIDO;

        }
    }

    return CAD_SUCESSO;
}

int validarCPF(char cpf[]) {

    int tamanho = 0;

    for(int i = 0; cpf[i] != '\0'; i++) {

        if(cpf[i] >= '0' && cpf[i] <= '9') {

            tamanho++;

        }

        else if(cpf[i] != '.' && cpf[i] != '-') {

            return INFORMACAO_INVALIDA;

        }
    }

    if(tamanho != 11) {

        return INFORMACAO_INVALIDA;

    }

    return CAD_SUCESSO;
}
int validaDataNasc(char data_nasc[]){

    int dia;
    int mes;
    int tamanho = strlen(data_nasc);

    if(tamanho != 10){
        return INFORMACAO_INVALIDA;
    }
    if(data_nasc[2] != '/' || data_nasc[5] != '/'){
        return INFORMACAO_INVALIDA;
    }

    for(int i = 0; i < 10; i++){

        if(i == 2 || i == 5){
            continue;
        }

        if(data_nasc[i] < '0' || data_nasc[i] > '9'){
            return INFORMACAO_INVALIDA;
        }

    }
    dia = (data_nasc[0] - '0') * 10 + (data_nasc[1] - '0');
    mes = (data_nasc[3] - '0') * 10 + (data_nasc[4] - '0');

    if(dia < 1 || dia > 31){
        return INFORMACAO_INVALIDA;
    
    }
    if(mes < 1 || mes > 12){
        return INFORMACAO_INVALIDA;
    }
    return CAD_SUCESSO;
}


// particularidades de modulo diciplina

int CadastrarAlunoDiciplina(
    diciplina diciplinas[],
    int qtd_diciplina,
    aluno alunos[],
    int qtd_aluno
 ) {

    int busca_matricula;
    int busca_materia;

    int materia_encontrada = INFORMACAO_INVALIDA;
    int aluno_ativo = INFORMACAO_INVALIDA;
    int vaga_encontada = LISTA_CHEIA;

    printf("---Cadastarar aluno na diciplina---\n");


    do {

        printf("Digite o código da Matéria na qual deseja cadastrar o aluno(a): \n");
        scanf("%d", &busca_materia);

        for(int i = 0; i < qtd_diciplina; i++) {

            if(diciplinas[i].codigo == busca_materia) {

                materia_encontrada = i;

                break;
            }
        }

        if(materia_encontrada == INFORMACAO_INVALIDA) {

            printf("Matéria não encontrada. Tente novamente\n");

        }

    } while(materia_encontrada == INFORMACAO_INVALIDA);


    printf("******************\n");
    printf("Matéria: %s\n",
           diciplinas[materia_encontrada].nome);
    printf("******************\n");


    do {

        printf("Digite a matrícula do aluno que deseja cadastrar na diciplina: \n");
        scanf("%d", &busca_matricula);

        for(int i = 0; i < qtd_aluno; i++) {

            if(alunos[i].matricula == busca_matricula) {

                for(int j = 0; j < TAM_ALUNO; j++) {

                    if(diciplinas[materia_encontrada].matricula_aluno[j] == 0) {

                        diciplinas[materia_encontrada].matricula_aluno[j] =
                            busca_matricula;

                        aluno_ativo = CAD_SUCESSO;
                        vaga_encontada = CAD_SUCESSO;

                        break;
                    }
                }

                break;
            }
        }

        if(aluno_ativo == INFORMACAO_INVALIDA) {

            printf("Matrícula não encontrada\n");

        }

        else if(vaga_encontada == LISTA_CHEIA) {

            return LISTA_CHEIA;
        }

    } while(aluno_ativo == INFORMACAO_INVALIDA);


    return CAD_SUCESSO;
}

void imprimeAlunosDiciplina(diciplina diciplinas[], int qtd_diciplina, aluno alunos[]) {

    int busca_matricula;

    for(int i = 0; i < qtd_diciplina; i++) {

        printf("------------------------------------\n");
        printf("Matéria - %s\n", diciplinas[i].nome);
        printf("------------------------------------\n");


        for(int j = 0; j < TAM_ALUNO; j++) {

            busca_matricula =
                diciplinas[i].matricula_aluno[j];


            for(int k = 0; k < TAM_ALUNO; k++) {

                if(alunos[k].matricula == busca_matricula) {

                    printf("Aluno(a): %s\n",
                           alunos[k].dados.nome);
                }
            }
        }
    }
}

void ordenaAluno(aluno alunos[], int qtd_aluno){
    aluno temporario;

    for(int i = 0; i < qtd_aluno - 1; i++ ){

        for(int j = 0; j < qtd_aluno - 1; j++ ){

            if(strcmp(alunos[j].dados.nome, alunos[j+1].dados.nome) > 0){

                aluno temporario = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = temporario;

            }
        }
    }
}

void ordenaProfessor(professor professores[], int qtd_professor){
    professor temporario;

    for(int i = 0; i < qtd_professor - 1; i++ ){

        for(int j = 0; j < qtd_professor - 1; j++ ){

            if(strcmp(professores[j].dados.nome, professores[j+1].dados.nome) > 0){

                professor temporario = professores[j];
                professores[j] = professores[j+1];
                professores[j+1] = temporario;

            }
        }
    }
}

int excluirAlunoDiciplina(diciplina diciplinas[]){

    int busca_matricula;
    int aluno_ativo = 0;
    int busca_materia;
    int materia_ativa = 0;

    printf("Digite o código da matéria na qual o aluno(a) está: \n");
    scanf("%d", &busca_materia);


    for(int i = 0; i < TAM_DICIPLINA; i++){

        if(busca_materia == diciplinas[i].codigo){
            materia_ativa = 1;

            printf("Digite qual a matrícula do aluno que deseja excluir: \n");
            scanf("%d", &busca_matricula);

            for(int j = 0; j < TAM_ALUNO; j++){

                if(busca_matricula == diciplinas[i].matricula_aluno[j]){
                    aluno_ativo = 1;

                    for(int k = j; k < TAM_ALUNO - 1; k++){

                        diciplinas[i].matricula_aluno[k] = diciplinas[i].matricula_aluno[k + 1];

                        diciplinas[i].matricula_aluno[TAM_ALUNO - 1] = 0;
                    }
                    return CAD_SUCESSO;
                }
            }
        }
    }
    if(materia_ativa == 0){
        return INFORMACAO_INVALIDA;
    }
    if(aluno_ativo == 0){
        return MATRICULA_IVALIDA;
    }
}

void imprimeAlunosAniversariantes(aluno alunos[], int qtd_aluno){

    char mes_escrito[12][20] = {"Janeiro",
                        "Fevereiro",
                        "Março",
                        "Abril",
                        "Maio",
                        "Junho",
                        "Julho",
                        "Agosto",
                        "Setembro",
                        "Outubro",
                        "Novembro",
                        "Dezembro"};

    for(int mes_num = 1; mes_num <= 12; mes_num++){

    printf("------------\n");
    printf("%s: \n", mes_escrito[mes_num - 1]);
    printf("------------\n"); 

    for(int i = 0; i < qtd_aluno; i++){

        int mes_nasc = (alunos[i].dados.data_nasc[3] - '0') * 10 + (alunos[i].dados.data_nasc[4] - '0');
        
        if(mes_nasc == mes_num){

            printf("Aluno(a): %s\n", alunos[i].dados.nome);
            printf("Data de nascimento: %s\n", alunos[i].dados.data_nasc);
            }
        }
    }
}
