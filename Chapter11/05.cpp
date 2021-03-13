//다른 무게로 볼링공 고르기

#include <bits/stdc++.h>
using namespace std;

int n, m; //볼링공 개수, 공의 최대무게
vector <int> v;

int main()
{
	cin >> n >> m;

	//볼링공 무게 입력
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (v[i] == v[j]) continue;
			else cnt++;
		}
	}

	cout<<cnt<<'\n';

	re
