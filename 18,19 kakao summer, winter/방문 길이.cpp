#include <string>
#include<iostream>
#include<set>
#include<vector>
#include<set>


#define SIZE 550

using namespace std;



int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,-0,0 };

int cnt = 0;
typedef struct Data{
	int x = 0, y = 0;

	bool operator ==(Data d) {
		if (x == d.x && y == d.y)
			return true;
		return false;
	}
}Data;
Data loc;
vector<pair<Data, Data>> v;

Data calc(Data h, char w) {
	Data n;
	if (w == 'U') {
		n.x = h.x + dx[0];
		n.y = h.y + dy[0];
	}
	else if (w == 'D') {
		n.x = h.x + dx[1];
		n.y = h.y + dy[1];
	}
	else if (w == 'R') {
		n.x = h.x + dx[2];
		n.y = h.y + dy[2];
	}
	else if (w == 'L') {
		n.x = h.x + dx[3];
		n.y = h.y + dy[3];
	}

	if (n.x < -5 || n.x > 5 || n.y < -5 || n.y >5)
		return h;

	return n;
}

void check(Data h, char w) {
	Data n = calc(h, w);
	if (n == h)
		return;
	loc = n;
	bool toggle = true;
	for (auto it = v.begin(); it != v.end(); it++) {
		if ((n.x == it->first.x && n.y == it->first.y &&
			h.x == it->second.x && h.y == it->second.y) ||
			(h.x == it->first.x && h.y == it->first.y &&
				n.x == it->second.x && n.y == it->second.y)) {
			toggle = false;
			break;
		}
	}

	if (toggle) {
		v.push_back({ h,n });
		cnt++;
	}

}

int solution(string dirs)
{
	int answer = 0;
	int d_size = dirs.size();


	for (int i = 0; i < d_size; i++) {
		check(loc, dirs[i]);
	}
	return answer = cnt;
}

int main(void) {
	string s; cin >> s;
	cout << solution(s);
}