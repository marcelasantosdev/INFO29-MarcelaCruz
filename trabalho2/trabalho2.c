#include <stdlib.h>
#define TAM_LIMITE_AUX 15

#include "trabalho2.h"

Dados vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int retorno = 0;
    
    // se posição é um valor válido {entre 1 e 10}
    if(posicao < 1 || posicao > TAM) {
    retorno = POSICAO_INVALIDA;
    }
    
    // a posicao pode já existir estrutura auxiliar
    else if(vetorPrincipal[posicao - 1].auxiliar != NULL){
    retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    }
    
    // o tamanho nao pode ser menor que 1
    else if(tamanho < 1){
    retorno = TAMANHO_INVALIDO;
    }
    
    // o tamanho ser muito grande
    else {
        vetorPrincipal[posicao-1].auxiliar = malloc(tamanho * sizeof(int));
        if(vetorPrincipal[posicao-1].auxiliar == NULL){
            retorno = SEM_ESPACO_DE_MEMORIA;
        }
    
    // deu tudo certo, crie
        else{
            vetorPrincipal[posicao-1].tam = tamanho;

            retorno = SUCESSO;
        }
    }
    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Retorno (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    if(posicao < 1 || posicao > TAM ) {
        posicao_invalida = 1;

        if (posicao_invalida)
        retorno = POSICAO_INVALIDA;
        
    }
    else
    {
        // testar se existe a estrutura auxiliar
        if(vetorPrincipal[posicao-1].auxiliar != NULL){
            existeEstruturaAuxiliar = 1;
        }


        if (existeEstruturaAuxiliar)
        {
            if(vetorPrincipal[posicao-1].qtd < vetorPrincipal[posicao-1].tam){
                temEspaco = 1;
            }
            if (temEspaco)
            {
                //insere
                vetorPrincipal[posicao-1].auxiliar[vetorPrincipal[posicao-1].qtd] = valor;
                vetorPrincipal[posicao-1].qtd++;
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte 
forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno;
    
     if(posicao < 1 || posicao > TAM ) {
        retorno = POSICAO_INVALIDA;
        
    } else if(vetorPrincipal[posicao-1].auxiliar == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        
    }
    else if(vetorPrincipal[posicao-1].qtd == 0){
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }
    else {
        // vetorPrincipal[posicao-1].auxiliar[vetorPrincipal[posicao-1].qtd-1] = 0;
        vetorPrincipal[posicao-1].qtd--;
        retorno = SUCESSO;
    }
    
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int achou = 0;
    int retorno;
    
    if(posicao < 1 || posicao > TAM ) {
        retorno = POSICAO_INVALIDA;
    }

    else if(vetorPrincipal[posicao-1].auxiliar == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else if(vetorPrincipal[posicao-1].qtd == 0){
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }
    else {
        for(int i = 0; i < vetorPrincipal[posicao-1].qtd; i++){
            
                if(vetorPrincipal[posicao-1].auxiliar[i] == valor){
                    achou = 1;
                    for(int j = i; j < vetorPrincipal[posicao-1].qtd-1 ; j++){
                       vetorPrincipal[posicao-1].auxiliar[j] = vetorPrincipal[posicao-1].auxiliar[j + 1];
                } 
                vetorPrincipal[posicao-1].qtd--;
                break;
            }
        }
        if(achou){
        retorno = SUCESSO;
        } else{
        retorno = NUMERO_INEXISTENTE;
        }
    }
    
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > TAM)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;
    
    if(posicao < 1 || posicao > TAM ) {
        retorno = POSICAO_INVALIDA;
    }

    else if(vetorPrincipal[posicao-1].auxiliar == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    
    else{
        for(int i = 0; i < vetorPrincipal[posicao-1].qtd; i++){
            vetorAux[i] = vetorPrincipal[posicao-1].auxiliar[i]; 
        }
    retorno = SUCESSO;
    }
    
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;

    if(posicao < 1 || posicao > TAM ) {
        retorno = POSICAO_INVALIDA;
    }

    else if(vetorPrincipal[posicao-1].auxiliar == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else{
        
        for(int i = 0; i < vetorPrincipal[posicao-1].qtd; i++){
            vetorAux[i] = vetorPrincipal[posicao-1].auxiliar[i];
        }    
        
        bubbleSort(vetorAux, vetorPrincipal[posicao-1].qtd);
        retorno = SUCESSO;
    }

    
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;
    
        int k = 0;
        for(int i = 0; i < TAM; i++){
            
            if(vetorPrincipal[i].auxiliar != NULL){
                if(vetorPrincipal[i].qtd != 0){
                    for(int j = 0; j < vetorPrincipal[i].qtd; j++){
                        vetorAux[k] = vetorPrincipal[i].auxiliar[j];
                        k++;
                    }
                }
            }
        }
        if(k == 0){
            retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
        }
        else
        retorno = SUCESSO;
        
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;

    int k = 0;
    for(int i = 0; i < TAM; i++){
        
        if(vetorPrincipal[i].auxiliar != NULL){
                if(vetorPrincipal[i].qtd != 0){
                for(int j = 0; j < vetorPrincipal[i].qtd; j++){
                    vetorAux[k] = vetorPrincipal[i].auxiliar[j];
                    k++;
                }
            }
        }
    }
    if(k == 0){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    else{
        bubbleSort(vetorAux, k);
        retorno = SUCESSO;
    }
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;
    int tamanhoTotal;
    int *auxiliar;
    
    if(posicao < 1 || posicao > TAM ) {
        retorno = POSICAO_INVALIDA;
    }

    else if(vetorPrincipal[posicao-1].auxiliar == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else{
    tamanhoTotal = vetorPrincipal[posicao-1].tam + novoTamanho;

        if(tamanhoTotal < 1){
            retorno = NOVO_TAMANHO_INVALIDO;
        }
        else {
        
            auxiliar = realloc(vetorPrincipal[posicao-1].auxiliar,tamanhoTotal * sizeof(int));
            
            if(auxiliar == NULL){
                retorno = SEM_ESPACO_DE_MEMORIA;
            }
            else{
                vetorPrincipal[posicao-1]. auxiliar = auxiliar;
                vetorPrincipal[posicao-1].tam = tamanhoTotal;
                if(vetorPrincipal[posicao-1].qtd > tamanhoTotal){
                    vetorPrincipal[posicao-1].qtd = tamanhoTotal;
                }
            }
        }
    }
    
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;
    

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    for(int i = 0; i < TAM; i++){
        vetorPrincipal[i].auxiliar = NULL;
        vetorPrincipal[i].qtd = 0;
        vetorPrincipal[i].tam = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
}

void bubbleSort(int arr[], int n) {
    int i, j, auxiliar;
    int flag;
    
    for (i = 0; i < n - 1; i++) {
        flag = 0; 
        
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                
                auxiliar = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = auxiliar;
                flag = 1;
            }
        }
        
        if (flag == 0) {
            break;
        }
    }
}
