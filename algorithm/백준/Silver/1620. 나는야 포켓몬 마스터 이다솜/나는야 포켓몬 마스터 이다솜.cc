#include<iostream>
#define MAX_TABLE 30011	// 10007, 20011, 30011, 40009, 100003, 200003
#define MAX_N 100001	// 최대 포켓몬 수
#define MAX_L 21	// 문자열 최대 길이
using namespace std;

typedef unsigned long long ull;

ull hashs(const char* str) {
	ull hash = 5381;
	int c;
	while (c = *str++) {
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}
	return hash % MAX_TABLE;
}
int strtoi(const char* str) {
	int x = 0;
	for (int i = 0; str[i]; i++) {
		x *= 10;
		x += str[i] - '0';
	}
	return x;
}
void mystrcpy(char* a, const char* b) {
	while (*a++ = *b++);
}
int mystrcmp(const char* a, const char* b) {
	while (*a && *a == *b) ++a, ++b;
	return *a - *b;	// 같으면 0을 반환
}

struct Node {
	int index;
	char name[MAX_L];
	Node* next;
};

Node HASH_TABLE[MAX_TABLE];
Node POOL[MAX_N];
int pcnt = 0;

Node pkm[MAX_N];	// idx -> string;

void new_node(const char* str, int i) {
	Node* node = &POOL[pcnt++];
	ull h = hashs(str);
	
	node->index = i;
	mystrcpy(node->name, str);
	
	node->next = HASH_TABLE[h].next;
	HASH_TABLE[h].next = node;

	mystrcpy(pkm[i].name, str);
}

//void del_node(const char* str) {
//	ull h = hashs(str);
//	
//	Node* ptr = &HASH_TABLE[h];
//	while (ptr->next) {
//		if (!mystrcmp(ptr->next->name, str)) {	// 같으면
//			ptr->next = ptr->next->next;
//			break;
//		}
//		ptr = ptr->next;
//	}	
//}

int find(const char* str) {
	ull h = hashs(str);
	
	Node* ptr = HASH_TABLE[h].next;
	while (ptr) {
		if (!mystrcmp(ptr->name, str)) {
			return ptr->index;
		}
		ptr = ptr->next;
	}

	//return -1;	// 못 찾은 경우
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	char str[MAX_L];

	int n, m; 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		new_node(str, i);
	}

	//del_node(pkm[26].name);	// 삭제 예시

	for (int i = 0; i < m; i++) {
		cin >> str;
		if (str[0] > '0' && str[0] <= '9') {
			cout << pkm[strtoi(str)].name << '\n';
		}
		else {
			cout << find(str) << '\n';
		}
	}
}