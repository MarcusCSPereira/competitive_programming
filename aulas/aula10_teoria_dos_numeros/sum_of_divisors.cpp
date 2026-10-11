#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,op,b,c) for (int i =a; i op b; i += c)
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
typedef long long ll;
typedef __int128 i128;

bool many_cases = false;

ll M = 1e9 + 7;

ll pa_soma(ll l, ll r){
  i128 qtd = (i128)(r-l+1);
  i128 res = (i128)(l+r) * qtd/2;
  return res % M;
}

void solve(){
  ll n; cin >> n;
  ll l =1, r, d; // d é o divisor naquele momento
  ll ans = 0;
  while(l<=n){
    d = n/l;
    r = n/d;
    ll soma = pa_soma(l,r); // soma do intervalo que sempre resulta no mesmo divisor
    i128 parcial = (i128)((d % M) * (soma % M)) % M; // calculo de quanto o intervalo l e r contribuem na soma total dos divisores
    ans = ((ans % M) + (parcial % M)) % M;
    l = r + 1;
  }

  cout << ans;

}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}