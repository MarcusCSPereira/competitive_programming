#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,op,b,c) for (int i =a; i op b; i += c)
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
typedef long long ll;

bool many_cases = false;

void solve(){
  ll n,p; cin >> n >> p;
  vector<ll> v(n);
  for(int i = 0; i<n; i++){
    cin >> v[i];
  }

  ll at=0;
  ll ans=0;
  vector<ll> times;

  if(v[p] > 300){
    cout << "0 0";
    return;
  }else{
    at = v[p];
    ans++;
    times.push_back(at);
    v.erase(v.begin()+p);
  }

  sort(v.begin(),v.end());

  for(int i=0;i<n-1;i++){
    if(v[i] + at > 300){
      break;
    }else{
      at+=v[i];
      ans++;
      times.push_back(at);
    }
  }

  vector<ll> pt(times.size()+1,0);
  for(int i=1;i<=times.size();i++){
    pt[i] = pt[i-1] + times[i-1];
  }

  cout << ans << " " << pt[times.size()];

}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}