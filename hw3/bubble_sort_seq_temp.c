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

int* mergeN(int *a[], int size, int n) {
	if (n > 2) {
		return merge(mergeN(a, size / 2, n / 2), mergeN(a + n/2, size / 2, n / 2), size);
	}
	else if (n == 1) {
		return a[0];
	}
	return merge(a[0], a[1], size);
}

int main(int argc, char** argv) {
	int i, n;
	int* A, *temp;
	clock_t start, end;
	double elapsed_time, t1, t2;

	MPI_Init(NULL, NULL);
	int world_rank, world_size;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	
	n = world_size;
	int chunkSize = N / world_size;
	int start_index = world_rank * chunkSize;

	t1 = MPI_Wtime();
	A = (int *)malloc(sizeof(int)*chunkSize);
	temp = (int *)malloc(sizeof(int)*N);
	if (A == NULL) {
		printf("Fail to malloc\n");
		exit(1);
	}
	for (i=chunkSize-1; i>=0; i--)
		A[chunkSize-1-i] = i + start_index;
	
	if (isSorted(A, chunkSize))
	  printf("Array is sorted\n");
	else
	  printf("Array is NOT sorted\n");
	
	bubbleSort(A, chunkSize);

	if (world_rank == 0) {
		int rank;
		int *partial[n];
		printArray(A, chunkSize);
		partial[0] = A;
		for (rank = 1; rank < world_size; rank++) {
			int* rev = (int *)malloc(sizeof(int)*chunkSize);
			MPI_Recv(rev, chunkSize, MPI_INT, rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printArray(rev, chunkSize);
			partial[rank] = rev;
		}

		temp = mergeN(partial, N, n);	      

		if (isSorted(temp, N))
		  printf("Array is sorted\n");
		else
		  printf("Array is NOT sorted\n");	

		t2 = MPI_Wtime();
		printf( "Elapsed time MPI_Wtime is %f\n", t2 - t1 ); 
		printArray(temp, N);
	}
	else if (world_rank != 0) {
		MPI_Send(A, chunkSize, MPI_INT, 0, 0, MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;
}
