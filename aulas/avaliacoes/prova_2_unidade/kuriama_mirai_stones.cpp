#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,op,b,c) for (int i =a; i op b; i += c)
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
typedef long long ll;

bool many_cases = true;

void solve(ll n, vector<ll> &p1, vector<ll> &p2){
  ll l, r, type; cin >> type >> l >> r;

  if(type == 1){
    cout << p1[r] - p1[l-1] << endl;
  }else{
    cout << p2[r] - p2[l-1] << endl;
  }

}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll n; cin >> n;
  vector<ll> v1(n),v2(n);
  for(int i=0; i<n; i++){
    ll x; cin >> x;
    v1[i] = x;v2[i]=x;
  }
  sort(v2.begin(),v2.end());
  vector<ll> p1(n+1), p2(n+1);
  for(int i=1; i<=n; i++){
    p1[i] = p1[i-1] + v1[i-1];
    p2[i] = p2[i-1] + v2[i-1];
  }
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve(n,p1, p2);
  return 0;
}