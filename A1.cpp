#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inf("input.txt");
    ofstream outf("output.txt");

    int rubles, sweet_count, zwei_divs = 0, funf_divs = 0;
    inf >> rubles >> sweet_count;

    for (int i = 2; i < min(rubles, sweet_count); i++) {

        while ((rubles % i == 0) and (sweet_count % i == 0)) {
            rubles /= i;
            sweet_count /= i;
        }
    }
    
    while ((sweet_count % 2 == 0) or (sweet_count % 5 == 0)) {

        if (sweet_count % 2 == 0) {
            sweet_count /= 2; zwei_divs++;
        }

        if (sweet_count % 5 == 0) {
            sweet_count /= 5; funf_divs++;
        }
    }
    outf << sweet_count << " " << max(zwei_divs, funf_divs);
    inf.close();  outf.close();
}