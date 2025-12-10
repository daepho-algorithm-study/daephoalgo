#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		string sentence;
		getline(cin, sentence);      // 한 줄 전체 입력받기

		if (sentence == ".") break;  // 입력이 "."이면 프로그램 종료
		
        // 괄호 검사를 위한 스택
		stack<char> s;
		for (int i = 0; i < (int)sentence.length(); i++) {
			// 여는 괄호는 스택에 push
			if (sentence[i] == '(' || sentence[i] == '[') {
				s.push(sentence[i]);
			}
			// 닫는 소괄호 ')'
			else if (sentence[i] == ')') {
				// 스택이 비어있지 않고 top이 '('이면 짝이 맞으므로 pop
				if (!s.empty() && s.top() == '(') s.pop();
				else {
					// 짝이 맞지 않으면 오류 상황 → 스택에 push 후 루프 종료
					s.push(sentence[i]);
					break;
				}
			}
			// 닫는 대괄호 ']'
			else if (sentence[i] == ']')
				// 스택이 비어있지 않고 top이 '['이면 pop
				if (!s.empty() && s.top() == '[') s.pop();
				else {
					// 짝이 맞지 않으면 오류 상황 → push 후 루프 종료
					s.push(sentence[i]);
					break;
				}
		}

		// 스택이 비어있으면 모든 괄호가 정상적으로 짝을 이룸
		if (s.empty()) cout << "yes" << "\n";
		// 스택에 남아 있다면 짝이 안 맞은 괄호가 존재
		else cout << "no" << "\n";
	}

	return 0;
}
