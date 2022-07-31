//Data: 01/12/2020
//Autor: Vitor Caligaris Figueira
//Titulo: Avaliacao Ciclo 10
#include <math.h>
#include <stdio.h>
#include<stdlib.h>

typedef struct {
    int n; // numerador
    int d; // denominador
} tRacional;


int mdc(int a, int b){//Funcao auxiliar do programa que calcula o MDC entre 2 inteiros.
    int i, maxDiv;
    for(i=1; i <= a && i <= b; i++){//Percorra todos os numeros ate o resto da divisao de i pelos 2 numeros seja 0.
        if(a%i==0 && b%i==0)
            maxDiv = i;//Quando a condicao for cumprida salve o valor como MDC.
    }
    return maxDiv;//Retorne o valor do MDC
}


int mmc(int a, int b){//Funcao auxiliar do programa que calcula o MMC entre 2 inteiros.
    int minMult;
    minMult = abs(a*b)/mdc(a, b);//Formula para calculo do MMC a partir do MDC.
    return minMult;//Retorne o valor do MMC.
}

tRacional simplifica(tRacional t){//Funcao auxiliar do programa que simplifica um numero racional.
    tRacional s;
    int aux;
    aux = mdc(abs(t.n), t.d);//Aux eh o MDC entre o numerador e o denominador do numero racional a ser simplificado.
    s.n = t.n/aux;//Obter o numerador simplificado dividindo o numerador pelo aux.
    s.d = t.d/aux;//Obter o denominador simplificado dividindo o denominador pelo aux.
    return s;
}


tRacional leiaRacional(){//Funcao que le um numero racional e simplifica caso necessario.
    tRacional t;
    int aux;
    printf("Insira o numerador do racional:");//Pergunte pelo numerador do numero racional.
    scanf("%d", &t.n);
    printf("Insira o numerador do denominador:");//Pergunte pelo denominador do numero racional.
    scanf("%d", &t.d);
    //Simplifique o numero racional obtido na propria rotina de leitura:
    aux = mdc(t.n, t.d);//Aux eh o MDC entre o numerador e o denominador do numero racional a ser simplificado.
    t.n = t.n/aux;//Obter o numerador simplificado dividindo o numerador pelo aux.
    t.d = t.d/aux;//Obter o denominador simplificado dividindo o denominador pelo aux.
    return t;//Retorne o numero racional que foi lido e simplificado.
}


void printRacional(tRacional t){//Procedimento que printa um numero racional em forma fracionaria.
    printf("%d/%d\n", t.n, t.d);//Print da forma fracionaria
}


tRacional somaRacional(tRacional x, tRacional y){//Funcao que soma dois numeros racionais.
    tRacional soma;
    int den, novoNum1, novoNum2;
    den = mmc(x.d, y.d);//Calculo do denominador da soma atraves do MMC entre os denominadores dos 2 numeros racionais escolhidos.
    novoNum1 = x.n * (den/x.d);//Calculo do novo numerador do primeiro numero.
    novoNum2 = y.n * (den/y.d);//Calculo do novo numerador do segundo numero.
    soma.n = novoNum1 + novoNum2;//Numerador da soma eh a soma dos 2 novos numeradores.
    soma.d = den;//Denominador da soma ja calculado.
    return soma;//Retorne o numero racional resultante da soma.
}


tRacional subtracaoRacional(tRacional x, tRacional y){//Funcao que subtrai dois numeros racionais.
    tRacional sub;
    int den, novoNum1, novoNum2;
    den = mmc(x.d, y.d);//Calculo do denominador da subtração atraves do MMC entre os denominadores dos 2 numeros racionais escolhidos.
    novoNum1 = x.n * (den/x.d);//Calculo do novo numerador do primeiro numero.
    novoNum2 = y.n * (den/y.d);//Calculo do novo numerador do segundo numero.
    sub.n = novoNum1 - novoNum2;//Numerador da subtração eh a subtração dos 2 novos numeradores.
    sub.d = den;//Denominador da subtração ja calculado.
    return sub;//Retorne o numero racional resultante da subtração.
}


tRacional produtoRacional(tRacional x, tRacional y){//Funcao que multiplica dois numeros racionais.
    tRacional mult;
    mult.n = x.n * y.n;//Numerador da multiplicação eh a multiplicação dos numeradores.
    mult.d = x.d * y.d;//Denominador da multiplicação eh a multiplicação dos denominadores.
    return mult;//Retorne o numero racional que eh o produto.
}


tRacional divisaoRacional(tRacional x, tRacional y){//Funcao que divide dois numeros racionais.
    tRacional divi;
    divi.n = x.n * y.d;//Numerador da divisão eh a multiplicação entre o numerador do primeiro e o denominador do segundo.
    divi.d = x.d * y.n;//Denominador da divisão eh a multiplicação entre o denominador do primeiro e o numerador do segundo.
    return divi;//Retorne o numero racional resultado da divisao.
}


int main()//Codigo principal:
{
    //Secao de declaracao
    tRacional r1, r2;
    
    //Secao de comandos e apresentacao de resultados
    printf("Insira os dados do primeiro numero racional(r1):\n");//Pergunte pelo primeiro numero racional.
    r1 = leiaRacional();//Leia o primeiro numero racional
    printf("Insira os dados do segundo numero racional(r2):\n");//Pergunte pelo segundo numero racional.
    r2 = leiaRacional();//Leia o segundo numero racional
    printf("r1 = ");
    printRacional(r1);//Escreva o racional r1.
    printf("r2 = ");
    printRacional(r2);//Escreva o racional r2.
    
    printf("\nResultados:\n");
    printf("Soma de r1 e r2 (r1+r2): ");
    printRacional(simplifica(somaRacional(r1, r2)));//Escreva a soma de r1 e r2(racionais) simplificada definidos pelo usuario.
    printf("Subtração entre r1 e r2 (r1-r2): ");
    printRacional(simplifica(subtracaoRacional(r1, r2)));//Escreva a subtração de r1 e r2(racionais) simplificada definidos pelo usuario.
    printf("Multiplicação entre r1 e r2 (r1*r2): ");
    printRacional(simplifica(produtoRacional(r1, r2)));//Escreva a multiplicação de r1 e r2(racionais) simplificada definidos pelo usuario.
    printf("Divisão entre r1 e r2 (r1/r2): ");
    printRacional(simplifica(divisaoRacional(r1, r2)));//Escreva a divisao de r1 e r2(racionais) simplificada definidos pelo usuario.
    
    printf("\n\nFIM");
    
    return 0;
}



