#include<iostream>
#define MAX_N 2000020
using namespace std;

int N;
int tree[1<<22];

/*
 * 값이 존재할 경우 해당 위치 값 = 1, 존재 하지 않을 경우 = 0
 * └→취소 : 중복 값이 존재할 수 있음 ㅋㅋ...
 * 구간 합 = 해당 구간에 존재하는 값의 수
*/
void update(int left, int right, int idx, int node, int data)
{
	if (idx < left || idx > right) return;
	if (left == right) {
		tree[node] += data;
		return;
	}
	
	int mid = (left + right) / 2;
	update(left, mid, idx, node * 2, data);
	update(mid + 1, right, idx, node * 2 + 1, data);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

/*
 * k번째 작은수 리턴
 * 왼쪽에 잇는 값이 k보다 클 경우 왼쪽으로 이동
 * else 오른쪽으로 이동하고 왼쪽에 있는 cnt는 카운팅 했으므로 k - cnt 넣어주기
*/
int find(int left, int right, int node, int k) {
	if (left == right) return left;

	int leftcnt = tree[node * 2];
	int mid = (left + right) / 2;

	if (k <= leftcnt) return find(left, mid, node * 2, k);
	else return find(mid + 1, right, node * 2 + 1, k - leftcnt);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) 
	{
		int a, b;
		cin >> a >> b;
		if (a == 1) 
		{
			update(1, MAX_N, b, 1, 1);
		}
		else 
		{
			int tmp = find(1, MAX_N, 1, b);
			update(1, MAX_N, tmp, 1, -1);
			cout << tmp << '\n';
		}
	}

	return 0;
}