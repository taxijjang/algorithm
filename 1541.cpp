#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> num;
vector<char> sign;

int main(void) {
	string s;
	cin >> s;

	int size = s.size();
	
	int jari = 1;
	string n = "";
	for (int i = 0; i <= size; i++) {
		
		if (s[i] != '+' && s[i] != '-') {
			n += s[i];
		}
		else {
			num.push_back(stoi(n));
			sign.push_back(s[i]);
			n = "";
		}
	}
	
	num.push_back(stoi(n));


	int sum = 0;
	sum += num[0];

	int num_size = num.size();

	for (int i = 0; i < num_size-1; i++) {
		if (sign[i] == '-' ) {
			int tmp = 0;
			while (sign[i] != '-' || i != num_size - 1) {
				tmp += num[i + 1];
				if (i + 1 >= num_size - 1)
					break;
				i++;
			}
			sum -= tmp;
			continue;
		}
		else {
			sum += num[i + 1];
		}
	}

	printf("%d", sum);
}