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

const int mx = 1e5 + 5;
int a[mx], b[mx], v[mx];

ll merge(int l, int md, int r) {
	Rep(i, l, md + 1)
		a[i] = v[i];
	Rep(i, md + 1, r + 1)
		b[i] = v[i];
	int x = l, y = md + 1, idx = l, ret = 0;
	while (x <= md && y <= r) {
		if (a[x] <= b[y])
			v[idx++] = a[x++];
		else {
			v[idx++] = b[y++];
			ret += (md - x + 1);
		}
	}
	Rep(i, x, md + 1)
		v[idx++] = a[i];
	Rep(i, y, r + 1)
		v[idx++] = b[i];
	return ret;
}

ll solve(int l, int r) {
	if (l == r)
		return 0;
	int md = l + (r - l) / 2;
	return solve(l, md) + solve(md + 1, r) + merge(l, md, r);
}

int main() {
	int n;
	cin >> n;
	vector<pair<string, int>> in(n), rev(n);
	char str[15];
	rep(i, n) {
		scanf("%s", str);
		in[i].first = str;
		in[i].second = i;
	}
	sort(all(in));
	rep(i, n) {
		rev[i].first = in[i].first;
		reverse(all(rev[i].first));
		rev[i].second = i;
	}
	sort(all(rev));
	rep(i, n)
		v[i] = rev[i].second;
	cout << solve(0, n - 1) << endl;
	return 0;
}
