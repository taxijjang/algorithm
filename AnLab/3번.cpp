#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include<algorithm>

using namespace std;

//���ο� ������ ���� ū ���� ã�� ���� ���� ���� �Ͽ����ϴ�.
int solution(int n, int m, vector<int> x_axis, vector<int> y_axis) {
    int answer = 0;

    //�簢���� ���ʾƷ�, �������� ������ �߰�
    x_axis.push_back(0);x_axis.push_back(n);
    y_axis.push_back(0);y_axis.push_back(m);

    //����
    sort(x_axis.begin() ,x_axis.end());
    sort(y_axis.begin(), y_axis.end());


    int garo = 0;
    int sero = 0;

    int x_size = x_axis.size();
    int y_size = y_axis.size();

    //������ ���� ū �� ����
    for(int i = 1 ; i <x_size; i++){
        garo = garo < x_axis[i] - x_axis[i-1] ? x_axis[i] - x_axis[i-1] : garo;
    }

    //������ ���� ū �� ����
    for(int i =1 ; i <y_size ; i++){
        sero = sero<y_axis[i] - y_axis[i- 1] ? y_axis[i] - y_axis[i-1] : sero;
    }

    //���� ���� ���� ū �� ���Ͽ� ���� ����
    answer = garo * sero;
    return answer;
