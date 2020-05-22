#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "gauss.h"

void HilbertMatrix(int N, double **H);
void displayMatrix(int N, double **H);
void computeVec(int N, double **H, double *b);
void plotVec(int N, double *b);

void main()
{
	int N;
	printf("podaj wielkosc macierzy Hilberta:\n");
	scanf("%d",&N);
	double **H=(double**)malloc(N*sizeof(double*));
	for(int i=0;i<N;i++)
	{
		H[i]=(double*)malloc(N*sizeof(double));
	}
	double *b=(double*)malloc(N*sizeof(double));
	double *x=(double*)malloc(N*sizeof(double));
	HilbertMatrix(N,H);
	printf("Macierz Hilberta:\n");
	displayMatrix(N,H);
	computeVec(N,H,b);
	printf("wektor b:\n");
	plotVec(N,b);
	gauss(N,H,x,b);
	printf("macierz x:\n");
	plotVec(N,x);

}
void HilbertMatrix(int N,double **H)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			H[i][j]=1./(1+i+j);
		}
	}
}
void displayMatrix(int N,double **H)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%lf\t",H[i][j]);
		}
		printf("\n");
	}
}
void computeVec(int N,double **H,double *b)
{
	for(int i=0;i<N;i++)
	{
		b[i]=0;
		for(int j=0;j<N;j++)
		{
			b[i]+=H[i][j];
		}
	}
}
void plotVec(int N,double *b)
{
	for(int i=0;i<N;i++)
	{
		printf("%f\n",b[i]);
	}
}