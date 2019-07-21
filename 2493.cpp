#include<iostream>
#include<stack>

using namespace std;
typedef struct Data {
	int height;
	int index;
}Data;
stack<Data> st;
int arr[500100];
int main(void) {
	int N; scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	int res;
	for (int i = 1; i <= N; i++) {
		while (1) {
			if (st.empty()) {
				res = 0;
				st.push({ arr[i],i });
				break;
			}

			Data top = st.top();
			if (top.height < arr[i]) {
				st.pop();
			}
			else if (top.height > arr[i]) {
				res = top.index;
				st.push({ arr[i], i });
				break;
			}
		}
		printf("%d ", res);
	}
}