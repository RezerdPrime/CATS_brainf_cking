#define _CRT_SECURE_NO_WARNINGS
#define elif else if
#include <stdio.h>

int main() {
    FILE* fin = fopen("input.txt", "r"),
        * fout = fopen("output.txt", "w");

    char raw_data[5] = {}, 
         fried_data[5] = {};
    int condition = 0;

    for (int i = 0; i < 5; i++) {
        raw_data[i] = fgetc(fin);

        /////////////////////////////////////////////////////////// пробовал оформить через свич, но все полетело, решил засрать ифами(9(((

        if ((raw_data[i] == '=') and (condition == 0)) {
            fried_data[i] = '*';
            continue;
        }

        elif ((raw_data[i] == '=') and (condition == 1)) {
            fried_data[i] = '-';
            continue;
        }

        elif ((raw_data[i] == '=') and (condition == 2)) {
            fried_data[i] = '+';
            continue;
        }
        ///////////////////////////////////////////////////////////

        elif ((raw_data[i] == '<') and (condition == 0)) {
            fried_data[i] = '+';
            condition = 2;
            continue;
        }

        elif ((raw_data[i] == '<') and (condition == 1)) {
            fried_data[i] = '?';
            condition = 3;
            continue;
        }

        elif ((raw_data[i] == '<') and (condition == 2)) {
            fried_data[i] = '+';
            continue;
        }
        ///////////////////////////////////////////////////////////

        elif ((raw_data[i] == '>') and (condition == 0)) {
            fried_data[i] = '-';
            condition = 1;
            continue;
        }

        elif ((raw_data[i] == '>') and (condition == 1)) {
            fried_data[i] = '-';
            continue;
        }

        elif ((raw_data[i] == '>') and (condition == 2)) {
            fried_data[i] = '?';
            condition = 3;
            continue;
        }
        ///////////////////////////////////////////////////////////

        if (condition == 3) {
            fried_data[i] = '?';
            continue;
        }
    }

    for (int i = 0; i < 5; i++) { fprintf(fout, "%c", fried_data[i]); }
}