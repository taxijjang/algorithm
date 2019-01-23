#include <iostream>
#include <deque>

using namespace std;

deque<int> arr;
int main(void) {
	int N;
	scanf("%d", &N);

	int num;
	for (int i = 1; i <= N; i++) {
		arr.push_back(i);
	}

	int front;
	while (arr.size() != 1) {
		arr.pop_front();
		arr.push_back(arr.front());
		arr.pop_front();
	}
	printf("%d", arr.front());
}