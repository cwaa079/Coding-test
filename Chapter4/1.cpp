#include <bits/stdc++.h>
using namespace std;

int n;
string plans;
int x = 1, y = 1;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
char moveTypes[4] = { 'L', 'R', 'U', 'D' };

int main()
{
	scanf("%d", &n);
	cin.ignore();
	getline(cin, plans); //한 라인 입력

	for (int i = 0; i < plans.size(); i++) {
		char plan = plans[i];

		int nx=0, ny=0;
		for (int j = 0; j < 4; j++) {
			if (plan == moveTypes[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}
		if (nx<1 || ny<1 || nx>n || ny>n) continue; //예외상황

		x = nx;
		y = ny;
	}
	
	printf("%d %d\n", x, y);
	return 0;
}
