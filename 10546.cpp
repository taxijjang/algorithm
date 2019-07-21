#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string, int> m;
int main(void) {
	int N; scanf("%d", &N);

	for (int i = 0; i < (N*2) - 1; i++) {
		string s; cin >> s;
		if (m[s] == 0)
			m[s] = 1;
		else if (m[s] == 1)
			m.erase(s);
	}
	auto it = m.begin();

	cout << it->first;
}