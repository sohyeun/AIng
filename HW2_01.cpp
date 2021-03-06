#include <stdio.h>

#define ROWS 3
#define COLS 3
#define MAX_TERMS 10

typedef struct {
	int row;
	int col;
	int value;
} element;
typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;
	int cols; 
	int terms;

} SparseMatrix;

void main()
{
	//Add B as an input
	SparseMatrix B = { {{0,2,1},{1,0,2},{1,2,1},{2,1,1} },ROWS,COLS,4 };

	SparseMatrix tB;
	tB.rows = B.cols;
	tB.cols = B.rows;
	tB.terms = B.terms;

	int i, j;

	//Perform the transpose operation
	for (i = 0; i < B.terms; i++) {
		tB.data[i].row = B.data[i].col;
		tB.data[i].col = B.data[i].row;
		tB.data[i].value = B.data[i].value;
	}

	//tB matrix를 row-wise manner로 정렬
	element temp;
	printf("row-wise manner로 정렬하기 이전 data[%d]: {%d,%d,%d} \n", 0, tB.data[0].row, tB.data[0].col, tB.data[0].value);
	for (i = 0; i < tB.terms; i++) {
		for (j = 0; j < (tB.terms) - 1 - i; j++) {
			if (tB.data[j].row > tB.data[j + 1].row)
			{
				temp = tB.data[j];
				tB.data[j] = tB.data[j + 1];
				tB.data[j + 1] = temp;
			}
			else if (tB.data[j].row == B.data[j + 1].row){
				if (tB.data[j].col > tB.data[j + 1].col)
				{
					temp = tB.data[j];
					tB.data[j] = tB.data[j + 1];
					tB.data[j + 1] = temp;
				}

				}
		}
	}
	printf("row-wise manner로 정렬 한 이후 data[%d]: {%d,%d,%d} \n", 0, tB.data[0].row, tB.data[0].col, tB.data[0].value);

	//Print out B and tB in a dense matrix form
	int r, c, t;
	

	puts("\nB matrix in dense matrix form\n");
	
	for (r = 0; r < B.rows; r++) {
		
		for (c = 0; c< B.cols; c++) {
			t = 0;
			for (i = 0; i < B.terms; i++) {
				if (r == B.data[i].row&&c == B.data[i].col) {
					printf("%d", B.data[i].value);
					t=1;
				}
			}
		if (t==1) continue;
			printf("%d", 0);
		}
		printf("\n");
	}

	puts("\ntB matrix in dense matrix form\n");

	for (r = 0; r < tB.rows; r++) {
		
		for (c = 0; c< tB.cols; c++) {
			t = 0;
			for (i = 0; i < tB.terms; i++) {
				if (r == tB.data[i].row&&c == tB.data[i].col) {
					printf("%d", tB.data[i].value);
					t=1;
				}
			}
			if (t == 1) continue;
			printf("%d", 0);
		}
		printf("\n");
	}


    
}

