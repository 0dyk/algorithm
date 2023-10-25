#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

struct MEET {
	int start;
	int end;
	int person;

	MEET(int start, int end, int person) :start(start), end(end), person(person) {}
};

// lower_bound에 compare 재정의를 할 경우에
// Reference Type과 Primitive Type을 비교해야 하는데
// operator를 여러개 만들 수도 있지만
// 오버로딩을 통한 형변환으로 간단하게(?) 가능하다.
// C++ : template, Java : Generic
struct COMP
{
	int endt(const MEET& a) const {
		return a.end;
	}

	int endt(int a) const {
		return a;
	}

	template< typename T1, typename T2 >
	bool operator()(T1 const& t1, T2 const& t2) const {
		return endt(t1) < endt(t2);
	}
};

// 끝나는 시간 기준으로 정렬
bool comp(MEET a, MEET b) {
	return a.end < b.end;
}

// 회의 벡터
vector<MEET> v;

// dp
int dp[100001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int s, e, p;
	for (int i = 0; i < N; ++i) {
		cin >> s >> e >> p;
		v.push_back(MEET(s, e, p));
	}

	// end 순으로 정렬 (COMP()도 가능)
	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < N; ++i) {
		v[i].start;
		v[i].end;
		v[i].person;
		
		// dp[i-1] 과 v[i]회의 시작 전에 끝나는 회의의 최대값 + v[i].person 비교
		int idx = upper_bound(v.begin(), v.end(), v[i].start, COMP()) - v.begin();

		// 곂치는게 없으면
		if (idx > i) dp[i + 1] = dp[i];
		else {
			// 곂치면
			if (dp[idx] + v[i].person > dp[i]) {
				dp[i + 1] = dp[idx] + v[i].person;
			}
			else {
				dp[i + 1] = dp[i];
			}
		}
	}

	cout << dp[N] << '\n';

	return 0;
}