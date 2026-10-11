#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
typedef long long ll;

const ll MOD = 1000000007LL;

ll mod_pow(ll a, ll b, ll m){
  ll res = 1;
  a %= m;
  while(b > 0){
    if(b % 2 == 1) res = (__int128)res * a % m;
    a = (__int128)a * a % m;
    b = b / 2;
  }
  return res;
}

bool many_cases = true;

void solve(){
  ll a, b;
  cin >> a >> b;
  cout << mod_pow(a, b, MOD) << endl;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}
