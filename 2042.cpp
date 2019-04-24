#include<iostream>

typedef long long int ll;
using namespace std;

ll tree[4000001];
int start_index;
//첫 번째 명령
void first_cmd(int index, int num) {
	int node = index + start_index -1;
	int tmp = num - tree[node];
	while (node > 0) {
		tree[node] += tmp;
		node /= 2;
	}
}

//두 번째 명령
ll second_cmd(int left, int right) {
	int sum = 0;
	left += start_index - 1;
	right += start_index - 1;

	while (left <= right) {
		//left가 짝수 인덱스 일 때
		if (left % 2 == 1)
			sum += tree[left];

		//right가 홀수 인덱스 일 때
		if (right % 2 == 0) {
			sum += tree[right];
		}

		left = (left + 1) / 2;
		right = (right - 1) / 2;
	}

	return sum;
}

void sum() {
	int node = start_index;
	while (node > 1) {
		for (int i = node; i < node * 2; i++) {
			tree[i / 2] += tree[i];
		}
		node /= 2;
	}
}
int main(void) {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	start_index = 1;

	while (start_index < N) {
		start_index *= 2;
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &tree[start_index + i]);
	}

	sum();

	while (M != 0 || K != 0) {
		int menu;
		scanf("%d", &menu);

		if (menu == 1) {
			int index, num;
			scanf("%d %d", &index, &num);

			first_cmd(index, num);
			M--;
		}

		else if (menu == 2) {
			int left, right;
			scanf("%d %d", &left, &right);
			printf("%lld\n", second_cmd(left, right));
			K--;
		}
	}
}