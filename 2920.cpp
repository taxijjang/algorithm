#include<iostream>

using namespace std;

int main(void) {
	int arr[8];
	for (int i = 0; i < 8; i++)
		scanf("%d", &arr[i]);

	int judge = arr[0] - arr[1];

	for (int i = 1; i < 8 - 1; i++) {
		int n = arr[i] - arr[i + 1];
		if (n == judge) continue;
		else {
			printf("mixed\n");
			return 0;
		}
	}

	if (judge == 1) printf("descending\n");
	else printf("ascending\n");
	return 0;
}