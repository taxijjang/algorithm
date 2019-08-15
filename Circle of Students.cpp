#include<iostream>
#include<deque>
#define SIZE 210
using namespace std;

int arr[SIZE];
int main(void) {
	int T; scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int n; scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		deque<int> l;
		deque<int> r;
		for (int i = arr[0]; i < arr[0] + n; i++) {
			int num = i > n ? i%n : i;
			l.push_front(num);
			r.push_back(num);
		}

		l.push_front(arr[0]); l.pop_back();

		//¿ÞÂÊ
		int l_i = 0;
		int r_i = 0;
		
		while (!l.empty()) {
			if (l.front() == arr[l_i])
				l_i++;
			l.pop_front();
		}
		//¿À¸¥ÂÊ
		while (!r.empty()) {
			if (r.front() == arr[r_i])
				r_i++;
			r.pop_front();
		}
		if (r_i == n || l_i == n)
			printf("YES\n");
		else
			printf("NO\n");
	}
}