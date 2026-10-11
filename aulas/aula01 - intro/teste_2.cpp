#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long k, n, w; 
  cin >> k >> n >> w;
  long long sum = k * (w * (w + 1) / 2);
  cout << (sum <= n ? 0 : sum - n) << endl;
  return 0;
}
