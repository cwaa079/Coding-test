#https://www.acmicpc.net/problem/17144
#미세먼지 안녕!
#pypy3로 제출

import sys
from copy import deepcopy
input = sys.stdin.readline

r, c, t = map(int, input().split()) #행열, 시간
a = [] #맵 정보
cleaner = -1 #청소기위치(r)
for i in range(r):
    a.append(list(map(int, input().split())))
    for j in range(c):
        if a[i][j] == -1:
            cleaner = i

dx = [0, -1, 0, 1] #우상좌하
dy = [1, 0, -1, 0]

def diffusion(): #한 좌표가 주어졌을 때 미세먼지 확산하는 함수
    temp = [[0]*c for _ in range(r)] #확산 형태를 저장하는 리스트
    temp[cleaner-1][0], temp[cleaner][0] = -1, -1

    for x in range(r):
        for y in range(c):
            if a[x][y] > 0:
                cnt = 0  # 확산된 방향의 개수
                for i in range(4):  # 4방향으로 확산
                    nx = x + dx[i]
                    ny = y + dy[i]

                    if 0 <= nx < r and 0 <= ny < c and a[nx][ny] != -1:  # 맵안, 공기청정기가 없으면
                        temp[nx][ny] += a[x][y] // 5
                        cnt += 1
                temp[x][y] += a[x][y] - (a[x][y] // 5 * cnt)
    return temp

def air_cleaner(x, y, dir): #공기청정기 작동
    temp = deepcopy(a)
    cx, cy = x, y-1
    a[x][y] = 0
    for i in range(4):
        while True:
            nx = x + dx[dir[i]]
            ny = y + dy[dir[i]]
            if nx == cx and ny == cy: return
            if 0<=nx<r and 0<=ny<c:
                a[nx][ny] = temp[x][y]
            else: break
            x, y = nx, ny

for sec in range(t):
    a = diffusion()

    air_cleaner(cleaner-1, 1, [0, 1, 2, 3])
    air_cleaner(cleaner, 1, [0, 3, 2, 1])

#공기청정기 자리는 미세먼지 없음
a[cleaner-1][0], a[cleaner][0] = 0, 0

result = 0
#미세먼지의 합
for i in range(r):
    result += sum(a[i])

print(result)
