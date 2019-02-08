/*
Resolver el siguiente problema: A veces planteamos el problema en peso en lugar de volumen. 
Dados 3 elementos, cuyos pesos son: 1800 grs., 600 grs. Y 1200 grs. y cuyos valores son: $72, $36 y $60 respectivamente,
y dado que la mochila puede soportar hasta 3000 grs. se pide:
A) Hallar una solución utilizando un algoritmo goloso.
B) Analizar dicha solución respecto a su grado de optimización y elaborar las conclusiones que considere adecuadas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define VOL 3000
void carga();
void ordenar();
void seleccionar();
float elementos[3][3];
float densidad[3];
float elemento[8];

main()
{
  int i;
  clrscr();
  carga();
  ordenar();
  seleccionar();
  printf("\nElementos seleccionados: \n");
  for (i = 0; i < 2; i++)
    printf("%f\n", elemento[i]);
  getche();
  getche();
}

void carga()
{
  int i;

  for (i = 0; i < 3; i++)
  {
    printf("Ingrese Peso del elemento %d: ", (i + 1));
    scanf("%f", &elementos[i][0]);
    printf("Ingrese Valor del elemento %d: ", (i + 1));
    scanf("%f", &elementos[i][1]);
    elementos[i][2] = ((elementos[i][1]) / (elementos[i][0]));
  }
  for (i = 0; i < 3; i++)
    printf("volumen %f valor %f densidad %f \n", elementos[i][0], elementos[i][1], elementos[i][2]);
}
void ordenar()
{
  float aux[3];
  int i, j, x = 0;

  for (j = 0; j < 3; j++)
  {
    aux[0] = elementos[x][0];
    aux[1] = elementos[x][1];
    aux[2] = elementos[x][2];
    for (i = x; i < 3; i++)
    {
      if (elementos[i][2] > aux[2])
      {
        elementos[x][0] = elementos[i][0];
        elementos[x][1] = elementos[i][1];
        elementos[x][2] = elementos[i][2];
        elementos[i][0] = aux[0];
        elementos[i][1] = aux[1];
        elementos[i][2] = aux[2];
        aux[0] = elementos[x][0];
        aux[1] = elementos[x][1];
        aux[2] = elementos[x][2];
      }
    }
    x++;
  }

  printf("\n");
  for (i = 0; i < 3; i++)
    printf("volumen %f valor %f densidad %f \n", elementos[i][0], elementos[i][1], elementos[i][2]);
}

void seleccionar()
{
  int auxm, min, dif = 3000, i = 0, mochila = 0, precio = 0;
  min = elementos[2][0];
  do
  {
    if (elementos[i][0] < dif)
    {
      mochila = mochila + elementos[i][0];
      precio = precio + elementos[i][1];
      dif = VOL - mochila;
      elemento[i] = elementos[i][0];
      i++;
    }
  } while (dif > min);

  printf("mochila %d precio %d", mochila, precio);
}