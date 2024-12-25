#include<iostream>

using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;

	if (A < B) {
		cout << "Bus" << '\n';
	}
	else if (A == B) {
		cout << "Anything" << '\n';
	}
	else {
		cout << "Subway" << '\n';
	}

	return 0;
}