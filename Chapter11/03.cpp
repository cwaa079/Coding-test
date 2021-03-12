//문자열 뒤집기

#include <bits/stdc++.h>

using namespace std;

string s;
int count1 = 0; //전부 1로 바꾸는 경우
int count0 = 0; //전부 0으로 바꾸는 경우

int main()
{
	cin >> s;

	//첫번째 원소
	if (s[0] == '1') count0++;
	else count1++;

	for (int i = 0; i < s.size()-1; i++) {
		if (s[i] != s[i + 1]) { //다음수와 현재 수가 같지않으면
			if (s[i + 1] == '1') count0++;
			else count1++;
		}
	}

	cout << min(count0, count1) << '\n';

	return 0;
}
