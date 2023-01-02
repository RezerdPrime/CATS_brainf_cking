#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE* fin = fopen("input.txt", "r"),
		* fout = fopen("output.txt", "w");

	int main_number; fscanf(fin, "%d", &main_number);
	int A_num = 0, B_num = 2 << 29, _index;

	int aod[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; // array of digits

	for (int i = 0; (i < 10 and main_number != 0); i++) {
		aod[i] = main_number % 10;
		main_number /= 10;
		//printf("%d\n", aod[i]);
	}

	for (int i = 0; i < 10; i++) {
		if ((aod[i] < B_num) and (aod[i] != -1)) {
			B_num = aod[i];
			_index = i;
		}
	} aod[_index] = -1; //printf("%d\n", B_num);

	int bufer = -(2 << 29);

	while ( !((aod[0] == -1) and (aod[1] == -1) and (aod[2] == -1) and
		      (aod[3] == -1) and (aod[4] == -1) and (aod[5] == -1) and
		      (aod[6] == -1) and (aod[7] == -1) and (aod[8] == -1)) ) {

		for (int i = 0; i < 10; i++) {
			if ((aod[i] > bufer) and (aod[i] != -1)) {
				bufer = aod[i];// printf("%d \n", bufer);
				_index = i;
			}
		} 
		aod[_index] = -1; A_num += bufer; A_num *= 10; bufer = -(2 << 29);
		//printf("%d %d %d %d %d %d %d %d %d\n", aod[0], aod[1], aod[2], aod[3], aod[4], aod[5], aod[6], aod[7], aod[8]);
		//printf("%d <> %d\n", A_num, B_num);
	}

	fprintf(fout, "%d\n%d", A_num / 10, B_num);
}