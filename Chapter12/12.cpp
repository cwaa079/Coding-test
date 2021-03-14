//기둥과 보 설치
//https://programmers.co.kr/learn/courses/30/lessons/60061

#include <bits/stdc++.h>

using namespace std;

bool possible(vector<vector<int>> answer) {
	for (int i = 0; i < answer.size(); i++) {
		int x = answer[i][0];
		int y = answer[i][1];
		int a = answer[i][2];

		if (a == 0) { //설치된 것이 기둥이면
			bool check = false;
			if (y == 0) check = true; //바닥위면 정상
            
			//보의 한쪽 끝 부분 위이거나 다른 기둥위면 정상
			for (int j = 0; j < answer.size(); j++) {
				if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) 
					check = true;
				if (x == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
					check = true;
				if(x == answer[j][0] && y-1 == answer[j][1] && 0 == answer[j][2])
					check = true;
			}
			if (!check) return false;
		}
		else if (a == 1) {//설치된 것이 보이면
			bool check = false;
			bool left = false;
			bool right = false;

			//한쪽 끝부분이 기둥위이거나 양쪽 끝부분이 다른 보와 연결이면 정상
			for (int j = 0; j < answer.size(); j++) {
				if (x +1 == answer[j][0] && y - 1== answer[j][1] && 0 == answer[j][2])
					check = true;
				if (x == answer[j][0] && y -1 == answer[j][1] && 0 == answer[j][2])
					check = true;
				if (x - 1== answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
					left = true;
				if (x + 1== answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
					right = true;
			}
			if (left&&right) check = true;
			if (!check) return false;
		}
	}
	return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    	for (int i = 0; i < build_frame.size(); i++) {
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int a = build_frame[i][2]; //기둥(0), 보(1)
		int b = build_frame[i][3]; //삭제(0), 설치(1)

		if (b == 0) { //삭제
			int index = 0;
			for (int j = 0; j < answer.size(); j++) {
				if (x == answer[j][0] && y == answer[j][1] && a == answer[j][2])
					index = j;
			}
			vector<int> deleted = answer[index];
			answer.erase(answer.begin() + index); //벡터 삭제
			if (!possible(answer)) answer.push_back(deleted); //가능한 구조물인지확인
		}

		if (b == 1) { //설치
			//일단 설치
			vector<int>inserted;
			inserted.push_back(x);
			inserted.push_back(y);
			inserted.push_back(a);
			answer.push_back(inserted);
			if (!possible(answer)) answer.pop_back();
		}
	}
	sort(answer.begin(), answer.end()); //정렬
    return answer;
}
