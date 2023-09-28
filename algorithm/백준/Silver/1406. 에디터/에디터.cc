#include<iostream>

using namespace std;

struct Node {
	char v;
	Node* prev;
	Node* next;
}nodes[600010];

int ncnt;
Node* point;

Node* new_node(int v) {
	nodes[ncnt].v = v;
	nodes[ncnt].prev = nullptr;
	nodes[ncnt].next = nullptr;
	return &nodes[ncnt++];
}

class DoublyLL {
public:
	Node head, tail;

	DoublyLL() = default;

	void init() {
		ncnt = 0;
		head.v = tail.v = -1;
		head.prev = nullptr;
		head.next = &tail;
		tail.prev = &head;
		tail.next = nullptr;
	}

	void insert(Node* iter, int x) {
		Node* ptr = new_node(x);
		Node* pre = iter->prev;

		pre->next->prev = ptr;
		ptr->next = pre->next;
		pre->next = ptr;
		ptr->prev = pre;

		point = ptr;
		//print();
		//cout << '\n';
	}

	void remove() {
		if (point == &tail) return;
		point->next->prev = point->prev;
		point->prev->next = point->next;
		point = point->next;
		//print();
		//cout << '\n';
	}

	void leftmove() {
		if (point->next == nullptr) return;
		point = point->next;
	}

	void rightmove() {
		if (point->prev == &head) return;
		point = point->prev;
	}

	Node* begin() {
		return head.next;
	}
	Node* end() {
		return &tail;
	}

	void print() {
		Node* ptr = end();
		while (ptr->prev->prev != nullptr) {
			cout << ptr->prev->v;
			ptr = ptr->prev;
		}
	}

};


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	DoublyLL dl;
	dl.init();

	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		dl.insert(dl.begin(), s[i]);
	}

	int m; cin >> m;
	char c, tmp;
	for (int i = 0; i < m; i++) {
		cin >> c;
		if (c == 'L') {
			dl.leftmove();
		}
		else if (c == 'D') {
			dl.rightmove();
		}
		else if (c == 'B') {
			dl.remove();
		}
		else {	// P 
			cin >> tmp;
			dl.insert(point, tmp);
		}
	}

	dl.print();

	return 0;
}