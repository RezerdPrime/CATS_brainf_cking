#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in_f("input.txt");
    ofstream out_f("output.txt");

    int x, k, rez;

    in_f >> x; in_f >> k;

    if (k > 31) { out_f << 0; }

    else {
        rez = (x >> k) & 1;
        out_f << rez;
    }

    in_f.close(); out_f.close();
}
