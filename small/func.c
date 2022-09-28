#include <stdio.h>
#include <stdlib.h>
#ifndef FUNC
#include "func.h"
#endif


double Fmax(double arr[], int len)
{
	double max = arr[0];
	for (int i = 0; i < len; i++)
	{
		arr[i] > max ? max = arr[i] : max;
	}
	return max;
}

double Fmin(double arr[], int len)
{
	double min = arr[0];
	for (int i = 0; i < len; i++)
	{
		arr[i] < min ? min = arr[i] : min;
	}
	return min;
}

double Faverage(double arr[], int len)
{
	double average = 0;
	for (int i = 0; i < len; i++)
	{
		average += arr[i];
	}
	average /= len;
	return average;
}

void swap(double* x, double* y)
{
	double temp = *x;
	*x = *y;
	*y = temp;
}

double* FsortMin(double* x, double* y)
{
	double* min = x;
	for (int i = 0; i < (y - x) + 1; i++)
	{
		*(x + i) < *min ? min = (x + i) : min;		
	}
	return min;
}

void Fsort(double* arr, int len)
{
	double* top = &arr[0];
	double* bottom = &arr[len - 1];
	while (top != bottom)
	{
		double* temp = FsortMin(top, bottom);
		swap(top, temp);
		top++;
	}
}

void ArrTing(void)
{
	srand(time(0));
	double* ptr;
	int len = 1000;
	ptr = (double*)calloc(len, sizeof(double));
	if (ptr == NULL)
	{
		printf("Memory wasn't allocated ):\n");
		return;
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			ptr[i] = (double)(rand() % (1001));
		}
		for (int i = 0; i < len; i++)
		{
			printf("%.lf\n", ptr[i]);
		}
		printf("\n\n\n");
		double max, min, average;

		max = Fmax(ptr, len); min = Fmin(ptr, len); average = Faverage(ptr, len);

		printf("%.lf\n%.lf\n%.lf", max, min, average);
		Fsort(ptr, len);
		printf("\n\n\n");
		for (int i = 0; i < len; i++)
		{
			printf("%.lf\n", ptr[i]);
		}
	}
}
