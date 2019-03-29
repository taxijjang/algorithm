#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	for (int t = 1; t <= 10; t++) {
		int dump;
		int arr[101];

		scanf("%d", &dump);

		for (int i = 0; i < 100; i++) {
			scanf("%d", &arr[i]);
		}

	
		int m_index, n_index;
		for (int i = 0; i <= dump; i++) {
			int m = 0, n = 101;
			for (int j = 0; j < 100; j++) {
				if (m < arr[j]) {
					m = arr[j];
					m_index = j;
				}

				if (n > arr[j]) {
					n = arr[j];
					n_index = j;
				}
			}

			if (i < dump) {
				arr[m_index]--;
				arr[n_index]++;
			}
			else if (i == dump) {
				printf("#%d %d\n", t, arr[m_index] - arr[n_index]);
			}
		}
	}
}