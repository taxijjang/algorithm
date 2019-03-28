#include<iostream>
#include<set>
#include<string>

using namespace std;

set<int> S;
int main(void) {
	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		string menu;
		cin >> menu;

		int num;
		scanf("%d", &num);

		if (menu == "add") {
			S.insert(num);
		}
		else if (menu == "remove") {
			S.erase(num);
		}
		else if (menu == "check") {
			if (S.find(num) != S.end()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (menu == "toggle") {
			if (S.find(num) != S.end()) {
				S.erase(num);
			}
			else {
				S.insert(num);
			}
		}
		else if (menu == "all") {
			for (int i = 1; i <= 20; i++) {
				S.insert(i);
			}
		}
		else if (menu == "empty") {
			S.clear();
		}
	}
}