#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 7
#define N 7
#define paula '-'
char Q[M][N];

void filltable(){
	puts("filltable");
}

void printtable(){
	puts("printtable");
}

void play() {
	puts("play");
}

void checkdraw(){
	puts("checkdraw");
}

int main(int argc, char *argv[]) {
	int contin = 1;
	do {
		filltable();
		printtable();
		play();
		checkdraw();
		puts("\nContinue?<1/0>");
		scanf_s("%d", &contin);
		putchar('\n');
	} while (contin == 1);
	system("PAUSE");
	return 0;
}