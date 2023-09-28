#include<iostream>
#include<string>
#define MAX_N 1000001
using namespace std;

struct Node {
	int idx;
	Node* pre, *next;
};

int N, M;
Node nodes[MAX_N];
Node Head = { -1, &Head, &Head };

// ptr의 오른쪽 위치에 x노드를 삽입
Node* add(Node* ptr, int x) {
	Node *node = &nodes[x];
	node->idx = x;

	// ptr의 오른쪽 위치에 삽입하기로 하자.
	node->next = ptr->next;
	node->pre = ptr;
	ptr->next->pre = node;
	ptr->next = node;

	return node;
}

// 전달받은 node 삭제
void remove(Node* node) {
	Node* pre = node->pre;

	pre->next = node->next;
	node->next->pre = pre;
	node->next = nullptr;
	node->pre = nullptr;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	// now는 이전에 저장한 노드의 주소값
	Node* now = &Head;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		now = add(now, x);
	}


	for (int i = 0; i < M; i++) {
		string str;
		int x, y;
		cin >> str;
		if (str == "BN") {
			cin >> x >> y;
			if (nodes[x].next->idx == -1) {
				cout << nodes[x].next->next->idx << '\n';
			}
			else {
				cout << nodes[x].next->idx << '\n';
			}
			add(&nodes[x], y);
		}
		else if (str == "BP") {
			cin >> x >> y;
			if (nodes[x].pre->idx == -1) {
				cout << nodes[x].pre->pre->idx << '\n';
			}else{
				cout << nodes[x].pre->idx << '\n';
			}
			add(nodes[x].pre, y);
		}
		else if (str == "CN") {
			cin >> x;
			if (nodes[x].next->idx == -1) {
				cout << nodes[x].next->next->idx << '\n';
				remove(nodes[x].next->next);
			}
			else {
				cout << nodes[x].next->idx << '\n';
				remove(nodes[x].next);
			}

		} 
		else {
			cin >> x;
			if (nodes[x].pre->idx == -1) {
				cout << nodes[x].pre->pre->idx << '\n';
				remove(nodes[x].pre->pre);
			}
			else {
				cout << nodes[x].pre->idx << '\n';
				remove(nodes[x].pre);
			}

		}
	}
	return 0;
}