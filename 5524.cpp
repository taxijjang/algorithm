#include<iostream>
#include<string>

using namespace std;

int main(void) {
	int N; scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		cout << s <<"\n";
	}
}