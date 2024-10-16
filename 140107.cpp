#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
// 프로그래머스 140107번: 점 찍기 (Lv.2)
long long solution(int k, int d);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k, d;
	cin >> k >> d;
	cout << solution(k, d);
	return 0;
}

long long solution(int k, int d) {
	long long answer = 0;
	for (int i = 0; i <= d; i += k) {
		int maxY = sqrt((long long)d * d - (long long)i * i);
		answer += (maxY / k) + 1;
	}
	return answer;
}