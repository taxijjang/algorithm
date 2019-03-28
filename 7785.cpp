#include<iostream>
#include <set>
#include <string>

using namespace std;

set<string> emp;
int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		string name, state;
		cin >> name >> state;

		if (state == "enter") {
			emp.insert(name);
		}
		else if (state == "leave") {
			emp.erase(name);
		}
	}

	for (auto iter = emp.rbegin(); iter != emp.rend(); iter++) {
		cout << *iter << "\n";
	}

	return 0;
}