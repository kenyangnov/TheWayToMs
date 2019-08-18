#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define eps 1e-8

//穷举法:O(n^3)
struct Point
{
	double x, y;
	Point() { x = 0; y = 0; }
	Point(double tx, double ty) { x = tx; y = ty; }
};

int n;
double r;
Point p[2001], center[2];

double Dist(Point a, Point b) {
	return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

void GetCircleCenter(Point p1, Point p2) {
	//我初步检验这里只需要对p1、p2相对关系取其中一种分析即可，其他的位置关系必满足这种情况下的结果（可能是因为旋转对称性？）
	Point mid = Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
	double angle = atan2(p1.x - p2.x, p2.y - p1.y);
	double d = sqrt(r * r - Dist(p1, mid) * Dist(p1, mid));
	//两点连线两侧各有一个圆心
	//对于圆心坐标来说，返回结构体数组在程序设计中的意义不大，不如设置全局变量，然后对其进行修改
	center[0] = { mid.x + d * cos(angle), mid.y + d * sin(angle) };
	center[1] = { mid.x - d * cos(angle), mid.y - d * sin(angle) };
}
int main() {
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (Dist(p[i], p[j]) > r*2) continue; //两点间距大于直径
			GetCircleCenter(p[i], p[j]);
			int cnt0 = 0;
			for (int k = 0; k < n; k++) {
				//if (Dist(center[0], p[k]) <= r) {
				if (Dist(center[0], p[k]) < r + eps) {
					cnt0++;
				}
			}
			int cnt1 = 0;
			for (int k = 0; k < n; k++) {
				//if (Dist(center[1], p[k]) <= r) {
				if (Dist(center[1], p[k]) < r + eps) {
					cnt1++;
				}
			}
			ans=max(ans,max(cnt0,cnt1));
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}

/*
//POJ_1981(穷举法:O(n^3))
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define eps 1e-8

struct Point
{
	double x, y;
	Point() { x = 0; y = 0; }
	Point(double tx, double ty) { x = tx; y = ty; }
};

int n;
Point p[300];

double Dist(Point a, Point b) {
	return sqrt((a.x - b.x)*(a.x-b.x) + (a.y - b.y)*(a.y-b.y));
};

Point GetCircleCenter(Point p1, Point p2) {
	Point mid = Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
	double angle = atan2(p1.x - p2.x, p2.y - p1.y);
	double d = sqrt(1 - Dist(p1, mid) * Dist(p1, mid));
	return Point(mid.x + d * cos(angle), mid.y + d * sin(angle));
};

int main() {
	cin >> n;
	while (n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> p[i].x >> p[i].y;
		}
		int ans = 1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (Dist(p[i], p[j]) > 2.0) continue;
				Point central = GetCircleCenter(p[i], p[j]);
				int cnt = 0;
				for (int k = 0; k < n; k++) {
					if (Dist(central, p[k]) < 1.0 + eps) {
						cnt++;
					}
				}
				ans = max(ans, cnt);
			}
		}
		cout << ans << endl;
		cin >> n;
	}
	return 0;
}
*/