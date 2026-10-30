# Competitive Programming Notebook

Caderno pessoal de programação competitiva em C++. As soluções ficam agrupadas por rating do Codeforces, contest, ICPC, aula e avaliação.

Perfil de competição: [ICPC ID B9GB7UBU9KIC](https://icpc.global/ICPCID/B9GB7UBU9KIC). Participação na fase sub-regional de 2026.

## Plataformas

![Codeforces](https://img.shields.io/badge/Codeforces-marcuscspereira-1F8ACB?logo=codeforces&logoColor=white)

## Estrutura


| Pasta                                        | Conteúdo                                                         |
| -------------------------------------------- | ---------------------------------------------------------------- |
| `rating_800/`, `rating_900/`, `rating_1000/` | Problemas do Codeforces, um arquivo por questão                  |
| `contest/`                                   | Contests de diferentes Divs                                      |
| `streak-keeper/`                             | Problemas resolvidos para manter a streak                        |
| `ICPC/`                                      | Problemas de ICPC                                                |
| `aulas/`                                     | Exercícios de aula (STL, greedy, grafos, DP, teoria dos números) |
| `aulas/avaliacoes/`                                | Listas, warmups e provas                                         |
| `template.cpp`                               | Ponto de partida de I/O e macros                                 |


O nome de cada solução segue `nome_do_problema-id.cpp` quando o id da questão existe.

## Template

O arquivo usado em contest é o [template.cpp](template.cpp):

```cpp
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = false;

void solve(){

}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}
```

`many_cases` fica `true` quando o problema tem vários casos de teste.

## Ambiente

- **Linguagem:** C++17
- **Compilador:** `g++` (GCC)

Checagem local, com avisos:

```bash
g++ -Wall -Wextra -Wshadow -std=c++17 solution.cpp -o solution
```

Compilação no estilo de contest:

```bash
g++ -O2 -std=c++17 solution.cpp -o solution
```

## Cards de estudo

O método de leitura dos cadernos Goodnotes, o cursor de retomada e a preparação
dos cards para Anki ficam em [cards-estudo/README.md](cards-estudo/README.md).
Os cards autorais serão guardados nessa pasta; o histórico de revisão fica no Anki.

