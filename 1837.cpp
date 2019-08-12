#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define SIZE 1000003

using namespace std;

bool era[SIZE] = { true, };
void eratos() {
	for (int i = 2; i <= SIZE; i++) {
		for (int j = 2; j *i <= SIZE; j++) {
			if (era[i*j] != true)
				era[i*j] = true;
		}
	}
}
int main(void) {
	eratos();
	string P; int K; cin >> P >> K;

	int P_size = P.size();
	bool toggle = false;
	int prime = 0;
	for (int i = 2; i < K; i++) {
		int res = 0;

		if (era[i])
			continue;

		for (int j = 0; j < P_size; j++) {
			res = ((res * 10 + P[j] - '0')) % i;
		}

		if (res == 0) {
			toggle = true;
			prime = i;
			break;
		}
	}

	if (!toggle) {
		cout << "GOOD\n";
	}
	else {
		cout << "BAD " << prime;
	}
	return 0;
}