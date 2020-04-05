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

#define SIZE 110
const int INF = 2000000000;

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

set<char> _set[SIZE];
int solution(string answer_sheet, vector<string> sheets) {
	vector<int> idx(sheets.size(), 0);
	idx[sheets.size() - 2] = 1;
	idx[sheets.size() - 1] = 1;

	int s_size = answer_sheet.size();

	int usim = 0;//의심
	int bujung_len = 0;//부정

	int max_len = 0;
	do {
		vector<string> cmp;
		for (int i = 0; i < idx.size(); i++) {
			if (idx[i] == 1)
				cmp.push_back(sheets[i]);
		}

		int len = 0,total_cnt = 0;
		for (int i = 0; i < s_size; i++) {
			//의심 문항
			if (answer_sheet[i] != cmp[0][i] || (answer_sheet[i] !=cmp[1][i])){
				if (cmp[0][i] == cmp[1][i]) {
					total_cnt++; len++;
					max_len = max(max_len, len);
				}
				else
					len = 0;
			}
			//아닐때
			else {
				len = 0;
			}
		}
		usim = max(usim, total_cnt);
		bujung_len = max(bujung_len, max_len);
	} while (next_permutation(idx.begin(), idx.end()));
	
	return (usim + (bujung_len *bujung_len));
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//string answer = "4132315142";
	//vector<string> sheets = { "3241523133","4121314445","3243523133","4433325251","2412313253" };

	string answer = "2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222";
	vector<string> sheets = { "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
		"1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
	"1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
	"1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
	"1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"};
	cout << solution(answer,sheets);
}