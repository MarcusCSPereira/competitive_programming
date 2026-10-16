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
  int n; cin >> n;
  vector<ll> a(n);
  map<ll,int> mp;
  int max_freq = 0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    mp[a[i]]++;
    max_freq = max(max_freq,mp[a[i]]);
  }

  int swaps = n-max_freq;
  int copies=0;
  while(max_freq < n){
    copies++;
    max_freq*=2;
  }

  cout << swaps+copies << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}