#include <stdio.h>
#include <stdlib.h>

int sxhmaeis() {
	puts("Choose shape:");
	printf("0: Tetragono\n1: Parallilogrammo keklimeno deksia\n2: Parallilogrammo keklimeno aristera\n3: Tetragono se tetragono\n4: Katw velos\n5: Anw velos\n");
	int i;
	printf("Shape: ");
	scanf_s("%d", &i);
	printf("\n");
	while (i < 0 || i>5) {
		puts("Mh apodekth timh");
		scanf_s("%d", &i);
	}
	return i;
}

int megeis() {
	printf("Epilexte megethos apo 0 ews 19: ");
	int i;
	scanf_s("%d", &i);
	printf("\n");
	while (i < 0 || i>19) {
		puts("Mh apodekth timh. Epilexte megethos apo 0 ews 19: ");
		scanf_s("%d", &i);
	}
	return i;
}

int roundtothree(int megethos) {
	if (megethos % 3 == 0) return megethos;
	else if ((megethos - 1) % 3 == 0) {
		printf("New size: %d\n", --megethos);
		return megethos;
	}
	else {
		printf("New size: %d\n", ++megethos);
		return megethos;
	}
}

int roundtotwo(int megethos) {
	if (megethos % 2 == 0) return megethos / 2;
	else return --megethos / 2;
}

void tetr(int megethos) {
	int i, j;
	for (i = 0; i < megethos; i++) {
		for (j = 0; j < megethos; j++) {
			if (i == 0 || i == megethos - 1 || j == 0 || j == megethos - 1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}

void paright(int megethos) {
	int i, j, k;
	for (k = 1; k < megethos; k++) printf(" ");
	for (i = 0; i < megethos; i++) printf("*");
	printf("\n");

	for (i = 1; i <= megethos - 2; i++) {
		for (k = megethos; k>i + 1; k--) printf(" ");
		for (j = 0; j < megethos; j++) {
			if (j == 0 || j == megethos - 1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	for (i = 0; i < megethos; i++) printf("*");
}

void parleft(int megethos) {
	int i, j, k;
	for (i = 0; i < megethos; i++) printf("*");
	printf("\n");

	for (i = 1; i <= megethos - 2; i++) {
		for (k = 0; k<i; k++) printf(" ");
		for (j = 0; j < megethos; j++) {
			if (j == 0 || j == megethos - 1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	for (k = 1; k<megethos; k++) printf(" ");
	for (i = 0; i < megethos; i++) printf("*");
}

void tetrtetr(int megethos) {
	int i, j;
	megethos = roundtothree(megethos);
	for (i = 1; i <= megethos; i++) {
		for (j = 1; j <= megethos; j++) {
			if (j == megethos) printf("*\n");
			else if (i == 1 || j == 1 || i == megethos) printf("*");
			else if ((i == megethos / 3 + 1 && j >= megethos / 3 + 1 && j <= megethos * 2 / 3) || (j == megethos / 3 + 1 && i >= megethos / 3 + 1 && i <= megethos * 2 / 3) || (i == megethos * 2 / 3 && j >= megethos / 3 + 1 && j <= megethos * 2 / 3) || (j == megethos * 2 / 3 && i >= megethos / 3 + 1 && i <= megethos * 2 / 3)) printf("*");
			else printf(" ");
		}
	}
}

void arrowdown(int megethos) {
	int i, j, k;
	megethos = roundtothree(megethos);
	int m1 = megethos / 3;
	int height1 = roundtotwo(megethos);
	//1st row
	for (i = 0; i < m1; i++) printf(" ");
	for (i = 0; i < m1; i++) printf("*");
	printf("\n");
	//tail
	for (i = 1; i < height1; i++) {
		for (j = 0; j < m1; j++) printf(" ");
		printf("*");
		for (j = 0; j < m1 - 2; j++) printf(" ");
		printf("*");
		for (j = 0; j < m1; j++) printf(" ");
		printf("\n");
	}
	//1st row pointer
	for (i = 0; i < m1 + 1; i++) printf("*");
	for (i = 0; i < m1 - 2; i++) printf(" ");
	for (i = 0; i < m1 + 1; i++) printf("*");
	printf("\n");
	//pointer
	for (i = 1; i < height1; i++) {
		for (k = 0; k<i; k++) printf(" ");
		printf("*");
		for (k = 0; k<megethos - 2 - 2 * i; k++) printf(" ");
		puts("*");
	}
	//last line
	if (megethos == 3 || megethos == 9 || megethos == 15) {
		for (i = 1; i < megethos / 2 + 1; i++) printf(" ");
		puts("*");
	}
}

void arrowup(int megethos) {
	int i, j, k;
	megethos = roundtothree(megethos);
	int m1 = megethos / 3;
	int height1 = roundtotwo(megethos);

	if (megethos == 3 || megethos == 9 || megethos == 15) {
		for (i = 1; i < megethos / 2 + 1; i++) printf(" ");
		puts("*");
	}
	//pointer
	for (i = 1; i < height1; i++) {
		for (k = 0; k<megethos / 2 - i; k++) printf(" ");
		printf("*");
		for (j = 0; j<megethos-2-2*k; j++) printf(" ");
		puts("*");
	}
	//1st row pointer
	for (i = 0; i < m1 + 1; i++) printf("*");
	for (i = 0; i < m1 - 2; i++) printf(" ");
	for (i = 0; i < m1 + 1; i++) printf("*");
	printf("\n");
	//tail
	for (i = 1; i < height1; i++) {
		for (j = 0; j < m1; j++) printf(" ");
		printf("*");
		for (j = 0; j < m1 - 2; j++) printf(" ");
		printf("*");
		for (j = 0; j < m1; j++) printf(" ");
		printf("\n");
	}
	//1st row
	for (i = 0; i < m1; i++) printf(" ");
	for (i = 0; i < m1; i++) printf("*");
	printf("\n");
}

int main() {
	int contin = 1;
	while (contin == 1) {
		int sxhma = sxhmaeis();
		int megethos = megeis();
		//epilogh sxhmatos
		if (sxhma == 0) tetr(megethos);
		else if (sxhma == 1) paright(megethos);
		else if (sxhma == 2) parleft(megethos);
		else if (sxhma == 3) tetrtetr(megethos);
		else if (sxhma == 4) arrowdown(megethos);
		else if (sxhma == 5) arrowup(megethos);
		//
		puts("\nContinue?<0/1>");
		scanf_s("%d", &contin);
	}
}