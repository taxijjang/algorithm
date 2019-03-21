#include<string>
#include <cstring>
#include <iostream>
#include<map>

using namespace std;

map<string, int> Name;
map<int, string> Num;

int main(void) {
	int N, M;
	char sss[500];
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		string s;
		int num = i;
		cin >> s;
		Name.insert(make_pair(s,num));
		Num.insert(make_pair(num, s));
	}

	for (int i = 0; i < M; i++) {
		scanf("%s", sss);
		string s = sss;

		if (s[0] >= '0' && s[0] <= '9') {
			printf("%s\n", Num[atoi(sss)].c_str());
		}
		else {
			printf("%d\n",Name[s]);
		}
	}
}