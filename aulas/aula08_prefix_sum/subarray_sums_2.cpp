#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, x; cin >> n >> x;
  vector<ll> a(n);
  for(ll &x: a) cin >> x;

  vector<ll> p(n+1, 0);
  for(int i =1;i<=n; i++) p[i] = p[i-1] + a[i-1];

  map<ll, ll> m;
  m[0] = 1;
  ll sub_c = 0;
  for(int i=1; i<= n; i++){
    ll sum;
    sum = p[i] - x;
    if (m[sum]) sub_c += m[sum];

    m[p[i]] = m[p[i]] + 1;  
  }

  cout << sub_c;


  return 0;
}