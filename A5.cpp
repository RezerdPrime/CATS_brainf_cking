#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in_f("input.txt");
	ofstream out_f("output.txt");

	int hours, mins, all_min; in_f >> hours; in_f >> mins;
	all_min = 24 * 60 - (hours * 60 + mins);

	out_f << all_min / 60 << " " << all_min % 60;

	in_f.close(); out_f.close();
}
