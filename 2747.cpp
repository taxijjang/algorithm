#include<iostream>
typedef long long int ll;
ll arr[100000];

int fibo(int n) {
	return 0;
}
int main(void) {
	int n; scanf("%d", &n);

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= 45; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	printf("%lld", arr[n]);
}