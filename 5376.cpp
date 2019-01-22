#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;

unsigned long long int Eucl(unsigned long long int a, unsigned long long int b) {
	//a가 분모 b가 분자
	if (b == 0)return a;
	Eucl(b, a % b);
}

void fraction(string s) {
	int size = s.size();

	char num[30];
	strcpy(num, s.c_str());

	double s_num = stod(s);

	unsigned long long int n1 = 0;
	unsigned long long int x1 = 0;

	bool roation = false;

	int exp = 1;

	int open;
	for (int i = 2; i < size; i++) {
		if (num[i] == '(' || num[i] == ')') {
			if (num[i] == '(') open = i - 2;
			roation = true;
			continue;
		}
		n1 = n1*10 + (num[i] - '0') ;
		x1 = pow(10, exp);
		exp++;

	}

	
	if (roation == false) {
		int a = (int)pow(10, size - 2);
		int b = (int)pow(10, size - 2)*s_num;
		int g = Eucl(a, b);
		printf("%d/%d\n", b/g,a/g);
	}
	else {
		unsigned long long int bun = 0;
		for (int i = 0; i < open; i++) {
			bun = bun * 10 + (num[i + 2] - '0');
		}
		unsigned long long int gcd = Eucl(x1 - (int)pow(10,open), n1 - bun);
		unsigned long long up = (n1 - bun) / gcd;
		unsigned long long down = (x1 - (int)pow(10, open)) / gcd;
		printf("%llu/%llu\n", up,down);
	}

}
int main(void) {
	int N;

	scanf("%d", &N);

	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		fraction(s);
	}

	return 0;
}