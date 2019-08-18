#include <iostream>
#include <algorithm>
using namespace std;

//https://hihocoder.com/discuss/question/5834
//复杂度：O(N*logN)
//一个点与据此点2R以内的点画圆，相交的一段弧，则包含这两个点的圆的圆心在这段弧内
//判断其他点在该圆上的弧区间并排序（nlogn）然后便利所有点
//使用极角表示圆弧：https://www.cnblogs.com/Patt/p/6381965.html
struct Point
{
	double x, y;
	Point() { x = 0; y = 0; }
	Point(double tx, double ty) { x = tx; y = ty; }
}p[2001];

struct Node {
	double angle; //圆上的点相对于圆心的极角
	bool flag; //标志圆弧区间的起点与终点
}arc[4000000 * 2 + 1];

bool Compare(const Node& a, const Node& b)
{
	return a.angle < b.angle;
}

double Dist(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


int n;
double r;

int main() {
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {	//对于每个圆
		int cnt = 0;
		for (int j = 0; j < n; j++) {	//注意这里j仍然从0开始遍历
			if (j == i || Dist(p[i], p[j]) > 2 * r) continue;
			//注：p[i]、p[j]为两圆圆心，两圆半径相等
			double angle = atan2(p[i].y - p[j].y, p[i].x - p[j].x);	//圆弧中点的极角
			double phi = acos((Dist(p[i], p[j])/2) / r);	//圆弧的圆心角的一半
			arc[cnt].angle = angle - phi; arc[cnt++].flag = true;
			arc[cnt].angle = angle + phi; arc[cnt++].flag = false;
		}
		//给定N个区间，找被覆盖次数最多的点：可以把区间端点排序之后扫描解决
		sort(arc, arc + cnt, Compare);//对极角排序
		int temp = 1;
		for (int i = 0; i < cnt; i++) {
			if (arc[i].flag)  temp++;//遇见起点就加
			else temp--;//遇见终点就减
			ans = max(ans, temp);
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}