#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VOL 4200
void carga();
void ordenar();
void seleccionar();
float elementos[10][3];
float densidad[10];
float elemento[8];

main() {
  int i;
  clrscr();
  carga();
  ordenar();
  seleccionar();
  printf("\nElementos seleccionados: \n");
  for (i = 0; i < 8; i++)
    printf("%f\n", elemento[i]);
  getche();
  getche();
}

void carga() {
  int i;

  for (i = 0; i < 10; i++) {
    printf("Ingrese Volumen del elemento %d: ", (i + 1));
    scanf("%f", &elementos[i][0]);
    printf("Ingrese Valor del elemento %d: ", (i + 1));
    scanf("%f", &elementos[i][1]);
    elementos[i][2] = ((elementos[i][1]) / (elementos[i][0]));
  }
  for (i = 0; i < 10; i++)
    printf("volumen %f valor %f densidad %f \n", elementos[i][0],
           elementos[i][1], elementos[i][2]);
}
void ordenar() {
  float aux[3];
  int i, j, x = 0;

  for (j = 0; j < 10; j++) {
    aux[0] = elementos[x][0];
    aux[1] = elementos[x][1];
    aux[2] = elementos[x][2];
    for (i = x; i < 10; i++) {
      if (elementos[i][2] > aux[2]) {
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
  for (i = 0; i < 10; i++)
    printf("volumen %f valor %f densidad %f \n", elementos[i][0],
           elementos[i][1], elementos[i][2]);
}

void seleccionar() {
  int auxm, min, dif = 4200, i = 0, mochila = 0, precio = 0;
  min = elementos[9][0];
  do {
    if (elementos[i][0] < dif) {
      mochila = mochila + elementos[i][0];
      precio = precio + elementos[i][1];
      dif = VOL - mochila;
      elemento[i] = elementos[i][0];
      i++;
    }
  } while (dif > min);

  printf("mochila %d precio %d", mochila, precio);
}