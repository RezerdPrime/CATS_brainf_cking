#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

int main() {
	FILE* fin = fopen("input.txt", "r"),
		* fout = fopen("output.txt", "w");

	int arr_size, OP_count, right_i, left_i;
	fscanf(fin, "%d", &arr_size);

	auto arr = (int*)malloc(sizeof(int) * arr_size);

	fscanf(fin, "%d", &arr[0]);
	for (int i = 1; i < arr_size; ++i) {
		fscanf(fin, "%d", &arr[i]);
		arr[i] += arr[i - 1];
	}

	//for (int i = 0; i < arr_size; ++i) { printf("%d ", arr[i]); } printf("\n");

	fscanf(fin, "%d", &OP_count);
	for (int i = 0; i < OP_count; ++i) {

		fscanf(fin, "%d %d", &left_i, &right_i);
		fprintf(fout, "%d ", arr[right_i - 1] - (((left_i - 2) >= 0) ? arr[left_i - 2] : 0));
	} 
}