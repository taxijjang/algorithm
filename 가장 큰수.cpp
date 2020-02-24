#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;
int n_size;
vector<string> res[10];

bool cmp(string a, string b) {
	return a + b < b + a ? true : false;
}
string solution(vector<int> numbers) {
	string answer = "";
	vector<string> v;

	for (auto num : numbers) {
		v.push_back(to_string(num));
	}

	sort(v.begin(), v.end(), cmp);

	while (!v.empty()) {
		answer += v.back();
		v.pop_back();
	}

	if (answer[0] == '0')
		return "0";

	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> numbers;
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		numbers.push_back(num);
	}

	cout << solution(numbers);

}