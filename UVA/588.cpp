//~In The Name Of Allah~//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <sstream>
#include <fstream>
#include <functional>
#include <stack>
#include <utility> 
#include <set>
#include <list>
#include <queue>
#include <bitset>
#include <time.h>
#include <complex>

using namespace std;

#define read freopen("in.txt", "r", stdin)
#define write freopen("out.txt", "w", stdout)
#define all(_) _.begin(), _.end()
#define rall(_) _.rbegin(), _.rend()
#define rep(i, j) for (int i = 0; i < j; i++)
#define Rep(i, j, k) for (int i = j; i < k; i++)
#define siz(_) (int)_.size()
#define ll long long
#define endl '\n'
#define ff fflush(stdout)

const double PI = 2.0 * acos(0.0);
const int MOD = 1e9 + 7;
const int oo = MOD;

typedef pair<int, int> pii;

ll gcd(ll x, ll y) { return !y ? x : gcd(y, x%y); }

struct p {
	double x, y;
};

struct line {
	p p1, p2;
};

double cp(p a, p b, p c) {
	c.x -= b.x, c.y -= b.y;
	b.x -= a.x, b.y -= a.y;
	return b.x*c.y - b.y*c.x;
}

p inter(p a, p b, p c, p d) {
	double a1, b1, c1;
	double a2, b2, c2;
	a1 = b.y - a.y;
	b1 = a.x - b.x;
	c1 = a1*a.x + b1*a.y;
	a2 = d.y - c.y;
	b2 = c.x - d.x;
	c2 = a2*c.x + b2*c.y;
	double det = a1*b2 - a2*b1;
	if (fabs(det) < 1e-9)
		return{ oo, -oo };
	p ret;
	ret.x = (b2*c1 - b1*c2) / det;
	ret.y = (a1*c2 - a2*c1) / det;
	return ret;
}

vector<p> CutPoly(line l, vector<p> poly) {
	vector<p> ret;
	rep(i, siz(poly)) {
		if (cp(l.p1, l.p2, poly[i]) <= 0) {
			ret.push_back(poly[i]);
			continue;
		}
		p p1, p2;
		p1 = poly[i];
		p2 = poly[(i + 1) % siz(poly)];
		p ip = inter(p1, p2, l.p1, l.p2);
		if (ip.x == oo && ip.y == -oo)
			continue;
		if (p1.x == p2.x) {
			if (p1.y > p2.y)
				swap(p1, p2);
			if (ip.y >= p1.y && ip.y <= p2.y)
				ret.push_back(ip);
		}
		else if (p1.y == p2.y) {
			if (p1.x > p2.x)
				swap(p1, p2);
			if (ip.x >= p1.x && ip.x <= p2.x)
				ret.push_back(ip);
		}
	}
	return ret;
}

int main() {
	int n, cs = 0;
	while (scanf("%d", &n) && n) {
		vector<p> in(n), opt;
		double x, y;
		x = y = 0;
		rep(i, n)
			scanf("%lf%lf", &in[i].x, &in[i].y);
		opt = in;
		rep(i, n)
			opt = CutPoly({ in[i], in[(i + 1) % siz(in)] }, opt);
		printf("Floor #%d\n", ++cs);
		if (!opt.empty())
			puts("Surveillance is possible.");
		else
			puts("Surveillance is impossible.");
		puts("");
	}
	return 0;
}
