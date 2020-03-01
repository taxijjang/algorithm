#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	while (T--) {
		vector<int> food(4, 0);
		int res = 0;
		cin >> food[1] >> food[2] >> food[3];

		sort(food.begin(), food.end());

		if (food[1] >= 4) {
			cout << 7 << "\n";
			continue;
		}
		if (food[3] == 0) {
			cout << 0 << "\n";
			continue;
		}

		if (food[3]>0) food[3]--, res++;
		if (food[2]>0) food[2]--, res++;
		if (food[1]>0) food[1]--, res++;
		if (food[3]>0 && food[2]>0) food[3]--, food[2]--, res++;
		if (food[3]>0 && food[1]>0) food[3]--, food[1]--, res++;
		if (food[1]>0 && food[2]>0) food[1]--, food[2]--, res++;
		if (food[3]>0 && food[2]>0 && food[1]>0) food[3]--, food[2]--, food[1]--, res++;


		cout << res << "\n";
	}
}
