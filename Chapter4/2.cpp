//시각

#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 60; j++) {
			for (int k = 0; k < 60; k++) {
				if (k % 10 == 3 || k / 10 == 3 || j % 10 == 3 || j / 10 == 3 || i % 10 == 3) //3이 있는지 검사
					cnt++;
			}
    }
	}
	printf("%d\n", cnt);
	return 0;
}
