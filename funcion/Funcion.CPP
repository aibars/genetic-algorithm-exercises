/*
Hacer un Algoritmo Genetico para buscar el máximo de la siguiente función: f(x)=(x/k)2, k=230 – 1.
Crossover: 0.75
Mutación:0.05
Población incial: 10
Ciclos: 20
Método de selección: Ruleta
Método de Crossover: Un punto
Método de mutación: Estandar
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define K 1073741823

void aleatorio();
void conver();
void supramax();
void ruleta();
void crossover();
void mutation();
int bin[10][30];
int bin2[10][30];
float num2[10];
float prob[10];
float func[10];
int probmil[10];
int rule[1000];
int ind[10];
int selec[10];
int probcros[100];
int auxbin[30];
int probm[100];
void main()
{
  int i, y;

  srand(time(0));
  clrscr();
  printf("Numeros aleatorios en Binario: \n");
  aleatorio();
  getche();
  printf("Numeros Convertidos: \n");
  for (y = 0; y < 20; y++)
  {
    randomize();
    clrscr();

    for (i = 0; i < 30; i++)
      auxbin[i] = 0;
    for (i = 0; i < 1000; i++)
      rule[i] = -1;
    for (i = 0; i < 10; i++)
    {
      num2[i] = 0;
      func[i] = 0;
      prob[i] = 0;
    }
    conver();
    getche();
    printf("Maximo, promedio y probabilidad \n");
    supramax();
    getche();
    ruleta();
    printf("Crossover: \n");
    crossover();
    getche();
    printf("Mutacion: \n");
    mutation();
    getche();
  }
}
void aleatorio()
{
  int i, j;
  printf("10 numeros generados aleatoriamente: \n\n");
  for (i = 0; i < 10; i++)
  {
    for (j = 0; j < 30; j++)
    {
      bin[i][j] = rand() % 2;
      printf("%d ", bin[i][j]);
    }
    printf("\n");
  }
}

void conver()
{
  int i, j, u, h;
  float sum, num;

  for (i = 0; i < 10; i++)
  {
    sum = 0;
    u = 0;
    for (j = 30; j >= 0; j--)
    {

      num = 1;
      if (bin[i][j] == 1)
      {
        if (u == 0)
          num = 1;
        if (u == 1)
          num = 2;
        if (u > 1)
          for (h = 0; h < u; h++)
            num = num * 2;
      }

      else
        num = 0;

      sum = sum + num;
      u++;
    }
    num2[i] = sum;
    printf("%f\n", num2[i]);
  }
}

void supramax()
{
  int i;
  float prom = 0, max = 0, sumat = 0, sumap = 0;
  for (i = 0; i <= 10; i++)
  {
    func[i] = ((num2[i] / K) * (num2[i] / K));
  }
  for (i = 0; i <= 10; i++)
  {
    if (max < func[i])
    {
      max = func[i];
    }
    sumat = sumat + func[i];
  }
  printf("Suma func %f\n", sumat);
  prom = sumat / 10;
  for (i = 0; i < 10; i++)
  {
    prob[i] = func[i] / sumat;
    sumap = sumap + prob[i];
    printf("Funcion %f probabilidad %f\n", func[i], prob[i]);
  }
  printf("Promedio %f maximo %f sumaprom %f \n", prom, max, sumap);
}

void ruleta()
{
  int i, j, z, x, ran, sumpromil = 0;

  for (i = 0; i < 10; i++)
  {
    probmil[i] = prob[i] * 1000;
    sumpromil = sumpromil + probmil[i];
    printf("%d\n ", probmil[i]);
  }

  for (i = 0; i < 10; i++)
  {
    j = probmil[i];
    for (x = 0; x < j; x++)
    {
      do
      {
        ran = rand() % 1000;
      } while (rule[ran] != -1);
      if (rule[ran] == -1)
        rule[ran] = i;
    }
  }

  // for(i=0; i<1000; i++)
  //  printf("%d ", rule[i]);
  printf("\n");

  for (i = 0; i < 10; i++)
  {
    ind[i] = rand() % 1000;
    if (rule[ind[i]] != -1)
      selec[i] = rule[ind[i]];
    printf("%d ", selec[i]);
  }
  printf("%d", sumpromil);
}
void crossover()
{
  int corte, x, i, j, ran;
  printf("\n");
  for (i = 0; i < 10; i++)
  {
    for (j = 0; j < 30; j++)
    {
      bin2[i][j] = bin[selec[i]][j];
      printf("%d", bin2[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < 75; i++)
    probcros[i] = 1;
  for (i = 75; i < 100; i++)
    probcros[i] = 0;

  for (i = 0; i < 10; i++)
  {
    ran = rand() % 100;
    if (probcros[ran] == 1)
    {
      corte = rand() % 30;
      printf("%d ", corte);
      for (x = corte; x < 30; x++)
      {
        auxbin[x] = bin2[i][x];
        bin2[i][x] = bin2[i + 1][x];
        bin2[i + 1][x] = auxbin[x];
        printf(".%d", auxbin[x]);
      }
    }

    printf("crossover\n");
    for (x = 0; x < 30; x++)
      printf("%d", bin2[i][x]);
    printf("\n");
    for (x = 0; x < 30; x++)
      printf("%d", bin2[i + 1][x]);
    printf("\n");
    i++;
  }
}

void mutation()
{
  int i, x, ran = 0, corte = 0;

  for (i = 0; i < 94; i++)
    probm[i] = 0;
  for (i = 95; i < 100; i++)
    probm[i] = 1;

  for (i = 0; i < 10; i++)
  {
    ran = rand() % 100;
    if (probm[ran] == 1)
    {
      corte = rand() % 30;
      printf("%d ", corte);
      for (x = corte; x < 30; x++)
      {
        if (bin2[i][x] == 0)
          bin2[i][x] = 1;
        else
          bin2[i][x] = 0;
        printf(".%d", bin2[i][x]);
      }
    }
    printf("\n");
    printf("Mutacion ");
    for (x = 0; x < 30; x++)
    {
      printf("%d", bin2[i][x]);
      bin[i][x] = bin2[i][x];
    }
  }
}