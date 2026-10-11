#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
typedef long long ll;

int binarySearch(vector<int>& v, int x) { // Implementação própria que retorna o indice em que o elemento está
    int l = 0;
    int r = v.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (v[mid] == x) {
            return mid;
        }

        if (v[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return -1;
}

void solve(){
  vector<int> v = {1, 3, 5, 7, 9};

  if (binary_search(v.begin(), v.end(), 5)) { // Implementação padrão do C++, retorna apenas True ou False
      cout << "Encontrou";
  } else {
      cout << "Nao encontrou";
  }
}

bool many_cases = false;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  
  ll t=1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}