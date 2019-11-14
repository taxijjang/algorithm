#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

using namespace std;

long long solution(int w, int h)
{
	long long answer = 1;
	long long tmp_w = static_cast<long long> (w);
	long long tmp_h = static_cast<long long>(h);

	if (tmp_w % tmp_h == 0)
		answer = tmp_w*tmp_h - tmp_w;
	else {
		if (tmp_w < tmp_h) swap(tmp_w, tmp_h);
		long long ratio = gcd(tmp_w, tmp_h);
		long long area = tmp_w*tmp_h;
		long long div = tmp_w / ratio + tmp_h / ratio - 1;

		area -= ratio*div;
		answer = area;
	}
	return answer;
}

int main(void) {
	cout << solution(8, 12);
}