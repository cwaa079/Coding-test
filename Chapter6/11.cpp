//성적이 낮은 순서로 학생 출력하기

#include <bits/stdc++.h>

using namespace std;

//학생 클래쓰
class Student {
public:
	string name; //이름
	int score; //점수
	Student(string name, int score) { //생성자
		this->name = name;
		this->score = score;
	}
	bool operator <(Student &other) {
		return this->score < other.score;
	}
};

int n;
vector <Student> v;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		string name;
		int score;
		cin >> name >> score;
		v.push_back(Student(name,score));
	}

	sort(v.begin(), v.end()); //정렬을 사용하기 위해 오퍼레이터 재정의
	
	for (int i = 0; i < n; i++)
		cout << v[i].name << ' ';

	return 0;
}
