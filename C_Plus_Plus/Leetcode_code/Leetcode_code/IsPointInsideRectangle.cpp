#include <iostream>

using namespace std;

struct point {
	double x, y;
};

class IsPointInRectangle {
public:
	IsPointInRectangle(point p) {
		p_ = p;
	}

	~IsPointInRectangle() {}

	// 计算向量ao 与 向量ab 的叉乘，返回叉乘结果
	double cross(const point& o, const point& a, const point& b) {
		return (o.x - a.x) * (b.y - a.y) - (o.y - a.y) * (b.x - a.x);
	}

	// 判断点是否在在旋转矩阵内部
	bool isPointInside(const point& A, const point& B, const point& C, const point& D) {
		double d1 = cross(p_, A, B);
		double d2 = cross(p_, B, C);
		double d3 = cross(p_, C, D);
		double d4 = cross(p_, D, A);

		//检查叉乘结果符号是否一致，来判断点P是否在旋转矩形内部
		if ((d1 > 0 && d2 > 0 && d3 > 0 && d4 > 0) || d1 < 0 && d2 < 0 && d3 < 0 && d4 < 0) {
			return true;
		}
		return false;
	}

private:
	point p_;
};



int main() {
	// 定义旋转矩阵
	point A = { 1, 1 }, B = { 5, 1 }, C = { 5, 5 }, D = { 1, 5 }; 

	// 定义某一点P
	point P = { 3, 4 };

	IsPointInRectangle isInside(P);

	bool result = isInside.isPointInside(A, B, C, D);

	cout << "The point is " << (result ? "inside" : "outside") << " the rectangle" << endl;

	return 0;

}