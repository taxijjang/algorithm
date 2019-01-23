#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;

	do {
		getline(cin, s);
		if (s == "END") break;
		
		int size = s.size();
		for (int i = s.size() - 1; i >= 0; i--) {
			printf("%c", s[i]);
		}
		printf("\n");
	} while (1);
}