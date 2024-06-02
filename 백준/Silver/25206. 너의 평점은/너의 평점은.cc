#include<iostream>
#include<string>

using namespace std;

int main() {
	
	double sum = 0;
	double den = 0;

	for (int i = 0; i < 20; ++i) {
		string str, grd;
		double scr;

		cin >> str >> scr >> grd;
		den += scr;

		if (grd == "A+") {
			sum += scr * 4.5;
		}
		else if (grd == "A0") {
			sum += scr * 4.0;
		}
		else if (grd == "B+") {
			sum += scr * 3.5;
		}
		else if (grd == "B0") {
			sum += scr * 3.0;
		}
		else if (grd == "C+") {
			sum += scr * 2.5;
		}
		else if (grd == "C0") {
			sum += scr * 2.0;
		}
		else if (grd == "D+") {
			sum += scr * 1.5;
		}
		else if (grd == "D0") {
			sum += scr * 1.0;
		}
		else if (grd == "P") {
			den -= scr;
		}
	}

	double answer = sum / den;

	cout << answer << '\n';

	return 0;
}