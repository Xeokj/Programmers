#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
// 프로그래머스 135808번: 과일 장수 (Lv.1)

int solution(int k, int m, vector<int> score);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k, m, num;
	cin >> k >> m;
	cin.ignore();

	vector<int> score;
	string input;
	// 한 줄에 score를 입력 받음
	getline(cin, input);
	istringstream iss(input);	// 문자열 파싱
	while (iss >> num)
		score.push_back(num);

	cout << solution(k, m, score);
	return 0;
}

int solution(int k, int m, vector<int> score) {
	int answer = 0;
	sort(score.begin(), score.end());
	int n = score.size();
	for (int i = n - m; i >= 0;) {
		answer += score[i] * m;
		i -= m;
	}
	return answer;
}