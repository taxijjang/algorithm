#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include<algorithm>

using namespace std;

//가로와 세로의 가장 큰 값을 찾아 내어 값을 도출 하였습니다.
int solution(int n, int m, vector<int> x_axis, vector<int> y_axis) {
    int answer = 0;

    //사각형의 왼쪽아래, 오른쪽위 꼭지점 추가
    x_axis.push_back(0);x_axis.push_back(n);
    y_axis.push_back(0);y_axis.push_back(m);

    //정렬
    sort(x_axis.begin() ,x_axis.end());
    sort(y_axis.begin(), y_axis.end());


    int garo = 0;
    int sero = 0;

    int x_size = x_axis.size();
    int y_size = y_axis.size();

    //가로의 가장 큰 값 추출
    for(int i = 1 ; i <x_size; i++){
        garo = garo < x_axis[i] - x_axis[i-1] ? x_axis[i] - x_axis[i-1] : garo;
    }

    //세로의 가장 큰 값 추출
    for(int i =1 ; i <y_size ; i++){
        sero = sero<y_axis[i] - y_axis[i- 1] ? y_axis[i] - y_axis[i-1] : sero;
    }

    //가로 세로 가장 큰 값 곱하여 넓이 도출
    answer = garo * sero;
    return answer;
