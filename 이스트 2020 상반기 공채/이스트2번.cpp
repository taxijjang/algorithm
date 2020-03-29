#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#include<cmath>
#include<stack>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

//자리수, 자리수에 맞는 숫자를 큰 순서대로 정렬하기 위해 pq 이용
map<int, priority_queue<int>> _map;

//자리수 계산
int jari_calc(int num) {
	int jari_sum = 0;

	while (num > 0) {
		jari_sum += num % 10;
		num /= 10;
	}
	return jari_sum;
}
int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	//자리수 계산하여 map에 저장
	for (auto a : A) {
		_map[jari_calc(a)].push(a);
	}

	int res = 0;
	//map을 탐색하며 숫자들의 합중 최대값을 구하기
	for (auto it = _map.begin(); it != _map.end(); it++) {
		if (it->second.size() >= 2) {
			int a1 = it->second.top(); it->second.pop();
			int a2 = it->second.top(); it->second.pop();

			res = (res> a1 + a2 ? res : a1 + a2);
		}
	}

	return (res == 0 ? -1 : res);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int > A = { 51,71,17,42 };
	cout << solution(A);
}