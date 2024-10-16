#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <iostream>
#include <string>
#include <stack>
using namespace std;
// 프로그래머스 12909번: 올바른 괄호 (Lv.2)
bool solution(string s);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	cout << solution(s);
	return 0;
}

bool solution(string s)
{
	bool answer = true;
	stack<char> st;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] == '(') {
			st.push('(');
		}
		else {
			if (st.empty())
				return !answer;
			else if (st.top() == '(')
				st.pop();
			else
				return !answer;
		}
	}
	if (st.empty())
		return answer;
	else
		return !answer;
}