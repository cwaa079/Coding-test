//효율적인 화폐 구성

#include <bits/stdc++.h>
using namespace std;

int n, m; //화폐가치 갯수, 만들고자하는 화폐
vector <int> arr;

int main()
{
	cin >> n >> m;
	
	//화폐의 가치 입력
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	//dp테이블 초기화(최소값을 알아내야 하기 때문에 큰수로 초기화)
	vector <int> d(m + 1, 10001); 

	d[0] = 0; //꼭 초기화
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= m; j++) {
			if (d[j - arr[i]] != 10001) {
				d[j] = min(d[j], d[j - arr[i]] + 1);
			}
		}
	}

	if (d[m] == 10001) cout << "-1\n";
	else cout << d[m] << '\n';
	return 0;
}
