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

class JarBox {
public:
	int numJars(int radius, int woodlength) {
		double r = radius, l = woodlength;
		double y = sqrt(4 * r*r - r*r);
		int ret = 0;
		Rep(i, 1, l / 2) {
			if (l / 2 < 2 * r*i)
				break;
			double rst = l / 2 - 2 * r*i;
			if (rst < 2 * r)
				continue;
			int n = (rst - 2 * r) / y + 1;
			ret = max(ret, i*(n / 2 + (n & 1)) + (i - 1)*(n / 2));
			rst = l / 2 - 2 * r*i - r;
			if (rst < 2 * r)
				continue;
			n = (rst - 2 * r) / y + 1;
			ret = max(ret, i*n);
		}
		return ret;
	}
};















//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
