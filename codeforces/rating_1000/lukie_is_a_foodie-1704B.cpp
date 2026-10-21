#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = true;

void solve(){
  int n; ll x; cin>> n >> x;
  vector<ll> v(n);
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  ll v_left_interval = v[0] - x;
  ll v_righ_interval = v[0] + x;
  ll ans = 0;
  for(int i=0;i<n;i++){
    ll actual_l_interval = v[i] - x;
    ll actual_r_interval = v[i] + x;
    if(actual_l_interval > v_righ_interval || actual_r_interval < v_left_interval){
      ans++;
      v_left_interval = actual_l_interval;
      v_righ_interval = actual_r_interval;
    }else{
      v_left_interval = max(v_left_interval, actual_l_interval);
      v_righ_interval = min(v_righ_interval, actual_r_interval);
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
