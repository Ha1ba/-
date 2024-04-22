#include <stdlib.h>
#include <stdio.h>
#include "header.h"

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

int main() {
    int comparisonsShell = 0, swapsShell = 0;
    int comparisonsInsertion = 0, swapsInsertion = 0;
    int comparisonsBubble = 0, swapsBubble = 0;
    int comparisonsCounting = 0, swapsCounting = 0;

    printf("Size\t     ShellSort\t\t   InsertionSort\t    CountingSort\t     BubbleSort\n");
    printf("\tDec\tRnd\tAsc\tDec\tRnd\tAsc\tDec\tRnd\tAsc\tDec\tRnd\tAsc\n");

    for (int n = 100; n <= 500; n += 100) {
        printf("%d\t", n);

        int massive[n];
        int cmassive[n];
        int smassive[n];
        int imassive[n];

        TypeOfCompletion(2, n, massive, cmassive, smassive, imassive); // Заполнение массивов случайными числами

        // ShellSort
        sortDescending(smassive, n);
        ShellSort(smassive, n, &comparisonsShell, &swapsShell);
        printf("%d\t", comparisonsShell + swapsShell);

        shuffleArray(smassive, n);
        ShellSort(smassive, n, &comparisonsShell, &swapsShell);
        printf("%d\t", comparisonsShell + swapsShell);

        sortAscending(smassive, n);
        ShellSort(smassive, n, &comparisonsShell, &swapsShell);
        printf("%d\t", comparisonsShell + swapsShell);

        // InsertionSort
        sortDescending(imassive, n);
        insertionSort(imassive, n, &comparisonsInsertion, &swapsInsertion);
        printf("%d\t", comparisonsInsertion + swapsInsertion);

        shuffleArray(imassive, n);
        insertionSort(imassive, n, &comparisonsInsertion, &swapsInsertion);
        printf("%d\t", comparisonsInsertion + swapsInsertion);

        sortAscending(imassive, n);
        insertionSort(imassive, n, &comparisonsInsertion, &swapsInsertion);
        printf("%d\t", comparisonsInsertion + swapsInsertion);

        // CountingSort
        sortDescending(cmassive, n);
        CountingSort(cmassive, n, 100, &comparisonsCounting, &swapsCounting);
        printf("%d\t", comparisonsCounting + swapsCounting);

        shuffleArray(cmassive, n);
        CountingSort(cmassive, n, 100, &comparisonsCounting, &swapsCounting);
        printf("%d\t", comparisonsCounting + swapsCounting);

        sortAscending(cmassive, n);
        CountingSort(cmassive, n, 100, &comparisonsCounting, &swapsCounting);
        printf("%d\t", comparisonsCounting + swapsCounting);

        // BubbleSort
        sortDescending(massive, n);
        BubbleSort(massive, n, &comparisonsBubble, &swapsBubble);
        printf("%d\t", comparisonsBubble + swapsBubble);

        shuffleArray(massive, n);
        BubbleSort(massive, n, &comparisonsBubble, &swapsBubble);
        printf("%d\t", comparisonsBubble + swapsBubble);

        sortAscending(massive, n);
        BubbleSort(massive, n, &comparisonsBubble, &swapsBubble);
        printf("%d\t", comparisonsBubble + swapsBubble);

        printf("\n");
    }

    return 0;
}