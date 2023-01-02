#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
//#include <time.h>

int main() {
	//clock_t t0 = clock();

	FILE* fin = fopen("input.txt", "r"),
		* fout = fopen("output.txt", "w");

	int length; fscanf(fin, "%d", &length);
	int buf;
	auto binar = (int*)calloc(length, sizeof(int));

	for (int i = 0; i < (1 << length); ++i) {
		buf = i; //printf("%d\n", buf);

		for (int j = 0; ((buf > 0) or (j < length)); ++j) {
			binar[j] += buf % 2;
			buf /= 2;
		}

		for (int j = length - 1; j >= 0; --j) {
			fprintf(fout, "%d", binar[j]);
			binar[j] = 0;
		} fprintf(fout, "\n");
	}

	/*clock_t t1 = clock();
	double tis = difftime(t1, t0) / 1000;
	printf("%f", tis);*/
}