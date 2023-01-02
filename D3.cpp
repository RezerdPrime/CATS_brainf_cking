#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(x,y) (x > y) ? x : y
#define min(x,y) (x < y) ? x : y

int main() {
    FILE* fin = fopen("input.txt", "r"),
        * fout = fopen("output.txt", "w");

    int a, b, copy1, copy2;
    fscanf(fin, "%d %d", &a, &b); copy1 = a, copy2 = b;
    int maximum = max(a, b), minimum = min(a, b);

    while ((maximum > 0) and (minimum > 0))
    {
        maximum %= minimum; a = maximum; b = minimum;
        maximum = max(a, b);
        minimum = min(a, b);
    }

    int HOK = maximum * (copy1 / maximum) * (copy2 / maximum);

    fprintf(fout, "%d %d", maximum, HOK);
}