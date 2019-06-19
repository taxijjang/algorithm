#include<iostream>
#define SIZE 10000

using namespace std;
bool arr[SIZE];

int main(void) {
	int sum = 0;
	for(int i =1 ; i <=SIZE;i++){
		sum += i;
		int n = i;
		while (n != 0) {
			sum += n % 10;
			 n/= 10;
		}
		arr[sum] = true;
		sum = 0;
	}

	for (int i = 1; i <= SIZE; i++) {
		if (!arr[i]) printf("%d\n", i);
	}
	getchar();
}