#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100  

// 배열 출력 함수
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 랜덤 숫자 생성 함수
void generateRandomNumbers(int arr[]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 1000; // 0~999 범위의 랜덤 값
    }
}

// 쉘 정렬 함수
void doShellSort(int arr[], int n, int gapDivider, int* comparisonCount, int* moveCount) {
    *comparisonCount = 0;  // 비교 횟수 초기화
    *moveCount = 0;        // 이동 횟수 초기화

    for (int gap = n / gapDivider; gap > 0; gap /= gapDivider) {
        printf("\nSorting with gap = %d:\n", gap);

        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            (*moveCount)++; // temp에 값 저장

            int j;
            for (j = i; j >= gap && (++(*comparisonCount), arr[j - gap] > temp); j -= gap) {
                arr[j] = arr[j - gap];
                (*moveCount)++; // 값이동
            }
            arr[j] = temp;
            (*moveCount)++; // temp 값 배열에 복사
        }

        // gap 단계 정렬 상태 출력
        printArray(arr, n);
    }
}

// 삽입 정렬 함수
void doInsertionSort(int arr[], int n, int* comparisonCount, int* moveCount) {
    *comparisonCount = 0;  // 비교 횟수 초기화
    *moveCount = 0;        // 이동 횟수 초기화

    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        (*moveCount)++; // temp에 값 저장

        int j = i - 1;
        while (j >= 0 && (++(*comparisonCount), arr[j] > temp)) {
            arr[j + 1] = arr[j];
            (*moveCount)++; // 값이동
            j--;
        }
        arr[j + 1] = temp;
        (*moveCount)++; // temp 값 배열에 복사
    }
}

// main 함수
int main() {
    int array[MAX_SIZE];
    int arrayCopy[MAX_SIZE];             // 쉘 정렬할 때 같은 데이터를 사용하기 위해 배열 복사
    int comparisonCount, moveCount;     // 비교 및 이동 횟수 저장

    srand(time(NULL)); // 난수 초기화

    generateRandomNumbers(array);

    // 배열 복사
    for (int i = 0; i < MAX_SIZE; i++) {
        arrayCopy[i] = array[i];
    }

    // Shell Sort(n/2)
    printf("Shell Sort (n/2):\n");
    doShellSort(array, MAX_SIZE, 2, &comparisonCount, &moveCount);

    // 최종 정렬된 배열 출력(n/2)
    printf("\nSorted shellArray(gap = 2):\n");
    printArray(array, MAX_SIZE);

    // 비교, 이동 횟수 출력(n/2)
    printf("\nShell Sort (n/2) - Comparisons: %d, Moves: %d\n\n", comparisonCount, moveCount);

    // 배열 복사 초기화 (랜덤 데이터에서 복원) >> 이거 안하면 이미 정렬 된 데이터로 다시 정렬함 >> 의미 없음 
    generateRandomNumbers(arrayCopy);

    // Shell Sort(n/3)
    printf("Shell Sort (n/3):\n");
    doShellSort(arrayCopy, MAX_SIZE, 3, &comparisonCount, &moveCount);

    // 최종 정렬된 배열 출력(n/3)
    printf("\nSorted shellArray(gap = 3):\n");
    printArray(arrayCopy, MAX_SIZE);

    // 비교, 이동 횟수 출력(n/3)
    printf("\nShell Sort (n/3) - Comparisons: %d, Moves: %d\n\n", comparisonCount, moveCount);

    // 배열 복사 초기화
    generateRandomNumbers(arrayCopy);

    // Insertion Sort - 보너스
    printf("Insertion Sort : \n");
    doInsertionSort(arrayCopy, MAX_SIZE, &comparisonCount, &moveCount);

    // 삽입 정렬 결과 출력
    printf("\nSorted array (Insertion Sort):\n");
    printArray(arrayCopy, MAX_SIZE);

    // 비교, 이동 횟수 출력(삽입 정렬)
    printf("\nInsertion Sort - Comparisons: %d, Moves: %d\n", comparisonCount, moveCount);

    return 0;
}
