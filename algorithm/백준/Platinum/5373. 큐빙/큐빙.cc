/*
		     (B,3)
		(L,4)(U,0)(R,5)
		     (F,2)
		     (D,1)

						{0, 0} {0, 1} {0, 2}
						{1, 0} {1, 1} {1, 2}
						{2, 0} {2, 1} {2, 2}

{0, 0} {0, 1} {0, 2}	{0, 0} {0, 1} {0, 2}	{0, 0} {0, 1} {0, 2}
{1, 0} {1, 1} {1, 2}	{1, 0} {1, 1} {1, 2}	{1, 0} {1, 1} {1, 2}
{2, 0} {2, 1} {2, 2}	{2, 0} {2, 1} {2, 2}	{2, 0} {2, 1} {2, 2}

						{0, 0} {0, 1} {0, 2}
						{1, 0} {1, 1} {1, 2}
						{2, 0} {2, 1} {2, 2}

						{0, 0} {0, 1} {0, 2}
						{1, 0} {1, 1} {1, 2}
						{2, 0} {2, 1} {2, 2}

*/

#include<iostream>
#include<map>

using namespace std;

map<char, int> m = { {'U', 0},{'D', 1}, {'F', 2}, {'B', 3}, {'L', 4}, {'R', 5} };
char brr[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };
char cube[6][3][3];

// w    y        r       o      g      b
// 0 up 1 bottom 2 front 3 back 4 left 5 right

void init() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cube[i][j][k] = brr[i];
			}
		}
	}
}

void right_rotation(int a) {
	int tmp[3][3] = {};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tmp[i][j] = cube[a][2-j][i];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[a][i][j] = tmp[i][j];
		}
	}
}
//void left_rotation(int a) {
//	int tmp[3][3] = {};
//	for (int j = 0; j < 3; j++) {
//		for (int i = 0; i < 3; i++) {
//			tmp[i][j] = cube[a][i][2 - j];
//		}
//	}
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			cube[a][i][j] = tmp[i][j];
//		}
//	}
//}


//	마주보는 면따라 3개가 나와야 하나..? 너무 헷갈려서 못 만들곘어...
//void c_rotation(int a1, int a2, int a3, int a4, int t) {
//	
//}

void rotation(int a, int b) {
	for (int n = 0; n < b; n++) {
		right_rotation(a);
	}

	// 0 up 1 down 2 front 3 back 4 left 5 right
	if (a == 0) {	// U : B -> R -> F -> L
		for (int k = 0; k < 4 - b; k++) {
			char ttmp[3] = {};
			for (int i = 0; i < 3; i++) ttmp[i] = cube[3][2][i];
			for (int i = 0; i < 3; i++) cube[3][2][i] = cube[5][i][0];
			for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][0][2 - i];
			for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[4][2 - i][2];
			for (int i = 0; i < 3; i++) cube[4][2 - i][2] = ttmp[i];
		}
		return;
	}
	else if (a == 1) {
		for (int k = 0; k < b; k++) {
			char ttmp[3] = {};
			for (int i = 0; i < 3; i++) ttmp[i] = cube[3][0][i];
			for (int i = 0; i < 3; i++) cube[3][0][i] = cube[5][i][2];
			for (int i = 0; i < 3; i++) cube[5][i][2] = cube[2][2][2 - i];
			for (int i = 0; i < 3; i++) cube[2][2][2 - i] = cube[4][2 - i][0];
			for (int i = 0; i < 3; i++) cube[4][2 - i][0] = ttmp[i];
		}
		return;
	}
	// 0 up 1 down 2 front 3 back 4 left 5 right
	else if (a == 2) {	// F : U -> R -> D -> L -> U
		for (int k = 0; k < 4 - b; k++) {
			char ttmp[3] = {};
			for (int i = 0; i < 3; i++) ttmp[i] = cube[0][2][i];
			for (int i = 0; i < 3; i++) cube[0][2][i] = cube[5][2][i];
			for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][0][2 - i];
			for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[4][2][i];
			for (int i = 0; i < 3; i++) cube[4][2][i] = ttmp[i];
		}
		return;
	}
	else if (a == 3) {
		for (int k = 0; k < b; k++) {
			char ttmp[3] = {};
			for (int i = 0; i < 3; i++) ttmp[i] = cube[0][0][i];
			for (int i = 0; i < 3; i++) cube[0][0][i] = cube[5][0][i];
			for (int i = 0; i < 3; i++) cube[5][0][i] = cube[1][2][2 - i];
			for (int i = 0; i < 3; i++) cube[1][2][2 - i] = cube[4][0][i];
			for (int i = 0; i < 3; i++) cube[4][0][i] = ttmp[i];
		}
		return;
	}
	else if (a == 4) {	// L : B -> U -> F -> D
		for (int k = 0; k < 4 - b; k++) {
			char ttmp[3] = {};
			for (int i = 0; i < 3; i++) ttmp[i] = cube[3][i][0];
			for (int i = 0; i < 3; i++) cube[3][i][0] = cube[0][i][0];
			for (int i = 0; i < 3; i++) cube[0][i][0] = cube[2][i][0];
			for (int i = 0; i < 3; i++) cube[2][i][0] = cube[1][i][0];
			for (int i = 0; i < 3; i++) cube[1][i][0] = ttmp[i];
		}
		return;
	}
	else if (a == 5) {	// R
		for (int k = 0; k < b; k++) {
			char ttmp[3] = {};
			for (int i = 0; i < 3; i++) ttmp[i] = cube[3][i][2];
			for (int i = 0; i < 3; i++) cube[3][i][2] = cube[0][i][2];
			for (int i = 0; i < 3; i++) cube[0][i][2] = cube[2][i][2];
			for (int i = 0; i < 3; i++) cube[2][i][2] = cube[1][i][2];
			for (int i = 0; i < 3; i++) cube[1][i][2] = ttmp[i];
		}
		return;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	int n;
	for (int test_case = 1; test_case <= T; test_case++) {
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {
			char a, b;
			cin >> a >> b;
			int t = 1;
			if (b == '-') t = 3;

			rotation(m[a], t);
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[0][i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}