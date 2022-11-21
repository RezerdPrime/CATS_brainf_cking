#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int shear_f(int pch, int fc) {

    switch (pch) {
    case(0): {
        if (fc % 2 == 0) { return 0; }
        else { return 4; }
    }
    case(1): {
        if (fc % 3 == 0) { return 0; }
        if (fc % 3 == 1) { return 4; }
        if (fc % 3 == 2) { return 2; }
    }
    case(2): {
        if (fc % 2 == 0) { return 0; }
        else { return 4; }
    }
    case(3): {
        if (fc % 3 == 0) { return 0; }
        if (fc % 3 == 1) { return 4; }
        if (fc % 3 == 2) { return 2; }
    }
    } // Ну мне тупо было влом копировать 4 раза этот кусок кода, без которого ничего бы не сработало
} // Это кста смена чётности

int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int W, H, D, W1, H1, D1;
    fin >> W >> H >> D;
    fin >> W1 >> H1 >> D1;

    if (W1 == 0 or H1 == 0 or D1 == 0) { W1 = 0; H1 = 0; D1 = 0; } // Ну типа если хотя бы 1 элемент будет равен 0
    // то мы вычитаем фигуру, у которой тупо меньше измерений. Какой смысл вычитать двумерную плоскость из трёхмерного куба?

    string line = "", empty_space = "", the_final_fixing_shit = "",
        subline1 = "", subline2 = "", subline3 = "", subline4 = "", reserveline, // для верхних и передних граней
        right_part1 = "", right_part2 = " |/| + |/| +", /* для боковых граней */
        right_symbols_list[] = { " +", " |", "/|" },
        rsl2[] = { " |", "/|", " +" };

    for (int j = 0; j < W; j++) {
        subline1 += "+---";
        subline2 += "/   ";
    } subline1 += "+"; subline2 += "/|";

    int pic_y = 3 * H + 2 * D + 1, // Количество строк (максимальная высота 2Д рисунка)
        pic_x = 2 * D + 4 * W + 1, // Количество столбцов (максимальная длина 2Д рисунка)
        shear = 0, // Сдвиг для внешней боковой грани
        parity_change = 0; the_final_fixing_shit.insert(0, pic_x, ' ');// cout << the_final_fixing_shit << "a" << endl;

    int count_of_dots = 2 * D,
        count = 0, count2 = 0, /* для чётностей разных секторов */
        str_count = 0, line_count = 0, pic_str_count = 0, fin_count = 0, /* чисто для учёта чётности для рисования грани */
        sub_line_limit = count_of_dots + W * 4 + 1,
        sub_line_limit2 = sub_line_limit - (4 * W1) + 1; // Для срезов строк
    //fout << sub_line_limit << " " << sub_line_limit2 << endl;

    // --- 1 (построение части верхней грани без среза)

    for (int i = 0; i < 2 * (D - D1) + 1; i++) {
        right_part1 += right_symbols_list[count % 3]; count++;
        right_part2 += rsl2[pic_str_count % 3];

        if (pic_str_count >= 3 * H + 1) { sub_line_limit--; empty_space += " "; }

        // ----

        if (((parity_change == 0) and (pic_str_count == 2 * (D - D1))) or ((parity_change == 1) and (pic_str_count == 2 * (D - D1) + 3 * H1))
            or ((parity_change == 2) and (pic_str_count == 2 * (D - D1) + 3 * H1 + 2 * D1))) {
            parity_change += 1; fin_count = 0;
        } shear = shear_f(parity_change, fin_count);

        // ----

        if (str_count % 2 == 0) {

            line.insert(0, count_of_dots - i, '.');
            fout << ((line + subline1 + right_part2.substr(shear, right_part2.length())).substr(0, sub_line_limit) + the_final_fixing_shit).substr(0, pic_x) << endl;///
            line = ""; str_count++; sub_line_limit2--;
        }

        else {

            line.insert(0, count_of_dots - i, '.');
            fout << ((line + subline2 + right_part2.substr(shear, right_part2.length())).substr(0, sub_line_limit) + the_final_fixing_shit).substr(0, pic_x) << endl;///
            line = ""; str_count++; sub_line_limit2--;
        } pic_str_count++; fin_count++;
    } subline1 = ""; subline2 = "";

    for (int j = 0; j < (W - W1); j++) {
        subline1 += "+---";
        subline2 += "/   ";
    } subline1 += "+"; subline2 += "/|";

    for (int j = 0; j < W1; j++) {
        subline3 += "   |";
        subline4 += "---+";
    }

    // --- 2 (построение части верхней грани со срезом)

    for (int i = count_of_dots - 2 * (D - D1) - 1; i > 0; i--) {
        right_part2 += rsl2[pic_str_count % 3];
        if (pic_str_count >= 3 * H + 1) { sub_line_limit--; empty_space += " "; }

        // ----

        if (((parity_change == 0) and (pic_str_count == 2 * (D - D1))) or ((parity_change == 1) and (pic_str_count == 2 * (D - D1) + 3 * H1))
            or ((parity_change == 2) and (pic_str_count == 2 * (D - D1) + 3 * H1 + 2 * D1))) {
            parity_change += 1; fin_count = 0;
        } shear = shear_f(parity_change, fin_count);

        // ----

        if (line_count >= 3 * H1) { sub_line_limit2--; }

        if (count2 >= 3 * H1) {
            subline3 = ""; subline4 = "";
            for (int l = 0; l < W1; l++) {
                subline3 += "   /";
                subline4 += "---+";
            } subline3 += "|";

            int fixer = count2;///
            if ((H % 2 != 0 or H % 2 == 0) and (H1 % 2 == 0)) { fixer = count; }

            reserveline = (fixer % 2 == 0) ? subline4 : subline3;
        }
        else { reserveline = ((count2 % 3 == 1) or (count2 % 3 == 0)) ? subline3 : subline4; }

        if (i % 2 == 0) {
            line.insert(0, i, '.');
            right_part1 += right_symbols_list[count % 3];

            fout << ((line + subline1 + right_part1.substr(2, right_part1.length())).substr(0, sub_line_limit2)
                + reserveline + right_part2.substr(shear, right_part2.length())).substr(0, sub_line_limit) + empty_space << endl;

            count++; count2++; str_count++; line = "";
        }

        else {
            line.insert(0, i, '.');
            right_part1 += right_symbols_list[count % 3];

            fout << ((line + subline2 + right_part1).substr(0, sub_line_limit2)
                + reserveline + right_part2.substr(shear, right_part2.length())).substr(0, sub_line_limit) + empty_space << endl;

            count++; count2++; str_count++; line = "";
        } line_count++; pic_str_count++; fin_count++;
    } line = ""; subline1 = ""; subline2 = "";
    reserveline = ""; str_count = 0;

    // --- 3 (построение части передней грани со срезом)

    for (int j = 0; j < (W - W1); j++) {
        subline1 += "+---";
        subline2 += "|   ";
    } subline1 += "+"; subline2 += "|";

    for (int i = 0; i < 3 * H1; i++) {

        if (pic_str_count >= 3 * H + 1) { sub_line_limit--; empty_space += " "; }

        // ----

        if (((parity_change == 0) and (pic_str_count == 2 * (D - D1))) or ((parity_change == 1) and (pic_str_count == 2 * (D - D1) + 3 * H1))
            or ((parity_change == 2) and (pic_str_count == 2 * (D - D1) + 3 * H1 + 2 * D1))) {
            parity_change += 1; fin_count = 0;
        } shear = shear_f(parity_change, fin_count);

        // ----

        if (count2 >= 3 * H1) {
            subline3 = ""; subline4 = "";
            for (int l = 0; l < W1; l++) {
                subline3 += "   /";
                subline4 += "---+";
            } subline3 += "|";

            int fixer = count2;///
            if ((H % 2 != 0 or H % 2 == 0) and (H1 % 2 == 0)) { fixer = count; }

            reserveline = (fixer % 2 == 0) ? subline4 : subline3;
        }
        else { reserveline = ((count2 % 3 == 1) or (count2 % 3 == 0)) ? subline3 : subline4; }

        if (line_count >= 3 * H1) { sub_line_limit2--; }

        if (str_count % 3 == 0) {
            fout << ((subline1 + right_part1.substr(2, right_part1.length())).substr(0, sub_line_limit2)
                + reserveline + right_part2.substr(shear, right_part2.length())).substr(0, sub_line_limit) + empty_space << endl; str_count++;
        }
        else if (str_count % 3 == 1) {
            fout << ((subline2 + right_part1).substr(0, sub_line_limit2)
                + reserveline + right_part2.substr(shear, right_part2.length())).substr(0, sub_line_limit) + empty_space << endl; str_count++;
        }
        else if (str_count % 3 == 2) {
            fout << ((subline2 + right_part1.substr(4, right_part1.length())).substr(0, sub_line_limit2)
                + reserveline + right_part2.substr(shear, right_part2.length())).substr(0, sub_line_limit) + empty_space << endl; str_count++;
        } line_count++; count2++; count++; pic_str_count++; fin_count++;

    } line = ""; subline1 = ""; subline2 = ""; str_count = 0;

    // --- 4 (построение части передней грани без среза)

    if (W1 == 0 or H1 == 0 or D1 == 0) { str_count++; }

    for (int j = 0; j < W; j++) {
        subline1 += "+---";
        subline2 += "|   ";
    } subline1 += "+"; subline2 += "|";

    for (int i = 0; i < 3 * (H - H1) + 1 - (H1 == 0); i++) {

        if (pic_str_count >= 3 * H + 1) { sub_line_limit--; empty_space += " "; }

        // ----

        if (((parity_change == 0) and (pic_str_count == 2 * (D - D1))) or ((parity_change == 1) and (pic_str_count == 2 * (D - D1) + 3 * H1))
            or ((parity_change == 2) and (pic_str_count == 2 * (D - D1) + 3 * H1 + 2 * D1))) {
            parity_change += 1; fin_count = 0;
        } shear = shear_f(parity_change, fin_count);

        // ----

        if (str_count % 3 == 0) {

            fout << (subline1 + right_part2.substr(shear, right_part2.length())).substr(0, sub_line_limit) + empty_space << endl; str_count++;

        }
        else {
            fout << (subline2 + right_part2.substr(shear, right_part2.length())).substr(0, sub_line_limit) + empty_space << endl; str_count++;
        }
        pic_str_count++; fin_count++;
    }
    fin.close(); fout.close();
}


/*

Короче в чем юмор. Боковуха в срезе норм строится, а вот внешняя боковуха шлёт на три весёлые буквы.
Боковуха представляет собой единый орнамент, который меняется лишь смещением. Сиё смещение имеет
определённую чётность, которая в определённые моменты меняется. Ниже я пронаблюдал какие происхо-
дят смещения и когда именно они меняются. Также, я выделил последовательность для внешней боковухи.
Её я буду собирать в течении первых двух корневых форов.

..........+---+---+---+---+---+ |/| +  --> 0 (null) 0 -/ 0
........./   /   /   /   /   /| + |/|   -> 4
........+---+---+---+---+---+ |/| + |   -> 0
......./   /   /   /   /   /| + |/| +   -> 4
......+---+---+---+---+---+ |/| + |/|   -> 0
...../   /   /   /   /   /| + |/| + |   -> 4
....+---+---+---+---+---+ |/| + |/| +  --> 0 (2 * (D - D1)) 6 -/ 1
.../   /   /   /|   |   | + |/| + |/|   -> 4
..+---+---+---+ |   |   |/| + |/| + |   -> 2
./   /   /   /| +---+---+ |/| + |/| +   -> 0
+---+---+---+ |/|   |   | + |/| + |/|   -> 4
|   |   |   | + |   |   |/| + |/| + |   -> 2
|   |   |   |/| +---+---+ |/| + |/| +   -> 0
+---+---+---+ |/|   |   | + |/| + |/|   -> 4
|   |   |   | + |   |   |/| + |/| + |   -> 2
|   |   |   |/| +---+---+ |/| + |/| +  --> 0 (2 * (D - D1) + 3 * H1) 15 -/ 2
+---+---+---+ |/   /   /| + |/| + |/|   -> 4
|   |   |   | +---+---+ |/| + |/| + |   -> 0
|   |   |   |/   /   /| + |/| + |/| +   -> 4
+---+---+---+---+---+ |/| + |/| + |/|  --> 0 (2 * (D - D1) + 3 * H1 + 2 * D1) 19 -/ 3
|   |   |   |   |   | + |/| + |/| + |   -> 4
|   |   |   |   |   |/| + |/| + |/| +   -> 2
+---+---+---+---+---+ |/| + |/| + |/|   -> 0


х |/| + |/| + |/| + |/| + |/| + |/| + |/|х

иксами пометил начало и конец, ибо тут юзается пробел, который ес че оч важен.

{ " |", "/|", " +" }

*/
