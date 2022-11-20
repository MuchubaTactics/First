#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <limits.h>

int Fmax(int arr[], int len);
int Fmin(int arr[], int len);
double Faverage(int arr[], int len);
void swap(int* x, int* y);

/*Previous Sorting Algorithm function declarations*/
//double* FsortMin(double* x, double* y);
//void Fsort(double* arr, int len);

void myQuicksort(int* arr, int low, int high);
int partition(int* arr, int low, int high);


#endif