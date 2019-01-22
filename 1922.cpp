#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <pair<int, int>> graph[100001];
int judge[1001] = { 0 };
int arr[1001] = { 0 };

int Find(int a);
void Union(int a, int b);

int main(void) {
	int N;
	scanf("%d", &N);

	for (int n = 1; n <=  N; n++) {
		arr[n] = n;
	}

	int M;
	scanf("%d", &M);

	int a, b, cost;

	for (int m=1; m <= M; m++) {
		scanf("%d %d %d", &a, &b, &cost);
		graph[cost].push_back(pair<int, int>(a, b));
	}

	int sum = 0;
	for (int m = 1; m <= M; m++) {
		if(!graph[m].empty()){
			for (auto node : graph[m]) {
				if (Find(node.first) != Find(node.second)) {
					Union(node.first, node.second);
					sum += m;
				}
			}
		}
	}
	printf("%d", sum);
}

void Union(int a, int b) {
	int aRoot = Find(a);
	int broot = Find(b);
	arr[aRoot] = broot;
}

int Find(int a) {
	if (arr[a] == a) return a;
	else return arr[a] = Find(arr[a]);
}