#include<iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int man = 0;
	int m_m = 0;
	for (int i = 0; i < 4; i++) {
		int out, in; cin >> out >> in;

		man += in - out;
		m_m = man > m_m ? man : m_m;
	}

	cout << m_m;
}