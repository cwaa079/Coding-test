//곱하기 혹은 더하기(큰수만들기)

#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
	cin >> s;

	int sum = s[0] - '0'; //첫문자

	for (int i = 1; i < s.size(); i++) {
		int now = s[i] - '0';

		if (now <= 1 || sum <= 1) sum += now; //1보다 작으면 덧셈
		else sum *= now; //아니면 곱셈
	}

	cout << sum << '\n';

	return 0;
}
