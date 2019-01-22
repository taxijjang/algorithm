#include <iostream>
#include <string>

using namespace std;

int arr[1001];
int main(void) {
	string s,c;
	cin >> s;

	int size, first, second, d;
	int cnt = 0;
	if (stoi(s) < 10) cnt += stoi(s);
	else {
		cnt += 9;
	}
	for (int j = 1; j <= stoi(s); j++) {
		c = to_string(j);
		first = c[0];
		second = c[1];
		size = c.size();
		d = first - second;
		for (int i = 0; i < size - 1; i++) {
			if ((c[i] - c[i + 1]) != d) break;
			if (i == size - 2) cnt++;
		}
	}
	printf("%d", cnt);
}