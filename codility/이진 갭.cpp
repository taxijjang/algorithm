#include<iostream>

using namespace std;

int solution(int N) {
	int num = N;
	int cnt = 0;
	int res = 0;
	bool toggle = false;
	while (num > 0) {
		int na = num % 2;

		if (na == 1){
			toggle = true;
			res = res < cnt ? cnt : res;
			cnt = 0;
		}
		else if(na == 0 && toggle == true) {
			cnt++;
		}
		num /= 2;
	}

	return res;
}
int main(void) {
	ios::sync_with_stdio(false);

	int N; cin >> N;
	cout << solution(N);
}