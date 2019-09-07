#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int solution(vector<int>& X, vector<int>& Y) {
	int size = X.size();
	map<pii, ll> m;
	int res = 0;

	for (int i = 0; i < size; i++) {

		int g = gcd(X[i], Y[i]);
		//가분수 제외
		if (X[i] > Y[i]) continue;
		X[i] /= g;
		Y[i] /= g;

		//더해서 1이 되는 수를 찾기
		int diff = Y[i] - X[i];
		if (m.find({ diff, Y[i] }) != m.end()) {
			res += m[{diff, Y[i]}];
		}

		if (m.find({ X[i], Y[i] }) == m.end()) {
			m.insert({ { X[i], Y[i] }, 1 });
		}
		else {
			m[{X[i], Y[i]}]++;
		}
	}

	return res;
}