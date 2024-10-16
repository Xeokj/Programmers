#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
// ���α׷��ӽ� 135808��: ���� ��� (Lv.1)

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
	// �� �ٿ� score�� �Է� ����
	getline(cin, input);
	istringstream iss(input);	// ���ڿ� �Ľ�
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