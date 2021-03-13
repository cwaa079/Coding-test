//문자열 압축

#include <bits/stdc++.h>
using namespace std;

int main(string s) {
	int answer = 0;

	for (int i = 1; i<s.size() / 2+1; i++) {
		string str = "";
		string prev = s.substr(0, i); //앞에서부터 i만큼 문자열 추출
		int cnt = 1; //같은 문자 개수

		for (int j = i; j < s.size(); j+=i) {
			if (prev == s.substr(j, i)) cnt++; //이전과 현재가 같으면 횟수 증가
			else {
				//같은 문자가 2개 이상이면 숫자,문자추출, 아니면 문자만 추출
				str += (cnt > 1) ? to_string(cnt) + prev : prev;
				prev = s.substr(j, i); //현위치부터 i만큼 문자열추출
				cnt = 1;
			}
		}
		str += (cnt > 1) ? to_string(cnt) + prev : prev; //마지막 문자열
		answer = min(answer, (int)str.size());
	}

	return answer;
}
