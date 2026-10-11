#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = false;

void dfs(ll u, vector<char> &escolha, vector<ll> &adj, vector<pair<ll, ll>> &tempo, vector<int> &estado, vector<pair<ll,ll>> &resultado){
  // Se já ta visitado não visito de novo.
  if(estado[u] == 2){
    return;
  }

  // ciclo
  if(estado[u] == 1){
    resultado[u] = {-1,-1};
    return;
  }

  //marco que estou visitando
  estado[u] = 1;

  // se ele não vai só colocar {-1,-1}
  if(escolha[u] == 'D'){
    resultado[u] = {-1,-1};
  // Se ele vai é só colocar o tempo que ele fica.
  }else if(escolha[u] == 'A'){
    resultado[u] = tempo[u];
  // se ele depende de alguém
  }else{
    // se esse alguem não existe nos convidados: só colocar que o meu tmb n vai.
    if(adj[u] == -1){
      resultado[u] = { -1,-1};
    // se não vejo para os nós adjacentes se eles vão ir.
    }else{
      dfs(
        adj[u],
        escolha,
        adj,
        tempo,
        estado,
        resultado
      );

      // o resultado do meu nó que depende de um, é o resultado dessa dependência.
      resultado[u] = resultado[adj[u]];
    }
  }

  //marco como visitado
  estado[u] = 2;
}

void solve(){
  ll f; cin >> f; ll n; cin >> n;
  vector<ll> indx(n,-1); //guarda no indice o verdadeiro valor do nó, ou seja, se eu leio 5 na primeira linha, 5 é o meu 0;
  map<ll, ll> id; //guarda para o nó X qual o indice dele no array de indx, ou seja, se eu leio 5, eu sei que o indice dele no array de indx é 0;
  vector<ll> custo(n);//guarda no indice dele, qual o custo dele, como exemplo, temos o nó 5 , se eu aplico id[5] = 0, logo custo[id[5]] = custo do nó 5.
  for(ll i=0;i<n;i++){
    cin >> indx[i]; // 0:1
    cin >> custo[i]; //0:1
    id[indx[i]] = i; //1:0
  }

  vector<pair<ll,ll>> tempo(n, {-1,-1}); //guarda qual o indx do nó e quanto tempo ele vai ficar, ex: nó 5 tem index 0, logo na posição 0 do array, temos salvo quando tempo o 5 fica na festa.
  vector<char> escolha(n);// guarda no indx, qual foi a escolha dele, ou seja, nó 5, indx 0, ele escolheu A, D ou T ?
  vector<ll> adj(n, -1);//guarda no indx de quem ele depende, ou seja, em adj[0] , estamos representando 5, e estamos falando que ele depende da resposta do proximo nó, por exemplo 6, logo adj[id[5]] = id[6];
  // Leitura e construção da lista de adjacência
  for(ll i=0;i<n;i++){
    cin >> escolha[i];
    if(escolha[i] == 'A'){
      ll a, t; cin >> a >> t;
      tempo[i]={a,a+t};
    }else if(escolha[i] == 'T'){
      ll k; cin >> k;
      if(id.count(k)){
        adj[i] = id[k];
      }
    }
  }

  // chamada da dfs para cada nó.
  vector<int> estado(n,0);
  vector<pair<ll,ll>> resultado(n,{-1,-1});
  for(ll i=0;i<n;i++){
    dfs(
      i,
      escolha,
      adj,
      tempo,
      estado,
      resultado
    );
  }

  //Agora calcular de forma perfomática, quantos ficarão de forma simultânea.
  vector<pair<ll,ll>> eventos(n);
  for(ll i=0; i<n; i++){
    if(resultado[i].first == -1) continue;
    //evento de chegada = No minuto x, chegam custo[i] elementos
    eventos.push_back({resultado[i].first, custo[i]});
    // evento de saida = nom minuto y, saem custo[i] elementos
    eventos.push_back({resultado[i].second,-custo[i]});
  }

  //Ordeno os eventos
  sort(eventos.begin(), eventos.end());

  ll ans=0;
  ll temp = 0;
  // Calculo quantas pessoas em cada posição já calculando o valor máximo.
  for(auto e : eventos){
    temp += e.second;
    ans = max(ans, temp);
  }
  
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}