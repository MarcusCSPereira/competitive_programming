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
  ll n, k, b, s; cin >> n >> k >> b >> s;
  if(s >= k*b && s <= (k*b + ((k-1)*n))){
    vector<ll> v(n,0);
    v[0] = k*b;
    s = s - k*b;
    for(int i=0; i<n;i++){
      v[i] += min((k-1),s);
      s = max((s-(k-1)), 0LL);
    }
    for(int i=0; i<n;i++){
      i == n-1 ? cout << v[i] << endl : cout << v[i] << " ";
    }
  }else{
    cout << -1 << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}