#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 가수의 수, 보조 PD의 수
int N, M;

// v[a] = b, a후 b
vector<int> v[1001];

int inDegree[1001];

int main() 
{
	cin >> N >> M;

	int a;
	for (int i = 0; i < M; ++i) 
	{
		cin >> a;
		
		int pre = 0, tmp = 0;
		for (int i = 0; i < a; ++i) 
		{
			pre = tmp;
			cin >> tmp;
			if (i == 0) continue;
			
			v[pre].push_back(tmp);
			++inDegree[tmp];
		}
	}

	queue<int> q;
	for (int i = 1; i <= N; ++i) 
	{
		if (inDegree[i] == 0) q.push(i);
	}

	vector<int> res;

	while (!q.empty()) 
	{
		int cur = q.front();
		q.pop();

		res.push_back(cur);

		for (int i = 0; i < v[cur].size(); ++i) 
		{
			int nx = v[cur][i];
			if (inDegree[nx] == 0) continue;

			if (--inDegree[nx] == 0) q.push(nx);
		}
	}

	if (res.size() != N) 
	{
		cout << 0 << '\n';
	}
	else 
	{
		for (int i = 0; i < res.size(); ++i) cout << res[i] << '\n';
	}

	return 0;
}