#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// 프로그래머스 12946번: 하노이의 탑 (Lv.2)
vector<vector<int>> solution(int n);
void hanoi(int a, int b, int c, int n);
vector<vector<int>> answer;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	solution(n);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i][0] << ' ' << answer[i][1] << "\n";
	return 0;
}

vector<vector<int>> solution(int n) {
	hanoi(1, 2, 3, n);
	return answer;
}

void hanoi(int a, int b, int c, int n) {
	vector<int> move;
	if (n == 1) {
		// 1을 옮길 때는 a에서 c로 옮기면 된다.
		move.push_back(a);	// from
		move.push_back(c);	// to
		answer.push_back(move);
		return;
	}
	// 2~n과 1을 옮긴다고 보자.
	hanoi(a, c, b, n - 1);	// 1. 2~n을 1에서 2로 옮긴다.
	// 2. 1을 1에서 3으로 옮긴다.
	move.push_back(a);	// from
	move.push_back(c);	// to
	answer.push_back(move);	// 3. 2~n을 2에서 3으로 옮긴다.
	hanoi(b, a, c, n - 1);
}