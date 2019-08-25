#include<iostream>
#define SIZE 110
using namespace std;

int arr[SIZE][SIZE];

int calc() {
	int m_num = 0;

	for (int i = 1; i <= 100; i++) {
		int sum = 0;
		for (int j = 1; j <= 100; j++) {
			sum += arr[i][j];
		}
		m_num = m_num < sum ? sum : m_num;
	}

	for (int j = 1; j <= 100; j++) {
		int sum = 0;
		for (int i = 1; i <= 100; i++) {
			sum += arr[i][j];
		}
		m_num = m_num < sum ? sum : m_num;
	}
	

	int cross = 0;
	for (int i = 1; i <= 100; i++) {
		cross += arr[i][i];
	}
	return m_num > cross ? m_num : cross;
}
int main(void) {
	ios::sync_with_stdio(false);

	for (int t = 1; t <= 10; t++) {
		int T; cin >> T;

		int m_num = 0;
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				cin >> arr[i][j];
			}
		}

		cout << "#" << t << " " << calc();
	}
}