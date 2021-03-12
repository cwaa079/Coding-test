//모험가 길드

#include <bits/stdc++.h>

using namespace std;
int n;
vector <int> v;

int main() 
{
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	};
	sort(v.begin(), v.end()); //오름차순 정렬

	int cnt = 1; //현재 그룹에 포함된 모험가 수
	int group = 0; //총 그룹의 수

	for (int i = 0; i < n; i++) {
		if (v[i] <= cnt) { //현재 그룹의 인원과 공포도가 같으면
			group++; //그룹추가
			cnt = 1; //인원수 초기화
		}
		else //현재 그룹의 인원이 공포도보다 작으면
			cnt++; //인원수 추가
	}
	cout << group << '\n';

	return 0;
}
