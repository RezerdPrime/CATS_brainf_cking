#include <stdio.h>

int main(){
    FILE * file_in = fopen("input.txt", "r");
    FILE * file_out = fopen("output.txt", "w");

    int N, arr_element, sum = 0; fscanf(file_in, "%d", &N);

    for (int i = 0; i < N; ++i){
        fscanf(file_in, "%d", &arr_element);
        sum += arr_element;
        //printf("%d\n", sum);/////
    }
    fprintf(file_out, "%d", sum);
}
