#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define true 1
#define false 0
typedef int boolean;

int main() {

    FILE* fin = fopen("input.txt", "r"),
        * fout = fopen("output.txt", "w");

    float x1, x2, y1, y2, xp, yp;
    boolean cond1 = false,
            cond2 = true;

    fscanf(fin, "%f %f %f %f", &x1, &y1, &x2, &y2);
    if ((x1 > 0) and (x1 < 9) and (x2 > 0) and (x2 < 9) and
        (y1 > 0) and (y1 < 9) and (y2 > 0) and (y2 < 9)) {

        cond1 = (fabs(x1 - x2) == fabs(y1 - y2));
        if ((cond1 == true) and ((fabs(x1 - x2) > 1) and (fabs(y1 - y2) > 1))) {

            if (((x1 < x2) and (y1 > y2)) or ((x1 > x2) and (y1 < y2))) {
                fprintf(fout, "%d %d", (int)ceil((x1 + x2) / 2), (int)floor((y1 + y2) / 2));
            }
            else {
                fprintf(fout, "%d %d", (int)ceil((x1 + x2) / 2), (int)ceil((y1 + y2) / 2));
            }
        }
        else if ((cond1 == true) and (fabs(x1 - x2) <= 1) and (fabs(y1 - y2) <= 1)) {
            fprintf(fout, "%d", 0);
        }
        else if (cond1 == false) {

            for (int i = 1; i <= 8; i++) {
                for (int j = 1; j <= 8; j++) {

                    xp = i;
                    yp = j;
                    cond1 = ((fabs(xp - x1)) == (fabs(yp - y1))) and ((fabs(xp - x2)) == (fabs(yp - y2)));

                    if (cond1 == true) {
                        fprintf(fout, "%d %d", (int)xp, (int)yp);
                        cond2 = false;
                        break;
                    }
                }
                if (cond2 == false) { break; }
            }
            if (cond2 == true) { fprintf(fout, "%d", 0); }
        }
    }
    else { fprintf(fout, "%d", 0); }
}