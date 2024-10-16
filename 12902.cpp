#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
// 프로그래머스 12902번: 3 x n 타일링 (Lv.2)
long long dp[5001] = { 1,0,3 };
int solution(int n);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	cin.ignore();
	cout << solution(n);
	return 0;
}

int solution(int n) {
	int answer = 0;
	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[i - 2] * 3;
		for (int j = 0; j <= i - 4; j += 2)
			dp[i] += dp[j] * 2;
		dp[i] %= 1000000007;
	}
	answer = dp[n];
	return answer;
}