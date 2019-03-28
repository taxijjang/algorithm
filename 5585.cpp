#include<iostream>

int main(void) {
	int arr[6] = { 500,100,50,10,5,1 };

	int cost;
	scanf("%d", &cost);

	cost = 1000 - cost;

	int cnt = 0;
	for (int i = 0; cost != 0;i++) {
		if (cost / arr[i] > 0) {
			cnt += (cost / arr[i]);
			cost = cost - (arr[i] * (cost / arr[i]));
		}
	}
	printf("%d", cnt);
}