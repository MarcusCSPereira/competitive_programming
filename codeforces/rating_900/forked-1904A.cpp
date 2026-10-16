#include <bits/stdc++.h>
#include <utility>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = true;

void solve(){
  int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1};
  ll a, b; cin >> a >> b;
  ll xk, yk, xq, yq; cin >> xk >> yk >> xq >> yq;
  set<pair<ll,ll>> kj; set<pair<ll, ll>> qj;
  for(int i=0;i<4;i++){
    kj.insert({xk + dx[i] * a,yk + dy[i] * b});
    kj.insert({xk + dx[i] * b,yk + dy[i] * a});

    qj.insert({xq + dx[i] * a,yq + dy[i] * b});
    qj.insert({xq + dx[i] * b,yq + dy[i] * a});
  }

  ll ans = 0;
  
  for(auto position : kj){
    if(qj.find(position) != qj.end()){
      ans++;
    }
  }

  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}