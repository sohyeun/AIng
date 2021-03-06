#include<stdio.h>
#include<malloc.h>

#define ROW 3
#define COL 3
#define HIGH 3

double *** mem_alloc_3D_double(int row,int col,int high, int s ) {

	int i, j, k;

	double ***m = (double ***)malloc(sizeof(double**)*high);
	for (i = 0; i < high; i++) {
		m[i] = (double**)malloc(sizeof(double*)*row);
		for (j = 0; j < row; j++) {
			m[i][j] = (double*)malloc(sizeof(double)*col);
		}
	}
	
	if (s == 0) {
		for (k = 0; k < high; k++) {
			for (i = 0; i < row; i++) {
				for (j = 0; j < col; j++) {
					m[k][i][j] = 0;
				}
			}
		}

	}
	else {
		for (k = 0; k < high; k++) {
			for (i = 0; i < row; i++) {
				for (j = 0; j < col; j++) {
					m[k][i][j] = s++;
				}
			}
		}
	}
	return m;
	
}

void addition_3D(double***A, double***B){

	double ***C = mem_alloc_3D_double(3,3,3,0);
	int i, j, k;
	printf("<3D array C 출력>\n\n");
	for (k = 0; k < HIGH; k++) {
		for (i = 0; i < ROW; i++) {
			for (j = 0; j < COL; j++) {
				C[k][i][j] = A[k][i][j] + B[k][i][j];
				printf("%6.3lf ", C[k][i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
	
}


void main()
{
	//Define two matrices A and B ‘mem_alloc_3D_double’
	double ***A = mem_alloc_3D_double(ROW, COL, HIGH, 3); 
	double ***B = mem_alloc_3D_double(ROW, COL, HIGH, 2);

	
	int i, j, k;
	
	printf("<3D array A 출력>\n\n");
	for (k = 0; k < HIGH; k++) {
		for (i = 0; i < ROW; i++) {
			for (j = 0; j < COL; j++) {
				A[k][i][j];
				printf("%6.3lf ", A[k][i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
	printf("<3D array B 출력>\n\n");
	for (k = 0; k < HIGH; k++) {
		for (i = 0; i < ROW; i++) {
			for (j = 0; j < COL; j++) {
				*(*(*(B + k) + i) + j);  //B[k][i][j];
				printf("%6.3lf ", *(*(*(B + k) + i) + j));
			}
			printf("\n");
		}
		printf("\n\n");
	} 
	

	//Perform addition of two matrices using ‘addition_3D()’
	addition_3D(A, B);

	//Deallocate A and B
	
	if (A != NULL) {
		free(A[0]);
		free(A[0][0]);
		free(A);
		A = NULL;
	}
	
	if (B != NULL) {
		free(B[0]);
		free(B[0][0]);
		free(B);
		B = NULL;
	}
}

