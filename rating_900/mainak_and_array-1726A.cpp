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
  long long n; cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  long long answer = v[n - 1] - v[0];

  // Ver se o primeiro elemento é o menor, logo o maior está no segmento que falta do array
  for (int i = 1; i < n; i++) answer = max(answer, v[i] - v[0]);

  // Ver se o ultimo elemento é o maior, logo o menor está no segmento que falta do array
  for (int i = 0; i < n - 1; i++) answer = max(answer, v[n - 1] - v[i]);

  //Ver se o o maior e menor elemento estão fora das posições 0 e n-1, e estão adjacentes dentro do array
  for (int i = 0; i < n - 1; i++) answer = max(answer, v[i] - v[i + 1]);

  cout << answer << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}