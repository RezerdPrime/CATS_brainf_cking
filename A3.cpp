#include <iostream>
#include <fstream>
//#include <ctime>////
using namespace std;

int main()
{
    ifstream in_f("input.txt");
    ofstream out_f("output.txt");

    int k = 0, n, rev = 0; // 1028 -> 8201 ->   1  +  0 * 10  +  2 * 100  +  8 * 1000
    in_f >> n; int i2;

    //clock_t t0 = clock();////

    for (int i = 1; i < n; i++) {

        i2 = i;
        while (i2 > 0) {
            rev += i2 % 10; rev *= 10;
            i2 /= 10;
        } rev /= 10;

        if (i + rev == n) {
            k++;
            //cout << i << " " << rev << endl;////
        } rev = 0;
    }

    /*clock_t t1 = clock();////

    //cout << t0 << " " << t1 << endl;////

    //cout << difftime(t1, t0) / 1000. << endl;////*/

    out_f << k;
}
