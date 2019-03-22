#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> p;
int arr[50001] = { 0 };
int solution(vector<int> people, int limit) {
	int answer = 0;

	sort(people.begin(),people.end());

	int start=0, end=people.size()-1;

	while (start < end) {
		if (people[start] + people[end] <= limit) {
			answer++;
			start++, end--;
		}
		else if (people[start] + people[end] > limit) {
			answer++;
			end--;
		}
	}

	return answer;
}

int main(void) {
	p.push_back(70);
	p.push_back(50);
	p.push_back(80);
	p.push_back(60);

	printf("%d", solution(p, 100));

	
}