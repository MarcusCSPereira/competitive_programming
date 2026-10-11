#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;


int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  freopen("hps.in", "r", stdin); freopen("hps.out", "w", stdout);

  ll n; cin >> n;

  vector<char> j1(n);
  for(char &x : j1) cin>>x;

  vector<int> vpe(n+1, 0);
  vector<int> vpa(n+1, 0);
  vector<int> vte(n+1, 0);

  for (int i =1; i<=n; i++){
    vpe[i] = vpe[i-1] + (j1[i-1] == 'S' ? 1 : 0);
    vpa[i] = vpa[i-1] + (j1[i-1] == 'H' ? 1 : 0);
    vte[i] = vte[i-1] + (j1[i-1] == 'P' ? 1 : 0);
  }

  ll ans = 0;
  for(int i=0;i<=n;i++){
    ll after, before;
    after = max({vpe[i], vpa[i], vte[i]});
    before = max({
      (vpe[n] - vpe[i]),
      (vpa[n] - vpa[i]),
      (vte[n] - vte[i])
    });

    ans = max(ans, after + before);
  }

  cout << ans << endl;


  return 0;
}