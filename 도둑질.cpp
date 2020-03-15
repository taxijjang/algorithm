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

#define SIZE 1010000
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int dp1[SIZE];
int dp2[SIZE];
int solution(vector<int> money) {
	int answer = 0;

	//���� 3�� �϶�
	if (money.size() == 3)
		return (money[1] > money[0] + money[2] ? money[1] : money[0] + money[2]);
	//�ð������� 1�� ����
	
	//1���� ��ġ�� ������ ���� �� ��ĥ ��
	dp1[0] = money[0]; dp1[1] = max(money[0],money[1]);

	for (int i = 2; i < money.size() - 1; i++) {
		dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
	}

	//1�� �� ��ġ�� ������ ���� ��ĥ ��
	dp2[0] = 0; dp2[1] = money[1];
	for (int i = 2; i < money.size(); i++) {
		dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
	}

	//�ִ밪 ����
	for (int i = 0; i < money.size(); i++) {
		answer = max(answer, max(dp1[i], dp2[i]));
	}

	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> money = { 10, 2 ,2, 100, 2};

	cout << solution(money);
}