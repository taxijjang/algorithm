#include<iostream>
#include<string>
#include<deque>

using namespace std;

deque<int> dq;
int main(void) {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		deque<int> q;
		dq.swap(q);
		string s; cin >> s;

		int size; scanf("%d", &size);

		string arr; cin >> arr;
		int arr_size = arr.size();
		int temp = 0;
		int jari = 10;
		bool com = true;
		for (int i = 0; i < arr_size; i++) {
			if (size == 0) { break;}
			if (arr[i] == '[')
				continue;
			else if (arr[i] >= '0' && arr[i] <= '9') {
				int num = arr[i] - '0';
				temp = temp * jari + num;
			}
			else if (arr[i] == ',') {
				com = false;
				dq.push_back(temp);
				temp = 0;
				jari = 10;
			}
			else if (arr[i] == ']') {
					dq.push_back(temp);
					continue;
			}
		}

 		bool judge = false;
		//false = pop.front;
		//true = pop.back;
		bool con = true;
		int s_size = s.size();
		int cnt = 0;
		for (int i = 0; i < s_size; i++) {
			if (s[i] == 'R') {
				judge = !judge;
			}
			else if (s[i] == 'D') {
				if (dq.empty()) {
					cout << "error" << "\n";
					con = !con;
					break;
				}
				
				if (judge) {
					dq.pop_back();
				}
				else {
					dq.pop_front();
				}
			}
		}
		
		if (con) {
			int dq_size = dq.size();
			if (dq_size == 0)
				printf("[]\n");
			else {
				printf("[");
				for (int i = 0; i < dq_size - 1; i++) {
					int num;
					if (judge) {
						num = dq.back();
						dq.pop_back();
					}
					else {
						num = dq.front();
						dq.pop_front();
					}
					printf("%d", num); printf(",");
				}

				printf("%d]\n", dq.front());
			}
		}
	}
}