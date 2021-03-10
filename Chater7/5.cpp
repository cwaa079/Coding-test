//부품찾기

#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> store;
vector <int> arr;

int binarySearch(vector<int>&array,int target, int start, int end)
{
    while(start<=end){
        int mid=(start+end)/2;
        
        if(array[mid]==target) return mid;
        else if(array[mid]>target) start = mid+1;
        else end = mid-1;
    }
    return -1;
}

int main()
{
    cin>>n;
    //가게물품 입력
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        store.push_back(x);
    }
    sort(store.begin(), store.end()); //정렬
    
    
    cin>>m;
    //타겟물품 입력
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    
    //이진탐색
    for(int i=0; i<m; i++){
        if(binarySearch(store,arr[i],0,n-1)==-1)
            cout<<"no"<<' ';
        else
            cout<<"yes"<<' ';
    }
    
    return 0;
}
