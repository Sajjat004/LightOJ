#include <bits/stdc++.h>
using namespace std;

typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair<int, int>     pii;
typedef pair<ll, ll>       pll;
typedef vector<int>        vi;
typedef vector<ll>         vll;

const int N      = (int) 2e5 + 5;
const int mxN    = (int) 1e6 + 6;
const int MOD    = (int) 1e9 + 7;
const int INF    = (int) 1e9 + 9;
const double EPS = (double) 1e-9;

#define all(x)   x.begin(), x.end()
#define szof(x)  (int) x.size()
#define ff       first
#define ss       second
#define pb       push_back
#define nl       '\n'
#define PI       acos(-1.0)
#define debug(x) cerr << #x << " = " << x << '\n';

/*................. let's try one more time .................*/

#ifdef LOCAL
#include "headerFile/debug.h"
#endif

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

int n, m;
string s[202];
bool isValid(int x, int y) {
  return (x >= 0 and x < n and y >= 0 and y < m);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  cin >> test;
  while (test--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    vector<vi> dp(n, vi(m, INF));
    vector<vi> dp1(n, vi(m, INF));
    queue<pii> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == 'J') {
          q.push({i, j});
          dp[i][j] = 0;
        }
      }
    }
    while (!q.empty()) {
      int x = q.front().ff;
      int y = q.front().ss;
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int xx = dx[i] + x, yy = dy[i] + y;
        if (isValid(xx, yy) and s[xx][yy] != '#' and dp[xx][yy] == INF) {
          dp[xx][yy] = dp[x][y] + 1;
          q.push({xx, yy});
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == 'F') {
          q.push({i, j});
          dp1[i][j] = 0;
        }
      }
    }
    while (!q.empty()) {
      int x = q.front().ff;
      int y = q.front().ss;
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int xx = dx[i] + x, yy = dy[i] + y;
        if (isValid(xx, yy) and s[xx][yy] != '#' and dp1[xx][yy] == INF) {
          dp1[xx][yy] = dp1[x][y] + 1;
          q.push({xx, yy});
        }
      }
    }
    int res = INF;
    for (int i = 0; i < n; ++i) {
      if (s[i][0] == '.' and dp[i][0] < dp1[i][0]) res = min(res, dp[i][0] + 1);
    }
    for (int i = 0; i < m; ++i) {
      if (s[0][i] == '.' and dp[0][i] < dp1[0][i]) res = min(res, dp[0][i] + 1);
    }
    for (int i = 0; i < n; ++i) {
      if (s[i][m - 1] == '.' and dp[i][m - 1] < dp1[i][m - 1]) res = min(res, dp[i][m - 1] + 1);
    }
    for (int i = 0; i < m; ++i) {
      if (s[n - 1][i] == '.' and dp[n - 1][i] < dp1[n - 1][i]) res = min(res, dp[n - 1][i] + 1);
    }

    
    if (res == INF) cout << "Case " << ++tc << ": IMPOSSIBLE" << nl;
    else cout << "Case " << ++tc << ": " << res << nl;
  }
  return 0;
}
