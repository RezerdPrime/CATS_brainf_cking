#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inf("a.in");
    ofstream outf("a.out");

    int K = 20, N = 25, page, string; inf >> K >> N;

    if (N % K != 0) {

        page = N / K + 1;
        string = N - (N / K) * K;
    }

    else {
        page = N / K;
        string = K;
    }

    outf << page << " " << string;

    //cout << page << " " << string;

    inf.close(); outf.close();
}
