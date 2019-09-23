#include<iostream>
#include<string>
#include<vector>

using namespace std;

string solution(int U, int L, vector<int> &C) {
	int c_size = C.size();

	//2�ǰ��� ī��Ʈ
	int count = 0;
	int c_sum = 0;
	string u = "";
	string l = "";

	for (int i = 0; i < c_size; i++) {
		if (C[i] == 2) {
			u += '1';
			l += '1';
			count++;
		}
		else {
			u += '0';
			l += '0';
			c_sum += C[i];
		}
	}

	U = U - count;
	L = L - count;

	// �������� ������ �Ǻ�
	if (U + L != c_sum || U < 0 || L < 0) {
		return "IMPOSSIBLE";
	}
	for (int i = 0; i < c_size; i++) {
		if (C[i] == 1) {
			if (U != 0) {
				u[i] = '1';
				l[i] = '0';
				U--;
			}
			else {
				u[i] = '0';
				l[i] = '1';
				L--;
			}
		}
	}
	return u + ',' + l;
}