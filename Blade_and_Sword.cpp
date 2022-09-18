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
string s[205];

int ans, ans1;
pii idx;
int tele = 0;

bool isValid(int x, int y) {
  return (x >= 0 and x < n and y >= 0 and y < m);
}

int getDist() {
  int x, y;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'P') {
        x = i, y = j;
      }
    }
  }
  vector<vi> dist(n, vi(m, -1));
  vector<vector<bool>> used(n, vector<bool>(m, 0));
  queue<pii> q;
  q.push({x, y});
  dist[x][y] = 0;
  used[x][y] = 1;
  while (!q.empty()) {
    x = q.front().ff;
    y = q.front().ss;
    q.pop();
    if (s[x][y] == 'D') return dist[x][y];
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (isValid(xx, yy) and (s[xx][yy] == '.' or s[xx][yy] == 'D') and used[xx][yy] == 0) {
        dist[xx][yy] = dist[x][y] + 1;
        q.push({xx, yy});
        used[xx][yy] = 1;
      }
    }
  }
  return INF;
}

int getDist1(int x, int y) {
  vector<vi> dist(n, vi(m, -1));
  vector<vector<bool>> used(n, vector<bool>(m, 0));
  queue<pii> q;
  q.push({x, y});
  dist[x][y] = 0;
  used[x][y] = 1;
  while (!q.empty()) {
    x = q.front().ff;
    y = q.front().ss;
    q.pop();
    if (s[x][y] == '*') {
      idx = {x, y};
      return dist[x][y];
    }
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (isValid(xx, yy) and (s[xx][yy] == '.' or s[xx][yy] == '*') and used[xx][yy] == 0) {
        dist[xx][yy] = dist[x][y] + 1;
        q.push({xx, yy});
        used[xx][yy] = 1;
      }
    }
  }
  return INF;
}

void getDist2(int x, int y) {
  vector<vi> dist(n, vi(m, -1));
  vector<vector<bool>> used(n, vector<bool>(m, 0));
  queue<pii> q;
  q.push({x, y});
  dist[x][y] = 0;
  used[x][y] = 1;
  while (!q.empty()) {
    x = q.front().ff;
    y = q.front().ss;
    q.pop();
    if (s[x][y] == '*') {
      pii idx1 = {x, y};
      if (idx1 != idx) ans = min(ans, ans1 + dist[x][y] + 1);
      else if (idx1 == idx and tele > 1) ans = min(ans, ans1 + dist[x][y] + 2);
    }
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (isValid(xx, yy) and (s[xx][yy] == '.' or s[xx][yy] == '*') and used[xx][yy] == 0) {
        dist[xx][yy] = dist[x][y] + 1;
        q.push({xx, yy});
        used[xx][yy] = 1;
      }
    }
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  cin >> test;
  while (test--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    ans = getDist();
    tele = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '*') tele++;
      }
    }
    for (int i = 0; i < n; ++i) {
      bool ok = 0;
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == 'P') {
          ans1 = getDist1(i, j);
          ok = 1;
          break;
        }
      }
      if (ok) break;
    }
    for (int i = 0; i < n; ++i) {
      bool ok = 0;
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == 'D') {
          getDist2(i, j);
          ok = 1;
          break;
        }
      }
      if (ok) break;
    }
    for (int i = 0; i < n; ++i) {
      bool ok = 0;
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == 'D') {
          ans1 = getDist1(i, j);
          ok = 1;
          break;
        }
      }
      if (ok) break;
    }
    for (int i = 0; i < n; ++i) {
      bool ok = 0;
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == 'P') {
          getDist2(i, j);
          ok = 1;
          break;
        }
      }
      if (ok) break;
    }
    if (ans >= INF) cout << "Case " << ++tc << ": impossible\n";
    else cout << "Case " << ++tc << ": " << ans << nl;
  }
  return 0;
}
