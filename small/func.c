#include "func.h"


int Fmax(int arr[], int len)
{
	int max = arr[0];
	for (int i = 0; i < len; i++)
	{
		arr[i] > max ? max = arr[i] : max;
	}
	return max;
}

int Fmin(int arr[], int len)
{
	int min = arr[0];
	for (int i = 0; i < len; i++)
	{
		arr[i] < min ? min = arr[i] : min;
	}
	return min;
}

double Faverage(int arr[], int len)
{
	double average = 0;
	for (int i = 0; i < len; i++)
	{
		average += arr[i];
	}
	return average / len;
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/*
* previous sorting algorithm implemenation
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
*/

int partition(int* arr, int low, int high)
{
	int* a = arr + low;
	int* pivot = arr + high;
	int* b = a;
	while (b <= pivot)
	{
		if (b == pivot)
		{
			if (*a > *pivot)
			{
				swap(pivot, a);
			}
			return a - arr;
		}
		if (*a < *pivot)
		{
			a++;
			b++;
		}
		else
		{
			if (*b < *pivot && *b < *a)
			{
				swap(b, a);
				a++;
			}
			b++;
		}

	}
}


void myQuicksort(int* arr, int low, int high)
{
	if (low < high)
	{
		int piv = partition(arr, low, high);
		myQuicksort(arr, low, piv - 1);
		myQuicksort(arr, piv + 1, high);
	}

}
