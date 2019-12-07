#include <string>
#include <vector>

#define SIZE 5
using namespace std;

//���� �迭
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

//�湮 üũ �迭
bool visited[SIZE][SIZE];

//���� �� �� ����
int cnt = 0;

void dfs(vector<vector<string>> board, int h_x, int h_y, int len, bool trick){
    cnt = cnt < len ? len : cnt; //ū ���� ����

    visited[h_x][h_y] = true;//�湮 üũ

    for(int i= 0; i <4 ; i++){ // �����¿� �湮
        int n_x = h_x + dx[i];
        int n_y =h_y + dy[i];

        if (n_x <0 || n_y <0 || n_x >=SIZE || n_y >=SIZE) //���� ���� ������ üũ
          continue;

        if(visited[n_x][n_y] == true)//�湮 �ߴ��� Ȯ��
            continue;

        if((board[h_x][h_y] >= board[n_x][n_y]) && trick == true) //trick �� �̿��� ���¿��� ���� ���� ������ üũ
            continue;

        if(board[h_x][h_y] < board[n_x][n_y]) //���� ���� Ŭ ��
            dfs(board,n_x,n_y, len+1, trick);

        if((board[h_x][h_y] > board[n_x][n_y]) && trick == false){ //���� ���� ������ trick �� �̿����� �ʾ��� ��
            trick = true;
            dfs(board,n_x,n_y, len+1, trick);
            trick = false;
        }

        visited[n_x][n_y] = false;
    }

    visited[h_x][h_y] =false;
}

//��Ʈ��ŷ�� �̿��Ͽ����ϴ�.
int solution(vector<vector<string>> board) {
    int answer = 0;

    for(int i =0 ; i <SIZE ; i++){
        for(int j =0 ; j <SIZE ; j++){
            dfs (board,i,j,1,false);
        }
    }

    answer = cnt;
    return answer;
}