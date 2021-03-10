//떡볶이 떡 만들기

#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> arr;

int main()
{
    cin>>n>>m;
    
    //떡의 개별 높이 입력
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    
    int start=0;
    int end = 1e9; //10억
    int result=0;
    
    while(start<=end){
        int mid = (start+end)/2;
        long long int sum=0;
        
        //잘린 떡의 총합
        for(int i=0; i<n; i++){
            if(arr[i]>mid) sum += arr[i]-mid;
        }
        
        if(sum<m) //떡의 양이 부족하면
            end = mid - 1; //왼쪽
        else { //떡의 양이 충분하면
            result = mid;
            start = mid + 1; //오른쪽
        }
    }
    cout<<result<<'\n';
    return 0;
}
