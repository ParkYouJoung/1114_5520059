#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100  

// �迭 ��� �Լ�
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ���� ���� ���� �Լ�
void generateRandomNumbers(int arr[]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 1000; // 0~999 ������ ���� ��
    }
}

// �� ���� �Լ�
void doShellSort(int arr[], int n, int gapDivider, int* comparisonCount, int* moveCount) {
    *comparisonCount = 0;  // �� Ƚ�� �ʱ�ȭ
    *moveCount = 0;        // �̵� Ƚ�� �ʱ�ȭ

    for (int gap = n / gapDivider; gap > 0; gap /= gapDivider) {
        printf("\nSorting with gap = %d:\n", gap);

        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            (*moveCount)++; // temp�� �� ����

            int j;
            for (j = i; j >= gap && (++(*comparisonCount), arr[j - gap] > temp); j -= gap) {
                arr[j] = arr[j - gap];
                (*moveCount)++; // ���̵�
            }
            arr[j] = temp;
            (*moveCount)++; // temp �� �迭�� ����
        }

        // gap �ܰ� ���� ���� ���
        printArray(arr, n);
    }
}

// ���� ���� �Լ�
void doInsertionSort(int arr[], int n, int* comparisonCount, int* moveCount) {
    *comparisonCount = 0;  // �� Ƚ�� �ʱ�ȭ
    *moveCount = 0;        // �̵� Ƚ�� �ʱ�ȭ

    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        (*moveCount)++; // temp�� �� ����

        int j = i - 1;
        while (j >= 0 && (++(*comparisonCount), arr[j] > temp)) {
            arr[j + 1] = arr[j];
            (*moveCount)++; // ���̵�
            j--;
        }
        arr[j + 1] = temp;
        (*moveCount)++; // temp �� �迭�� ����
    }
}

// main �Լ�
int main() {
    int array[MAX_SIZE];
    int arrayCopy[MAX_SIZE];             // �� ������ �� ���� �����͸� ����ϱ� ���� �迭 ����
    int comparisonCount, moveCount;     // �� �� �̵� Ƚ�� ����

    srand(time(NULL)); // ���� �ʱ�ȭ

    generateRandomNumbers(array);

    // �迭 ����
    for (int i = 0; i < MAX_SIZE; i++) {
        arrayCopy[i] = array[i];
    }

    // Shell Sort(n/2)
    printf("Shell Sort (n/2):\n");
    doShellSort(array, MAX_SIZE, 2, &comparisonCount, &moveCount);

    // ���� ���ĵ� �迭 ���(n/2)
    printf("\nSorted shellArray(gap = 2):\n");
    printArray(array, MAX_SIZE);

    // ��, �̵� Ƚ�� ���(n/2)
    printf("\nShell Sort (n/2) - Comparisons: %d, Moves: %d\n\n", comparisonCount, moveCount);

    // �迭 ���� �ʱ�ȭ (���� �����Ϳ��� ����) >> �̰� ���ϸ� �̹� ���� �� �����ͷ� �ٽ� ������ >> �ǹ� ���� 
    generateRandomNumbers(arrayCopy);

    // Shell Sort(n/3)
    printf("Shell Sort (n/3):\n");
    doShellSort(arrayCopy, MAX_SIZE, 3, &comparisonCount, &moveCount);

    // ���� ���ĵ� �迭 ���(n/3)
    printf("\nSorted shellArray(gap = 3):\n");
    printArray(arrayCopy, MAX_SIZE);

    // ��, �̵� Ƚ�� ���(n/3)
    printf("\nShell Sort (n/3) - Comparisons: %d, Moves: %d\n\n", comparisonCount, moveCount);

    // �迭 ���� �ʱ�ȭ
    generateRandomNumbers(arrayCopy);

    // Insertion Sort - ���ʽ�
    printf("Insertion Sort : \n");
    doInsertionSort(arrayCopy, MAX_SIZE, &comparisonCount, &moveCount);

    // ���� ���� ��� ���
    printf("\nSorted array (Insertion Sort):\n");
    printArray(arrayCopy, MAX_SIZE);

    // ��, �̵� Ƚ�� ���(���� ����)
    printf("\nInsertion Sort - Comparisons: %d, Moves: %d\n", comparisonCount, moveCount);

    return 0;
}
