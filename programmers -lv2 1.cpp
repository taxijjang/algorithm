#include<iostream>
#include<vector>

using namespace std;
int answer = 0;

void dfs(vector<int> numbers, int h_index, int h_num ,int target) {
	if (h_num == target && h_index == numbers.size()) { answer++; return; }
	if (h_index == numbers.size()) return;
	for (int i = 0; i < 2; i++) {
		if(i == 0 )
			dfs(numbers, h_index + 1, numbers[h_index] + h_num, target);
		else
			dfs(numbers, h_index + 1, (numbers[h_index]*-1) + h_num, target);
	}
}
int solution(vector<int> numbers, int target) {
	for (int i = 0; i < 2; i++) {
		if (i == 0)
			dfs(numbers, 1, numbers[0], target);
		else
			dfs(numbers, 1, numbers[0] * -1, target);
	}
	return answer;
}
int main(void) {
	vector<int> numbers;
	int targer; scanf("%d", &targer);

	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);

	printf("%d",solution(numbers, targer));
}