#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;

typedef struct Data {
	int x, y;

	bool operator <(Data d) {
		if (y == d.y)
			return x < d.x;
		return y < d.y;
	}
}Data;

Data loc[100100];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> loc[i].x >> loc[i].y;
	}

	sort(loc, loc + N);

	for (int i = 0; i < N; i++) {
		cout << loc[i].x << " " << loc[i].y << "\n";
	}

}