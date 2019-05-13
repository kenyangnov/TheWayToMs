#include <iostream>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

// 每个单元中的四个子区域
struct Ceil {
	int top;
	int right;
	int down;
	int left;
};

//将符号转换为区域编号
void CeilPattern(char c, Ceil *ceil){
	Ceil pattern = { 0, 0, 0, 0};
	switch (c)
	{
	case '\\':
		pattern = { 1, 1, 2, 2 };
		break;
	case '/':
		pattern = { 1, 2, 2, 1 };
		break;
	case ' ':
		pattern = { 1, 1, 1, 1 };
		break;
	default:
		break;
	}
	*ceil = pattern;
}

void DisplayCeil(Ceil* ceil) {
	cout << ceil->top << ceil->right << ceil->down << ceil->left << endl;
}


int main() {
	int m, n;
	cin >> m >> n;
	
	//清空缓冲区中的换行符
	cin.clear();
	cin.ignore();

	//读入符号
	string *s = new string[m];
	for (int i = 0; i < m; i++) {
		getline(cin, s[i]);
	}

	//初始化ceils
	Ceil **line = new Ceil*[m];
	for (int i = 0; i < m; i++) {
		line[i] = new Ceil[n];
	}
	
	//给ceils单元赋值
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			CeilPattern(s[i][j], &line[i][j]);
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			DisplayCeil(&line[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		delete[] line[i];
	}
	delete[] line;

	cin.get();
	return 0;
}