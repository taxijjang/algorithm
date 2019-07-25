#include<iostream>
#define SIZE 8

using namespace std;
int main(void) {
	int cnt = 0;
	for (int i = 0; i < SIZE; i++) {
		bool judge = false;
		if (i % 2 == 0) judge = true;
		else judge = false;
		for (int j = 0; j < SIZE; j++) {
			char c; cin >> c;
			if (judge && c == 'F' && j % 2 == 0) {
				cnt++;
			}
			else if (!judge && c == 'F' && j % 2 == 1) {
				cnt++;
			}
		}
	}
	printf("%d", cnt);
}