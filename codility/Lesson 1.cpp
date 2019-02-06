#include <iostream>
#include <vector>

using namespace std;

int solution(int N) {
	int arr[40];
	int num = N;
	int index;
	for (index = 0;num != 1; index++) {
		arr[index] = num % 2;
		num /= 2;
	}
	arr[index] = num;

	int judge = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i <= index; i++) {
		if (arr[i] == 1) {
			judge = 1;
			if (cnt1 < cnt2) {
				cnt1 = cnt2;
			}
			cnt2 = 0;
		}
		if (judge == 1) {
			if(arr[i] == 0)
				cnt2++;
		}
	}
	return cnt1;
}
int main(void) {
	int N;
	scanf("%d", &N);

	printf("%d",solution(N));
	
}