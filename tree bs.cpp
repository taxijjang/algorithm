#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 110

using namespace std;

typedef long long int ll;

void printPostOrder(vector<int> preorder, vector<int> inorder) {
	// 트리에 포함된 노드의 수
	int N = preorder.size();

	// 텅 빈 트리는 return
	if (preorder.empty())
		return;

	//루트노드
	int root = preorder[0];

	//왼쪽 노드의 크기는 중위 순회에서 찾을 수 있따
	int left_size = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	int right_size = N - left_size - 1;

	printPostOrder(vector<int>(preorder.begin() + 1, preorder.begin() + left_size + 1), vector<int>(inorder.begin(), inorder.begin() + left_size));
	printPostOrder(vector<int>(preorder.begin() + left_size + 1, preorder.begin() + N), vector<int>(inorder.begin() + left_size + 1, inorder.begin() + N));

	cout << root << " ";

}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;  cin >> T;
	for (int t = 0; t < T; t++) {
		int N; cin >> N;
		vector<int> preorder;
		vector<int> inorder;

		for (int i = 0; i < N; i++) {
			int node; cin >> node;
			preorder.push_back(node);
		}
		for (int i = 0; i < N; i++) {
			int node; cin >> node;
			inorder.push_back(node);
		}

		printPostOrder(preorder, inorder);
		cout << "\n";
	}

}