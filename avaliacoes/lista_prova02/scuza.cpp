#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;

void solve(){
  ll n, q; cin >> n >> q;
  vector<ll> vd(n);
  vector<ll> vq(q);
  for(int i=0;i<n;i++) cin >> vd[i];
  for(int i=0;i<q;i++) cin >> vq[i];

  vector<ll> pmax_d(n+1,0);
  vector<ll> psum_d(n+1,0);
  for(int i=1;i<=n;i++){
    pmax_d[i] = max(vd[i-1], pmax_d[i-1]);
    psum_d[i] = psum_d[i-1] + vd[i-1];
  }

  for(int i=0; i<q; i++){
    ll indx = (upper_bound(pmax_d.begin(),pmax_d.end(),vq[i]) - pmax_d.begin()) - 1;
    cout << psum_d[indx] << " ";
  }

  cout << endl;

}

bool many_cases = true;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}