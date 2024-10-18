#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// ���α׷��ӽ� 12946��: �ϳ����� ž (Lv.2)
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
		// 1�� �ű� ���� a���� c�� �ű�� �ȴ�.
		move.push_back(a);	// from
		move.push_back(c);	// to
		answer.push_back(move);
		return;
	}
	// 2~n�� 1�� �ű�ٰ� ����.
	hanoi(a, c, b, n - 1);	// 1. 2~n�� 1���� 2�� �ű��.
	// 2. 1�� 1���� 3���� �ű��.
	move.push_back(a);	// from
	move.push_back(c);	// to
	answer.push_back(move);	// 3. 2~n�� 2���� 3���� �ű��.
	hanoi(b, a, c, n - 1);
}