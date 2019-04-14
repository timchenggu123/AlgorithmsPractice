#include<iostream>
#include<vector>
#include<algorithm>


template<typename T>
void mergeSort(T* A, T A_size) {
	if (A_size == 1) {
		return A;
	}

	int k = A_size / 2;
	int* B = new T[k];
	int* C = new T[A_size - k];
	
	for (int i = 0; i < k; i++) {
		B[i] = A[i];
	}
	for (int i = 0; i < A_size - k; i++) {
		C[i] = A[k + i];
	}

	return merge(A,mergeSort(B,k),k,MergeSort(C,A_size -k)
		, A_size -k);
}

template<typename T>
void merge(T* A, T* B, int B_size, T* C, int C_size) {
	//note A is recycled as a holder for the merged array
	
	int size = C_size + B_size;
	int j = 0;
	int i = 0;
	int k = 0;
	while (i < B_size && j < C_size) {
		if (B[i] < C[j]) {
			A[k] = B[i];
			i++;
			k++;
		}
		else {
			A[k] = C[j];
			j++;
			k++;
		}
	}
	if (i != B_size) {
		while (k < size) {
			A[k] = B[++i];
		}
	}
	if (j != C_size) {
		while (k < size) {
			A[k] = C[++i];
		}
	}

	delete[] B;
	delete[] C;

	return A;
}