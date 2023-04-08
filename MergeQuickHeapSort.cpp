#include <iostream>
#include <array>
using namespace std;

// set comp counter and swap counter as global variables

int c1 = 0;
int c2 = 0;
int c3 = 0;

int s1 = 0;
int s2 = 0;
int s3 = 0;

// merge sort

void merge(int A[], int left, int middle, int right) {
	int i = left;
	int j = middle + 1;
	int t = 1;

	int size = right - left + 1;
	int* temp = new int[size + 1];

	while (i <= middle && j <= right) {
		c1++;

		if (A[i] <= A[j]) {
			temp[t++] = A[i++];
			s1++;
		}

		else {
			temp[t++] = A[j++];
			s1++;
		}
	}

	while (i <= middle) {
		temp[t++] = A[i++];
		s1++;
	}

	while (j <= right) {
		temp[t++] = A[j++];
		s1++;
	}

	i = left;
	t = 1;

	while (i <= right) {
		A[i++] = temp[t++];
		s1++;
	}

	delete[] temp;
}

void merge_sort(int A[], int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		merge_sort(A, left, middle);
		merge_sort(A, middle + 1, right);
		merge(A, left, middle, right);
	}
}

// quick sort

int partition(int A[], int left, int right) {
	int pivot = A[right];
	int i = left - 1;

	int temp = 0;

	for (int j = left; j <= right - 1; j++) { 
		c2++;

		if (A[j] <= pivot) {
			i++;

			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			s2++;
		}
	}

	temp = A[i + 1];
	A[i + 1] = A[right];
	A[right] = temp;
	s2++;

	return i + 1;
}

void quick_sort(int A[], int left, int right) {
	if (left < right) {
		int p = partition(A, left, right);
		quick_sort(A, left, p - 1);
		quick_sort(A, p + 1, right);
	}
}

// heap sort

void down_heap(int A[], int i, int n) {
	int left = 2 * i;
	int right = 2 * i + 1;
	int largest = i;

	int temp = 0;

	if (left <= n) {
		c3++;
		
		if (A[left] > A[largest]) {
			largest = left;
		}
	}

	if (right <= n) {
		c3++;

		if (A[right] > A[largest]) {
			largest = right;
		}
	}

	if (largest != i) {
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		s3++;
		down_heap(A, largest, n);
	}
}

void heap_sort(int A[], int n) {
	int temp = 0;

	for (int i = n / 2; i >= 1; i--) {
		down_heap(A, i, n);
	}

	for (int i = n; i >= 2; i--) {
		temp = A[i];
		A[i] = A[1];
		A[1] = temp;
		s3++;

		down_heap(A, 1, i - 1);
	}
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

	merge_sort(arr1, 1, n);
	quick_sort(arr2, 1, n);
	heap_sort(arr3, n);

	printf("comp: %d, swap: %d\n", c1, s1);
	printf("comp: %d, swap: %d\n", c2, s2);
	printf("comp: %d, swap: %d\n", c3, s3);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	return 0;
}