#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

std::string getVectorFunction() {
	std::string input;
	cin >> input;
	return input;
}

void printArray(char array[][4]) {
	cout << " x1  x2  f1  f2" << std::endl;
	for (int i = 0; i < 4; i++) {
		cout << ' ';
		for (int j = 0; j < 4; j++)
			cout << array[i][j] << " | ";
		cout << endl;
	}
}

void fillArray(char array[][4],const std::string &functionStringFirst, const std::string &functionStringSecond) {
	for (int i = 0; i < 4; i++) {
		if (i < 2) array[i][0] = '0';
		else array[i][0] = '1';
	}
	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0) array[i][1] = '0';
		else array[i][1] = '1';
	}
	for (int i = 0; i < 4; i++) 
		array[i][2] = functionStringFirst[i];
	for (int i = 0; i < 4; i++) 
		array[i][3] = functionStringSecond[i];
}

int findFunction(int a, int b, char array[][4], int func[]) {
	if (a == array[0][0] - '0' && b == array[0][1] - '0') return func[0];
	else if (a == array[1][0] - '0' && b == array[1][1] - '0') return func[1];
	else if (a == array[2][0] - '0' && b == array[2][1] - '0') return func[2];
	else return func[3];
}
bool isFourSetsFunction(const std::string &string) {
	int i = sizeof(string) / sizeof(string[0]);
	return string.length() == 4 ? 1 : 0;
}

bool isBinary(const std::string &string) {
	for (char c : string) 
		if (c != '0' && c != '1') return 0;
	return 1;
}

void convertArrayToInt(const std::string &stringArray, int intArray[], int size) {
	for (int i = 0; i < size; i++)
		intArray[i] = static_cast<int>(stringArray[i] - '0');	
}
int main() {
	std::string functionStringFirst;
	std::string functionStringSecond;
	do {
		cout << "Write a vector of first function: " << endl;
		functionStringFirst = getVectorFunction();
	} while (!(isFourSetsFunction(functionStringFirst) && isBinary(functionStringFirst)));
	do {
		cout << "Write a vector of second function: " << endl;
		functionStringSecond = getVectorFunction();
	} while (!(isFourSetsFunction(functionStringSecond) && isBinary(functionStringSecond)));
	
	char array[4][4]{};
	fillArray(array, functionStringFirst, functionStringSecond);
	cout << "\tTruth table" << endl;
	printArray(array);
	
	int functionFirst[4];
	int functionSecond[4];
	convertArrayToInt(functionStringFirst, functionFirst, 4);
	convertArrayToInt(functionStringSecond, functionSecond, 4);
	
	cout << "vector of function: ";
	for (int x2 = 0; x2 <= 1; x2++)
		for (int x3 = 0; x3 <= 1; x3++)
			for (int x4 = 0; x4 <= 1; x4++) 
				cout << findFunction(findFunction(x4, x2, array, functionSecond), x3, array, functionFirst);
	return 0;
}