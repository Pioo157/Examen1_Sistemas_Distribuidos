#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void get_walltime(double* wcTime){
	struct timeval tp;
	gettimeofday(&tp, NULL);
	*wcTime=(tp.tv_sec + tp.tv_usec/1000000.0);
}

int main(int argc, char* arvg[]){
	int i, j, k;
	int n = 1000;
	int **matrizA, **matrizB, **matrizC;
	double S1 ,E1, L1;

	//Inicializando matrices.
	matrizA = (int **)malloc(n*sizeof(int *));
	matrizB = (int **)malloc(n*sizeof(int *));
	matrizC = (int **)malloc(n*sizeof(int *));

	for (i = 0; i < n; i++){
		*(matrizA + i) = (int *)malloc(n*sizeof(int));
		*(matrizB + i) = (int *)malloc(n*sizeof(int));
		*(matrizC + i) = (int *)malloc(n*sizeof(int));
	}

	get_walltime(&L1);

	//Llenado de matrices.
	for(i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			matrizA[i][j] = rand() % 6;
			matrizB[i][j] = rand() % 6;
		}
	}

	get_walltime(&S1);

	//Multiplicacion de matrices.
	for (k = 0; k < n; ++k)
	{
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
			}
		}
	}

	get_walltime(&E1);



	printf("Tiempo método kij: %f s\n",(E1-S1));
	printf("Tiempo del llenado de las matrices %dx%d A y B: %f s\n",n,n,(S1-L1));
	return 0;
}

