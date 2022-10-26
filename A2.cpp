#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream in_f("input.txt");
    ofstream out_f("output.txt");

    int A;
    in_f >> A;

    if (A >= 0 and A <= 100){
        out_f << 2;
    }

    if (A <= -1 and A >= -100){
        out_f << 4;
    }

    if (A > 100 and A % 100 == 0){
        out_f << A / 100 + 1;
    }

    if (A > 100 and A % 100 != 0){
        out_f << A / 100 + 2;
    }

    if (A < -100 and abs(A) % 100 == 0){
        out_f << abs(A) / 100 + 3;
    }

    if (A < -100 and abs(A) % 100 != 0){
        out_f << abs(A) / 100 + 4;
    }
}
