#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef struct data {
	int cnt = 0;
	char c;
}Data;

bool cmp(Data a, Data b) {
	if (a.cnt < b.cnt)
		return true;
	return false;
}

int main(void) {
	string s; cin >> s;
	Data arr[26];
	for(auto it = s.begin() ; it != s.end(); it++) {
		int index;
		if (*it >= 'a') {
			arr[*it - 'a'].cnt++;
			index = *it - 'a';
		}
		else {
			arr[*it - 'A'].cnt++;
			index = *it - 'A';
		}

		arr[index].c = index + 'a';
	}

	sort(arr, arr + 26, cmp);
	if (arr[24].cnt == arr[25].cnt) printf("?\n");
	else printf("%c\n", arr[25].c-32);

	return 0;
}