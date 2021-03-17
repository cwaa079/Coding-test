#다익스트라 알고리즘

import heapq
import sys

input = sys.stdin.readline
INF = int(1e9) #무한

n, m = list(map(int, input().split()))

start = int(input()) #시작노드

graph=[[] for i in range(n+1)] #2차원 배열
distance = [INF] * (n+1) #최단거리 테이블(1차원)

for _ in range(m):
    a, b, c = map(int, input().split()) #a번 노드에서 b번 노드로 가는 비용이 c라는 의미
    graph[a].append((b, c)) #노드,간선

def dijkistra(start):
    q = [] #리스트 생성
    heapq.heappush(q, (0, start)) #큐에 삽입(거리,노드)
    distance[start]=0 #최단 경로는 0으로 설정

    while q:
        dist, now = heapq.heappop(q) #최단 경로가 가장 짧은 노드에 대한 정보 꺼내기
        if distance[now] < dist: #현재 노드가 이미 처리 = 계산된 최단경로보다
            continue

        for i in graph[now]: #now노드의 인접한 노드,거리 확인
            cost = dist + i[1]  #now노드의 비용 = 최단경로 + 인접한 노드의 간선
            if cost < distance[i[0]]: #현재 노드 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

dijkistra(start)

for i in range(1, n+1):
    if distance[i] == INF:
        print("INFINITY")
    else:
        print(distance[i])
