#include <stdio.h>
#include <conio.h>
#include <locale.h>
#define S 10

void metodo_quadrados() {
  int n, i;
  float x[S], y[S], sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0, a, b;

  //Entrada de Dados
  do {
    printf("\tDigite a quantidade de pontos: ");
    scanf("%d", & n);
    if (n < 2 || n > 10)
      printf("\tValor inválido! Digite um valor entre 2 e 10.\n");
  } while (n < 2 || n > 10);

  printf("\tDigite as coordenadas:\n");

  for (i = 1; i <= n; i++) {
    printf("\tx[%d]= ", i-1);
    scanf("%f", & x[i]);
    printf("\ty[%d]= ", i-1);
    scanf("%f", & y[i]);
  }

  for (i = 1; i <= n; i++) {
    sumX = sumX + x[i];
    sumX2 = sumX2 + x[i] * x[i];
    sumY = sumY + y[i];
    sumXY = sumXY + x[i] * y[i];
  }

  //Calculando o valor de a e b
  b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
  a = (sumY - b * sumX) / n;

  //Imprime os valores
  printf("\tSendo assim, temos que o sistema é: \n");
  printf("\t%0.4f * %0.4f + %0.4f * %0.4f = %0.4f\n", a, sumX2, b, sumX, sumXY);
  printf("\t%0.4f * %0.4f + %d * %0.4f = %0.4f\n\n", a, sumX, n, b, sumY);
  printf("\ty=%0.4f * x + %0.4f", a, b);
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  int op;

  do {
    printf("\tMENU PRINCIPAL\t\n\n\t0 - Sair\n\t1 - Método dos mínimos quadrados\n\n\tOpção Desejada: ");
    scanf("%d", & op);

    switch (op) {

    case 0: {
      printf("\n\tDesenvolvido por: Cauê Mendonça Magela do Ó (RGM: 43558)");
      break;
    }

    case 1: {
      metodo_quadrados();
      break;
    }

    default: {
      printf("\n\tOpção Inválida! Tente novamente!");
      break;
    }
    }

    printf("\n\n");
  } while (op != 0);

  return 0;
}