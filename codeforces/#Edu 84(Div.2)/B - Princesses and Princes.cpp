#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

int main(void) {
	int T; cin >> T;

	while (T--) {
		int N; cin >> N;

		set<int> _set;
		for (int i = 1; i <= N; i++)
			_set.insert(i);
		bool check = false;
		int queen = 0;
		
		for (int i = 1; i <= N; i++) {
			int M; cin >> M;
			
			bool isSelect = false;
			int cnt = 0;
			for (int m = 0; m < M; m++) {
				int king; cin >> king;

				if (isSelect)
					continue;
				if (_set.find(king) != _set.end()) {
					_set.erase(king);
					isSelect = true;
				}
				else if (_set.find(king) == _set.end()) {
					cnt++;
				}
			}

			if (cnt == M)
				queen = i;
		}

		if (_set.size() == 0) {
			cout << "OPTIMAL\n";
		}
		else{
			cout << "IMPROVE\n";
			cout << queen << " " << *_set.begin() << "\n";
		}
	}
}