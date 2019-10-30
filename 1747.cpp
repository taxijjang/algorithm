#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 2000100

using namespace std;

typedef long long int ll;

bool prime[SIZE];

void eratos() {
	prime[1] = true;
	for (int i = 2; i < SIZE; i++) {
		for (int j = 2; j *i < SIZE; j++) {
			if (prime[i*j] != true)
				prime[i*j] = true;
		}
	}
}

bool pall_check(string num) {
	int p_size = num.size();
	int left = 0, right = p_size - 1;

	while (left <= right) {
		if (num[left] != num[right])
			return false;
		left++; right--;
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	eratos();

	int N; cin >> N;

	for (int i = N+1; i < SIZE; i++) {
		if (prime[i] == false) {
			if (pall_check(to_string(i))) {
				cout << i;
				return 0;
			}
		}

	}

	return 0;
}