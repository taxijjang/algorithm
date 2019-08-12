#include<iostream>
#include<string>

using namespace std;

int main(void) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int res = 0;
		int cnt = 0;
		while (1) {
			cnt++;
			res = (res * 10 + 1) % n;
			
			if (res == 0) {
				printf("%d\n", cnt);
				break;
			}			
		}
	}
}