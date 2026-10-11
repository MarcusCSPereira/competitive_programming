#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  vector<ll> a(n);
  for(ll &x : a) cin >> x;

  vector<ll> p(n+1, 0);
  for(int i = 1; i<= n; i++) p[i] = p[i-1] + a[i-1];

  ll men = 0;
  ll mai = LLONG_MIN;
  int ma_i = 0;
  int me_i = 0;
  for(int i=1; i<=n; i++){
    if(p[i] - men > mai){
      mai = p[i] - men;
      ma_i = i-1;
    }
    if(p[i] < men){
      men = p[i];
      me_i = i;
    }
  }

  vector<ll> sub(a.begin() + me_i, a.begin() + ma_i+1);

  cout << mai << " " << me_i << " " << ma_i << "\n";
  for(ll x : sub) cout << x << " ";

  return 0;
}