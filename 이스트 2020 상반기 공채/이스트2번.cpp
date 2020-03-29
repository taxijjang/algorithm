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

//�ڸ���, �ڸ����� �´� ���ڸ� ū ������� �����ϱ� ���� pq �̿�
map<int, priority_queue<int>> _map;

//�ڸ��� ���
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

	//�ڸ��� ����Ͽ� map�� ����
	for (auto a : A) {
		_map[jari_calc(a)].push(a);
	}

	int res = 0;
	//map�� Ž���ϸ� ���ڵ��� ���� �ִ밪�� ���ϱ�
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