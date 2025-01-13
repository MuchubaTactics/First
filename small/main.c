#include "func.h"


// I dedicate all this code, all my work, to my wife, Darlene, who will 
// have to support me and our three children and the dog once it gets 
// released into the public.

int main(void)
{
	
	srand(time(NULL));
	int* ptr;
	int len = 500000;
	ptr = (int*)malloc(len * sizeof(int));
	if (ptr == NULL)
	{
		printf("Memory wasn't allocated ):\n");
		return;
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			ptr[i] = rand() % (len + 1);
		}
		for (int i = 0; i < len; i++)
		{
			printf("%d ", ptr[i]);
		}
		printf("\n\n\n");
		int max, min;
		double average;

		max = Fmax(ptr, len); min = Fmin(ptr, len); average = Faverage(ptr, len);

		printf("%d\n%d\n%.2lf", max, min, average);

		//sorting inside timer code
		clock_t before = clock();
		//Fsort(ptr, len);
		myQuicksort(ptr, 0, len - 1);
		double difference = (double)(clock() - before);
		difference /= CLOCKS_PER_SEC;
		printf("\n\n%lf", difference); //printing time spent sorting;
		
		Sleep(3000);
		printf("\n\n\n");
		for (int i = 0; i < len; i++)
		{
			printf("%d ", ptr[i]);
		}
	}

	//free the memory
	if (ptr)
	{
		free(ptr);
	}
	return 0;
}
