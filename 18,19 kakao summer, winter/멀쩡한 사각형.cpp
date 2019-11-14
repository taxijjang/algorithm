#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

int gcd(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

using namespace std;

long long solution(int w, int h)
{
	long long answer = 1;

	if (w % h == 0)
		answer = w*h - w;
	else {
		if (w < h) swap(w, h);
		long long ratio = gcd(w, h);
		long long area = w*h;
		long long div = w / ratio + h / ratio - 1;


		getchar();
	}
	return answer;
}

int main(void) {
	cout << solution(8, 12);
}