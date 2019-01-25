#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string N;
	cin >> N;

	int n = stoi(N);
	
	int sum;
	string t;
	for (int i = 1; i <= n; i++) {
		sum = 0;
		t = to_string(i);
		int size = t.size();
		for (int j = 0; j < size; j++) {
			sum += t[j] - '0';
		}
		if ((sum += i) == n) {
			printf("%d", i);
			i = n;
			break;
		}
	}
}