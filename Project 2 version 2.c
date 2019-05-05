#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 20

float A[N][M];
float B[N][M];

void fillarray(float Q[N][M], float val){
	int i, j;
	for (i = 1; i<N - 1; i++) for (j = 1; j<M - 1; j++) Q[i][j]=val;
	return;
}

void firstline(float Q[N][M], float val){
	int i, j;
	for (i = 0; i<N; i++) for (j = 0; j<M; j++) if(i==0 && j!=0 && j!=M-1) Q[i][j]=val;
	return;
}

void lastline(float Q[N][M], float val){
	int i, j;
	for(i=0;i<N;i++) for(j=0;j<M;j++) if(i==N-1 && j!=0 && j!=M-1) Q[i][j]=val;
	return;
}

void firstc(float Q[N][M], float val){
	int i, j;
	for(i=0;i<N;i++) for(j=0;j<M;j++) if(i!=0 && j==0 && i!=N-1) Q[i][j]=val;
	return;
}

void lastc(float Q[N][M], float val){
	int i, j;
	for(i=0;i<N;i++) for(j=0;j<M;j++) if (j == M - 1 && i != 0 && i != N - 1) Q[i][j] = val;
	return;
}

void printarray(float Q[N][M]) {
	int i, j;
	for (i = 0; i<N; i++) {
		for (j = 0; j < M; j++) {
			printf("%6.1f", Q[i][j]);
		}
		printf("\n");
	}
	return;
}

void fillA(){
	fillarray(A, 6);
	firstline(A, 3);
	lastline(A, 7);
	firstc(A, 2);
	lastc(A, 8);
	A[0][0] = (A[1][0] + A[0][1])*0.5;
	A[0][M-1] = (A[0][M-2] + A[1][M-1])*0.5;
	A[N-1][0] = (A[N-2][0] + A[N-1][1])*0.5;
	A[N-1][M-1] = (A[N-2][M-1] + A[N-1][M-2])*0.5;
	return;
}

void new_temps() {
	int i, j;
	for (i = 1; i<N - 1; i++) for (j = 1; j<M - 1; j++) B[i][j] = 0.1*(A[i - 1][j - 1] + A[i - 1][j] + A[i - 1][j + 1] + A[i][j - 1] + A[i][j] + A[i][j + 1] + A[i + 1][j - 1] + A[i + 1][j] + A[i + 1][j + 1]);
	return;
}

void fillB(){
	firstline(B, 3);
	lastline(B, 7);
	firstc(B, 2);
	lastc(B, 8);
	B[0][0] = (B[1][0] + B[0][1])*0.5;
	B[0][M-1] = (B[0][M-2] + B[1][M-1])*0.5;
	B[N-1][0] = (B[N-2][0] + B[N-1][1])*0.5;
	B[N-1][M-1] = (B[N-2][M-1] + B[N-1][M-2])*0.5;
	new_temps();
	return;
}

float maxtemp(float matrix[N][M]){
	int i, j;
	float temp = matrix[0][0];
	for (i=0 ; i<N ; i++) for (j=0 ; j<M ; j++) if (matrix[i][j]>temp) temp=matrix[i][j];
	return temp;
}

float mintemp(float matrix[N][M]){
	int i, j;
	float temp = matrix[0][0];
	for (i=0 ; i<N ; i++) for (j=0 ; j<M ; j++) if (matrix[i][j]<temp) temp=matrix[i][j];
	return temp;
}

void kanonikopoihsh(float Q[N][M]){
	float mint = mintemp(Q);
	float diafora = (maxtemp(Q) - mint) / 10.0;
	float C[N][M];
	int k;
	for (int i=0 ; i<N ; i++) for (int j=0 ; j<M ; j++){
		k = 9;
		while (Q[N][M] < mint + k*diafora) k = k - 1;
		C[i][j] = k;
	}
	puts("Normalized:\n");
	printarray(C);
	return;
}

int main(int argc, char *argv[]) {
	float maxt, mint;
	puts("Matrix A:");
	fillA();
	printarray(A);
	putchar('\n');
	kanonikopoihsh(A);
	putchar('\n');
	
	puts("Matrix B:");
	fillB();
	printarray(B);
	putchar('\n');
	kanonikopoihsh(B);
	putchar('\n');
	
	system("pause");
	return 0;
}
