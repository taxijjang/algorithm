#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 10000

using namespace std;

typedef long long int ll;

map<char, int> _map;

int arr[SIZE];
int N, M;
void init() {
	for (char i = 'A'; i <= 'Z'; i++) {
		if (i == 'C' || i == 'G' || i == 'I' || i == 'J' || i == 'L' || i == 'O' || i == 'S' || i == 'U' || i == 'V' || i == 'W' || i == 'Z')
			_map.insert({ i,1 });
		else if (i == 'B' || i == 'D' || i == 'N' || i == 'P' || i == 'Q' || i == 'R' || i == 'T' || i == 'X' || i == 'Y')
			_map.insert({ i,2 });
		else if (i == 'E')
			_map.insert({ i,4 });
		else
			_map.insert({ i,3 });
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	init();

	cin >> N >> M;
	string n, m; cin >> n >> m;

	int len = N < M ? N : M;

	bool toggle = N > M ? true : false;

	int index = 0;

	for (int i = 0; i < len * 2 ; ) {
		arr[i++] = _map[n[index]];
		arr[i++] = _map[m[index++]];
	}

	if (toggle) {
		int i = len * 2 ;
		while (index < N) {
			arr[i++] = _map[n[index++]];
		}
	}
	else {
		int i = len * 2;
		while (index < M) {
			arr[i++] = _map[m[index++]];
		}
	}

	for (int i = N+M; i > 2; i--) {
		for (int j = 1; j < i; j++) {
			arr[j - 1] = (arr[j-1] + arr[j])%10;
		}
	}

	if (arr[0] != 0)
		cout << arr[0];
	cout << arr[1] << "%";
}
