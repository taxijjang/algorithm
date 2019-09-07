#include <vector>

using namespace std;

int solution(int inner, int outer, vector<int>& point_x, vector<int>& point_y) {
	int len = point_x.size();
	int size = 0;
	int cnt = 0;

	// �����ֵ� �Ÿ����
	for (int i = 0; i < len; i++) {
		size = (point_x[i] * point_x[i] + point_y[i] * point_y[i]);

		if ((inner * inner) < size && (outer * outer) > size) {
			cnt++;
		}
	}

	return cnt;
}