#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct pal
{
	int a;
	int b[3];
	int c[5];
	int d[7];
} palitos;
void init(void);
int contPalitos(int, int, int, int);
void actualizarPantalla(void);

void main()
{
	int f, p, z, t = 0, a, h = 0, k, cont, q, i;
	clrscr();
	srand(time(0));
	init();
	actualizarPantalla();
	while (z > 0)
	{
		if (t % 2 == 0)
			printf("turno jugador 1\n");
		else
			printf("turno jugador 2\n");
		do
		{
			printf("ingresar fila: ");
			scanf("%d", &f);
			if ((f >= 1) & (f <= 4))
				h = 1;
		} while (h == 0);
		h = 0;
		if (f == 1)
			palitos.a = 0;
		if (f == 2)
		{
			p = 1;
			do
			{
				printf("ingresar cant. de palitos: ");
				scanf("%d", &p);
				if ((p >= 1) & (p <= contPalitos(0, 1, 0, 0)))
					h = 1;
			} while (h == 0);
			cont = 0;
			q = 0;
			while (cont < p)
			{
				if (palitos.b[q] == 1)
				{
					palitos.b[q] = 0;
					cont++;
					q++;
				}
				else
					q++;
			}
		}
		if (f == 3)
		{
			p = 1;
			do
			{
				printf("ingresar cant. de palitos: ");
				scanf("%d", &p);
				if ((p >= 1) & (p <= contPalitos(0, 0, 1, 0)))
					h = 1;
			} while (h == 0);
			cont = 0;
			q = 0;
			while (cont < p)
			{
				if (palitos.c[q] == 1)
				{
					palitos.c[q] = 0;
					cont++;
					q++;
				}
				else
					q++;
			}
		}
		if (f == 4)
		{
			p = 1;
			do
			{
				printf("ingresar cant. de palitos: ");
				scanf("%d", &p);
				if ((p >= 1) & (p <= contPalitos(0, 0, 0, 1)))
					h = 1;
			} while (h == 0);
			cont = 0;
			q = 0;
			while (cont < p)
			{
				if (palitos.d[q] == 1)
				{
					palitos.d[q] = 0;
					cont++;
					q++;
				}
				else
					q++;
			}
		}
		actualizarPantalla();
		z = contPalitos(1, 1, 1, 1);
		t++;
	}
	if (z == 0)
	{
		if (t % 2 == 0)
			a = 1;
		else
			a = 2;

		printf("\njugador %d ganador", a);
	}
	getche();
}

void init(void)
{
	int k;
	palitos.a = 1;
	for (k = 0; k < 3; k++)
		palitos.b[k] = 1;
	for (k = 0; k < 5; k++)
		palitos.c[k] = 1;
	for (k = 0; k < 7; k++)
		palitos.d[k] = 1;
}

int contPalitos(int a, int b, int c, int d)
{
	int k, cont = 0;
	if (a == 1 & palitos.a == 1)
		cont = cont + 1;
	if (b == 1)
		for (k = 0; k < 3; k++)
			if (palitos.b[k] == 1)
				cont = cont + 1;
	if (c == 1)
		for (k = 0; k < 5; k++)
			if (palitos.c[k] == 1)
				cont = cont + 1;
	if (d == 1)
		for (k = 0; k < 7; k++)
			if (palitos.d[k] == 1)
				cont = cont + 1;
	return (cont);
}

void actualizarPantalla()
{
	int k;
	clrscr();
	gotoxy(30, 2);
	printf("1");
	gotoxy(38, 2);
	if (palitos.a == 1)
		printf("|");
	else
		printf(" ");
	gotoxy(30, 3);
	printf("2");
	gotoxy(37, 3);
	for (k = 0; k < 3; k++)
	{
		if (palitos.b[k] == 1)
			printf("|");
		else
			printf(" ");
	}
	gotoxy(30, 4);
	printf("3");
	gotoxy(36, 4);
	for (k = 0; k < 5; k++)
	{
		if (palitos.c[k] == 1)
			printf("|");
		else
			printf(" ");
	}
	gotoxy(30, 5);
	printf("4");
	gotoxy(35, 5);
	for (k = 0; k < 7; k++)
	{
		if (palitos.d[k] == 1)
			printf("|");
		else
			printf(" ");
	}
	printf("\n\n");
}