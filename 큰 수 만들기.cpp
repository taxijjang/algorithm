#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> st;

string solution(string number, int k) {
	string answer = "";
	int n_size = number.size();
	int cnt = k;
	int plus = 0;
	for (int i = 0; i < n_size;) {
		if (st.empty()) {
			st.push(number[i++]);
			plus++;
		}
		if ((st.top() < number[i]) && cnt !=0) {
			st.pop();
			cnt--;
			plus--;
		}
		else  {
 			st.push(number[i++]);
			plus++;
		}
	}

	int st_size = st.size();

	for (int i = 0; i < st_size; i++) {
		if (st_size- i <= n_size - k) {
			answer = st.top() + answer;		
		}
		st.pop();
	}

	
	return answer;

}
int main(void) {
	string s;
	int N;
	cin >> s;
	scanf("%d", &N);

	printf("%s",solution(s, N).c_str());
}