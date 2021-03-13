//무지의 먹방 라이브
//문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42891

#include <bits/stdc++.h>

using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second<b.second;
}

int solution(vector<int> food_times, long long k) {

	long long sum = 0;
	for (int i = 0; i < food_times.size(); i++) {
		sum += food_times[i];
	}
	if (sum <= k) return -1;

	priority_queue<pair<int, int>> pq; //음식 시간, 번호

	for (int i = 0; i<food_times.size(); i++) {
		pq.push({ -food_times[i],i + 1 });
	}

	sum = 0; //먹기 위해 사용한 시간
	long long pre = 0; //이전에 먹은 음식 시간
	long long len = food_times.size(); //남은 음식의 개수

	while (sum + ((-pq.top().first - pre)*len) <= k) {
		int now = -pq.top().first; //가장 적은 시간
		pq.pop();
		sum += (now - pre) * len; //가장 적은 시간 1개를 다 먹은 시간을 더해감
		//남은 음식의 개수를 곱하는 이유 : 한번 먹고 전체를 돌고 먹을 수 있으니까
		len--;
		pre = now;
	}

	vector <pair<int, int>> result; //시간,음식번호
	while (!pq.empty()) {
		int food_time = -pq.top().first; //가장 적은 시간
		int num = pq.top().second; //가장 적은 시간의 음식번호
		pq.pop();
		result.push_back({ food_time,num });
	}
	sort(result.begin(), result.end(), compare); //음식번호 순서대로 정렬

	return result[(k - sum) % len].second;
	//(중단된 시간 - 먹기위해 사용한 시간) % 남은 음식의 개수의 나머지 수의 음식번호
}
