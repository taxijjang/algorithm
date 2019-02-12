#include <iostream>
#include <string>

using namespace std;

int arr[40000];
int l = 20000, r = 20000;
void push_front(int num) {
	arr[--l] = num;
}
void push_back(int num) {
	arr[r++] = num;
}
void pop_front() {
	if (l >= r) {
		printf("-1\n");
	}
	else {
		printf("%d\n", arr[l++]);
	}
}
void pop_back() {
	if (r <= l) {
		printf("-1\n");
	}
	else {
		printf("%d\n", arr[--r]);
	}
}
void size() {
	printf("%d\n", r - l);
}
void empty() {
	if (r - l == 0) {
		printf("%d\n", 1);
	}
	else {
		printf("%d\n", 0);
	}
}
void front() {
	if (r - l == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", arr[l]);
	}
}
void back() {
	if (r - l == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", arr[r - 1]);
	}
}
int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		if (s == "push_back") {
			int num;
			scanf("%d", &num);
			push_back(num);
		}
		else if (s == "push_front") {
			int num;
			scanf("%d", &num);
			push_front(num);
		}
		else if (s == "pop_back") {
			printf("\n");
			pop_back();
		}
		else if (s == "pop_front") {
			printf("\n");
			pop_front();
		}
		else if (s == "size") {
			printf("\n");
			size();
		}
		else if (s == "empty") {
			printf("\n");
			empty();
		}
		else if (s == "front") {
			printf("\n");
			front();
		}
		else if (s == "back") {
			printf("\n");
			back();
		}
	}
}