#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 7
#define N 7
#define paula '-'
char Q[M][N];

void filltable(){
	int i,j;
	for (i = 0; i<M; i++) {
		for (j = 0; j<N; j++) {
			Q[i][j]='-';
		}
	}
	return;
}

void printtable(){
	int i,j;
	for (i = 0; i<M; i++) {
		for (j = 0; j<N; j++) {
			printf("%c",Q[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	return;
}

void play(int player){
	int i = N, sthlh = -1;
	const char symbol = (player == 1 ? '+' : '*');
	printf("Player: %d\n", player);
	while(sthlh<0 || sthlh>6){
		full: puts("Epilexte stili");
		scanf_s("%d", &sthlh);
		if (Q[0][sthlh] != paula) {
			puts("Stili pliris");
			goto full;
		}
		else if (sthlh > 0 && sthlh < 6) break;
	}
	while (--i >= 0) if (Q[i][sthlh] == paula) {
			Q[i][sthlh] = symbol;
			break;
	}
	return;
}

int main(int argc, char *argv[]){
	int contin = 1, turn=1, player=1;
	do {
		filltable();
		printtable();
		do {
			play(player);
			printtable();
			player = player == 1 ? ++player : --player;
		}while (++turn <= M*N);
		puts("\nContinue?<1/0>");
		scanf_s("%d", &contin);
		putchar('\n');
	} while (contin == 1);
	system("PAUSE");
	return 0;
}