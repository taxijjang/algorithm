#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M; cin >> M;

	int res = 0;
	for (int i = 0; i < M; i++) {
		string menu; cin >> menu;

		if (menu == "add") {
			int num; cin >> num;
			res |= (1 << num);
		}
		else if (menu == "remove") {
			int num; cin >> num;
			if (res &(1 << num))
				res &= ~(1 << num);
		}
		else if (menu == "check") {
			int num; cin >> num;
			if (res & (1 << num)) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (menu == "toggle") {
			int num; cin >> num;
			if (res &(1 << num))
				res &= ~(1 << num);
			else
				res |= (1 << num);
		}
		else if (menu == "all") {
			res = 0;
			for (int i = 1; i <= 20; i++)
				res |= (1 << i);
		}
		else if (menu == "empty") {
			res = 0;
		}
	}

}