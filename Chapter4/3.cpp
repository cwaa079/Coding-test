//왕실의 나이트

#include <bits/stdc++.h>
using namespace std;

string inputData;
int dx[] = { -2, -2, 2, 2, 1, -1, 1, -1 };
int dy[] = { -1, 1, -1, 1, -2, -2, 2, 2 };

int main()
{
	cin >> inputData;
	int row = inputData[1] - '0';
	int col = inputData[0] - 'a' + 1;

	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int nextRow = row + dx[i];
		int nextCol = col + dy[i];
		
		if (nextRow >= 1 && nextRow <= 8 && nextCol >= 1 && nextCol <= 8)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
