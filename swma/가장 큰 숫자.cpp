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


int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   int N; cin >> N;

   int one = N / 2;
   int seven = N % 2;

   string s = "";

   s += seven == 1 ? "7" : s;

   if (N == 3)
      cout << "7";
   else {
      for (int i = 0; i < one; i++) {
         s += "1";
      }
      cout << s;
   }
}