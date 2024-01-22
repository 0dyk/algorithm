#include <iostream>

using namespace std;

int main() {

	// 무한 반복..? 
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;

		if (!a && !b && !c) {
			break;
		}

		int tmp = a;
		if (tmp < b) {
			tmp = b;
		}
		if (tmp < c) {
			tmp = c;
		}

		int tmp2 = a + b + c - tmp;

		// 불가능
		if (tmp >= tmp2) {
			cout << "Invalid" << '\n';
		}
		// 가능
		else if (a == b && b == c) {
			cout << "Equilateral" << '\n';
		}
		else if (a != b && b != c && c != a) {
			cout << "Scalene" << '\n';
		}
		else {
			cout << "Isosceles" << '\n';
		}
	}

	return 0;
}