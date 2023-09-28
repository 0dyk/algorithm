#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	

	int t;
	cin >> t;

	while (t--) {

		int k;
		multiset<long long> ms;
		cin >> k;

		for (int i = 0; i < k; i++) {
			char a;
			long long b;
			cin >> a >> b;

			if (a == 'I') {
				ms.insert(b);
			}
			else {
				if (ms.empty()) continue;

				if (b == 1) {
					ms.erase(--ms.end());
				}
				else {
					ms.erase(ms.begin());
				}
			}
		}

		if (ms.empty()) {
			cout << "EMPTY" << '\n';
		}
		else {
			cout << *(--ms.end()) << " " << *ms.begin() << '\n';
		}
	}

	return 0;
}