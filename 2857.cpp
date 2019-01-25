#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	string name[5];
	vector<int> num;
	for (int i = 0; i < 5; i++) {
		cin >> name[i];
	}

	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		int find = 0;
		if (name[i].find("FBI",0) != -1) {
			num.push_back(i + 1);
			cnt++;
		}

	}

	if (cnt != 0) {
		for (int i = 0; i < num.size(); i++) {
			printf("%d ", num[i]);
		}
	}
	else
		printf("HE GOT AWAY!\n");

}