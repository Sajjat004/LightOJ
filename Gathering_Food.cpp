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

int n;
string s[20];

bool isValid(int x, int y) { return (x >= 0 and x < n and y >= 0 and y < n); }

int bfs(int x, int y, char target) {
  vector<vi> dist(20, vi(20, 0));
  vector<vector<bool>> used(20, vector<bool>(20, 0));
  queue<pii> q;
  q.push({x, y});
  dist[x][y] = 0;
  used[x][y] = 1;
  while (!q.empty()) {
    x = q.front().ff;
    y = q.front().ss;
    q.pop();
    if (s[x][y] == target) return dist[x][y];
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (isValid(xx, yy) and used[xx][yy] == 0 and (s[xx][yy] == '.' or s[xx][yy] == target)) {
        used[xx][yy] = 1;
        dist[xx][yy] = dist[x][y] + 1;
        q.push({xx, yy});
      }
    }
  }
  return INF;
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
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    vector<char> alph;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (s[i][j] >= 'A' and s[i][j] <= 'Z') alph.push_back(s[i][j]);
      }
    }
    sort(all(alph));
    bool ok = 0;
    int res = 0;
    for (int k = 1; k < szof(alph); ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (s[i][j] == alph[k - 1]) {
            int sub = bfs(i, j, alph[k]);
            s[i][j] = '.';
            res += sub;
            if (sub == INF) ok = 1;
          }
        }
      }
    }
    if (ok) cout << "Case " << ++tc << ": Impossible\n";
    else cout << "Case " << ++tc << ": " << res << nl;
  }
  return 0;
}
