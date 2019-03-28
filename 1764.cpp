#include <iostream>
#include<string>
#include<set>

using namespace std;

set<string> name;
set<string> dbg;
int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		name.insert(s);
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;

		auto iter = name.find(s);
		
		if (iter != name.end())
			dbg.insert(s);
	}
	printf("%d\n", dbg.size());
	for (auto iter = dbg.begin(); iter != dbg.end(); iter++) {
		cout << *iter << "\n";
	}
	return 0;
}