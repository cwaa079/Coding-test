//자물쇠와 열쇠
//https://programmers.co.kr/learn/courses/30/lessons/60059

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotate90Degree(vector<vector<int>> a) { //90도로 돌리는 함수
	vector<vector<int>> result(a.size(), vector<int>(a[0].size()));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			result[j][a.size()-i-1] = a[i][j];
		}
	}
	return result;
}

//자물쇠가 모두 1인지 확인(맞는 열쇠인지 확인)
bool check(vector<vector<int>> a){

	for (int i = a.size() / 3; i < a.size() / 3 * 2; i++) {
		for (int j = a.size() / 3; j < a.size() / 3 * 2; j++) {
			if (a[i][j] != 1) return false;
		}
	}
	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

	//크기가 3배인 자물쇠 배열선언
	vector<vector<int>> newlock(lock.size() * 3, vector<int>(lock.size() * 3));

	//가운데로 입력
	for (int i = 0; i < lock.size(); i++) {
		for (int j = 0; j < lock.size(); j++) {
			newlock[i + lock.size()][j + lock.size()] = lock[i][j];
		}
	}

	//4가지 방향에 대해 열쇠가 맞는지 확인
	for (int r = 0; r < 4; r++) {
		key = rotate90Degree(key); //90도 회전

		for (int i = 0; i < lock.size()*2; i++) {
			for (int j = 0; j < lock.size()*2; j++) {
                //열쇠
				for (int x = 0; x < key.size(); x++) {
					for (int y = 0; y < key.size(); y++) {
						newlock[x + i][y + j] += key[x][y]; //열쇠를 자물쇠에 끼어보기
					}
				}
				if (check(newlock)) return true; //맞는 열쇠이면 true 리턴
                
				for (int x = 0; x < key.size(); x++) {
					for (int y = 0; y < key.size(); y++) {
						newlock[x + i][y + j] -= key[x][y]; //열쇠를 자물쇠에 끼어보기
					}
				}
			}
		}
		
	}
	return false;
}
