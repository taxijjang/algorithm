#include<iostream>
#include<vector>

using namespace std;

int window(int size, int ii, int jj, vector<vector<int>> &A) {
	int res = 0;
	int check = 0;
	//가로
	for (int i = ii; i < ii + size; i++) {
		check = 0;
		for (int j = jj; j < jj + size; j++) {
			check += A[i][j];
			if (i == ii)
				res = check;
		}
		if (res != check)
			return 0;
	}

	//세로
	for (int i = jj; i < jj + size; i++) {
		check = 0;
		for (int j = ii; j < ii + size; j++) {
			check += A[j][i];
		}
		if (res != check)
			return 1;
	}
	//오른쪽으로 대각선
	check = 0;
	int i = ii, j = jj;
	for (int s = 0; s < size; s++) {
		check += A[i++][j++];
	}

	if (res != check)
		return 1;

	//왼쪽으로 대각선
	check = 0;
	i = ii, j = jj + size - 1;
	for (int s = 0; s < size; s++) {
		check += A[i++][j--];
	}
	if (res != check)
		return 1;

	return size;
}
int solution(vector<vector<int>> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int res = 1;
	int m_size = A.size() < A[0].size() ? A.size() : A[0].size();

	int g_size = A.size();
	int s_size = A[0].size();
	for (int size = 2; size <= m_size; size++) {
		for (int i = 0; i < g_size; i++) {
			for (int j = 0; j < s_size; j++) {
				if (i + size - 1 >= g_size || j + size - 1 >= s_size)
					continue;
				res = res < window(size, i, j, A) ? window(size, i, j, A) : res;
			}
		}

	}
	return res;
}

int main(void) {
	ios::sync_with_stdio(false);

	vector < vector<int> >A({ vector<int>(1) });



	cout << solution(A);
}