#include<iostream>
#define MAX 110

using namespace std;

int up = -1;
int down = 1;

bool check[MAX][MAX];
int arr[MAX][MAX];

//���� ���¸� ã�� �Լ�
int deadlock(int NN) {
	bool judge = false; //���� ���¿� ��� ������ �Ǵ� �ϴ� ����
	int tmp = 0; //���� ��ġ ���� ���� �����ϴ� ����
	int cnt = 0; 

	int N = 1, S = 2;
	for (int i = 1; i <= NN; i++) {
		for (int j = 1; j <= NN; j++) {
			//judge�� false�� ���� ���� ���¸� ������ ����

			if (judge == false) {
				//���� ���¸� ������ ���� ���¿��� N���� ������ ������
				//���� ���¿� ��� ������ judge = true�� ��Ÿ��
				if (arr[j][i] != 0) {
					judge = true;
					tmp = N;
					cnt++; //���� ���¿� ���� ī��Ʈ�� ���� ������
				}
				else if(arr[j][i] == 0){}

			}

			//���� �������� ���� �� �϶�
			else if (judge == true) {
				if (arr[j][i] != 0) {
					//�̶� NSNS�� ���� 2���� ���� ���°� �߻� �� �� �����Ƿ�
					//���������� ���� ������ tmp�� ���� ������ ���� ��
					//�̶� N�ؿ��� S������ ������ tmp�� S�� ���� ����
					//tmp�� S���̰� ���簡 N�� �϶����� ������ 2�� �߻��ϹǷ� 
					//cnt�� ���� �ϰ� tmp�� N������ ����
					if (tmp == N && arr[j][i] == S) {
						tmp = S;
					}
					if (tmp == S && arr[j][i] == N) {
						tmp = N;
						cnt++;
					}
					
				}
				else if (arr[j][i] == 0) {
					judge = false;
				}
			}
		}
		judge = false;
		tmp = 0;
	}
	return cnt;
}

int main(void) {
	for (int t = 1; t <= 10; t++) {
		int N;
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		//cnt�� ���̺��� Ž�� �ϸ鼭 ��� �ڼ�ü����
		//������������ �ƴ����� Ȯ�� �ϴ� ���� �ϳ��� �����̸� 0�� �ƴϰ� ��
		int cnt;

		//���ѹݺ� ���� �����̸� ���� ����
		do {
			cnt = 0;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (arr[i][j] == 1) {
						
						//N���� S���� ���� ���ԵǹǷ� �Ʒ� ������ �����ԵǸ� ������
						if (i+down == N+1) {
							arr[i][j] = 0;
						}

						//check�迭�� �̹� �ѹ� ������ �ڼ��� �� �ٽ� �������� �ʰ� �ϴ� �迭
						//N���� ������ ���Ƿ� �ؿ� ��������� S���� �ִ��� �Ǵ� �� �ൿ�� ����
						else if (arr[i + down][j] == 0) {
							if (check[i][j] != true) {
								arr[i][j] = 0;
								arr[i + down][j] = 1;
								check[i + down][j] = true;
								cnt++;
							}
						}
					}

					else if (arr[i][j] == 2) {
						
						//S���� N���� ���� ���ԵǹǷ� �� ������ �����ԵǸ� ������
						if (i+up == 0) {
							arr[i][j] = 0;
						}

						//S���� ���� ���Ƿ� ���� ��������� N���� �ִ��� �Ǵ� �� �ൿ�� ����
						else if (arr[i + up][j] == 0) {
							if (check[i][j] != true) {
								arr[i][j] = 0;
								arr[i + up][j] = 2;
								cnt++;
								check[i + up][j] = true;
							}
						}
					}
				}
			}
			fill(&check[0][0], &check[MAX][MAX], false);

		} while (cnt != 0);

		printf("#%d %d\n",t,deadlock(N));

		printf("�ȳ�");
		getchar();
	}
}