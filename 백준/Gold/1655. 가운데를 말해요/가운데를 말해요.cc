#include<iostream>
using namespace std;

int N;
int maxHeap[100100];
int minHeap[100100];
int maxcnt, mincnt;

void maxPush(int x) {
	maxHeap[++maxcnt] = x;
	for (register int i = maxcnt; i > 1; i /= 2){
		if (maxHeap[i] < maxHeap[i / 2]) break;
		int tmp = maxHeap[i];
		maxHeap[i] = maxHeap[i / 2];
		maxHeap[i / 2] = tmp;
	}
}

void minPush(int x) {
	minHeap[++mincnt] = x;
	for (register int i = mincnt; i > 1; i /= 2) {
		if (minHeap[i] > minHeap[i / 2]) break;
		int tmp = minHeap[i];
		minHeap[i] = minHeap[i / 2];
		minHeap[i / 2] = tmp;
	}
}

void maxPop(){
	maxHeap[1] = maxHeap[maxcnt];
	maxHeap[maxcnt--] = -10001;
	
	for (register int i = 1; i * 2 <= maxcnt;){
		if (maxHeap[i] > maxHeap[i * 2] && maxHeap[i] > maxHeap[i * 2 + 1]) break;
		else if (maxHeap[i * 2] > maxHeap[i * 2 + 1]) {
			int tmp = maxHeap[i];
			maxHeap[i] = maxHeap[i * 2];
			maxHeap[i * 2] = tmp;
			i = i * 2;
		}
		else {
			int tmp = maxHeap[i];
			maxHeap[i] = maxHeap[i * 2 + 1];
			maxHeap[i * 2 + 1] = tmp;
			i = i * 2 + 1;
		}
	}
}

void minPop(){
	minHeap[1] = minHeap[mincnt];
	minHeap[mincnt--] = 10001;
	
	for (register int i = 1; i * 2 <= mincnt;) {
		if (minHeap[i] < minHeap[i * 2] && minHeap[i] < minHeap[i * 2 + 1]) break;
		else if (minHeap[i * 2] < minHeap[i * 2 + 1]) {
			int tmp = minHeap[i];
			minHeap[i] = minHeap[i * 2];
			minHeap[i * 2] = tmp;
			i = i * 2;
		}
		else {
			int tmp = minHeap[i];
			minHeap[i] = minHeap[i * 2 + 1];
			minHeap[i * 2 + 1] = tmp;
			i = i * 2 + 1;
		}
	}
}

void push(int x) {
	if (maxcnt == mincnt) {
		if (x > minHeap[1]) {
			maxPush(minHeap[1]);
			minPop();
			minPush(x);
		}
		else {
			maxPush(x);
		}
	}
	else {
		if (x < maxHeap[1]) {
			minPush(maxHeap[1]);
			maxPop();
			maxPush(x);
		}
		else {
			minPush(x);
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x;

	cin >> N;

	cin >> x;
	maxPush(x);
	cout << x << '\n';
	for (int i = 1; i < N; i++){
		cin >> x;
		push(x);
		cout << maxHeap[1] << '\n';
	}

	return 0;
}