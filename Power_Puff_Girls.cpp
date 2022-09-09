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

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

int n, m;
string s[20];

bool isValid(int x, int y) { return (x >= 0 and x < n and y >= 0 and y < m); }
vector<vi> dp[3];

void bfs(int x, int y, int id) {
  queue<pii> q;
  q.push({x, y});
  dp[id][x][y] = 0;
  while (!q.empty()) {
    x = q.front().ff;
    y = q.front().ss;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (isValid(xx, yy) and s[xx][yy] != '#' and s[xx][yy] != 'm' and dp[id][xx][yy] == -1) {
        dp[id][xx][yy] = dp[id][x][y] + 1;
        q.push({xx, yy});
      }
    }
  }
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
    dp[0].assign(n, vi(m, -1));
    dp[1].assign(n, vi(m, -1));
    dp[2].assign(n, vi(m, -1));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == 'a') {
          bfs(i, j, 0);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == 'b') {
          bfs(i, j, 1);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == 'c') {
          bfs(i, j, 2);
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == 'h') {
          cout << "Case " << ++tc << ": " << max({dp[0][i][j], dp[1][i][j], dp[2][i][j]}) << nl;
        }
      }
    }
  }
  return 0;
}
