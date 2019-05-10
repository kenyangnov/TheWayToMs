#include <iostream>
#include <sstream>
using namespace std;

// 每个单元中的四个子区域
struct Ceil {
	int top;
	int right;
	int down;
	int left;
};

Ceil* CeilPattern(char c){
	Ceil pattern;
	switch (c)
	{	
	case '\\':
		pattern = { 2, 1, 4, 3 };
		break;
	case '/':
		pattern = { 4, 3, 2, 1 };
		break;
	case ' ':
		pattern = { 0, 0, 0, 0 };
		break;
	default:
		break;
	}
	return &pattern;
}

int main() {
	int m, n;
	cin >> m >> n;
	
	//清空缓冲区中的换行符
	cin.clear();
	cin.ignore();

	string *s = new string[m];
	for (int i = 0; i < m; i++) {
		getline(cin, s[i]);
	}

	Ceil **line = new Ceil*[m];
	for (int i = 0; i < n; i++) {
		line[i] = new Ceil[n];
		for (int j = 0; j < n; j++) {
			line[i][j] = *CeilPattern(s[i][j]);
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << line[i][j].top << line[i][j].right << line[i][j].down << line[i][j].left<<endl;

		}
	}

	for (int i = 0; i < n; i++) {
		delete[] line[i];
	}
	delete[] line;
	cin.get();
}