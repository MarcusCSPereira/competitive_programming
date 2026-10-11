#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  int a[n];
  for(int i = 0; i < n; i++){ cin >> a[i]; }

  int cut = a[k - 1];
  
  int dir, esq, meio;
  esq = 0;
  dir = n - 1;
  while(esq <= dir){
    meio = (esq + dir)/2;
    if (a[meio] >= cut && a[meio] > 0){
      esq = meio + 1;
    }else{
      dir = meio - 1;
    }
  }

  cout << esq;

}