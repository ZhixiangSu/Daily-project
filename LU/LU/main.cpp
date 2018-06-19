
#include<stdio.h>
#include<stdlib.h>
void Matrix_LU_Factorization(float *B, int n);
void main() {
	int i, j;
	int n;//  矩阵n-by-n
	printf("请输入n-by-n矩阵A的大小n：\n");
	scanf("%d", &n);
	float *A;
	A = (float *)malloc(sizeof(float)*n*n);
	printf("请输入%d-by-%d矩阵A,一次性输入%d个元素，元素之间用空格隔开：\n", n, n, n*n);
	for (i = 0; i<n*n; i++) {
		scanf("%f", &A[i]);
	}
	Matrix_LU_Factorization(A, n);
}
void Matrix_LU_Factorization(float *B, int n) {
	int i, j, k, p;
	float(*L)[n], (*U)[n], (*test)[n], (*A)[n];
	float temp = 0;
	A = (float(*)[n])malloc(sizeof(float)*n*n);
	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++) {
			A[i][j] = B[i*n + j];
		}
	}
	printf("输入的矩阵A：%d by %d\n", n, n);
	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++) {
			printf("%8.3f", A[i][j]);
		}
		printf("\n");
	}
	L = (float(*)[n])malloc(sizeof(float)*n*n);
	U = (float(*)[n])malloc(sizeof(float)*n*n);
	test = (float(*)[n])malloc(sizeof(float)*n*n);
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++) {
			L[i][j] = 0;
			U[i][j] = 0;
			if (i == j)
				L[i][j] = 1;
		}
	//进行LU分解 
	for (i = 0; i<n; i++) {
		if (i == 0) {
			L[0][0] = 1;
			for (j = 0; j<n; j++)
				U[i][j] = A[i][j];
		}
		else {
			for (j = 0; j<i; j++) {//计算l[i][j] 
				temp = A[i][j];
				p = 0;
				while (j >= 1 && p<j) {
					temp = temp - L[i][p] * U[p][j];
					p++;
				}
				L[i][j] = temp / U[j][j];
			}
			for (j = i; j<n; j++) {   //计算U[i][j] 
				temp = A[i][j];
				p = 0;
				while (p<j) {
					temp = temp - L[i][p] * U[p][j];
					p++;
				}
				U[i][j] = temp;
			}
		}
	}
	printf("L矩阵:\n");
	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++) {
			printf("%10.3f", L[i][j]);
		}
		printf("\n");
	}
	printf("U矩阵:\n");
	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++) {
			printf("%10.3f", U[i][j]);
		}
		printf("\n");
	}
	printf("还原矩阵A，计算L*U,存放到新矩阵test中，并输出\n");
	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++) {
			test[i][j] = 0;
			for (p = 0; p<n; p++) {
				test[i][j] += L[i][p] * U[p][j];
			}
			printf("%10.3f", test[i][j]);
		}
		printf("\n");
	}
}