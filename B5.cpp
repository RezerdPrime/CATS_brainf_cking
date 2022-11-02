#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inf("input.txt");
    ofstream outf("output.txt");

    float number; inf >> number;
    //cout << number << endl;
    int* l = (int*) &number;

    //cout << *l << endl;

    int pow = ((*l >> 23) & 255) - 127;

    if (number == 0) { pow = 0; }
    else if (pow < -126) { pow = -126; }
    
    outf << pow << endl;
    //cout << pow << endl;
}
