#include <stdio.h>
#include <stdlib.h>

int sxhmaeis() {
	puts("sxhmaeis");
	int i;
	scanf_s("%d", &i);
	printf("%d\n", i);
	return 0;
}

int megeis() {
	puts("megeis");
	int i;
	scanf_s("%d", &i);
	printf("%d\n", i);
	return 5;
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
		puts("Continue?<0/1>");
		scanf_s("%d", &contin);
	}
}