#include <iostream>
#include <algorithm>
#define MAX 5000001
using namespace std;
typedef long long int ll;

ll arr[MAX];
ll temp[MAX];
ll temp2[MAX];
int main(void) {
	int N, L;
	scanf("%d %d", &N, &L);

	for (int i = 1; i <= N; i++) {
		scanf("%lld", &arr[i]);
	}

	fill_n(temp,5000001, 1000000001);
	fill_n(temp2, 5000001, 1000000001);
	int head = 1, tail = 1;
	int t_index = 0;
	while (tail <= N) {
		temp[(t_index % L) + 1] = arr[(t_index++) + 1];
		copy(temp, (temp + L) + 1, temp2);
		sort(temp + 1, temp + tail + 1);
		printf("%lld ", temp[1]);
		copy(temp2, (temp2 + L) + 1, temp);
		tail++;
	
	}
	return 0;
}