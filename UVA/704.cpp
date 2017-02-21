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

int t, n;
pair<vector<int>, vector<int>> ori;

struct state {
	pair<vector<int>, vector<int>> grid;
	string pth;
};

pair<vector<int>, vector<int>> rot(vector<int> l, vector<int> r, int tyb) {
	if (tyb == 1) rep(i, 2)
		l.insert(l.begin(), l.back()), l.pop_back();
	else if (tyb == 2) rep(i, 2)
		r.push_back(r.front()), r.erase(r.begin());
	else if (tyb == 3) rep(i, 2)
		l.push_back(l.front()), l.erase(l.begin());
	else rep(i, 2)
		r.insert(r.begin(), r.back()), r.pop_back();
	Rep(i, 9, 12) if (tyb & 1)
		r[i] = l[i];
	else
		l[i] = r[i];
	return{ l, r };
}

int main() {
	ori.first = { 0, 3, 4, 3, 0, 5, 6, 5, 0, 1, 2, 1 };
	ori.second = { 0, 7, 8, 7, 0, 9, 10, 9, 0, 1, 2, 1 };
	queue<state> q;
	vector<int> l(12), r(12);
	cin >> t;
	while (t--) {
		rep(i, 12)
			scanf("%d", &l[i]);
		rep(i, 12)
			scanf("%d", &r[i]);
		q.push({ { l, r }, "" });
		set<pair<vector<int>, vector<int>>> vis, dne;
		map<pair<vector<int>, vector<int>>, string> m;
		string ans = "9999999999999999999999999";
		while (!q.empty()) {
			pair<vector<int>, vector<int>> grid = q.front().grid;
			string pth = q.front().pth;
			q.pop();
			if (siz(pth) > 9 || vis.find(grid) != vis.end())
				continue;
			if (grid == ori) {
				ans = pth;
				break;
			}
			vis.insert(grid);
			m[grid] = pth;
			Rep(i, 1, 5)
				q.push({ rot(grid.first, grid.second, i), pth + char(i + '0') });
		}
		if (ans == "9999999999999999999999999") {
			while (!q.empty())
				q.pop();
			q.push({ ori, "" });
			while (!q.empty()) {
				pair<vector<int>, vector<int>> grid = q.front().grid;
				string pth = q.front().pth;
				q.pop();
				if (siz(pth) > 9 || dne.find(grid) != dne.end())
					continue;
				if (vis.find(grid) != vis.end()) {
					string opt = m[grid];
					reverse(all(pth));
					rep(i, siz(pth)) if (pth[i] == '1')
						pth[i] = '3';
					else if (pth[i] == '3')
						pth[i] = '1';
					else if (pth[i] == '2')
						pth[i] = '4';
					else
						pth[i] = '2';
					opt += pth;
					if (siz(opt) <= 16 && (siz(ans) > siz(opt) || siz(ans) == siz(opt) && ans > opt))
						ans = opt;
					continue;
				}
				dne.insert(grid);
				Rep(i, 1, 5)
					q.push({ rot(grid.first, grid.second, i), pth + char(i + '0') });
			}
		}
		if (ans.empty())
			puts("PUZZLE ALREADY SOLVED");
		else if (ans == "9999999999999999999999999")
			puts("NO SOLUTION WAS FOUND IN 16 STEPS");
		else
			cout << ans << endl;
		while (!q.empty())
			q.pop();
	}
	return 0;
}
