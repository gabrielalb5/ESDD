#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAX 1500

/*int main(){
    clock_t start, end;
    double cpu_time_used;

    bool is_prime;
    int number;
    int divider;

    start = clock();
    for (number = 1; number <= MAX; number++) {
        is_prime = true;
        divider = 2;

        while (divider <= number / 2 && is_prime) {
            if ( number % divider == 0){
                is_prime = false;
            }
            divider += 1;
        }

        if (is_prime){
            printf("%d ", number);
        }
    }
    end = clock();

    cpu_time_used = (  (double)(end - start) / CLOCKS_PER_SEC );
    printf("\nTempo de execução: %f segundos. \n", cpu_time_used);

    return 0;
}*/