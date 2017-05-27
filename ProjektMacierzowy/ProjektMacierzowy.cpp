// ProjektMacierzowy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdint.h>
#include <stdlib.h>

FILE *fd;

int main()
{
	int n;
	double **matrixA;
	double *matrixB;
	double *matrixX;

	if (!(fd = fopen("data.txt", "r"))) exit(5);
	fscanf(fd, "%d", &n);
	printf("rozmiar: %d\nMacierz A: \n", n);

	if (!(matrixA = malloc(sizeof(double)*n))) exit(4);
	if (!(matrixB = malloc(sizeof(double)*n))) exit(4);
	if (!(matrixX = malloc(sizeof(double)*n))) exit(4);

	//macierz A
	for (int i = 0; i < n; i++)
	{
		if (!(matrixA[i] = malloc(sizeof(double)*n))) exit(4);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fscanf(fd, "%LF", &matrixA[i][j]);
			printf("%LF ", matrixA[i][j]);
		}
		printf("\n");
	}

	//macierz B
	printf("Macierz B: \n");
	for (int i = 0; i < n; i++)
	{
		fscanf(fd, "%LF", &matrixB[i]);
		printf("%LF\n", matrixB[i]);
	}


	//Z£E:
	//rozwiazywanie ukladu równañ
	/*
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < n-1; j++)
		{
			matrixA[i][j] = matrixA[i][j] * (1.0 / matrixA[i][i])*matrixA[i - 1][i];
		}
		
		matrixB[i] = matrixB[i] * (1.0 / matrixA[i][i])*matrixA[i - 1][i];
		
		for (int j = 0; j < n; j++)
		{
			matrixA[i - 1][j] = matrixA[i - 1][j] - matrixA[i][j];
		}
		matrixB[i - 1] = matrixB[i - 1] - matrixB[i];
	}
	matrixB[0] *= (1.0 / matrixA[0][0]);
	matrixA[0][0] = 1.0;
	matrixX[0] = matrixB[0];

	//obliczanie kolejnych x-ów
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			matrixB[i] = matrixB[i] - (matrixX[j] * matrixA[i][j]);
		}
		matrixB[i] = matrixB[i] / matrixA[i][i];
		matrixX[i] = matrixB[i];
		matrixA[i][i] = 1.0;
		//printf("x%d = %LF\n", i, matrixX[i]);
	}
	for (int i = 0; i < n; i++)
	{
		printf("x%d = %LF \n", i, matrixX[i]);
	}
	*/
	getchar();
    return 0;
}

