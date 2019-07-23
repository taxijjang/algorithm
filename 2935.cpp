#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string a, b;
	char ki;

	cin >> a >> ki >> b;

	int a_size = a.size();
	int b_size = b.size();

	if (ki == '*') {
		for (int i = 1; i < b_size; i++) {
			a += "0";
		}
		cout << a;
	}
	else if (ki == '+') {
		if (a_size > b_size) {
			a[a_size - b_size] += 1;
			cout << a;
		}
		else {
			b[b_size - a_size] += 1;
			cout << b;
		}
	}
}