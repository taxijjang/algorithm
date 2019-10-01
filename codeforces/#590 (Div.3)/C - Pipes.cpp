4 - pipe
#include<iostream>
#include<string>
#define SIZE 10010
using namespace std;
 
string arr[2];
 
int main(void) {
	ios::sync_with_stdio(false);
 
	int T; cin >> T;
 
	for (int t = 0; t < T; t++) {
		int n; cin >> n;
		for (int i = 0; i < 2; i++) {
			cin >> arr[i];
		}
 
		bool res = true;
		int i = 0, j = 0;
		//왼쪽 false 위,아래 true
		bool _where;
		if (arr[i][j] == '1' || arr[i][j] == '2')
			_where = false;
		else
			_where = true;
 
		while (true) {
			//위,아래에서 왓을 대
			if (_where) { 
				//위에 있을때
				if (i == 0)
					i++;
	
				//아래에 있을때
				else 
					i--;
				if (arr[i][j] == '1' || arr[i][j] == '2') {
					res = false;
					break;
				}
 
				_where = !_where;
			}
 
			//왼쪽에서 왓을때
			else {
				j++;
				if (arr[i][j] != '1' && arr[i][j] != '2') {
					_where = !_where;
				}
			}
			if (i == 0 && j == n) {
				res = false;
				break;
			}
			if (i == 1 && j == n) {
				res = true;
				break;
			}
		}
 
		if (res)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}