#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define VOL 4200

void carga();
void comb3();
void comb4();
void comb5();
void comb6();
void seleccionar();
float elementos[10][3];
float densidad[10];
float auxcomb[10];
float elemento[10];

main()
{
	int i;
	clrscr();
	for (i = 0; i < 10; i++)
		auxcomb[i] = 0;
	carga();
	comb2();
	comb3();
	comb4();
	comb5();
	comb6();
	for (i = 0; i < 5; i++)
		printf("Mejor combinacion tomado de a %d: %f \n", (i + 2), auxcomb[i]);
	printf("Elementos seleccionados: %f\n %f\n %f\n %f\n %f\n %f \n", elemento[0], elemento[1], elemento[2], elemento[3], elemento[4], elemento[5]);
	getche();
	getche();
}

void carga()
{
	int i;

	for (i = 0; i < 10; i++)
	{
		printf("Ingrese Volumen del elemento %d: ", (i + 1));
		scanf("%f", &elementos[i][0]);
		/*	 printf("Ingrese Valor del elemento %d: ",(i+1));
	 scanf("%f",&elementos[i][1]);
	 elementos[i][2]=((elementos[i][1])/(elementos[i][0]));
	 }
   for (i=0;i<10;i++)
       printf("volumen %f valor %f densidad %f \n",elementos[i][0],elementos[i][1],elementos[i][2]);   */
	}
}
void comb2()
{
	int k, j = 0, max = 0;
	for (k = 0; k < 10; k++)
	{
		j = 1;
		j = j + k;
		for (; j <= 10; j++)
		{
			if (elementos[k][0] + elementos[j][0] <= VOL)
				if (elementos[k][0] + elementos[j][0] > max)
				{
					max = elementos[k][0] + elementos[j][0];
					auxcomb[0] = max;
				}
		}
	}
}

void comb3()
{
	int k, i, j = 0, max = 0;
	for (k = 0; k <= 8; k++)
	{
		j = 1;
		j = j + k;
		for (; j <= 9; j++)
		{
			i = 2;
			i = i + j;
			for (; i <= 10; i++)
			{
				if (elementos[k][0] + elementos[j][0] + elementos[i][0] <= VOL)
					if (elementos[k][0] + elementos[j][0] + elementos[i][0] > max)
					{
						max = elementos[k][0] + elementos[j][0] + elementos[i][0];
						auxcomb[1] = max;
					}
			}
		}
	}
}

void comb4()
{
	int k, i, n, j = 0, max = 0;
	for (k = 0; k <= 7; k++)
	{
		j = 1;
		j = j + k;
		for (; j <= 8; j++)
		{
			i = 1;
			i = i + j;
			for (; i <= 9; i++)
			{
				n = 2;
				n = n + i;
				for (; n <= 10; n++)
				{
					if (elementos[k][0] + elementos[j][0] + elementos[i][0] + elementos[n][0] <= VOL)
						if (elementos[k][0] + elementos[j][0] + elementos[i][0] + elementos[n][0] > max)
						{
							max = elementos[k][0] + elementos[j][0] + elementos[i][0] + elementos[n][0];
							auxcomb[2] = max;
						}
				}
			}
		}
	}
}
void comb5()
{
	int k, i, n, m, j = 0, max = 0;
	for (k = 0; k <= 6; k++)
	{
		j = 1;
		j = j + k;
		for (; j <= 7; j++)
		{
			i = 1;
			i = i + j;
			for (; i <= 8; i++)
			{
				n = 1;
				n = n + i;
				for (; n <= 9; n++)
				{
					m = 2;
					m = m + n;
					for (; m <= 10; m++)
					{
						if (elementos[k][0] + elementos[j][0] + elementos[i][0] + elementos[n][0] + elementos[m][0] <= VOL)
							if (elementos[k][0] + elementos[j][0] + elementos[i][0] + elementos[n][0] + elementos[m][0] > max)
							{
								max = elementos[k][0] + elementos[j][0] + elementos[i][0] + elementos[n][0] + elementos[m][0];
								auxcomb[3] = max;
							}
					}
				}
			}
		}
	}
}

void comb6()
{
	int k, i, n, m, j, l, max = 0;
	for (k = 0; k <= 5; k++)
	{
		j = 1;
		j = j + k;
		for (; j <= 6; j++)
		{
			i = 1;
			i = i + j;
			for (; i <= 7; i++)
			{
				n = 1;
				n = n + i;
				for (; n <= 8; n++)
				{
					m = 1;
					m = m + n;
					for (; m <= 9; m++)
					{
						l = 1;
						l = l + m;
						for (; l <= 10; l++)
						{
							if (elementos[k][0] + elementos[j][0] + elementos[i][0] + elementos[n][0] + elementos[m][0] + elementos[l][0] <= VOL)
								if (elementos[k][0] + elementos[j][0] + elementos[i][0] + elementos[n][0] + elementos[m][0] + elementos[l][0] > max)
								{
									elemento[0] = elementos[k][0];
									elemento[1] = elementos[j][0];
									elemento[2] = elementos[i][0];
									elemento[3] = elementos[n][0];
									elemento[4] = elementos[m][0];
									elemento[5] = elementos[l][0];
									max = elementos[k][0] + elementos[j][0] + elementos[i][0] + elementos[n][0] + elementos[m][0] + elementos[l][0];
									auxcomb[4] = max;
								}
						}
					}
				}
			}
		}
	}
}