/*
* 크기가 약 1억 이하인 int 배열은 전역변수로 선언 가능하다?(int : 4byte)
* 지역변수의 경우 25만 넘어가면 stackoverflow 발생하는 것 같다.
*/

#include<iostream>
#define MAXN 1000000
typedef long long ll;

int arr[MAXN];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N, B, C;
	std::cin >> N;

	ll answer = N;	// default = 총감독관 수, 100만 * 100만이 들어갈 수도 있으므로 long long

	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
	std::cin >> B >> C;

	for (int i = 0; i < N; i++) {
		double dd = (double)(arr[i] - B) / C;	// 부감독관 수
		int ddd = (int)dd;
		if (dd < 0) ddd = 0;	// (응시인원 < 총감독관 감시 가능 수)
		else if (dd != ddd) ddd++;	// 반올림하기

		answer += ddd;
	}

	std::cout << answer;

	return 0;
}