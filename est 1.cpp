#include<iostream>
#include<string>

using namespace std;

int solution(string &S) {
	int s_size = S.size();

	char c = S[0];
	int e_cnt = 1;
	int cnt = 1;
	int m_cnt = 1;
	for (int i = 1; i < s_size; i++) {
		if (c == S[i]) {
			e_cnt++;
			if (e_cnt == 3) {
				e_cnt = 2;
				m_cnt = m_cnt < cnt ? cnt : m_cnt;
				//이미 앞에 같은 수가 있으므로 2로 초기화
				cnt = 2;
			}
			else {
				cnt++;
				m_cnt = m_cnt < cnt ? cnt : m_cnt;
			}
		}
		else if (c != S[i]) {
			e_cnt = 1;
			c = S[i];
			cnt++;
			m_cnt = m_cnt < cnt ? cnt : m_cnt;
		}
	}
	return m_cnt;
}