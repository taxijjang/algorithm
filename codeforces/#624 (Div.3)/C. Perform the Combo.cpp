#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define SIZE 200010
const int INF = 2e9;
using namespace std;

typedef long long int ll;

map<int, map<char, int>> arr;

//int arr[SIZE][30];
int res[30];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	while (T--) {
		arr.clear();
		memset(res, 0, sizeof(res));
		int n, m; cin >> n >> m;
		string s; cin >> s;

		for (int i = 1; i <= s.size(); i++) {
			arr[i][s[i - 1]]++;
			for (auto cnt : arr[i - 1])
				arr[i][cnt.first] += cnt.second;
		}		
		
		for (int i = 0; i < m; i++) {
			int p; cin >> p;
			for(int j = 'a'; j <= 'z'; j++) {
				res[j-'a'] += arr[p][j];
				if (i == m - 1) {
					res[j- 'a'] +=arr[s.size()][j];
					cout << res[j-'a'] << " ";
				}
			}
		}
		cout << "\n";
	}
	return 0;
}