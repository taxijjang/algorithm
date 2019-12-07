#include <vector>
#include <set>
#define SIZE 6
using namespace std;

//��÷��ȣ�� ��ġ�ϴ� ��ȣ�� �������� set�� ũ�⸦ �̿��Ͽ� ���� ���� �Ͽ����ϴ�.

int solution(vector<int> winnum, int bonus, vector<int> usernum) {
    int answer = 0;

    //winnum -> set
    set<int> _set(winnum.begin(), winnum.end());

    //bonus ��ȣ ���� ���
    bool toggle = false;
    //��÷��ȣ�� ���� ��ȣ�� ������ set���� ����
    for(int i =0 ; i <SIZE;i++){
        if(_set.find(usernum[i])!= _set.end()){
            _set.erase(usernum[i]);
        }

        //bounus ���� ��
        else if(bonus == usernum[i]){
            toggle = true;
        }
    }

    answer = _set.size();

    //1���϶�
    if(answer == 0)
        answer ++;

    //5���� ��÷ �Ǿ�����
    else if(answer == 1){
        answer++;
        //bonus��ȣ�� ���� �Ͽ����� answer ����
        if(!toggle)
            answer++;

    }
    //3�� �����϶�
    else{
        answer+= 2;
    }

    //answer�� ���� 5�� �Ѿ�� ��÷�� ���� �ʾ���
    return answer >5 ? -1 : answer;
}