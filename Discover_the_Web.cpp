/*==========================================
    Bismillahir Rahmanir Rahim
    Author  : Md. Sajjat Hosen
    Created : 05-February,2021 10:31:20 PM
==========================================*/

#include <bits/stdc++.h>
using namespace std;

typedef  long long               ll;
typedef  long double             ld;
typedef  unsigned long long      ull;
typedef  pair<int, int>          pii;
typedef  pair<ll, ll>            pll;
typedef  vector<int>             vi;
typedef  vector<ll>              vll;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N       = (int) 2e5 + 5;
const int mxN     = (int) 1e6 + 6;
const ll MOD      = (ll) 1e9 + 7;

#define    debug(x)    cerr << #x << " = " << x << '\n';
#define    all(x)      x.begin(), x.end()
#define    szof(x)     (int) x.size()
#define    ff          first
#define    ss          second
#define    pb          push_back
#define    mp          make_pair
#define    pie         acos(-1.0)
#define    TN          typename
#define    nl          '\n'
#define    Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

template<TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template<TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

int main() {
    Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    cin >> test;
    while (test--) {
        stack<string> forward, backward;
        string curr = "http://www.lightoj.com/", s;
        cout << "Case " << ++tc << ":" << nl;
        while (1) {
            cin >> s;
            if (s == "VISIT") {
                backward.push(curr);
                cin >> curr;
                cout << curr << nl;
                while (!forward.empty()) forward.pop();
            } else if (s == "BACK") {
                if (backward.empty()) {
                    cout << "Ignored" << nl;
                } else {
                forward.push(curr);
                curr = backward.top();
                backward.pop();
                cout << curr << nl;
                }
            } else if (s == "FORWARD"){
                if (forward.empty()) {
                    cout << "Ignored" << nl;
                } else {
                    backward.push(curr);
                    curr = forward.top();
                    forward.pop();
                    cout << curr << nl;
                }
            } else {
                break;
            }
        }
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
