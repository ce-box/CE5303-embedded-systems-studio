#include <time_driver.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 8
int main()
{
    unsigned int start, end;

    printf("[1] Start program ...\n");
    start_timer();
    start = read_timer();
    printf("[2] Timer initialized ...\n");

    printf("[3] Calculating random numbers ...\n");

    unsigned int results[MAX];

    for (int i = 0; i < MAX; i++)
    {
        results[i] = generate_random_number();
        printf("\t@%d --> %u\n", i, results[i]);
    }

    end = read_timer() - start;
    printf("[4] Execution completed in: %u (tu)\n", end);

    stop_timer();
    printf("[5] Timer stopped ...\n");

    printf("[6] Finished program ...\n");

    return 0;
}