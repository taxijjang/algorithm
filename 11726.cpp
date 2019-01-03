#include <iostream>
#include <cstring>
using namespace std;

int tile(int N);
int cache[1001];
int main(void) {
	int N;
	cin >> N;
	memset(cache, -1, sizeof(cache));
	cout <<tile(N);
}

int tile(int N) {
	//if (N == 0) {
	//	return 1;
	//}
	if (N == 1) {
		return 1;
	}
	int& ret = cache[N];
	if (ret != -1) return ret;
	return (tile(N - 1) + tile(N - 2)) % 10007;
}