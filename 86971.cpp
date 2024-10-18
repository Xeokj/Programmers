#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
// 프로그래머스 86971번: 전력망을 둘로 나누기 (Lv.2)

int tree[101][101];
int visited[101];
int num;
void dfs(int n, int a);
int solution(int n, vector<vector<int>> wires);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> wires;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		wires.push_back({ a,b });
	}
	cout << solution(n, wires);
	return 0;
}

int solution(int n, vector<vector<int>> wires) {
	int answer = n;
	int i, a, b;
	for (i = 0; i < n - 1; i++) {
		a = wires[i][0];
		b = wires[i][1];
		tree[a][b] = 1;
		tree[b][a] = 1;
	}
	for (i = 0; i < n - 1; i++) {
		a = wires[i][0];
		b = wires[i][1];
		tree[a][b] = 0;
		tree[b][a] = 0;
		num = 0;
		dfs(n, a);
		if (abs(n - 2 * num) < answer)
			answer = abs(n - 2 * num);
		tree[a][b] = 1;
		tree[b][a] = 1;
	}
	return answer;
}

void dfs(int n, int a) {
	visited[a] = 1;
	num++;
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && tree[a][i])
			dfs(n, i);
	}
	visited[a] = 0;
}