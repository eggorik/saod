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

int main()
{
    srand(wtime(0));

    uint32_t *array = (uint32_t *)malloc(sizeof(uint32_t) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = getrand(0, 100000);
    }

    double start_t = wtime();
    counting_sort(array, SIZE);
    double end_t = wtime();

    printf("time: %f\n", end_t - start_t);

    free(array);

    return 0;
}
