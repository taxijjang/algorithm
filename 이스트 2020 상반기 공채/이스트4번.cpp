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
#include<cctype>
#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

//이름에 있는 하이픈을 지우기 위함
string calc(string &name) {
	string res = "";
	for (auto i = strtok(&name[0], "-"); i != NULL; i = strtok(NULL, "-")) {
		res+=i;
	}
	return res;
}

string emails(vector<string> &tokens, string &C) {
	//이메일 아이디의 중복을 확인 하기 위해 map 생성
	map<string, int> overlap;

	//모든 이메일
	string emails = "";

	for (auto token : tokens) {
		vector<string> name;

		//띄어 쓰기를 기준으로 first ,middle, last 분리
		for (auto i = strtok(&token[0], " "); i != NULL; i = strtok(NULL, " ")) {
			name.push_back(i);
		}
		
		//이름 first, last
		string first = calc(name[0]);
		string last = calc(name.back());

		//이메일 아이디
		string id = last + "_" + first;

		string email = "";

		//이메일 아이디의 중복 여부 확인
		if (overlap[id] == 0) {
			overlap[id] ++;
			email += "<" + last + "_" + first + "@" + C + ".com>;";
		}

		else {
			overlap[id]++;
			email += "<" + last + "_" + first + to_string(overlap[id]) + "@" + C + ".com>;";
		}
		
		//이메일을 모두 소문자로 변경
		transform(email.begin(), email.end(), email.begin(), ::tolower);

		email = token + " "+ email;
		emails += email;
	}

	string res = "";
	for (auto e : emails) {
		if (e == '\0')
			res = res + ' ';
		else
			res = res + e;
	}

	//마지막 ; 제거
	res.pop_back();
	return res;
}
string solution(string &S, string &C) {
	// write your code in C++14 (g++ 6.2.0)
	vector<string> tokens;

	//이름을 ;로 분리
	for (auto i = strtok(&S[0], ";"); i != NULL; i = strtok(NULL, ";")) {
		tokens.push_back(i);
	}

	return emails(tokens, C);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string S, C;
	S = "John Doe; Peter Benjamin Parker; Mary Jane Watson-Parker; John Elvis Doe; John Evan Doe; Jane Doe; Peter Brian Parker";
	//S = "Mary Jane Watson-Parker; John Elvis Doe;";
	C = "Example";
	cout << solution(S, C);
}