#include<iostream>
#include<unordered_map>

using namespace std;

int N, S;

int arr[41];

long long res;

unordered_map<int, int> um;

void leftCalcul(int x, int sum) {
	// 모두 체크하면
	if (x == N / 2) {
		if (um.find(sum) != um.end()) ++um[sum];
		else um[sum] = 1;

		return;
	}
	// 안뽑거나
	leftCalcul(x + 1, sum);
	// 뽑거나
	leftCalcul(x + 1, sum + arr[x]);
}

void rightCalcul(int x, int sum) {
	// 모두 체크하면
	if (x == N) {
		res += um[S - sum];
		return;
	}
	// 안뽑거나
	rightCalcul(x + 1, sum);
	// 뽑거나
	rightCalcul(x + 1, sum + arr[x]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; ++i) cin >> arr[i];

	res = 0;
	
	leftCalcul(0, 0);
	rightCalcul(N / 2, 0);

	if (S == 0) cout << res - 1 << '\n';
	else cout << res << '\n';

	return 0;
}