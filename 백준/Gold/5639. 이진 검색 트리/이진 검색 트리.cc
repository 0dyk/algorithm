#include <iostream>

int idx;
int arr[10001];

// 후위순회
void postorder(int start, int end) {
	if (start >= end) return;
	
	// 출력
	if (start == end - 1) {
		std::cout << arr[start] << '\n';
		return;
	}

	int mid = start + 1;
	while (mid < end) {
		if (arr[mid] > arr[start]) break;
		++mid;
	}
	
	// start + mid - 1 : left
	postorder(start + 1, mid);
	// mid ~ end : right
	postorder(mid, end);
	// start : root : start 출력
	postorder(start, start + 1);
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int tmp; idx = 0;
	while (std::cin >> tmp) { arr[idx++] = tmp; }

	postorder(0, idx);

	return 0;
}