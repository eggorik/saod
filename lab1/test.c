#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define SIZE 450000

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

void counting_sort(uint32_t array[], size_t size)
{
    uint32_t max = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    max++;

    uint32_t *temp = (uint32_t *)malloc(sizeof(uint32_t) * max);

    for (int i = 0; i < max; i++)
    {
        temp[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        temp[array[i]]++;
    }

    uint32_t k = 0;
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < temp[i]; j++)
        {
            array[k++] = i;
        }
    }
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

void print_arr(uint32_t array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    puts("");
}

int main()
{
    srand(wtime());
    uint32_t *array_cnt = (uint32_t *)malloc(sizeof(uint32_t) * SIZE);
    uint32_t *array_bub = (uint32_t *)malloc(sizeof(uint32_t) * SIZE);
    int array_merge[SIZE];

     for (int i = 0; i < SIZE; i++)
    {
        int k = getrand(0, 100000);
        array_cnt[i] = k;
        array_bub[i] = k;
        array_merge[i] = k;
    }
    
    double start_t = wtime();
    counting_sort(array_cnt, SIZE);
    double end_t = wtime();
    print_arr(array_cnt, SIZE);
    printf("Counting Sort time:  %f\n", end_t - start_t);
    start_t = wtime();
    bubble_sort(array_bub, SIZE);
    end_t = wtime();
    printf("Bubble sort time:     %f\n", end_t - start_t);

    start_t = wtime();
    mergeSort(array_merge, 0, SIZE - 1);
    end_t = wtime();
    printf("Merge sort time:     %f\n", end_t - start_t);

    free(array_cnt);
    free(array_bub);
    return 0;
}   