#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
const int tam_limit = 2e5 + 1;

bool many_cases = false;
vector<vector<ll>> dp;

ll mochila(vector<ll> &P, vector<ll> &V, ll w, ll n){
  if(w==0 || n == 0) return 0;
  if(dp[n][w] != -1) return dp[n][w];

  if(P[n-1] <= w){
    dp[n][w] = max(mochila(P,V,w,n-1), V[n-1] + mochila(P,V, w - P[n-1], n-1));
  }else{
    dp[n][w] = mochila(P,V,w,n-1);
  }

  return dp[n][w];
}


bool bs2(){return false;}

void solve(){
  int n, w; cin >> n >> w;
  vector<ll> V(n);
  vector<ll> P(n);
  dp = vector<vector<ll>>(n+1,vector<ll>(w+1,-1));
  for(int i=0; i<n; i++){
    cin >> P[i] >> V[i];
  }
  cout << (mochila(P, V, w, n));
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}