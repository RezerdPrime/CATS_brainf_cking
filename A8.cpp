#include <stdio.h>

int main() {

	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int num, max_el = -(2 << 30), current_el; fscanf(fin, "%d", &num);
	//printf("%d", max_el);

	while (num > 0) {

		fscanf(fin, "%d", &current_el);
		max_el = (current_el > max_el) ? current_el : max_el;
		num--;
	}

	fprintf(fout, "%d", max_el);
	//printf("%d", max_el);
}
