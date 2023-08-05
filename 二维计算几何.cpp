#include <bits/stdc++.h>
using namespace std;

const double eps = 1E-6;
bool equal(double x, double y) {
    return fabs(x - y) < eps;
}

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}

    friend bool operator==(const Point &a, const Point &b) {
        return equal(a.x, b.x) && equal(a.y, b.y);
    }
    friend Point operator-(const Point &a, const Point &b) {
        return {a.x - b.x, a.y - b.y};
    }
    friend Point operator+(const Point &a, const Point &b) {
        return {a.x + b.x, a.y + b.y};
    }
    friend Point operator*(const Point &a, double x) {
        return {a.x * x, a.y * x};
    }
    friend Point operator/(const Point &a, double x) {
        return {a.x / x, a.y / x};
    }
};

double len(const Point &p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

double cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

//�����н�
double angle(const Point &a, const Point &b) {
    return acos(dot(a, b) / len(a) / len(b));
}

//a bƽ���ı������
double area(const Point &a, const Point &b) {
    return cross(a, b);
}

//��תagl����
Point rotate(const Point &a, double agl) {
    return Point(a.x * cos(agl) + a.y * sin(agl) , -a.x * sin(agl) + a.y * cos(agl));
}
//�ж��Ƿ���ֱ����
bool on_line(const Point &p, const Point &a, const Point &b) {
    Point v = b - a, u = p - a;
    return cross(u, v) == 0;
}
//�ж��Ƿ����߶���
bool on_seg(const Point &p, const Point &a, const Point &b) {
    Point v = b - a, u = p - a, l = p - b;
    return (cross(v, u) == 0 && dot(u, l) <= 0);
}

//����㵽ֱ�߾���
double distance_line(const Point &p, const Point &a, const Point &b) {
    Point v1 = b - a, v2 = p - a;
    return fabs(cross(v1, v2) / len(v1));
}

//����㵽�߶ξ���
double distance_seg(const Point &p, const Point &a, const Point &b) {
    if (a == b)
        return len(p - a);
    Point v1 = b - a, v2 = p - a, v3 = p - b;
    if (dot(v1, v2) < 0)
        return len(v2);
    if (dot(v1, v3) > 0)
        return len(v3);
    return distance_line(p, a, b);
}

//����ֱ����ͶӰ
Point projection(const Point &p, const Point &a, const Point &b) {
    Point v = b - a, u = p - a;
    return a + v * (dot(v, u) / dot(v, v));
}

//�ж��߶��Ƿ��ཻ
bool seg_intersection(const Point &a1, const Point &a2, const Point &b1, const Point &b2) {
    double c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1);
    double c3 = cross(b2 - b1, a2 - b1), c4 = cross(b2 - b1, a1 - b1);
    return (c1 * c2 <= 0 && c3 * c4 <= 0);
}

//ö�ٶ���ε�ÿ���ߣ����������
double polygon_area(const vector<Point> p) {
    double s = 0;
    int n = p.size();
    for (int i = 1; i < n - 1; i++)
        s += cross(p[i] - p[0], p[i + 1] - p[i]);
    return s / 2;
}







