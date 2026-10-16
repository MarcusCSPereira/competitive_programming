#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << "=" << x << endl
#define READVEC(n,v,TN,TV) TN n; cin >> n; vector<TV> v(n); for(TN i=0; i<n;i++) cin >> v[i];
#define COUT(x) ({cout << x << endl; return;})
typedef long long ll;

bool many_cases = true;

void solve(){
  string n;
  cin >> n;

  int digits = n.size();
  int firstDigit = n[0] - '0';

  int answer = 9 * (digits - 1) + firstDigit;

  COUT(answer);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll t=1;
  if(many_cases) cin >> t;
  while(t--)solve();
  return 0;
}