#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#include<cmath>
#include<stack>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;


int molra = 0, NO = 1, OK = 2;
int check[SIZE];

vector<int> has_jaego;
vector<int> arr[SIZE];
string solution(int n, vector<vector<int>> delivery) {
	int d_size = delivery.size();

	for (int i = 0; i < d_size; i++) {
		vector<int> d = delivery[i];

		if (d[2] == 1) {
			has_jaego.push_back(d[0]);
			has_jaego.push_back(d[1]);
			check[d[0]] = OK; check[d[1]] = OK;
		}
		else {
			arr[d[0]].push_back(d[1]);
			arr[d[1]].push_back(d[0]);
		}
	}

	for (auto has : has_jaego) {
		for (auto next_sangpom : arr[has]) {
			if (check[next_sangpom] != 1) {
				check[next_sangpom] = NO;
			}
		}
	}

	string answer = "";

	for (int i = 1; i <= n; i++) {
		if (check[i] == molra)
			answer = answer + '?';
		else if (check[i] == NO)
			answer = answer + 'x';
		else if (check[i] == OK)
			answer = answer + 'o';
	}

	return answer;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n = 7;
	//vector<vector<int>> delivery = { {1,3,1},{3,5,0},{5,4,0},{2,5,0} };
	vector<vector<int>> delivery = { {5,6,0},{1,3,1},{1,5,0},{7,6,0},{3,7,1},{2,5,0} };
	cout << solution(n, delivery);

}