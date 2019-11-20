#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 1010

using namespace std;

typedef long long int ll;

vector<int> arr;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		int N; cin >> N;

		for (int i = 0; i < N; i++) {
			int n; cin >> n;
			arr.push_back(n);
		}

		sort(arr.begin(), arr.end());

		int M; cin >> M;

		for (int i = 0; i < M; i++) {
			int num; cin >> num;

			int left = 0, right = N - 1, mid;

			bool toggle = false;
			while (left <= right) {
				mid = (left + right) / 2;

				if (arr[mid] < num)
					left = mid + 1;
				else if(arr[mid] >num)
					right = mid - 1;
				else {
					toggle = true;
					break;
				}
			}

			if (toggle)
				cout << "1\n";
			else
				cout << "0\n";
			
		}
		arr.clear();
	}
}