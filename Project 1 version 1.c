#include <stdio.h>
#include <stdlib.h>

int sxhmaeis() {
	puts("Choose:");
	printf_s("0: Tetragono\n1: Parallilogrammo keklimeno deksia\n2: Parallilogrammo keklimeno aristera\n3: Tetragono se tetragono\n4: Katw velos\n5: Anw velos\n");
	int i;
	scanf_s("%d", &i);
	while (i < 0 || i>5) {
		puts("Mh apodekth timh");
		scanf_s("%d", &i);
	}
	return i;
}

int megeis() {
	puts("Epilexte megethos apo 0 ews 19: ");
	int i;
	scanf_s("%d", &i);
	while (i < 0 || i>19) {
		puts("Mh apodekth timh. Epilexte megethos apo 0 ews 19: ");
		scanf_s("%d", &i);
	}
	return i;
}

void tetr(int megethos) {
	puts("tetr");
	printf("%d", megethos);
}
void paright(int megethos) {
	puts("paright");
	printf("%d", megethos);
}
void parleft(int megethos) {
	puts("parleft");
	printf("%d", megethos);
}
void tetrtetr(int megethos) {
	puts("tetrtetr");
	printf("%d", megethos);
}
void arrowdown(int megethos) {
	puts("arrowdown");
	printf("%d", megethos);
}
void arrowup(int megethos) {
	puts("arrowup");
	printf("%d", megethos);
}

int main() {
	int contin = 1;
	while (contin == 1) {
		int sxhma, megethos;
		sxhma = sxhmaeis();
		megethos = megeis();
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