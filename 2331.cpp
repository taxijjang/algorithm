#include <iostream>
#include <string>
#define MAX 300000
using namespace std;

int d[MAX];
int visited[MAX] = { 0, };

int main(void) {
	string a;
	int P,A;

	cin >> a >> P;

	A = stoi(a);
	int A_size = a.size();

	d[0] = 0;
	d[1] = A;
	visited[A] = 1;

	for(int index = 2;;index++){
		int sum = 0;
		for (int i = 0; i < A_size; i++) {
			int tmp = 1;
			for (int j = 1; j <= P; j++) {
				tmp *= a[i] -'0';
			}
			sum += tmp;
		}
		if (visited[sum] == 2) {
			break;
		}
		else {
			visited[sum] += 1;
		}
		d[index] = sum;
		a = to_string(d[index]);
		A_size = a.size();

	}

	int cnt = 0;
	for (int i = 0; i < MAX; i++) {
		if (visited[i] == 1) {
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}