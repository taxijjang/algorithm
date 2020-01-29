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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	do {
		int arr[3], zero_cnt = 0;
		for (int i = 0; i < 3; i++) {
			cin >> arr[i];
			zero_cnt += arr[i] == 0 ? 1 : 0;
		}

		if(zero_cnt== 3)
			break;

		sort(arr, arr + 3);
		if (((arr[0] * arr[0]) + (arr[1] * arr[1])) == (arr[2] * arr[2]))
			cout << "right\n";
		else
			cout << "wrong\n";
	} while (1);
}