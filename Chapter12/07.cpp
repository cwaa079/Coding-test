//럭키 스트레이트
//왼쪽 자릿수의 합 = 오른쪽 자릿수의 합

#include <bits/stdc++.h>
using namespace std;

int n; //점수

int main()
{
	cin >> n;

	string s = to_string(n);

	int sum_f = 0; //앞에서부터 덧셈
	int sum_b = 0; //뒤에서부터 덧셈

	for (int i = 0; i<s.size() / 2; i++) {
		sum_f = sum_f + (s[i] - '0');
		sum_b = sum_b + (s[s.size() -1 - i] - '0');
	}

	if (sum_f == sum_b) cout << "LUCKY" << '\n';
	else cout << "READY" << '\n';

	return 0;
}
