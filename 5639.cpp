#include<iostream>
#include<cstdio>
#define SIZE 1001000

using namespace std;

int tree[SIZE][2];

void post(int root) {
	if(tree[root][0] != 0)
		post(tree[root][0]);
	if(tree[root][1] != 0)
		post(tree[root][1]);
	printf("%d\n", root);
}
int main(void) {
	int root; scanf("%d", &root);

	int node;
	while (scanf("%d",&node) != EOF) {
		int n_root= root;
		while (1) {
			if (n_root > node && tree[n_root][0] != 0) {
				n_root = tree[n_root][0];
			}
			else if (n_root > node && tree[n_root][0] == 0) {
				tree[n_root][0] = node;
				break;
			}
			else if (n_root < node && tree[n_root][1] != 0) {
				n_root = tree[n_root][1];
			}
			else if (n_root < node && tree[n_root][1] == 0) {
				tree[n_root][1] = node;
				break;
			}
			
		}
	}

	post(root);
	return 0;

}