#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
// 프로그래머스 49189번: 가장 먼 노드 (Lv.3)
int solution(int n, vector<vector<int>> edge);
vector<vector<int>> graph(50001);
int visited[50001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;	// m은 문제에 없는 변수인데, 그래프의 간선 개수를 모르므로 가상으로 설정함
	cin >> n >> m;
	cin.ignore();
	vector<vector<int>> edge;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge.push_back({ a,b });
	}
	cout << solution(n, edge);
	return 0;
}

int solution(int n, vector<vector<int>> edge) {
	int cnt = 0, farthest = 0;
	int a, b, i;
	for (i = 0; i < edge.size(); i++) {
		a = edge[i][0];
		b = edge[i][1];
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// BFS
	queue<pair<int, int>> q;
	q.push({ 1,0 });
	visited[1] = 1;
	while (!q.empty()) {
		int num = q.front().first;
		int dist = q.front().second;
		q.pop();
		if (dist > farthest) {
			farthest = dist;
			cnt = 1;
		}
		else if (dist == farthest)
			cnt++;
		for (i = 0; i < graph[num].size(); i++) {
			int next = graph[num][i];
			if (!visited[next]) {
				q.push({ next,dist + 1 });
				visited[next] = 1;
			}
		}
	}
	return cnt;
}