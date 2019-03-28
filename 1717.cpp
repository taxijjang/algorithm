#include<iostream>

int parent[1000001];

int Find(int a) {
	if (parent[a] == a)
		return a;
	else {
		return parent[a] = Find(parent[a]);
	}
}

void Union(int a, int b) {
	int a_root = Find(a);
	int b_root = Find(b);
	parent[b_root] = a_root;
}
int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == 0) {
			Union(b, c);
		}
		else if (a == 1) {
			int B_root = Find(b);
			int C_root = Find(c);
			
			if (B_root == C_root) {
				printf("YES\n");
			}
			else if (B_root != C_root) {
				printf("NO\n");
			}
		}
	}
}