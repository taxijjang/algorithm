#include <iostream>

int arr[100001][4] = { 0 };
int psum[100001][4] = { 0 };

int main(void) {
	int a, b;
	scanf("%d %d", &a,&b);

	for (int i = 1; i <= a; i++) {
		int race;
		scanf("%d", &race);
		arr[i][race] = 1;
	}

	psum[1][1] = arr[1][1];
	psum[1][2] = arr[1][2];
	psum[1][3] = arr[1][3];

	for (int i = 2; i <= a; i++) {
		psum[i][1] = psum[i - 1][1] + arr[i][1];
		psum[i][2] = psum[i - 1][2] + arr[i][2];
		psum[i][3] = psum[i - 1][3] + arr[i][3];
	}

	for (int i = 0; i < b; i++) {
		int start, end;
		scanf("%d %d", &start, &end);

		printf("%d %d %d\n", psum[end][1] - psum[start - 1][1],
			psum[end][2] - psum[start - 1][2], psum[end][3] - psum[start - 1][3]);

	}
	return 0;
}