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

ll dp[3][1234];

int main() {
	int n, cnt[26];
	string str;
	cin >> n >> str;
	rep(i, 26)
		cin >> cnt[i];
	str = " " + str;
	dp[0][0] = 1;
	Rep(i, 1, n + 1) {
		int mn = cnt[str[i] - 'a'];
		dp[2][i] = dp[2][i - 1] + 1;
		for (int j = i; j > 0; j--) {
			mn = min(mn, cnt[str[j] - 'a']);
			if (i - j + 1 > mn)
				break;
			dp[0][i] += dp[0][j - 1], dp[0][i] %= MOD;
			dp[1][i] = max(dp[1][i], max(dp[1][j - 1], i - j + 1LL));
			dp[2][i] = min(dp[2][i], dp[2][j - 1] + 1);
		}
	}
	cout << dp[0][n] << endl;
	cout << dp[1][n] << endl;
	cout << dp[2][n] << endl;
	return 0;
}