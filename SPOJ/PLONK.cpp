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
#include <cstdio>
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
const int oo = MOD << 1;

typedef pair<int, int> pii;

ll gcd(ll x, ll y) { return !y ? x : gcd(y, x%y); }

int main() {
	int t, n;
	cin >> t;
	while (t-- && cin >> n) {
		vector<pii> in(n);
		int l = oo, r = -oo, u = -oo, d = oo;
		rep(i, n) {
			scanf("%d%d", &in[i].first, &in[i].second);
			l = min(l, in[i].first);
			r = max(r, in[i].first);
			u = max(u, in[i].second);
			d = min(d, in[i].second);
		}
		pii c = { (l + r) / 2, (u + d) / 2 };
		vector<pii> nrst;
		vector<pii> s(n);
		rep(i, n)
			s[i] = { abs(in[i].first - c.first) + abs(in[i].second - c.second), i };
		sort(all(s));
		int opt = oo;
		rep(i, min(n, 100)) {
			pii p = in[s[i].second];
			int tmp = 0;
			rep(j, n)
				tmp += abs(in[j].first - p.first) + abs(in[j].second - p.second);
			opt = min(opt, tmp);
		}
		cout << opt << endl;
	}
	return 0;
}
