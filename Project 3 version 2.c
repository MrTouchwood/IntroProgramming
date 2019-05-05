#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 7
#define N 7
#define paula '-'
char Q[M][N];

void filltable(void) {
	int i, j;
	for (i = 0; i<M; i++) {
		for (j = 0; j<N; j++) {
			Q[i][j] = '-';
		}
	}
	return;
}

void printtable(void) {
	int i, j;
	for (i = 0; i<M; i++) {
		for (j = 0; j<N; j++) {
			printf("%c", Q[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	return;
}

void play(int player) {
	int i = N, sthlh = -1;
	const char symbol = (player == 1 ? '+' : '*');
	printf("Player: %d\n", player);
	while (1) {
		puts("Epilexte stili");
		scanf_s("%d", &sthlh);
		if (sthlh < 0 || sthlh>6) puts("Mh apodekth timh");
		else {
			if (Q[0][sthlh] != paula) puts("Stili pliris");
			else break;
		}
	}
	while (--i >= 0) if (Q[i][sthlh] == paula) {
		Q[i][sthlh] = symbol;
		break;
	}
	return;
}

int checkdraw(int player) {
	int i, j, counter;
	const char symbol = (player == 1 ? '+' : '*');
	//orizontios elegxos
	for (i = 0; i<M; i++) {
		counter = 0;
		for (j = 0; j<N; j++) counter = Q[i][j] == symbol ? counter + 1 : 0;
		if (counter >= 4) return (player == 1) ? 1 : 2;
	}
	//katakoryfos elegxos
	for (i = 0; i<M; i++) {
		counter = 0;
		for (j = 0; j<N; j++) counter = Q[j][i] == symbol ? counter + 1 : 0;
		if (counter >= 4) return (player == 1) ? 1 : 2;
	}
	//diagwnios elegxos
	return 0;
}

int main(int argc, char *argv[]){
	int contin = 1, turn = 1, player = 1, win;
	do {
		filltable();
		printtable();
		do {
			play(player);
			printtable();
			win = checkdraw(player);
			player = player == 1 ? ++player : --player;
		} while (++turn <= M*N && win == 0);

		if (win == 1) puts("Player 1 wins");
		else if (win == 2) puts("Player 2 wins");
		else puts("Isopalia");
	
		puts("\nContinue?<1/0>");
		scanf_s("%d", &contin);
		putchar('\n');
	} while (contin == 1);
	system("PAUSE");
	return 0;
}