#include<iostream>
#include<map>
#include<string>
#include <vector>
#include<algorithm>

using namespace std;

map<string, int> Data;
vector<pair<int, string>> v;

int main(void) {
	int K, L;
	scanf("%d %d", &K, &L);

	for (int i = 1; i <= L; i++) {
		string num;
		cin >> num;
		Data[num] = i;
	}

	for (auto it = Data.begin(); it != Data.end(); it++) {
		v.push_back(make_pair(it->second, it->first));
	}

	sort(v.begin(), v.end());

	int cnt = 0;

	for (auto it = v.begin(); it != v.end(); it++) {
		if (cnt < K) {
			cout << it->second << "\n";
			cnt++;
		}
	}
}