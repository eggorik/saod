#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define SIZE 1000000

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

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;


	int L[n1], R[n2];


	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}


	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], int l, int r)
{
	if (l < r) {

		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}


int main()
{
	int arr[SIZE];

	srand(wtime(0));

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = getrand(0, 100000);
    }

    double start_t = wtime();

	mergeSort(arr, 0, SIZE - 1);

    double end_t = wtime();

    printf("time: %f\n", end_t - start_t);

    start_t = wtime();
    bubble_sort(array_bub, 0, SIZE - 1);
    end_t = wtime();
    printf("Bubble sort time:     %f\n", end_t - start_t);

    start_t = wtime();
    mergeSort(array_merge, SIZE);
    end_t = wtime();
    printf("Merge sort time:     %f\n", end_t - start_t);

    free(array_cnt);
    free(array_bub);
	return 0;
}
