/*-----------------------------------
  bismillahir rahmanir rahim
  @author : md. sajjat hossen
  created : 27-October,2021 21:57:04
------------------------------------*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair <int, int>    pii;
typedef pair <ll, ll>      pll;
typedef vector <int>       vi;
typedef vector <ll>        vll;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N      = (int) 2e5 + 5;
const int mxN    = (int) 1e6 + 6;
const int MOD    = (int) 1e9 + 7;
const int INF    = (int) 1e9 + 9;
const double EPS = (double) 1e-9;

#define debug(x) cerr << #x << " = " << x << '\n';
#define all(x)   x.begin(), x.end()
#define szof(x)  (int) x.size()
#define ff       first
#define ss       second
#define pb       push_back
#define mp       make_pair
#define PI       acos(-1.0)
#define TN       typename
#define nl       '\n'
#define Fast_IO  ios_base::sync_with_stdio(false); cin.tie(nullptr);

inline int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
inline int mult(int a, int b, int mod) { return (ll) a * b % mod; }

template <TN T> inline void umin(T &x, T y) { x = x < y ? x : y; }
template <TN T> inline void umax(T &x, T y) { x = x > y ? x : y; }

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

vi prime;

bool isPrime(int n) {
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void getPrime() {
    for (int i = 2; i <= 110; ++i) {
        if (isPrime(i)) prime.pb(i);
    }
}

void multipy(vll& v, ll m) {
    ll carry = 0;
    for (auto& x : v) {
        carry += (m * x);
        x = carry % 10;
        carry /= 10;
    }
    while (carry) {
        v.pb(carry % 10);
        carry /= 10;
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // Fast_IO
    getPrime();
    int test = 1, tc = 0;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        vi freq(10005, 0);
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            for (int j = 0; (prime[j] * prime[j]) <= x; ++j) {
                if (x % prime[j] == 0) {
                    int cnt = 0;
                    while (x % prime[j] == 0) {
                        ++cnt;
                        x /= prime[j];
                    }
                    umax(freq[prime[j]], cnt);
                }
            }
            if (x > 1) {
                umax(freq[x], 1);
            }
        }
        vll res;
        res.pb(1LL);
        for (int i = 1; i < 10005; ++i) {
            while (freq[i]--) {
                multipy(res, (ll) i);
            }
        }
        cout << "Case " << ++tc << ": ";
        int sz = szof(res);
        for (int i = sz - 1; i >= 0; --i) cout << res[i];
        cout << nl;
    }
    return 0;
}
