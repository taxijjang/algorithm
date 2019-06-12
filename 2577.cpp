#include<iostream>
typedef long long int ll;
using namespace std;

int main(void) {
	ll a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);

	ll sum = a*b*c;
	int arr[10] = { 0 ,};
	while(sum!=0) {
		arr[sum % 10]++;
		sum /= 10;
	}

	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
}