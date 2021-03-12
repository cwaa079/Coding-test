#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n,m,start;
int d[100001];
vector <pair<int,int>> graph[100001];

void dijkstra(int start){
    priority_queue<pair<int,int>> pq; //우선순위 큐
    pq.push({0,start}); //기본 초기화
    d[start]=0;
    
    while(!pq.empty()){
        int dist = -pq.top().first; //가장 적은 간선의 합
        int nowNode = pq.top().second; //현재노드
        pq.pop();
        
        if(d[nowNode]<dist) continue; //방문한 이력이 있는지 확인
        
        for(int i=0; i<graph[nowNode].size(); i++){
            int cost = dist + graph[nowNode][i].second; //합+현재노드의 간선
            
            if(cost < d[graph[nowNode][i].first]){ //현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
                d[graph[nowNode][i].first] = cost;
                pq.push(make_pair(-cost,graph[nowNode][i].first));
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    
    fill(d,d+100001,INF);
    
    dijkstra(start);
    
    for(int i=1; i<=n; i++){
        if(d[i]==INF) cout<<"INFINITY"<<'\n';
        else cout<<d[i]<<'\n';
    }
    
    return 0;
}
