//내림차순 정렬

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100000];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n, greater<int>()); //내림차순 정렬
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}
