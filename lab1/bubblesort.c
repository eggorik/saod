#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define SIZE 500

uint32_t getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void swap(uint32_t* a, uint32_t* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(uint32_t* array, int size)
{
	int i, j;
	for (i = 0; i < size - 1; ++i) {
		for (j = 0; j < size - i - 1; ++j) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}

int main()
{
	srand(wtime(0));

    uint32_t *array = (uint32_t *)malloc(sizeof(uint32_t) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = getrand(0, 100000);
    }

    double start_t = wtime();
    bubble_sort(array, SIZE);
    double end_t = wtime();

    printf("time: %f\n", end_t - start_t);

    free(array);
	return 0;
}
