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
#define sz(c) (c).size()
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

int main(){
    string S, t;
    cin >> S >> t;
    int i = 0;
    bool automaton = false, arr = true, all = true;
    REP(j, sz(S)){
        if(i < sz(t) && t[i] == S[j]){
            i++;
        }
        if(i == sz(t)){
            automaton = true;
        }
    }
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    REP(i, sz(S)) cnt[S[i]-'a']++;
    REP(i, sz(t)) cnt[t[i]-'a']--;

    REP(i, 26){
        arr &= (cnt[i] == 0);
        all &= (cnt[i] >= 0);
    }
    if(automaton) cout << "automaton" << endl;
    else if(arr) cout << "array" << endl;
    else if(all) cout << "both" << endl;
    else cout << "need tree" << endl;
}