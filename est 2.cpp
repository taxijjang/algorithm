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

	//���� ����
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
	//��Ʈ��ŷ �Ͽ� �湮 üũ����
	visited[T->x] = false;
}
int solution(tree * T) {
	//���� ���� �����ϱ�
	if (T == NULL)
		return 0;
	dfs(T, 0);
	return m_len;
}