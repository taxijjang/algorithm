#include <iostream>

using namespace std;

int tree[2000][2];

void pre_order(int root) {
	if (root == '.') return;
	else {
		printf("%c", root);
		pre_order(tree[root][0]);
		pre_order(tree[root][1]);
	}
}

void in_order(int root) {
	if (root == '.') return;
	else {
		in_order(tree[root][0]);
		printf("%c", root);
		in_order(tree[root][1]);
	}
}

void post_order(int root) {
	if (root == '.') return;
	else {
		post_order(tree[root][0]);
		post_order(tree[root][1]);
		printf("%c", root);
	}
}
int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		char root, n1, n2;
		cin >> root >> n1 >> n2;
		tree[root][0] = n1;
		tree[root][1] = n2;
	}
	pre_order('A');
	printf("\n");
	in_order('A');
	printf("\n");
	post_order('A');
	printf("\n");
}