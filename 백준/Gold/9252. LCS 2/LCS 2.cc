#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str1;
	string str2;

	cin >> str1;
	cin >> str2;

	// graph 만들기
	for (int i = 0; i < str1.length(); ++i) 
	{
		for (int j = 0; j < str2.length(); ++j) 
		{
			if (str1[i] == str2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
			else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}

	// 결과값 저장
	deque<char> res;
	
	int i = str1.length();
	int j = str2.length();

	while (dp[i][j]) 
	{
		if (dp[i][j] == dp[i - 1][j]) 
		{
			--i;
		}
		else if (dp[i][j] == dp[i][j - 1]) 
		{
			--j;
		}
		else 
		{
			res.push_front(str1[i - 1]);
			--i;
			--j;
		}
	}

	// 최대 길이 출력
	cout << dp[str1.length()][str2.length()] << '\n';

	// LCS 출력
	for (int i = 0; i < res.size(); ++i) cout << res[i];
	cout << '\n';

	return 0;
}