#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = false;

void solve(){
  ll n, d; cin >> n >> d;
  vector<ll> p(n);
  for(ll i = 0; i<n; i++){
    cin >> p[i];
  }

  sort(p.begin(), p.end());

  int l=0;
  int r=n-1;
  ll sum = 0;
  int ans = 0;
  int count = 0;
  while(l<=r){
    if(p[r] > d){
      ans++;
      r--;
    }else if(sum > d){
      ans++;
      r--;
      sum = 0;
      count = 0;
    }else{
      count++;
      sum = p[r] + p[r]*count;
      l++;
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