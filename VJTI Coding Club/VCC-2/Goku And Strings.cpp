#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define sz(c) (int)(c).size()
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPD(i, n) for(int i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define mp make_pair
#define LL long long
#define CHECK(S, j) (S & (1 << j))
#define SET(S, j) (S |= (1 << j))
#define SETALL(S, j) (S = (1 << j)-1)
#define UNSET(S, j) (S &= ~(1 << j))
#define TOGGLE(S, j) (S ^= (1 << j))
#define modulo 1000000007
template<class T>string tostring(T t){stringstream s;s<<t;return s.str();}

int dp[2003][2003];

int main(){
    freopen("input.in", "r", stdin);
    int T;
    cin >> T;
    while(T--){
        string X, Y;
        cin >> X >> Y;
        int n = sz(X), m = sz(Y);
        dp[0][0] = 0;
        FOR(i, 1, n) dp[i][0] = i;
        FOR(i, 1, m) dp[0][i] = i;
        FOR(i, 1, n){
            FOR(j, 1, m){
                int val = X[i-1] == Y[j-1] ? 0:1;
                int t1 = min(dp[i-1][j]+1, dp[i][j-1]+1);
                int t2 = dp[i-1][j-1]+val;
                dp[i][j] = min(t2, t1);
            }
        }
        cout << dp[n][m] << endl;
    }
}
