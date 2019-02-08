#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>


struct pal { int a;
		int b[3];
		int c[5];
		int d[7];
	      } palitos;
void init(void);
int xor(int,int,int,int);
int contPalitos(int,int,int,int);
void actualizarPantalla(void);
void jugarMaq(void);
void generarTablero(void);
int tab[5][3];
FILE *arc1;

void main()
{int f,p,z=16,t=0,a,h=0,k,cont,q,i;
clrscr(); arc1=fopen("m:\\bin.txt","w");
init(); actualizarPantalla(); fprintf(arc1,"tablero inicial\n"); generarTablero();
while(z>0){
if(t%2==0)
 {printf("Turno jugador...\n");
  do{flushall(); printf("ingresar fila: ");
   scanf("%d",&f);
   if((f>=1) & (f<=4)) h=1;
  } while(h==0);
h=0;
if(f==1) palitos.a=0;
if(f==2) {p=1;
	  do{printf("ingresar cant. de palitos: ");
	     scanf("%d",&p);
	     if((p>=1) & (p<=contPalitos(0,1,0,0))) h=1;
	     } while(h==0);
	  cont=0; q=0;
	  while(cont<p)
	   {if(palitos.b[q]==1) {palitos.b[q]=0;
				   cont++; q++;}
	    else q++;}
	  }
if(f==3){ p=1;
	  do{printf("ingresar cant. de palitos: ");
	  scanf("%d",&p);
	  if((p>=1) & (p<=contPalitos(0,0,1,0))) h=1;} while(h==0);
	  cont=0; q=0;
	  while(cont<p)
	   {if(palitos.c[q]==1) {palitos.c[q]=0;
				   cont++; q++;}
	    else q++;}
	}
if(f==4){ p=1;
	  do{printf("ingresar cant. de palitos: ");
	  scanf("%d",&p);
	  if((p>=1) & (p<=contPalitos(0,0,0,1))) h=1;} while(h==0);
	  cont=0; q=0;
	  while(cont<p)
	   {if(palitos.d[q]==1) {palitos.d[q]=0;
				   cont++; q++;}
	    else q++;}
	  }
t++;
fprintf(arc1,"jugada usuario:\n");
generarTablero();
}
else {printf("Turno CPU...\n"); delay(750); jugarMaq(); t++;}

actualizarPantalla();
z=contPalitos(1,1,1,1);

}
if(z==0)
 {t=t+1; if(t%2==0) printf("\nGanador: Usuario");
  else printf("\nGanador: CPU");
 }
getche();
fcloseall();
}

void init(void)
{int k;
palitos.a=1;
for(k=0;k<3;k++)
 palitos.b[k]=1;
for(k=0;k<5;k++)
 palitos.c[k]=1;
for(k=0;k<7;k++)
 palitos.d[k]=1;
}

int contPalitos(int a, int b, int c, int d)
{int k,cont=0;
if(a==1 & palitos.a==1) cont=cont+1;
if(b==1) for(k=0;k<3;k++) if(palitos.b[k]==1) cont=cont+1;
if(c==1) for(k=0;k<5;k++) if(palitos.c[k]==1) cont=cont+1;
if(d==1) for(k=0;k<7;k++) if(palitos.d[k]==1) cont=cont+1;
return(cont);
}

void actualizarPantalla()
{int k;
clrscr();
gotoxy(30,2); printf("1");
gotoxy(38,2);
if(palitos.a==1) printf("|");
else printf(" ");
gotoxy(30,3); printf("2");
gotoxy(37,3);
for(k=0;k<3;k++)
{if(palitos.b[k]==1) printf("|");
 else printf(" ");}
gotoxy(30,4); printf("3");
gotoxy(36,4);
for(k=0;k<5;k++)
{if(palitos.c[k]==1) printf("|");
 else printf(" ");}
gotoxy(30,5); printf("4");
gotoxy(35,5);
for(k=0;k<7;k++)
{if(palitos.d[k]==1) printf("|");
 else printf(" ");}
printf("\n\n");
printf("Reglas: sacar palitos de una fila (cualquier cantidad posible), quien saca el £ltimo gana.\n");
printf("El oponente se llama CPU.\n\n");
}

void jugarMaq(void)
{int k,j,x,z,max=0,a[4],b[2],aux[4],d,f=2,p,cont,q;
a[0]=contPalitos(1,0,0,0);
a[1]=contPalitos(0,1,0,0);
a[2]=contPalitos(0,0,1,0);
a[3]=contPalitos(0,0,0,1);
for(k=0;k<4;k++)
   {aux[0]=a[0];
    aux[1]=a[1];
    aux[2]=a[2];
    aux[3]=a[3];
   if(a[k]!=0) for(j=0;j<=a[k];j++)
    {aux[k]=a[k]-j;
     d=xor(aux[0],aux[1],aux[2],aux[3]); fprintf(arc1,"%d %d %d %d s=%d\n",aux[0],aux[1],aux[2],aux[3],d);
     if(d==1) {b[1]=k+1;b[0]=j;f=0;}  if(f==0) break;
    } if(f==0) break;

   }

if(b[1]==1) palitos.a=0;
if(b[1]==2) {p=b[0];
	     cont=0; q=0;
	  while(cont<p)
	   {if(palitos.b[q]==1) {palitos.b[q]=0;
				   cont++; q++;}
	    else q++;}
	  }
if(b[1]==3){ p=b[0];
	    cont=0; q=0;
	  while(cont<p)
	   {if(palitos.c[q]==1) {palitos.c[q]=0;
				   cont++; q++;}
	    else q++;}
	}
if(b[1]==4){ p=b[0];
	  cont=0; q=0;
	  while(cont<p)
	   {if(palitos.d[q]==1) {palitos.d[q]=0;
				   cont++; q++;}
	    else q++;}
	  }
fprintf(arc1,"jugada pc:\n");
generarTablero();

}

void generarTablero()
{int k,cont,j,pilas[4],z,t,b;
pilas[0]=contPalitos(1,0,0,0);
pilas[1]=contPalitos(0,1,0,0);
pilas[2]=contPalitos(0,0,1,0);
pilas[3]=contPalitos(0,0,0,1);
for(k=0;k<4;k++) for(j=0;j<3;j++) tab[k][j]=0;
for(k=0;k<4;k++)
{t=2; b=pilas[k];
 while(b>0)
 {tab[k][t]=b%2;
  b=floor(b/2);
  t--;
 }
}
for(k=0;k<3;k++)
 {cont=0;
  for(j=0;j<4;j++)
   if(tab[j][k]==1) cont=cont+1;
  if(cont%2==0) tab[4][k]=0;
  else if(cont%2!=0) tab[4][k]=1;
 }
for(k=0;k<5;k++)
 {for(j=0;j<3;j++)
   fprintf(arc1,"%d\t",tab[k][j]);
   fprintf(arc1,"\n");} fprintf(arc1,"\n");
}

int xor(int x, int y, int z, int u)
{int b,k,j,t,arr[5][3],a[4],cont;
 a[0]=x;
 a[1]=y;
 a[2]=z;
 a[3]=u;
 for(k=0;k<5;k++)
  for(j=0;j<3;j++)
    arr[k][j]=0;
 for(k=0;k<4;k++)
  {t=2; b=a[k];
   while(b>0)
   { arr[k][t]=b%2;
     b=floor(b/2);
     t--;
   }
  }
for(k=0;k<3;k++)
 {cont=0;
  for(j=0;j<4;j++)
   if(arr[j][k]==1) cont=cont+1;
  if(cont%2==0) arr[4][k]=0;
  else if(cont%2!=0) arr[4][k]=1;

  } cont=0;
  for(k=0;k<5;k++)
   {for(j=0;j<3;j++)
    fprintf(arc1,"%d\t",arr[k][j]);
    fprintf(arc1,"\n");
   }
for(k=0;k<3;k++) if(arr[4][k]!=0) cont++;
if(cont==0) return(1); else if(cont!=0) return(0);

}