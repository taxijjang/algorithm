#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 1010

using namespace std;

typedef long long int ll;


vector<int> lesson;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		lesson.push_back(num);
	}

	ll left = 1, right = INF, mid;
	ll res = INF;
	while (left <= right) {
		mid = (left + right) / 2;
		ll blue_ray_cnt = 0;
		ll lesson_sum = 0;
		for (auto it = lesson.begin(); it != lesson.end(); it++) {
			if (lesson_sum + *it > mid) {
				lesson_sum = 0;
				blue_ray_cnt++;
			}
			lesson_sum += *it;
		}
		if (lesson_sum != 0)
			blue_ray_cnt++;

		if (blue_ray_cnt <= M) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			
		}
	}
	cout << left;
}