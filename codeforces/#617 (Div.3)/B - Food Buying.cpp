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
 
int zari(int num) {
	int cnt = 1;
 
	while (num > 0) {
		cnt *= 10;
		num /= 10;
	}
	return cnt/10;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T; cin >> T;
 
	while (T--) {
		int num; cin >> num;
 
		int z = zari(num);
 
		int sum = 0;
 
		while (z > 0) {
			z = zari(num);
			int cashback = ((num / z)*z)/10;
			sum += (num / z)*z;
			num = (num% z)+cashback;
			z /= 10;
		}
		cout << sum<<"\n";
	}
}