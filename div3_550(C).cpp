#include<iostream>
#include<vector>
using namespace std;

vector<int> in;
vector<int> de;

int arr[200005] = { 0 };
int main(void) {
	int N;
	scanf("%d", &N);
	bool judge = true;
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		arr[num]++;

		if (arr[num] > 2) { printf("NO"); judge = false; }
	}

	if (judge) {
		for (int i = 0; i <= 200001; i++) {
			if (arr[i] > 1) {
				in.push_back(i);
				arr[i]--;
			}
		}

		for (int i = 200001; i >= 0; i--) {
			if (arr[i] > 0) {
				de.push_back(i);
			}
		}
		
		printf("YES\n");
		printf("%d\n", in.size());
		for (auto it = in.begin(); it != in.end(); it++) {
			printf("%d ", *it);
		}
		printf("\n");

		printf("%d\n", de.size());
		for (auto it = de.begin(); it != de.end(); it++) {
			printf("%d ", *it);
		}
		printf("\n");
	}
	else {
		printf("NO");
	}
}