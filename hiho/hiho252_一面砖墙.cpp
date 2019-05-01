#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	int layerNum;
	cin >> layerNum;
	unordered_map<int, int> layerMap;
	// 1.遇到map初始化问题，我使用flag数组作为标记，避免了初始化为零这个步骤
	int brickCnt = 0;
	int curWidth = 0;
	int brickWidth = 0;
	bool* flag = new bool[100000000];
	fill(flag, flag + 100000000, 0);
	int max = 0;
	for (int i = 0; i < layerNum; i++) {
		cin >> brickCnt;
		curWidth = 0;
		for (int j = 0; j < brickCnt; j++) {
			cin >> brickWidth;
	// 考虑到围成一面墙，最右边的缝隙不算在内
			if (j == brickCnt - 1) {
				break;
			}
			curWidth += brickWidth;
			if (flag[curWidth] == 0) {
				flag[curWidth] = 1;
				layerMap[curWidth] = 1;
				max = std::max(max, layerMap[curWidth]);
			}
			else {
				layerMap[curWidth]++;
				max = std::max(max, layerMap[curWidth]);
			}
		}
	}
	delete[] flag;
	cout << layerNum - max << endl;
	//system("pause");
	return 0;
}
