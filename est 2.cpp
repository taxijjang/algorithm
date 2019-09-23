#include<iostream>
#define SIZE 50010
using namespace std;

int m_len = 1;
bool visited[SIZE];
void dfs(tree * T, int len) {
	if (visited[T->x] == true) {
		m_len = m_len < len ? len : m_len;
		return;
	}

	//길이 증가
	len++;
	visited[T->x] = true;
	if (T->l == NULL || T->r == NULL) {
		m_len = m_len < len ? len : m_len;
	}
	if (T->l != NULL) {
		dfs(T->l, len);
	}
	if (T->r != NULL) {
		dfs(T->r, len);
	}
	//백트래킹 하여 방문 체크해제
	visited[T->x] = false;
}
int solution(tree * T) {
	//없을 수도 있으니까
	if (T == NULL)
		return 0;
	dfs(T, 0);
	return m_len;
}