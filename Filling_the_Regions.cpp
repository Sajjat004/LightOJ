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

int n, m;
string s[55];

bool isValid(int x, int y) { return (x >= 0 and x < n and y >= 0 and y < m); }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

void bfs(char match) {
  vector<vector<bool>> used(n, vector<bool>(m, 0));
  queue<pii> q;
  for (int i = 0; i < n; ++i) {
    if (s[i][0] != match) {
      used[i][0] = 1;
      q.push({i, 0});
    }
    if (s[i][m - 1] != match) {
      used[i][m - 1] = 1;
      q.push({i, m - 1});
    }
  }
  for (int j = 0; j < m; ++j) {
    if (s[0][j] != match) {
      used[0][j] = 1;
      q.push({0, j});
    }
    if (s[n - 1][j] != match) {
      used[n - 1][j] = 1;
      q.push({n - 1, j});
    }
  }
  while (!q.empty()) {
    int x = q.front().ff, y = q.front().ss;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (isValid(nx, ny)) {
        if (s[nx][ny] == match) continue;
        if (used[nx][ny]) continue;
        used[nx][ny] = 1;
        q.push({nx, ny});
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) if (!used[i][j]) s[i][j] = match;
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
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
      bfs(ch);
    }
    cout << "Case " << ++tc << ":\n";
    for (int i = 0; i < n; ++i) cout << s[i] << nl;
  }
  return 0;
}
