#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include "BD.h"

using namespace std;
void readFromFile(vector <vector<string>>* vec, string Filename) {

	ifstream file(Filename);


	while (!file.eof())
	{
		vector <string> temp; 

		string str;
		getline(file, str, '\n');

		bool flag = true;
		while (flag)
		{
			int comaNum = str.find(',');
			if (comaNum == -1)
			{
				temp.push_back(str);
				flag = false;
			}
			else
			{
				string substring = str.substr(0, comaNum);
				str = str.substr(comaNum + 1, str.size() - 1);
				temp.push_back(substring);
			}
		}
		vec->push_back(temp);
	}
}


void checkRequest(vector<string>* request) {
	handleRequest(request);
}
void handleRequest(vector<string>* request) {

}
void getRequest() {
	string input = "";
	vector<string> request;
	while (input != "\\q" && input != "\\quit") {
		cin >> input;
		request.push_back(input);
	}
	checkRequest(&request);
}
int main()
{
	getRequest();
	
	//	vector <vector<string>> vec;
	//	readFromFile(&vec, "data.csv");
	
	return 0;
}