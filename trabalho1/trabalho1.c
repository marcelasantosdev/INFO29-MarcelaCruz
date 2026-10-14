// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Marcela Santos
//  Email: marcelaofficial1.0@gmail.com
//  Matrícula: 20261160034
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
    DataQuebrada dq;
    int ano_bissexto = 0;

    dq = quebraData(data);

    if (dq.valido == 0) {
        return 0;
    }

    if (dq.iDia < 1 || dq.iDia > 31 ||
        dq.iMes < 1 || dq.iMes > 12 ||
        dq.iAno == 0) {
        return 0;
    }

    if ((dq.iMes == 4 || dq.iMes == 6 ||
         dq.iMes == 9 || dq.iMes == 11) &&
        dq.iDia == 31) {
        return 0;
    }

    if (dq.iMes == 2 && dq.iDia > 29) {
        return 0;
    }

    if ((dq.iAno % 4 == 0 && dq.iAno % 100 != 0) ||
        dq.iAno % 400 == 0) {
        ano_bissexto = 1;
    }

    if (dq.iMes == 2 && dq.iDia == 29 &&
        ano_bissexto == 0) {
        return 0;
    }

    return 1;
}
  //printf("%s\n", data);




/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
 
int diasNoMes(int mes, int ano){
          
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    }

    if (mes == 2) {
        if ((ano % 4 == 0 && ano % 100 != 0) ||
            ano % 400 == 0) {
            return 29;
        }

        return 28;
    }

    return 31;
}
 
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
    DiasMesesAnos dma;
    DataQuebrada inicial, final;

    int mesAnterior;
    int anoMesAnterior;

    dma.qtdDias = 0;
    dma.qtdMeses = 0;
    dma.qtdAnos = 0;
    dma.retorno = 0;

    if (q1(datainicial) == 0) {
        dma.retorno = 2;
        return dma;
    }

    if (q1(datafinal) == 0) {
        dma.retorno = 3;
        return dma;
    }

    // Para quebrar as datas 
    inicial = quebraData(datainicial);
    final = quebraData(datafinal);

    //verifique se a data final não é menor que a data inicial    
        if (inicial.iAno > final.iAno ||
        (inicial.iAno == final.iAno &&
         inicial.iMes > final.iMes) ||
        (inicial.iAno == final.iAno &&
         inicial.iMes == final.iMes &&
         inicial.iDia > final.iDia)) {

        dma.retorno = 4;
        return dma;
    }

    // Calcular inicialmente a diferença
    dma.qtdAnos = final.iAno - inicial.iAno;
    dma.qtdMeses = final.iMes - inicial.iMes;
    dma.qtdDias = final.iDia - inicial.iDia;

    // Se os dias ficarem negativos -> pegar um mês emprestado 
    if (dma.qtdDias < 0) {

        mesAnterior = final.iMes - 1;
        anoMesAnterior = final.iAno;

        if (mesAnterior == 0) {
            mesAnterior = 12;
            anoMesAnterior--;
        }

        dma.qtdDias += diasNoMes(mesAnterior, anoMesAnterior);
        dma.qtdMeses--;
    }

    /* Se os meses ficaram negativos, pegar um ano emprestado!
     ex.: mes final -> 2 de 2025 e mes inicial -> 12 de 2024 = - 10 e 1 ano, somando
     12 a -10 e diminuindo 1  do ano fica com resultado 2 meses */
     
    if (dma.qtdMeses < 0) {
        dma.qtdMeses += 12;
        dma.qtdAnos--;
    }

    // se tudo der certo
    dma.retorno = 1;

    return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = -1;
    char sensitiveC = 0;
    
    /*if(isCaseSensitive != 1){
        if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e'
        || c == 'f' || c == 'g' || c ==  'h' || c == 'i' || c == 'j' 
        || c ==  'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' 
        || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' 
        || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z'){
           sensitiveC = c + 32; 
        }
        else if(c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E'
        || c == 'F' || c == 'G' || c ==  'H' || c == 'I' || c == 'J' 
        || c ==  'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' 
        || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' 
        || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z'){
           sensitiveC = c - 32; 
    } */
    
    if(isCaseSensitive != 1){
        if (c >= 97 || c <= 122){
           sensitiveC = c - 32; 
        }
    }
    else if (c >= 65 || c <= 90){
           sensitiveC = c + 32; 
        }
        
    qtdOcorrencias = 0;
    if(isCaseSensitive != 1){
        for(int i = 0; texto[i] != '\0'; i++){
            if( texto[i] == c || texto[i] == sensitiveC){
            qtdOcorrencias++;
            }
        }
    }
    if(isCaseSensitive){
        for(int i = 0; texto[i] != '\0'; i++){
            if( texto[i] == c){
            qtdOcorrencias++;
            }
        }
    } 
    

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
    
int q4(char texto[], char palavra[], int posicoes[]) {
    int igual = 1;
    int qtdOcorrencias = 0;
    int k;

    char modificaPalavra[250];
    char modificaTexto[250];

    // Limpa e converte a palavra para minúscula
    for(k = 0; palavra[k] != '\0'; k++) {
        modificaPalavra[k] = palavra[k];
        if(modificaPalavra[k] >= 65 && modificaPalavra[k] <= 90) {
            modificaPalavra[k] = modificaPalavra[k] + 32;
        }
    }
    modificaPalavra[k] = '\0';

    // Limpa e converte o texto para minúscula
    for(k = 0; texto[k] != '\0'; k++) {
        modificaTexto[k] = texto[k];
        if(modificaTexto[k] >= 65 && modificaTexto[k] <= 90) {
            modificaTexto[k] = modificaTexto[k] + 32;
        }
    }
    modificaTexto[k] = '\0';

    int i = 0;
    int char_pos = 1; // Contador da posição real do caractere para o vetor posicoes[]

    while(modificaTexto[i] != '\0') {
        if(modificaPalavra[0] == modificaTexto[i] || modificaTexto[i] < 0) {
            igual = 1;
            int temp_i = i;

            for(int j = 0; modificaPalavra[j] != '\0'; j++) {
                if(modificaTexto[temp_i] == '\0') {
                    igual = 0;
                    break;
                }

                // Se for acento, muda na comparação; senão, compara normal
                if(modificaTexto[temp_i] < 0) {
                    temp_i += 2; // Pula o acento na verificação
                } else {
                    if(modificaPalavra[j] != modificaTexto[temp_i]) {
                        igual = 0;
                        break;
                    }
                    temp_i += 1;
                }
            }

            if(igual == 1) {
                posicoes[qtdOcorrencias * 2] = char_pos;
                posicoes[qtdOcorrencias * 2 + 1] = char_pos;

                int tamanho_palavra = 0;
                for(int j = 0; modificaPalavra[j] != '\0'; j++) {
                    tamanho_palavra++;
                }

                posicoes[qtdOcorrencias * 2 + 1] = char_pos + tamanho_palavra - 1;
                qtdOcorrencias++;
            }
        }

        // CHAMANDO A FUNÇÃO (avanca_posicao) AQUI
        i += avanca_posicao(modificaTexto, i);
        
        char_pos++; // Avança a contagem da letra real
    }

    return qtdOcorrencias;
}


/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int digito, invertido = 0;
  
    while(num != 0){
    digito = num % 10;
    num = num / 10;
    invertido = (invertido * 10) + digito;
}

    return invertido;
}


/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */


int q6(int num, int digito) {
    
    int qtdOcorrencia = 0;
    int i, c;
    int igual;
    int casas = 0;
    int aux;

    char numero[20];
    char sequencia[20];

    i = 0;
    while(num > 0) {
        numero[i] = num % 10 + '0';
        num = num / 10;
        i++;
    }

    numero[i] = '\0';

    for(c = 0; c < i / 2; c++) {
        aux = numero[c];
        numero[c] = numero[i - 1 - c];
        numero[i - 1 - c] = aux;
    }

    i = 0;
    while(digito > 0) {
        sequencia[i] = digito % 10 + '0';
        digito = digito / 10;
        i++;
    }

    sequencia[i] = '\0';

    for(c = 0; c < i / 2; c++) {
        aux = sequencia[c];
        sequencia[c] = sequencia[i - 1 - c];
        sequencia[i - 1 - c] = aux;
    }

    while(sequencia[casas] != '\0') {
        casas++;
    }

    for(i = 0; numero[i] != '\0'; i++) {
        igual = 1;

        for(c = 0; c < casas; c++) {
            if(numero[i + c] == '\0' ||
               numero[i + c] != sequencia[c]) {
                igual = 0;
                break;
            }
        }

        if(igual) {
            qtdOcorrencia++;
        }
    }

    return qtdOcorrencia;
}
    
/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */


int q7(char matriz[8][10], char palavra[]){

    int i, j, k, sentido;
    int novaLinha, novaColuna;
    int igual;
    int tamanho = 0;
    int achou = 0;

    int linhas[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colunas[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while(palavra[tamanho] != '\0'){
        tamanho++;
    }

    for(i = 0; i < 8; i++){

        for(j = 0; j < 10; j++){

            for(sentido = 0; sentido < 8; sentido++){

                igual = 1;

                for(k = 0; k < tamanho; k++){

                    novaLinha = i + k * linhas[sentido];
                    novaColuna = j + k * colunas[sentido];

                    if(novaLinha < 0 || novaLinha >= 8 ||
                       novaColuna < 0 || novaColuna >= 10){

                        igual = 0;
                        break;
                    }

                    if(matriz[novaLinha][novaColuna] != palavra[k]){
                        igual = 0;
                        break;
                    }
                }

                if(igual == 1){
                    achou++;
                }
            }
        }
    }

    return achou;
}


DataQuebrada quebraData(char data[]) {

    DataQuebrada dq;

    int pos1 = -1, pos2 = -1;
    int tamanho_dia, tamanho_mes, tamanho_ano;
    int i;

    dq.iDia = 0;
    dq.iMes = 0;
    dq.iAno = 0;
    dq.valido = 0;

    // Procurar a primeira barra
    for(i = 0; data[i] != '\0'; i++) {
        if(data[i] == '/') {
            pos1 = i;
            break;
        }
    }

    if(pos1 == -1) {
        return dq;
    }

    // Procurar a segunda barra
    for(i = pos1 + 1; data[i] != '\0'; i++) {
        if(data[i] == '/') {
            pos2 = i;
            break;
        }
    }

    if(pos2 == -1) {
        return dq;
    }

    // Calcular os tamanhos
    tamanho_dia = pos1;
    tamanho_mes = pos2 - pos1 - 1;

    tamanho_ano = 0;

    for(i = pos2 + 1; data[i] != '\0'; i++) {
        tamanho_ano++;
    }

    // Verificar os tamanhos permitidos
    if((tamanho_dia != 1 && tamanho_dia != 2) ||
       (tamanho_mes != 1 && tamanho_mes != 2) ||
       (tamanho_ano != 2 && tamanho_ano != 4)) {
        return dq;
    }

    // Verificar se o dia contém apenas números
    for(i = 0; i < pos1; i++) {
        if(data[i] < '0' || data[i] > '9') {
            return dq;
        }
    }

    // Verificar se o mês contém apenas números
    for(i = pos1 + 1; i < pos2; i++) {
        if(data[i] < '0' || data[i] > '9') {
            return dq;
        }
    }

    // Verificar se o ano contém apenas números
    for(i = pos2 + 1; data[i] != '\0'; i++) {
        if(data[i] < '0' || data[i] > '9') {
            return dq;
        }
    }

    // Converter o dia para inteiro
    for(i = 0; i < pos1; i++) {
        dq.iDia = dq.iDia * 10 + (data[i] - '0');
    }

    // Converter o mês para inteiro
    for(i = pos1 + 1; i < pos2; i++) {
        dq.iMes = dq.iMes * 10 + (data[i] - '0');
    }

    // Converter o ano para inteiro
    for(i = pos2 + 1; data[i] != '\0'; i++) {
        dq.iAno = dq.iAno * 10 + (data[i] - '0');
    }

    dq.valido = 1;

    return dq;
}

int avanca_posicao(char str[], int i) {
    
    // No UTF-8, se o byte for menor que 0, é um caractere acentuado (ocupa 2 bytes)
    if (str[i] < 0) {
        return 2; // Pula 2 bytes
    }
    return 1;     // Pula 1 byte normal
}
