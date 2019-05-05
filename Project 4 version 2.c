#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 20
#define N 60

int Q[M][N], area[M][N], newarea[M][N], testmatrix[M][N];
void filltable(void);
void printtable(void);
int eisodos(void);
//void play(void);
void botplay(void);
int checktable(void);
void checkarea(void);
void candy_cane_miss_fortune(void);
int Red_Card_Katarina(void);

int main(int argc, char *argv[]) {
	int prospatheies = 0;
	filltable();
	printtable();
	area[0][0]++;
	do {
		//play();
		botplay();
		checkarea();
		prospatheies++;
		printtable();
	} while (checktable() == 1);
	printf("End of game\nProspatheies: %d\n", prospatheies);
	system("pause");
	return 0;
}

void filltable(void) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			do Q[i][j] = (rand() % 6); while (Q[i][j] == 0);
	return;
}

void printtable(void) {
	int i, j;
	for (i = 0; i<M; i++) {
		for (j = 0; j<N; j++) {
			printf("%d ", Q[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	return;
}

int eisodos(void) {
	int eis;
	while (1) {
		puts("Choose a number [1-5]: ");
		scanf_s("%d", &eis);
		putchar('\n');
		if (eis < 1 || eis > 5) puts("Mh apodekth epilogh\n");
		else break;
	}
	putchar('\n');
	return eis;
}

int checktable(void) {
	for (int i = 0; i<M; i++)
		for (int j = 0; j<N; j++)
			if (Q[i][j] != Q[0][0]) return 1;
	return 0;
}

void checkarea(void) {
	candy_cane_miss_fortune();
	do {
		for (int i = 0; i < M - 1; i++) for (int j = 0; j < N - 1; j++)
			if (area[i][j] == 1) {
				if (Q[i][j] == Q[i + 1][j]) area[i + 1][j] = 1;
				if (i > 0 && Q[i][j] == Q[i - 1][j]) area[i - 1][j] = 1;
				if (Q[i][j] == Q[i][j + 1]) area[i][j + 1] = 1;
				if (j > 0 && Q[i][j] == Q[i][j - 1]) area[i][j - 1] = 1;
			}
	} while (Red_Card_Katarina() == 1);
	return;
}

/*void play(void) {
	int i, j, eis = eisodos();
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			if (area[i][j] == 1) Q[i][j] = eis;
}*/

void candy_cane_miss_fortune(void) {
	for (int i = 0; i<M; i++)
		for (int j = 0; j<N; j++)
			newarea[i][j] = area[i][j];
	return;
}

int Red_Card_Katarina(void) {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (area[i][j] != newarea[i][i]) return 0;
	return 1;
}

void botplay(void) {
	int i, j, eis = eisodos();
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			if (area[i][j] == 1) Q[i][j] = eis;
}