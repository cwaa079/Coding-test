//문자열 재정렬
//알파벳 정렬, 숫자는 합출력

#include <bits/stdc++.h>
using namespace std;

string s;
vector <char> v;

int main()
{
	cin >> s;

	int sum = 0;
	for (int i = 0; i<s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			sum = sum + (s[i] - '0');
		else v.push_back(s[i]);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	cout << sum << '\n';

	return 0;
}
