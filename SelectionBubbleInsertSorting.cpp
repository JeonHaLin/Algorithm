#include <iostream>
using namespace std;

void selection_sort(int A[], int n) {
    int k = 1;

    int c = 0;
    int s = 0;
    int temp = 0;

    for (int i = n; i >= 2; i--) {
        k = 1;

        for (int j = 2; j <= i; j++) {
            c++;

            if (A[j] > A[k]) {
                k = j;
            }
        }

        if (k != i) {
            s++;
            temp = A[k];
            A[k] = A[i];
            A[i] = temp;
        }
    }

    printf("comp: %d, swap: %d\n", c, s);
}

void bubble_sort(int A[], int n) {
    int c = 0;
    int s = 0;
    int temp = 0;

    for (int i = n; i >= 2; i--) {
        for (int j = 1; j <= i - 1; j++) {
            c++;

            if (A[j] > A[j + 1]) {
                s++;
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    printf("comp: %d, swap: %d\n", c, s);

}

void insert_sort(int A[], int n) {
    int item = 0;
    int loc = 0;

    int c = 0;
    int s = 0;

    for (int i = 2; i <= n; i++) {
        loc = i - 1;
        item = A[i];

        while (loc >= 1) {
            c++;

            if (item < A[loc]) {
                A[loc + 1] = A[loc];
                loc = loc - 1;
                s++;
            }
            else {
                break;
            }
        }

        A[loc + 1] = item;
        s++;
    }

    printf("comp: %d, swap: %d\n", c, s);

}

int main() {
    int n = 0;
    cin >> n;

    int num;
    int* arr1 = new int[n + 1];
    int* arr2 = new int[n + 1];
    int* arr3 = new int[n + 1];


    for (int i = 1; i <= n; i++) {
        cin >> num;
        arr1[i] = num;
        arr2[i] = num;
        arr3[i] = num;
    }

    selection_sort(arr1, n);
    bubble_sort(arr2, n);
    insert_sort(arr3, n);

    delete[n] arr1;
    delete[n] arr2;
    delete[n] arr3;

    return 0;
}