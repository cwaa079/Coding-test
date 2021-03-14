//외벽 점검
//https://programmers.co.kr/learn/courses/30/lessons/60062

#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int len = weak.size();
    for(int i=0; i<len; i++){
        weak.push_back(n+weak[i]);
    }
    
    int answer = dist.size()+1; //최대인원
    
    for(int start=0; start<len; start++){
        do{
            int cnt=1;
            int position = weak[start] + dist[cnt-1];
            for(int i=start; i<start+len; i++){
                if(position < weak[i]){ //닿지 않으면
                    cnt++; //새로운 친구 추가
                    if(cnt>dist.size()) break; //친구 투입 불가능
                    position = weak[i]+dist[cnt-1];
                }
            }
            answer = min(answer,cnt); //최소인원
        }while(next_permutation(dist.begin(),dist.end()));
    }
    if(answer>dist.size()) return -1;
    return answer;
}
