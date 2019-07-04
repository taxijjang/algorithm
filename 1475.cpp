#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int arr[11];

int main(void) {
	string s;
	cin >> s;
	int size = s.size();
	bool tmp = true;
	for (int i = 0; i < size; i++) {
		int n = s[i] - '0';
		if (n == 6 || n == 9) {
			if (tmp) {
				arr[6]++;
			}
			else {
				arr[9]++;
			}
			tmp = !tmp;
		}
		else {
			arr[n]++;
		}		
	}
	sort(arr, arr + 11);
	printf("%d\n", arr[10]);
}