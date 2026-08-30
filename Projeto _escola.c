#include <stdio.h>
int main() {
    int opcao, opcao2;  
    int sair = 0;      
    int sair_aluno = 0;             
    printf("-- Sistema Escolar --\n");
  
    while(sair != 1) {              
    printf("Digite o número de acordo com a opção desejada: \n");       
    printf("1 - Professor\n");         
    printf("2 - Aluno\n");         
    printf("3 - Diciplina\n");                      
    printf("0 - Sair\n");     
    scanf("%d", &opcao);       
      
    switch (opcao) {       
    case 1 : printf("Módulo Professor\n"); break;                     
    case 2 : printf("Módulo Aluno\n"); break;            
    case 3 : printf("Módulo Diciplina\n"); break;              
    case 0 : printf("Programa finalizado\n");       
    sair = 1; break;               
    default : printf("Opção selecionada inválida");        
}}             
  
    return 0;}    
