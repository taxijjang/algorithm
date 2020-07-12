#include <iostream>
#include <string>
#include<map>
#include<sstream>
#include<vector>

using namespace std;

int main(int argc, char *argv[]) {
	// ---
	// This is a sample code to use stdin and stdout.
	// Edit and remove this code as you like.

	string line;
	map<string, string> judge;

	while (!cin.eof()) {
		vector<string> v;

		string color, action, command;
		getline(cin, line);
		stringstream ss(line);

		judge["R"] = "D";
		judge["W"] = "D";

		bool flag = true;
		while (getline(ss, line, ' ')) {
			color = line[0];
			action = line[1];
			
			if (judge[color] == action) {
				printf("Alice\n");
				flag = false;
				break;
			}
			else {
				judge[color] = action;
			}
		}

		if (flag == true) {
			printf("Simon\n");
			cout << judge["R"] << judge["W"];
		}
	}
	return 0;
}