#include<iostream>
#include <vector>

int N, M;
std::vector<int> v;

void input() {
	std::cin >> N >> M;

	int tmp;
	for (int i = 0; i < N; ++i) {
		std::cin >> tmp;
		v.push_back(tmp);
	}
}

void solve() {

	int left = 0, right = 0;

	for (int i = 0; i < v.size(); ++i) {
		right += v[i];
		if (v[i] > left) left = v[i];
	}

	while (left < right) {
		int mid = (left + right) / 2;

		int cnt = 1, tmp = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (tmp + v[i] <= mid) {
				tmp += v[i];
			}
			else {
				tmp = v[i];
				cnt++;
			}
		}

		if (cnt <= M) {
			right = mid;
		}
		else {
			left++;
		}
	}

	std::vector<int> ans;

	int tmp = 0;
	int cnt = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (tmp + v[i] > left) {
			ans.push_back(cnt);
			cnt = 0;
			tmp = 0;
		}
		tmp += v[i]; cnt++;

		// 남는게 없어요...
		if (v.size() - i == M - ans.size()) {
			ans.push_back(cnt);
			while (ans.size() != M) {
				ans.push_back(1);
			}
			break;
		}


	}

	std::cout << left << '\n';
	for (int i = 0; i < ans.size(); ++i) {
		if (i != ans.size() - 1) std::cout << ans[i] << ' ';
		else std::cout << ans[i] << '\n';
	}

}

int main() {

	input();
	solve();

	return 0;
}