#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string DNA[1001];
int cnt[20] = { 0 ,};
int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		cin >> DNA[i];
	}

	int Hamming = 0;

	printf("\n");
	for (int i = 0; i < M; i++) {
		fill(cnt, cnt + 20, 0);
		for (int j = 1; j <= N; j++) {
			cnt[DNA[j][i] - 'A']++;
		}
		
		int nucle = max_element(cnt, cnt + 20) - cnt;
		printf("%c", nucle + 'A');
		Hamming += N - cnt[nucle];
	}
	printf("\n%d", Hamming);

	return 0;
}
