#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void asignar(int *A, int *B, int tam)
{
	for (int i=0;i<tam;i++)		//asignacion de valores a las matrices
	{
		scanf("%d", &A[i]);
		B[i]=A[i];
	}
}
void burbuja(int *B,int tam)		//ordenamiento burbuja
{	
	int eliminar=0, i=0, aux=0;				
	while(tam != eliminar)
	{
      for(i=0; i <((tam-1)-eliminar); i++)
		{
          if(B[i]>B[i+1])
		  {
             aux=B[i];
             B[i]=B[i+1];
             B[i+1]=aux;
          }
      	}
       eliminar++;
	}
	for(i=0;i<tam;i++)
		printf(" %d ",B[i]);
}

void seleccion(int *B,int tam)		//ordenamiento por selección
{
	int aux=0, i=0, j=0, aux2=0;
	for(i=0; i<tam; i++)
	{
    	aux2=i;
    	for(j=i+1;j<tam;j++)
		{
        	if(B[j]<B[aux2])
            	aux2=j;

        	aux=B[i];
        	B[i]=B[aux2];
        	B[aux2]=aux;
    	}	
	}
	for(i=0;i<tam;i++)
		printf(" %d ",B[i]);
}

void insercion(int *B, int tam)		//ordenamiento por inserción
{ 
	for (int i = 1;i<tam;i++)
	{
		int key=B[i], j=i-1;
		
		while (j>=0 && B[j]>key){
			B[j+1]= B[j];
			j = j-1;
		}
		B[j+1]= key;
	}
	for(int i=0;i<tam;i++)
		printf(" %d ",B[i]);
}

int main()
{
	int tam=2000, A[tam], B[tam];		//A para recibir los datos, y B para que sea la matriz que sea modificada
	clock_t inicio_tiempo, fin_tiempo;
	double resultado_tiempo;

	asignar(A, B, tam);		//asiganmos valores a B
	inicio_tiempo=clock();		//tomamos el tiempo
	burbuja(B,tam);				//ejecutamos la función burbuja
	fin_tiempo=clock();					
	resultado_tiempo = (double)(fin_tiempo - inicio_tiempo)/CLOCKS_PER_SEC;	
	printf("\n\nTiempo de ordenamiento burbuja: %.8f seconds. \n\n", resultado_tiempo);					//mostramos el tiempo que demoro

	asignar(A, B, tam);			//asiganmos valores a B
	inicio_tiempo=clock();		//tomamos el tiempo
	seleccion(B,tam);			//ejecutamos la función insersión
	fin_tiempo=clock();
	resultado_tiempo = (double)(fin_tiempo - inicio_tiempo)/CLOCKS_PER_SEC;
	printf("\n\nTiempo del ordenamiento por seleccion: %.8f seconds. \n\n", resultado_tiempo);			//mostramos el tiempo que demoro

	asignar(A, B, tam);			//asignamos valores a B
	inicio_tiempo=clock();		//tomamos el tiempo
	insercion(B, tam);			//ejecutamos la función insersión
	fin_tiempo=clock();
	resultado_tiempo = (double)(fin_tiempo - inicio_tiempo)/CLOCKS_PER_SEC;
	printf("\n\nTiempo del ordenamiento por insercion: %.8f seconds. \n\n\n", resultado_tiempo);		//mostramos el tiempo que demoro
	return 0;
}