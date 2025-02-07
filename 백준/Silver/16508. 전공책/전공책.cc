#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct book {
	
	int price;
	int alp[26];
};

int answer = -1;
int ans[26] = { 0 };
int sum[26] = { 0 };
vector<book> books;

bool isCann() {

	for (int i = 0; i < 26; ++i) {

		if (sum[i] < ans[i]) {

			return false;
		}
	}

	return true;
}

void DFS(int idx, int sumPrice) {

	if (idx == books.size()) {

		if (answer == -1 || sumPrice < answer) {

			answer = sumPrice;
		}

		return;
	}

	// 빼버리기
	for (int j = 0; j < 26; ++j) {
			
		sum[j] -= books[idx].alp[j];
	}
		
	// 빼도 가능
	if (isCann()) {
		
		DFS(idx + 1, sumPrice - books[idx].price);
	}

	// 다시 넣기
	for (int j = 0; j < 26; ++j) {

		sum[j] += books[idx].alp[j];
	}

	DFS(idx + 1, sumPrice);
}

int main() {

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); ++i) {

		ans[str[i] - 'A']++;
	}

	int N;
	cin >> N;

	int sumPrice = 0;
	for (int i = 0; i < N; ++i) {
		int tmp;
		string tmpstr;

		cin >> tmp >> tmpstr;

		sumPrice += tmp;
		int count[26] = { 0 };

		book nbook = {};
		nbook.price = tmp;

		for (int j = 0; j < tmpstr.size(); ++j) {

			nbook.alp[tmpstr[j] - 'A']++;
			sum[tmpstr[j] - 'A']++;
		}

		books.push_back(nbook);
	}
	
	if (isCann()) {

		DFS(0, sumPrice);
	}

	cout << answer << '\n';

	return 0;
}