#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
typedef long long ll;

ll w;

bool f(ll m, vector<ll> &v){
  ll holes = 0;
  for(int i=0;i<v.size();i++){
    holes += max(m - v[i], 0LL);
  }
  return holes <= w; // T T T (T) F F F -> maximizacao
}

void solve(){
  ll n; cin >> n; cin >> w;
  vector<ll> v(n);
  ll maior = LLONG_MIN;
  for(int i=0; i<n; i++){
    cin >> v[i];
    if (v[i] > maior) maior = v[i];
  }

  ll l = 0;
  ll r = maior + w; // O pior caso é a maior coluna recebendo toda a água
  ll ans = -1;
  while(l<=r){
    ll m = l + (r-l)/2;
    if(f(m,v)){
      ans = m;
      l = m+1;
    }else{
      r=m-1;
    }
  }

  cout << ans << endl;

}

bool many_cases = true;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll t = 1;
    if(many_cases) cin >> t;
    while(t--) solve();
    return 0;
}