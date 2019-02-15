#include <iostream>
#include <string>

using namespace std;
char arr[10000002] = { 0,0 };
int main(void) {
	scanf("%s", arr);

	int sum = 0;

	int size = strlen(arr);

	int i=0;
	if (size % 3 > 0) {
		if (size % 3 == 1) {
			printf("%d", arr[i] - '0');
			i++;
		}
		else {
			printf("%d", (arr[i] - '0') * 2 + (arr[i+1] - '0'));
			i += 2;
		}
	}
	for (; i < size ; i+=3) {
		printf("%d", ((arr[i]-'0') * 4 + (arr[i + 1]-'0') * 2 + (arr[i + 2]-'0') * 1));
	}
}