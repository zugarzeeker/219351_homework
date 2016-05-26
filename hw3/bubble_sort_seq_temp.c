#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 16

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n-1; i++)      
    for (j = 0; j < n-i-1; j++)
      if (arr[j] > arr[j+1])
	swap(&arr[j], &arr[j+1]);
}

int isSorted(int *a, int size) {
  int i;
  for (i = 0; i < size - 1; i++) {
    if (a[i] > a[i + 1]) {
      return 0;
    }
  }
  return 1;
}

// Function to print an array
void printArray(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int* merge(int *a, int *b, int size) {
	int *m = (int *)malloc(sizeof(int)*size);
	int i = 0, j = 0;

	while (i + j < size) {
		if (i == size / 2) {
			m[i+j] = b[j];
			j++;
		}
		else if (j == size / 2) {
			m[i+j] = a[i];
			i++;
		}
		else if (a[i] < b[j]) {
			m[i+j] = a[i];
			i++;
		}
		else {
			m[i+j] = b[j];
			j++;
		}
	}
	return m;
}

int* mergeN(int *a, int size, int n) {
	if (n > 2) {
		return merge(mergeN(a, size / 2, n / 2), mergeN(a + size / 2, size / 2, n / 2), size);
	}
	return merge(a, &a[size/2], size);
}

int main(int argc, char** argv) {
	int i, n;
	int* A, *temp;
	clock_t start, end;
	double elapsed_time, t1, t2;

	MPI_Init(NULL, NULL);

	t1 = MPI_Wtime();
	A = (int *)malloc(sizeof(int)*N);
	temp = (int *)malloc(sizeof(int)*N);
	if (A == NULL) {
		printf("Fail to malloc\n");
		exit(1);
	}
	for (i=N-1; i>=0; i--)
		A[N-1-i] = i;
	
	if (isSorted(A, N))
	  printf("Array is sorted\n");
	else
	  printf("Array is NOT sorted\n");
	

	n = 4;
	for (i = 0; i < n; i++) {
		bubbleSort(&A[N/n*i], N/n);
		printArray(&A[N/n*i], N/n);
	}
	// bubbleSort(A, N/2);
	// printArray(A, N/2);
	
	// bubbleSort(&A[N/2],N-N/2);
	// printArray(&A[N/2],N-N/2);

	// int *m = merge(A, &A[N/2], N);
	printf("================================\n");
	// int *m = merge(&A[N/2], A, N);
	int *m = mergeN(A, N, n);
	// mergeN(A, N, 2);
	// printArray(A, N);
	
	printArray(m, N);

	printf("================================\n");

	if (isSorted(m, N))
	// if (isSorted(A, N))
	  printf("Array is sorted\n");
	else
	  printf("Array is NOT sorted\n");	
	
	t2 = MPI_Wtime();
	printf( "Elapsed time MPI_Wtime is %f\n", t2 - t1 ); 
	


	MPI_Finalize();
	return 0;
}
