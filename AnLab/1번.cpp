#include <vector>
#include <set>
#define SIZE 6
using namespace std;

//당첨번호과 일치하는 번호를 지워가며 set의 크기를 이용하여 답을 도출 하였습니다.

int solution(vector<int> winnum, int bonus, vector<int> usernum) {
    int answer = 0;

    //winnum -> set
    set<int> _set(winnum.begin(), winnum.end());

    //bonus 번호 적중 결과
    bool toggle = false;
    //당첨번호에 나의 번호가 있으면 set에서 제거
    for(int i =0 ; i <SIZE;i++){
        if(_set.find(usernum[i])!= _set.end()){
            _set.erase(usernum[i]);
        }

        //bounus 적중 시
        else if(bonus == usernum[i]){
            toggle = true;
        }
    }

    answer = _set.size();

    //1등일때
    if(answer == 0)
        answer ++;

    //5개가 당첨 되었을때
    else if(answer == 1){
        answer++;
        //bonus번호가 적중 하였을때 answer 증가
        if(!toggle)
            answer++;

    }
    //3등 이하일때
    else{
        answer+= 2;
    }

    //answer의 값이 5가 넘어가면 당첨이 되지 않았음
    return answer >5 ? -1 : answer;
}