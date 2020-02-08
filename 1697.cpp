#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<string.h>

#define SIZE 202020

using namespace std;

typedef long long int ll;

typedef struct Data {
	int loc, cnt = 0;
}Data;

const int INF = 2e9;
bool visited[SIZE];

queue<Data> q;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;  cin >> N >> K;
	int max_index = (2 * K - N);
	Data start; 
	start.loc = N;
	start.cnt = 0;

	q.push(start);
	
	while (!q.empty()) {
		Data here = q.front();
		visited[here.loc] = true;

		if (here.loc == K) {
			cout << here.cnt;
			break;
		}
		q.pop();

		int left = here.loc - 1;
		int right = here.loc + 1;
		int telpo = 2 * here.loc;

		Data next;
		next.cnt = here.cnt + 1;
		//-1
		if (left >= 0 && visited[left] != true) {
			next.loc = left;
			q.push(next);
			visited[next.loc] = true;
		}

		//+1
		if (right <= max_index && visited[right] != true) {
			next.loc = right;
			q.push(next);
			visited[next.loc] = true;
		}

		//*2
		if (telpo <= max_index && visited[telpo] != true) {
			next.loc = telpo;
			q.push(next);
			visited[next.loc] = true;
		}
	}

	return 0;
}