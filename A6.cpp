#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int color_count, col_num; fin >> color_count;

    for (int z_coord = 0; z_coord < color_count; z_coord++) {

        for (int y_coord = 0; y_coord < color_count; y_coord++) {

            col_num = 0;
            for (int x_coord = 0; x_coord < color_count; x_coord++) {

                col_num += 1;
                string result = to_string(((z_coord + y_coord + x_coord) % color_count) + 1);

                if (col_num < color_count) { result += " "; }
                fout << result;
            }
            fout << endl;
        }
    }
}