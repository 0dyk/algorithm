#include<iostream>
#define MAXN 5000010
using namespace std;


struct NODE {
	int data;
	bool isLive;
};

bool comp (NODE* a, NODE* b) {
	return a->data < b->data;
}

// 노드 풀
int pCnt;
NODE POOL[MAXN];

int hCnt;
NODE* HEAP[MAXN];

NODE dumyMax = {1111111111};

int N, L;

void push_node(int data) {
	NODE* node = &POOL[++pCnt];
	POOL[pCnt].data = data;
	POOL[pCnt].isLive = true;

	HEAP[++hCnt] = node;


	NODE* tmp;
	for (int i = hCnt; i > 1; i /= 2) {
		if (comp(HEAP[i], HEAP[i / 2])) {
			tmp = HEAP[i / 2];
			HEAP[i / 2] = HEAP[i];
			HEAP[i] = tmp;
		}
	}
}

void pop_node() {
	HEAP[1] = HEAP[hCnt];
	HEAP[hCnt--] = &dumyMax;

	NODE* tmp;
	for (int i = 1; i * 2 <= hCnt;) {
		if (comp(HEAP[i * 2], HEAP[i]) || comp(HEAP[i * 2 + 1], HEAP[i])) {
			if (comp(HEAP[i * 2], HEAP[i * 2 + 1])) {
				tmp = HEAP[i * 2];
				HEAP[i * 2] = HEAP[i];
				HEAP[i] = tmp;
				i = i * 2;
			}
			else {
				tmp = HEAP[i * 2 + 1];
				HEAP[i * 2 + 1] = HEAP[i];
				HEAP[i] = tmp;
				i = i * 2 + 1;
			}
		}
		else {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L;

	int a;
	for (int i = 1; i <= N; i++) {
		if (i > L) {
			POOL[i - L].isLive = false;
		}
		
		cin >> a;
		push_node(a);
		while (HEAP[1]->isLive == false) {
			pop_node();
		}
		cout << HEAP[1]->data << ' ';
	}

	return 0;
}