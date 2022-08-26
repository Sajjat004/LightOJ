/*  Bismillahir Rahmanir Rahim
    Author  :  Md. Sajjat Hosen
    Created :  Friday, 05 June, 2020 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long               ll;
typedef long double             ld;
typedef unsigned long long      ull;
typedef pair<int, int>          pii;
typedef pair<ll, ll>            pll;
typedef vector<int>             vi;
typedef vector<ll>              vll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N       = (int) 2e5 + 5;
const int maxN    = (int) 1e6 + 6;
const int Mod     = (int) 1e9 + 7;

#define     debug(x)    cerr << #x << " = " << x << '\n';
#define     all(x)      x.begin(), x.end()
#define     szof(x)     (int) x.size()
#define     ff          first
#define     ss          second
#define     pb          push_back
#define     mp          make_pair
#define     PI          acos(-1.0)
#define     TN          typename
#define     nl          '\n'
#define     Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

inline int add(int a, int b) { a += b; return a >= Mod ? a - Mod : a < 0 ? a + Mod : a; }
inline int mult(int a, int b) { return (ll) a * b % Mod; }

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

bool isDigit(char c){return c >= '0' and c <= '9';} 
bool isLower(char c){return c >= 'a' and c <= 'z';} 
bool isUpper(char c){return c >= 'A' and c <= 'Z';}
bool isVowel(char c){
    return c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U' ;
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' ;
}


int cnt[30];

int main() {
    //Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    cin >> test;
    getchar();
    while (test--) {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < szof(s1); ++i) {
        	if (s1[i] != ' ') {
        		if (isUpper(s1[i])) cnt[s1[i] - 'A']++;
        		else cnt[s1[i] - 'a']++;
        	}
        }
        for (int i = 0; i < szof(s2); ++i) {
        	if (s2[i] != ' ') {
        		if (isUpper(s2[i])) cnt[s2[i] - 'A']--;
        		else cnt[s2[i] - 'a']--;
        	}
        }
        bool ok = 1;
        for (int i = 0; i <= 26; ++i) {
        	if (cnt[i] != 0) {
        		ok = 0;
        		break;
        	}
        }
        if (ok) cout << "Case " << ++tc << ": Yes\n";
        else cout << "Case " << ++tc << ": No\n";
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
