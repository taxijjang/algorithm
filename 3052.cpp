#include<iostream>
#include<set>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	set<int> s;

	for (int i = 0; i < 10; i++) {
		int num; cin >> num;
		s.insert(num % 42);
	}

	cout << s.size();

}