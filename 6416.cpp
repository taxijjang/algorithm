#include<iostream>
#include<map>

using namespace std;

int main(void) {
	bool toggle = true;
	map<int, pair<int,int>> m;
	int t = 0;
	while (toggle) {
		t++;
		m = map<int, pair<int, int>>();
		while (1) {
			int a, b;scanf("%d %d",&a,&b);
			if (a == 0 && b == 0)
				break;
			else if (a == -1 && b == -1) {
				toggle = !toggle;
				break;
			}
			if (m.find(a) == m.end()) {
				m.insert({ a,{1,0} });
			}
			else {
				m[a].first++;
			}

			if (m.find(b) == m.end()) {
				m.insert({ b,{0,1} });
			}
			else {
				m[b].second++;
			}
		}
		
		if (toggle) {
			bool res = true;
			int r_cnt = 0;
			for (auto it = m.begin(); it != m.end(); it++) {
				if ((it->second.second) > 1) {
					res = false;
					break;
				}
				if ((it->second.second) == 0) {
					r_cnt++;
				}
			}

			if (r_cnt > 1 || r_cnt == 0)
				res = !res;
			if (res) {
				printf("Case %d is a tree.\n", t);
			}
			else {
				printf("Case %d is not a tree.\n", t);
			}
		}
	}
}