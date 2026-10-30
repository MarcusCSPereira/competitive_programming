# Cards de revisão — lote histórico

69 cards autorais. Teoria, aplicação em C++17 e critérios de acerto.

Este arquivo deriva dos JSON em `../cards/`. O manifesto registra o envio ao Anki.

## Índice

- [cp-note-000001 — casa_dos_pombos](#cp-note-000001)
- [cp-note-000002 — construir_linked_list](#cp-note-000002)
- [cp-note-000003 — dijkstra_estados](#cp-note-000003)
- [cp-note-000004 — dijkstra_fila_obsoleta](#cp-note-000004)
- [cp-note-000005 — grafo_funcional_ciclos](#cp-note-000005)
- [cp-note-000006 — sweep_line_intervalos](#cp-note-000006)
- [cp-note-000007 — coordenadas_e_conjuntos](#cp-note-000007)
- [cp-note-000008 — palindromo_paridade](#cp-note-000008)
- [cp-note-000009 — somas_extremas_pa](#cp-note-000009)
- [cp-note-000010 — ganho_limitado_min](#cp-note-000010)
- [cp-note-000011 — xor_paridade_segmento](#cp-note-000011)
- [cp-note-000012 — intervalo_divisores](#cp-note-000012)
- [cp-note-000013 — ordenar_maior_bloco](#cp-note-000013)
- [cp-note-000014 — comparacoes_monotonas](#cp-note-000014)
- [cp-note-000015 — gcd_classes_de_indices](#cp-note-000015)
- [cp-note-000016 — prefix_sum_consultas](#cp-note-000016)
- [cp-note-000017 — greedy_invariante_prefixo](#cp-note-000017)
- [cp-note-000018 — classificar_rotacao](#cp-note-000018)
- [cp-note-000019 — mex_blocos_nao_nulos](#cp-note-000019)
- [cp-note-000020 — divisao_teto_limites](#cp-note-000020)
- [cp-note-000021 — greedy_direita_esquerda](#cp-note-000021)
- [cp-note-000022 — ultimas_ocorrencias](#cp-note-000022)
- [cp-note-000023 — dobramento_custo_fixo](#cp-note-000023)
- [cp-note-000024 — equacao_pa_multiplo](#cp-note-000024)
- [cp-note-000025 — periodicidade_modulo](#cp-note-000025)
- [cp-note-000026 — transicoes_extremidades](#cp-note-000026)
- [cp-note-000027 — sufixo_divisivel_25](#cp-note-000027)
- [cp-note-000028 — subconjuntos_zeros_uns](#cp-note-000028)
- [cp-note-000029 — and_remocao_bits](#cp-note-000029)
- [cp-note-000030 — gcd_diferenca_invariante](#cp-note-000030)
- [cp-note-000031 — manhattan_cantos_opostos](#cp-note-000031)
- [cp-note-000032 — potencia_dois_bits](#cp-note-000032)
- [cp-note-000033 — soma_tetos_agrupar](#cp-note-000033)
- [cp-note-000034 — maximizar_medianas](#cp-note-000034)
- [cp-note-000035 — pico_local_permutacao](#cp-note-000035)
- [cp-note-000036 — jogo_invariante_jogadas](#cp-note-000036)
- [cp-note-000037 — expoentes_primos_operacoes](#cp-note-000037)
- [cp-note-000038 — estoque_prefixo_binario](#cp-note-000038)
- [cp-note-000039 — divisibilidade_produto](#cp-note-000039)
- [cp-note-000040 — greedy_custo_capacidade](#cp-note-000040)
- [cp-note-000041 — concentrar_menores_valores](#cp-note-000041)
- [cp-note-000042 — resto_ordenacao_desempate](#cp-note-000042)
- [cp-note-000043 — contar_subarrays_blocos](#cp-note-000043)
- [cp-note-000044 — runs_por_valor_merge](#cp-note-000044)
- [cp-note-000045 — prefixo_sufixo_distintos](#cp-note-000045)
- [cp-note-000046 — divisores_em_pares](#cp-note-000046)
- [cp-note-000047 — minimo_lcm_soma_fixa](#cp-note-000047)
- [cp-note-000048 — proximo_evento_ciclo](#cp-note-000048)
- [cp-note-000049 — times_dois_ponteiros](#cp-note-000049)
- [cp-note-000050 — quocientes_restos_capacidade](#cp-note-000050)
- [cp-note-000051 — intersecao_intervalos_greedy](#cp-note-000051)
- [cp-note-000052 — rotacao_blocos_sem_fixos](#cp-note-000052)
- [cp-note-000053 — chars_ascii_conversao](#cp-note-000053)
- [cp-note-000054 — janela_fixa_contagem](#cp-note-000054)
- [cp-note-000055 — lru_arquitetura](#cp-note-000055)
- [cp-note-000056 — lista_dupla_sentinelas](#cp-note-000056)
- [cp-note-000057 — ponteiro_copia_referencia](#cp-note-000057)
- [cp-note-000058 — map_lookup_sem_inserir](#cp-note-000058)
- [cp-note-000059 — assinatura_anagramas](#cp-note-000059)
- [cp-note-000060 — topk_buckets](#cp-note-000060)
- [cp-note-000061 — limiar_blocos_restos](#cp-note-000061)
- [cp-note-000062 — prefixo_sufixo_exclusivos](#cp-note-000062)
- [cp-note-000063 — reusar_saida_prefixo](#cp-note-000063)
- [cp-note-000064 — serializacao_comprimento](#cp-note-000064)
- [cp-note-000065 — linearizar_coordenadas](#cp-note-000065)
- [cp-note-000066 — bitmask_presenca_sudoku](#cp-note-000066)
- [cp-note-000067 — inicializar_tipos_compostos](#cp-note-000067)
- [cp-note-000068 — fila_pilha_interfaces](#cp-note-000068)
- [cp-note-000069 — soma_listas_carry](#cp-note-000069)

## cp-note-000001

**Pergunta**

Como o princípio da casa dos pombos ajuda a distribuir r letras R entre b letras B, minimizando o maior bloco consecutivo de R? Explique como tratar o resto da divisão e implementar em C++.

**Resposta**

Os b separadores criam k = b + 1 espaços. Os R são os pombos e esses espaços são as casas.

Pelo princípio da casa dos pombos, algum espaço terá pelo menos ceil(r / k) elementos: se todos tivessem menos, não caberiam os r elementos. Esse é um limite inferior para o maior bloco.

Para atingir esse limite, cada espaço recebe r / k elementos, usando divisão inteira. Os r % k elementos restantes são distribuídos um por espaço. Assim, os tamanhos diferem em no máximo 1, e o maior bloco atinge exatamente o limite inferior.

Exemplo: r = 10, b = 3. Temos 4 espaços, base 2 e resto 2; os blocos ficam 3, 3, 2, 2. Uma saída é RRRBRRRBRRBRR; o maior bloco é 3. No problema original r > b, e os B podem ficar isolados nessa construção.

```cpp
string distribuir(int r, int b) {
    int grupos = b + 1;
    int base = r / grupos;
    int extras = r % grupos;

    string resposta;
    for (int i = 0; i < grupos; ++i) {
        int quantidade = base + (i < extras ? 1 : 0);
        resposta.append(quantidade, 'R');
        if (i < b) resposta += 'B';
    }
    return resposta;
}
```

**Complexidade:** O(r + b) de tempo, pois escreve cada caractere da saída; O(1) de espaço auxiliar além da string de saída, que ocupa O(r + b).

**Critérios de acerto**

- Explicar os b + 1 espaços e o limite inferior pela casa dos pombos.
- Distribuir quociente e resto e explicar o código.

**Fontes**

- [Red Versus Blue · problemas · páginas 98, 99](https://codeforces.com/problemset/problem/1659/A)

## cp-note-000002

**Pergunta**

Como percorrer uma linked list e construir outra com os mesmos valores, sem alterar a original? Explique o papel de head e actual, o avanço dos ponteiros e o retorno da lista em C++.

**Resposta**

Mantenha um ponteiro para percorrer a entrada e dois para construir a saída:

- head permanece fixo em um nó sentinela, antes do primeiro elemento real.
- actual aponta para o fim da lista criada; começa no sentinela.
- origem percorre os nós da lista original.

Para cada nó da entrada, crie um novo nó, conecte-o em actual->next e avance actual. Depois avance origem. Ao terminar, head->next é o início da nova lista. Salve esse ponteiro, libere o sentinela e retorne a lista.

Percorrer a entrada não cria a saída automaticamente: os dois avanços têm funções diferentes. O sentinela permite usar a mesma inserção inclusive para o primeiro nó. Se a entrada for vazia, head->next será nullptr.

Considere o ListNode simples do LeetCode, cujo construtor inicializa next como nullptr e cujo destrutor não apaga a cadeia. Copiar os valores é uma aplicação didática do padrão presente em Add Two Numbers. Na soma, cada valor criado é o dígito calculado; as entradas e o carry determinam a condição do laço.

```cpp
ListNode* copiarLista(const ListNode* origem) {
    ListNode* head = new ListNode(0); // sentinela fixo
    ListNode* actual = head;         // fim da nova lista

    while (origem != nullptr) {
        actual->next = new ListNode(origem->val);
        actual = actual->next;  // avança na lista criada
        origem = origem->next;  // avança na lista original
    }

    ListNode* resultado = head->next;
    delete head; // libera apenas o sentinela
    return resultado;
}
```

**Complexidade:** O(n) de tempo e O(1) de espaço auxiliar; os novos nós da saída ocupam O(n).

**Critérios de acerto**

- Manter head fixo e actual no fim da saída.
- Criar e conectar um novo nó a cada passo.
- Avançar separadamente entrada e saída e retornar head->next.

**Fontes**

- [Add Two Numbers · big-tech-problems · páginas 14](https://leetcode.com/problems/add-two-numbers/description/)

## cp-note-000003

**Pergunta**

Quando a possibilidade de usar uma aresta depende de quantos recursos já foram usados, por que dist[v] não basta? Como implementar Dijkstra com até K usos de uma alternativa?

**Resposta**

Duas chegadas ao mesmo vértice podem ter futuros diferentes: uma gastou o recurso e a outra ainda o possui. O estado deve guardar (v, usados), e a distância é dist[v][usados]. Uma aresta normal preserva usados; a alternativa consome mais um. Todos os pesos precisam ser não negativos. Como o limite é até K, a resposta é o mínimo entre todos os estados finais, não apenas dist[destino][K].

```cpp
struct Aresta { int v; long long normal, extra; };
long long menorCaminho(const vector<vector<Aresta>>& g, int K) {
    const long long INF = LLONG_MAX / 4;
    int n = g.size();
    vector<vector<long long>> d(n, vector<long long>(K+1, INF));
    using Estado = tuple<long long,int,int>;
    priority_queue<Estado, vector<Estado>, greater<Estado>> pq;
    d[0][0]=0; pq.push({0,0,0});
    while (!pq.empty()) {
        auto estado=pq.top(); pq.pop();
        long long c=get<0>(estado);
        int u=get<1>(estado),k=get<2>(estado);
        if (c!=d[u][k]) continue;
        for (auto e:g[u]) {
            auto relaxar = [&](int nk, long long peso) {
                if (c+peso<d[e.v][nk]) {
                    d[e.v][nk]=c+peso; pq.push({d[e.v][nk],e.v,nk});
                }
            };
            relaxar(k,e.normal);
            if (e.extra>=0 && k<K) relaxar(k+1,e.extra);
        }
    }
    return *min_element(d.back().begin(),d.back().end());
}
```

**Complexidade:** O((K+1)(V+E) log((K+1)V)) de tempo; dist ocupa O((K+1)V), além do grafo e da fila.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- Microwaves · problemas · páginas 45, 46

## cp-note-000004

**Pergunta**

Como usar priority_queue como min-heap e descartar propostas obsoletas no Dijkstra? Por que isso evita reprocessamento sem perder caminhos válidos?

**Resposta**

A fila guarda propostas de distância, não a distância definitiva de cada nó. Depois de melhorar dist[u], propostas antigas podem continuar na fila. Ao retirar uma proposta cuja distância difere de dist[u], descarte-a. greater transforma a priority_queue em min-heap. Com pesos não negativos, a menor proposta atual pode ser expandida com segurança.

```cpp
vector<long long> dijkstra(const vector<vector<pair<int,int>>>& g, int s) {
    vector<long long> d(g.size(),LLONG_MAX/4);
    using Item=pair<long long,int>;
    priority_queue<Item,vector<Item>,greater<Item>> pq;
    d[s]=0; pq.push({0,s});
    while(!pq.empty()) {
        auto [c,u]=pq.top(); pq.pop();
        if(c!=d[u]) continue;
        for(auto [v,w]:g[u]) if(c+w<d[v]) {
            d[v]=c+w; pq.push({d[v],v});
        }
    }
    return d;
}
```

**Complexidade:** O((V+E) log V) para grafo simples; O(V+E) de armazenamento incluindo propostas.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- Microwaves · problemas · páginas 45, 46

## cp-note-000005

**Pergunta**

Como detectar ciclos num grafo funcional usando três estados? Qual a diferença entre encontrar um nó em processamento e um nó já finalizado?

**Resposta**

Cada nó aponta para no máximo uma dependência; use -1 para término. Estado 0 significa não visto, 1 significa no caminho atual e 2 significa finalizado. Reencontrar estado 1 fecha um ciclo; chegar ao estado 2 apenas reutiliza uma cadeia já resolvida. A versão iterativa evita estourar a pilha em cadeias longas. Para propagar respostas de dependências, processe o caminho em ordem reversa depois de resolver seu fim.

```cpp
bool temCiclo(const vector<int>& prox) {
    vector<int> cor(prox.size(),0);
    for(int s=0;s<(int)prox.size();++s) {
        if(cor[s]) continue;
        vector<int> caminho; int u=s;
        while(u!=-1 && cor[u]==0) {
            cor[u]=1; caminho.push_back(u); u=prox[u];
        }
        if(u!=-1 && cor[u]==1) return true;
        for(int v:caminho) cor[v]=2;
    }
    return false;
}
```

**Complexidade:** O(V) de tempo e espaço, pois cada nó entra em um caminho uma vez.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- Porquinho da Índia · problemas · páginas 46, 47, 48

## cp-note-000006

**Pergunta**

Como encontrar o máximo de pessoas simultâneas em intervalos de presença sem percorrer cada minuto? Como tratar saída e entrada no mesmo instante?

**Resposta**

Converta cada intervalo semiaberto [chegada, saída) em dois eventos: +quantidade na chegada e -quantidade na saída. Ordene e acumule os deltas. Agrupar todos os deltas do mesmo instante aplica corretamente a convenção de que quem sai nesse instante já não ocupa espaço. Se a entrada fornece duração t, a saída é chegada+t. Não aloquem um vetor pelo maior horário: o custo depende da quantidade de eventos.

```cpp
long long pico(const vector<tuple<long long,long long,long long>>& presencas) {
    map<long long,long long> delta;
    for(auto [inicio,fim,qtd]:presencas) {
        if(inicio>=fim) continue;
        delta[inicio]+=qtd; delta[fim]-=qtd;
    }
    long long atual=0,maior=0;
    for(auto [tempo,mudanca]:delta) {
        (void)tempo; atual+=mudanca; maior=max(maior,atual);
    }
    return maior;
}
```

**Complexidade:** O(N log N) de tempo e O(N) de espaço.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- Porquinho da Índia · problemas · páginas 46, 47, 48

## cp-note-000007

**Pergunta**

Como gerar movimentos simétricos no plano e contar posições que alcançam dois alvos? Por que usar set quando os deslocamentos podem coincidir?

**Resposta**

Para cada alvo, gere as posições obtidas por (±a,±b) e (±b,±a). Como os movimentos são reversíveis, são também possíveis posições de origem. A resposta é a interseção dos conjuntos. Quando a=b, várias fórmulas produzem a mesma posição; set remove a duplicidade. Coordenadas podem ser negativas e devem usar tipo suficiente para a soma.

```cpp
using P=pair<long long,long long>;
set<P> origens(long long x,long long y,long long a,long long b) {
    set<P> s;
    for(int dx:{-1,1}) for(int dy:{-1,1}) {
        s.insert({x+dx*a,y+dy*b});
        s.insert({x+dx*b,y+dy*a});
    }
    return s;
}
int comuns(P rei,P rainha,long long a,long long b) {
    auto A=origens(rei.first,rei.second,a,b);
    auto B=origens(rainha.first,rainha.second,a,b);
    int total=0; for(auto p:A) total+=B.count(p);
    return total;
}
```

**Complexidade:** O(1) por caso: no máximo 8 posições por conjunto; espaço O(1).

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Forked! · problemas · páginas 48, 49, 50](https://codeforces.com/problemset/problem/1904/A)

## cp-note-000008

**Pergunta**

Qual propriedade das frequências permite reorganizar uma string em palíndromo? Como decidir se isso é possível após remover exatamente k caracteres?

**Resposta**

Os caracteres das duas metades formam pares; só o centro pode ter frequência ímpar. Portanto, sem remoções, há no máximo uma frequência ímpar. Cada remoção pode corrigir uma frequência ímpar. Para 0 <= k < n, a condição é impares <= k+1. O excedente de remoções pode ser absorvido por pares e pelo centro respeitando a paridade do tamanho final. Não é necessário construir todas as permutações.

```cpp
bool podePalindromo(const string& s,int k) {
    array<int,26> freq{};
    for(char c:s) ++freq[c-'a'];
    int impares=0;
    for(int f:freq) impares+=f%2;
    return impares<=k+1;
}
```

**Complexidade:** O(n+26) de tempo e O(26) de espaço; assume letras a-z e 0<=k<n.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Chemistry · problemas · páginas 50, 51](https://codeforces.com/problemset/problem/1883/B)

## cp-note-000009

**Pergunta**

Como decidir se a soma x pode ser formada por k inteiros distintos de 1 a n sem enumerar combinações? Derive os limites e implemente com tipos seguros.

**Resposta**

A soma mínima usa 1 até k: k(k+1)/2. A máxima usa n-k+1 até n: k(2n-k+1)/2. Para números consecutivos disponíveis, todas as somas entre os extremos são atingíveis: a partir da configuração mínima, distribua incrementos sem ultrapassar n nem repetir valores, um passo por vez. Assim basta testar o intervalo. A multiplicação precisa ocorrer em long long, não apenas ser atribuída a ele depois.

```cpp
bool somaPossivel(long long n,long long k,long long x) {
    if(k<1 || k>n) return false;
    long long minimo=k*(k+1)/2;
    long long maximo=k*(2*n-k+1)/2;
    return minimo<=x && x<=maximo;
}
```

**Complexidade:** O(1) de tempo e espaço, sob limites que cabem em 64 bits.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Vasilije in Cacak · problemas · páginas 52](https://codeforces.com/problemset/problem/1878/C)

## cp-note-000010

**Pergunta**

Num contador que explode em zero e tem capacidade a, por que uma recarga x contribui no máximo min(x,a-1)? Como maximizar o tempo total sem simular cada segundo?

**Resposta**

Espere o contador chegar a 1 antes de usar cada recarga. Não pode esperar zero, pois a explosão já ocorreu. A capacidade disponível é a-1, portanto o ganho é min(x,a-1). Usar antes só reduz a capacidade disponível e não melhora o resultado. Some os ganhos ao valor inicial b; o contador pode ter duração enorme, mas só precisamos percorrer a lista de recargas.

```cpp
long long tempoMaximo(long long a,long long b,const vector<long long>& cargas) {
    long long total=b;
    for(long long x:cargas) total+=min(x,a-1);
    return total;
}
```

**Complexidade:** O(N) de tempo e O(1) de espaço auxiliar.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Jellyfish and Undertale · problemas · páginas 53](https://codeforces.com/problemset/problem/1875/A)

## cp-note-000011

**Pergunta**

Por que aplicar duas vezes a operação de substituir um segmento pelo XOR de seus valores zera um segmento de comprimento par? Como lidar com comprimento ímpar?

**Resposta**

Na primeira operação, todos os elementos viram o mesmo XOR x. Na segunda, o XOR de uma quantidade par de cópias de x é zero, porque x^x=0. Para n ímpar, zere [1,n-1] com duas operações e depois [n-1,n], também de comprimento par. A sobreposição não desfaz o prefixo já zerado. Essa construção usa no máximo quatro operações.

```cpp
vector<pair<int,int>> operacoesZero(int n) {
    if(n%2==0) return {{1,n},{1,n}};
    return {{1,n-1},{1,n-1},{n-1,n},{n-1,n}};
}
```

**Complexidade:** O(1) para emitir os intervalos; simular as operações custa O(n). Assume n>=2.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Make It Zero · problemas · páginas 54](https://codeforces.com/problemset/problem/1869/A)

## cp-note-000012

**Pergunta**

Por que procurar divisores consecutivos começando em 1 resolve o maior intervalo de divisores de n? Qual argumento evita testar todos os intervalos?

**Resposta**

Em qualquer intervalo de comprimento L existe um múltiplo de cada d entre 1 e L. Se todos os números desse intervalo dividem n, então cada d também divide n. Logo [1,L] também é válido. Assim, encontre o primeiro inteiro que não divide n e devolva o anterior. O laço termina cedo para n limitado: n precisa ser múltiplo de lcm(1,...,L). Não é correto justificar o limite usando apenas produto de primos ou decorar 43.

```cpp
int maiorIntervalo(long long n) {
    int d=1;
    while(n%d==0) ++d;
    return d-1;
}
```

**Complexidade:** O(L), onde L é o tamanho da resposta; O(1) de espaço. Para n<=1e18, L<=42.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Longest Divisors Interval · problemas · páginas 55](https://codeforces.com/problemset/problem/1855/B)

## cp-note-000013

**Pergunta**

Como minimizar remoções quando podemos reordenar um array e exigimos diferença de no máximo k entre vizinhos? Por que ordenar e manter o maior bloco funciona?

**Resposta**

Ordene os valores. Uma diferença maior que k separa componentes que não podem ser conectadas: não há elemento intermediário disponível. Dentro de cada bloco com diferenças adjacentes <=k, a ordem crescente já satisfaz a regra. Mantenha o maior bloco e remova o restante. A condição é sobre vizinhos, não sobre máximo-mínimo do bloco.

```cpp
int remocoes(vector<long long> a,long long k) {
    if(a.empty()) return 0;
    sort(a.begin(),a.end());
    int atual=1,melhor=1;
    for(int i=1;i<(int)a.size();++i){
        atual=(a[i]-a[i-1]<=k ? atual+1 : 1);
        melhor=max(melhor,atual);
    }
    return (int)a.size()-melhor;
}
```

**Complexidade:** O(n log n) de tempo; o trecho recebe cópia O(n), varredura usa O(1) auxiliar.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Balanced Round · problemas · páginas 55, 56](https://codeforces.com/problemset/problem/1850/D)

## cp-note-000014

**Pergunta**

Como a maior sequência de sinais iguais numa string de < e > determina o mínimo de valores distintos necessários para satisfazer as comparações?

**Resposta**

Uma sequência de L sinais iguais impõe uma cadeia estritamente crescente ou decrescente com L+1 valores distintos. Isso dá um limite inferior. Ele é suficiente: ao mudar a direção, podemos reutilizar níveis, atribuindo a cada posição um nível compatível com as cadeias monotônicas incidentes. Portanto a resposta é a maior sequência de sinais iguais mais 1. Não é preciso tentar valores do array.

```cpp
int niveis(const string& s) {
    int atual=0,melhor=0; char anterior=0;
    for(char c:s){
        atual=(c==anterior ? atual+1 : 1);
        melhor=max(melhor,atual); anterior=c;
    }
    return melhor+1;
}
```

**Complexidade:** O(n) de tempo e O(1) de espaço.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Comparison String · problemas · páginas 56, 57](https://codeforces.com/problemset/problem/1837/B)

## cp-note-000015

**Pergunta**

Se só podemos trocar posições cuja distância é exatamente k, quais posições continuam conectadas? Como usar isso para achar o maior k que ordena uma permutação?

**Resposta**

Trocas de distância k mantêm cada elemento na mesma classe de índice módulo k. Em cada classe, trocas adjacentes no caminho permitem qualquer permutação. Portanto k deve dividir todos os deslocamentos entre posição atual e posição final. O maior k válido é o gcd desses deslocamentos. Zeros não atrapalham: gcd(0,d)=d. O problema garante permutação inicialmente não ordenada.

```cpp
int maiorPasso(const vector<int>& p) {
    int g=0;
    for(int i=0;i<(int)p.size();++i)
        g=gcd(g,abs(p[i]-(i+1)));
    return g;
}
```

**Complexidade:** O(n log n) como limite seguro para os gcds; O(1) de espaço.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Permutation Swap · problemas · páginas 57, 58](https://codeforces.com/problemset/problem/1828/B)

## cp-note-000016

**Pergunta**

Como pré-computar somas ou contagens de um intervalo e responder consultas em O(1)? Como avaliar substituir [l,r] por k sem modificar o array a cada consulta?

**Resposta**

Defina pref[i] como a soma dos primeiros i elementos; pref[0]=0. Em índices base 1, a soma de [l,r] é pref[r]-pref[l-1]. A soma após a substituição é total-somaAntiga+(r-l+1)*k. Cada consulta usa o array original, portanto não atualize os prefixos. Para contar um predicado, some 1 quando ele é verdadeiro: o mesmo padrão conta W em cada janela de Black and White Stripe.

```cpp
vector<long long> prefixos(const vector<long long>& a) {
    vector<long long> p(a.size()+1,0);
    for(int i=0;i<(int)a.size();++i) p[i+1]=p[i]+a[i];
    return p;
}
long long substituir(const vector<long long>& p,int l,int r,long long k) {
    return p.back()-(p[r]-p[l-1])+1LL*(r-l+1)*k;
}
```

**Complexidade:** O(n) de pré-processamento, O(1) por consulta e O(n) de espaço.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Odd Queries · problemas · páginas 58, 59](https://codeforces.com/problemset/problem/1807/D)
- [Black and White Stripe · problemas · páginas 97, 98](https://codeforces.com/problemset/problem/1690/D)

## cp-note-000017

**Pergunta**

Como construir um array com a[i+1] não divisível por a[i], usando apenas incrementos? Por que percorrer da esquerda para a direita preserva o que já foi corrigido?

**Resposta**

Primeiro elimine o valor 1, pois ele divide todos os inteiros. Depois percorra da esquerda para a direita. Se o próximo valor for múltiplo do atual, incremente o próximo uma vez. Como o divisor é pelo menos 2, dois inteiros consecutivos não podem ser ambos múltiplos dele. Cada passo fixa o par à esquerda e nunca volta a mudar esse prefixo. São no máximo n incrementos para eliminar 1 e n-1 para ajustar pares.

```cpp
vector<int> ajustar(vector<int> a) {
    for(int& x:a) if(x==1) ++x;
    for(int i=0;i+1<(int)a.size();++i)
        if(a[i+1]%a[i]==0) ++a[i+1];
    return a;
}
```

**Complexidade:** O(n) de tempo e O(1) auxiliar além do array retornado; valores positivos.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Not Dividing · problemas · páginas 59, 60](https://codeforces.com/problemset/problem/1794/B)

## cp-note-000018

**Pergunta**

Como reduzir a maximização de último-primeiro após uma rotação cíclica de um segmento a três casos lineares?

**Resposta**

Se a rotação não envolve a primeira posição, o primeiro valor continua a[0], e escolhemos o melhor valor para o fim. Se não envolve a última, preservamos a[n-1] e escolhemos o menor primeiro. Se envolve as duas extremidades, o segmento é o array inteiro: o novo fim e o novo início eram vizinhos, e o candidato é a[i]-a[i+1]. Esses casos cobrem todas as posições do segmento; para n=1 a resposta é zero.

```cpp
long long melhorDiferenca(const vector<long long>& a) {
    int n=a.size(); long long ans=a.back()-a.front();
    for(int i=1;i<n;++i) ans=max(ans,a[i]-a.front());
    for(int i=0;i+1<n;++i){
        ans=max(ans,a.back()-a[i]);
        ans=max(ans,a[i]-a[i+1]);
    }
    return ans;
}
```

**Complexidade:** O(n) de tempo e O(1) de espaço; array não vazio.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Mainak and Array · problemas · páginas 60, 61](https://codeforces.com/problemset/problem/1726/A)

## cp-note-000019

**Pergunta**

Como usar os blocos de valores não nulos para zerar um array com operações de substituir um intervalo pelo seu MEX? Por que a resposta nunca precisa exceder 2?

**Resposta**

Sem valores não nulos, nada é necessário. Um único bloco não nulo não contém zero, então seu MEX é zero e uma operação basta. Com vários blocos, qualquer intervalo que cubra todos inclui zero; seu MEX será positivo, formando um único bloco não nulo. A segunda operação o transforma em zero. Logo a resposta é min(2, quantidade de blocos).

```cpp
int zerarComMex(const vector<int>& a) {
    int blocos=0; bool dentro=false;
    for(int x:a){
        if(x==0) dentro=false;
        else if(!dentro){ ++blocos; dentro=true; }
    }
    return min(2,blocos);
}
```

**Complexidade:** O(n) de tempo e O(1) de espaço.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [NIT Destroys the Universe · problemas · páginas 61, 62](https://codeforces.com/problemset/problem/1696/B)

## cp-note-000020

**Pergunta**

Como calcular divisão inteira com teto sem ponto flutuante e usar limites de capacidade para obter quantidades mínimas e máximas?

**Resposta**

Para a>=0 e b>0, ceil(a/b)=a/b+(a%b!=0). Essa forma evita overflow de a+b-1. Com ônibus de 4 ou 6 rodas, um total n é possível se n é par e n>=4. O mínimo é ceil(n/6) e o máximo floor(n/4); a mistura de 4 e 6 permite ajustar as sobras. Em agrupamentos gerais, somar antes de aplicar teto nunca aumenta o resultado: ceil((x+y)/d)<=ceil(x/d)+ceil(y/d).

```cpp
long long ceilDiv(long long a,long long b) {
    return a/b+(a%b!=0);
}
pair<long long,long long> onibus(long long n) {
    if(n<4 || n%2) return {-1,-1};
    return {ceilDiv(n,6),n/4};
}
```

**Complexidade:** O(1) de tempo e espaço; a>=0 e b>0.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [AvtoBus · problemas · páginas 62, 63](https://codeforces.com/problemset/problem/1679/A)
- [Strange Partition · problemas · páginas 75, 76](https://codeforces.com/problemset/problem/1471/A)

## cp-note-000021

**Pergunta**

Por que, ao tornar um array estritamente crescente usando divisões por 2, devemos decidir da direita para a esquerda? Como reconhecer impossibilidade?

**Resposta**

A operação só reduz valores. Preserve o elemento à direita tão grande quanto possível para não restringir desnecessariamente os anteriores. Para cada posição, reduza apenas até ficar menor que a seguinte. Isso usa o mínimo de divisões necessário com o sufixo já fixo. Se o valor à direita é zero, nenhum valor não negativo à esquerda pode ser menor: é impossível. O primeiro elemento pode ser zero sem problema.

```cpp
int tornarCrescente(vector<long long> a) {
    int ops=0;
    for(int i=(int)a.size()-2;i>=0;--i){
        if(a[i+1]==0) return -1;
        while(a[i]>=a[i+1]){ a[i]/=2; ++ops; }
    }
    return ops;
}
```

**Complexidade:** O(n log(A+1)) de tempo; cópia do array O(n).

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Make It Increasing · problemas · páginas 63, 64](https://codeforces.com/problemset/problem/1675/B)

## cp-note-000022

**Pergunta**

Se só podemos apagar a primeira ocorrência de uma letra, quais ocorrências podem permanecer? Como verificar um alvo sem simular todas as remoções?

**Resposta**

Para cada letra, as ocorrências que sobrevivem devem ser as últimas: não é possível apagar uma ocorrência posterior mantendo uma anterior da mesma letra. Conte quantas de cada letra o alvo precisa. Varra a origem da direita para a esquerda e preserve só as últimas quantidades necessárias. Depois compare a ordem obtida com o alvo: frequências corretas sozinhas não garantem a ordem correta.

```cpp
bool editar(const string& s,const string& t) {
    array<int,26> falta{};
    for(char c:t) ++falta[c-'A'];
    string mantida;
    for(int i=(int)s.size()-1;i>=0;--i){
        int c=s[i]-'A';
        if(falta[c]>0){ mantida+=s[i]; --falta[c]; }
    }
    reverse(mantida.begin(),mantida.end());
    return mantida==t;
}
```

**Complexidade:** O(|s|+|t|) de tempo; O(|t|+26) de espaço; letras A-Z.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Deletive Editing · problemas · páginas 64, 65](https://codeforces.com/problemset/problem/1666/D)

## cp-note-000023

**Pergunta**

Como separar o custo de trocar elementos do custo de clonar arrays para uniformizar um array? Por que começar pelo valor mais frequente é ótimo?

**Resposta**

Se o valor escolhido aparece f vezes, no mínimo n-f posições precisam mudar. Clonar um array com c cópias desse valor oferece no máximo c novas cópias utilizáveis; após as trocas úteis, a quantidade dobra até n. Começar com a maior frequência minimiza tanto as trocas quanto as clonagens. Some separadamente n-f e o número de duplicações necessárias.

```cpp
int custoUniformizar(const vector<int>& a) {
    unordered_map<int,int> freq; int f=0;
    for(int x:a) f=max(f,++freq[x]);
    int n=a.size(),ops=n-f;
    while(f<n){ ++ops; f=min(n,2*f); }
    return ops;
}
```

**Complexidade:** O(n) esperado para frequências e O(log n) duplicações; O(n) de espaço; array não vazio.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Array Cloning Technique · problemas · páginas 65, 66](https://codeforces.com/problemset/problem/1665/B)

## cp-note-000024

**Pergunta**

Como transformar a condição de três números em progressão aritmética numa checagem O(1) ao multiplicar exatamente um deles por um inteiro positivo?

**Resposta**

Uma PA satisfaz a+c=2b. Isole o valor novo para cada escolha: aNovo=2b-c, bNovo=(a+c)/2, cNovo=2b-a. O valor novo deve ser positivo e múltiplo inteiro do valor original. Para o termo central, a+c também precisa ser par. Testar as três possibilidades evita escolher um caso por intuição sem cobrir os outros.

```cpp
bool fazerPA(long long a,long long b,long long c) {
    auto multiplo=[](long long novo,long long antigo){
        return novo>0 && novo%antigo==0;
    };
    return multiplo(2*b-c,a)
        || ((a+c)%2==0 && multiplo((a+c)/2,b))
        || multiplo(2*b-a,c);
}
```

**Complexidade:** O(1) de tempo e espaço; a,b,c positivos e intermediários cabem em long long.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Make AP · problemas · páginas 66, 67, 68](https://codeforces.com/problemset/problem/1624/B)

## cp-note-000025

**Pergunta**

Como reconhecer um padrão periódico para evitar simular até 10^14 passos? Aplique ao movimento: passo i vai à esquerda se a posição é par, à direita se é ímpar.

**Resposta**

Simule poucos passos simbolicamente a partir de uma posição par: os deslocamentos para n mod 4 iguais a 0,1,2,3 são 0,-n,1,n+1. Quatro passos restauram o deslocamento zero; isso permite agrupar ciclos. Começar numa posição ímpar inverte os sinais. Em C++, para números negativos, use x%2==0 para detectar paridade; não suponha que o resto ímpar seja sempre 1.

```cpp
long long posicao(long long x,long long n) {
    long long d=0;
    if(n%4==1) d=-n;
    if(n%4==2) d=1;
    if(n%4==3) d=n+1;
    return x+(x%2==0 ? d : -d);
}
```

**Complexidade:** O(1) de tempo e espaço; valores finais devem caber em 64 bits.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Odd Grasshopper · problemas · páginas 68, 69](https://codeforces.com/problemset/problem/1607/B)

## cp-note-000026

**Pergunta**

Por que a diferença entre o número de substrings adjacentes ab e ba depende só do primeiro e último caracteres? Como equilibrar uma string binária com o mínimo de mudanças?

**Resposta**

Associe a=0 e b=1. Cada transição ab soma +1 e cada ba soma -1; aa e bb somam zero. A soma das diferenças consecutivas cancela os valores internos e resulta no último menos o primeiro. Logo ab=ba exatamente quando as extremidades são iguais. Se diferem, uma mudança numa extremidade é suficiente e necessária.

```cpp
string equilibrar(string s) {
    if(!s.empty()) s.back()=s.front();
    return s;
}
```

**Complexidade:** O(1) para alterar a extremidade; receber e retornar uma string por valor custa O(n).

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [AB Balance · problemas · páginas 69, 70](https://codeforces.com/problemset/problem/1606/A)

## cp-note-000027

**Pergunta**

Como minimizar remoções de dígitos para tornar um número divisível por 25 sem testar todas as subsequências?

**Resposta**

Um número positivo divisível por 25 termina em 00,25,50 ou 75. Para cada sufixo, procure o último dígito da direita para a esquerda e depois o penúltimo antes dele. Preserve todo o prefixo anterior: apenas o que está entre os dois dígitos e depois deles precisa sair. Pegar a ocorrência mais à direita deixa o máximo de posições disponíveis e minimiza remoções. A fonte garante existir uma solução positiva; não generalize para entrada sem solução silenciosamente.

```cpp
int remover25(const string& s) {
    int n=s.size(),ans=n;
    for(string fim:{"00","25","50","75"}){
        int j=n-1; while(j>=0 && s[j]!=fim[1]) --j;
        if(j<0) continue;
        int i=j-1; while(i>=0 && s[i]!=fim[0]) --i;
        if(i>=0) ans=min(ans,n-i-2);
    }
    return ans;
}
```

**Complexidade:** O(4D)=O(D) de tempo, D é o número de dígitos; O(1) auxiliar.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Make It Divisible by 25 · problemas · páginas 70, 71](https://codeforces.com/problemset/problem/1593/B)

## cp-note-000028

**Pergunta**

Quando um array tem soma S, como contar subsequências por índices cuja soma é S-1? Por que zeros multiplicam possibilidades e como evitar pow com ponto flutuante?

**Resposta**

Considere os elementos que ficam de fora: sua soma precisa ser 1. Como todos os valores são não negativos, devemos excluir exatamente um 1, qualquer subconjunto de zeros e nenhum valor maior. São quantidadeDeUns * 2^quantidadeDeZeros escolhas. Subsequências são contadas pelas posições, mesmo com valores repetidos. Use aritmética inteira; sob n<=60 o resultado cabe em unsigned long long e o shift é válido.

```cpp
unsigned long long contarSubsequencias(const vector<int>& a) {
    int zeros=0,uns=0;
    for(int x:a){ zeros+=(x==0); uns+=(x==1); }
    return (unsigned long long)uns*(1ULL<<zeros);
}
```

**Complexidade:** O(n) de tempo e O(1) de espaço; n<=60, valores não negativos.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Luntik and Subsequences · problemas · páginas 71, 72](https://codeforces.com/problemset/problem/1582/B)

## cp-note-000029

**Pergunta**

Por que combinar valores com AND nunca cria bits e como isso ajuda a encontrar o menor valor atingível por operações de AND em um array?

**Resposta**

Um bit só fica 1 no AND se todos os operandos tiverem esse bit. Portanto x&y<=x e x&y<=y para inteiros não negativos. Associatividade e comutatividade permitem acumular o AND de todos os elementos. No problema, uma operação pode espalhar esse AND ao array inteiro; nenhum resultado pode perder um bit que já era 1 em todos os elementos. Assim o AND global é o limite atingível.

```cpp
int andGlobal(const vector<int>& a) {
    int ans=a.front();
    for(int x:a) ans&=x;
    return ans;
}
```

**Complexidade:** O(n) de tempo e O(1) de espaço; array não vazio de inteiros não negativos.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Mocha and Math · problemas · páginas 72](https://codeforces.com/problemset/problem/1559/A)

## cp-note-000030

**Pergunta**

Se uma operação soma 1 aos dois números ou subtrai 1 dos dois, qual invariante limita o maior gcd? Como obter o mínimo de passos para alcançá-lo?

**Resposta**

A diferença d=|a-b| não muda. Todo divisor comum divide a diferença, então o gcd não excede d. Se a!=b, é possível tornar ambos múltiplos de d. O resto r=a%d mede a distância ao múltiplo inferior; d-r mede a distância ao superior. Escolha min(r,d-r). Se a=b, o gcd pode crescer sem limite e a convenção do problema é retornar 0,0.

```cpp
pair<long long,long long> aposta(long long a,long long b) {
    long long d=llabs(a-b);
    if(d==0) return {0,0};
    long long r=a%d;
    return {d,min(r,d-r)};
}
```

**Complexidade:** O(1) de tempo e espaço; entradas não negativas.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Exciting Bets · problemas · páginas 73, 74](https://codeforces.com/problemset/problem/1543/A)

## cp-note-000031

**Pergunta**

Como usar a distância Manhattan para escolher duas posições numa grade e maximizar o menor passeio que sai de uma posição, visita as duas e retorna?

**Resposta**

Na grade sem obstáculos, d((x,y),(u,v))=|x-u|+|y-v|. Escolha cantos opostos (1,1) e (n,m). Para qualquer início dentro da grade, a soma das distâncias aos dois cantos é n+m-2; a distância entre eles também é n+m-2. O passeio total vale 2(n+m-2). Qualquer triângulo de pontos da grade tem perímetro Manhattan no máximo esse valor, separando as contribuições de linhas e colunas.

```cpp
array<long long,4> cantos(long long n,long long m) {
    return {1,1,n,m};
}
long long manhattan(long long x,long long y,long long u,long long v){
    return llabs(x-u)+llabs(y-v);
}
```

**Complexidade:** O(1) de tempo e espaço.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Bad Boy · problemas · páginas 74, 75](https://codeforces.com/problemset/problem/1537/B)

## cp-note-000032

**Pergunta**

Como reconhecer uma potência de dois com bits e relacionar isso à existência de divisor ímpar maior que 1? Quais cuidados de sintaxe são necessários?

**Resposta**

Para n positivo, uma potência de dois tem exatamente um bit 1. Ao subtrair 1, esse bit vira zero e os inferiores viram 1; logo n&(n-1)==0 somente nesse caso. Um n positivo possui divisor ímpar >1 se, ao retirar todos os fatores 2, sobrar algo maior que 1; equivale a não ser potência de dois. Verifique n>0 e use parênteses, pois a precedência de == em C++ muda a interpretação sem eles.

```cpp
bool potenciaDeDois(unsigned long long n) {
    return n>0 && ((n & (n-1))==0);
}
bool divisorImpar(unsigned long long n) {
    return n>1 && !potenciaDeDois(n);
}
```

**Complexidade:** O(1) para inteiros de tamanho fixo; O(1) de espaço.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Odd Divisor · problemas · páginas 75](https://codeforces.com/problemset/problem/1475/A)

## cp-note-000033

**Pergunta**

Por que agrupar valores antes de aplicar ceil(soma/x) minimiza o resultado, enquanto mantê-los separados maximiza? Como calcular os dois extremos?

**Resposta**

Para valores não negativos, ceil((a+b)/x)<=ceil(a/x)+ceil(b/x): arredondar separadamente pode pagar duas sobras que juntas caberiam no mesmo grupo. Repetindo a desigualdade, unir tudo dá o mínimo e manter todos separados dá o máximo. Some em 64 bits e use divisão inteira com teto, sem converter para double.

```cpp
pair<long long,long long> extremos(const vector<long long>& a,long long x) {
    long long soma=0,maior=0;
    for(long long v:a){ soma+=v; maior+=v/x+(v%x!=0); }
    long long menor=soma/x+(soma%x!=0);
    return {menor,maior};
}
```

**Complexidade:** O(n) de tempo e O(1) de espaço.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Strange Partition · problemas · páginas 75, 76](https://codeforces.com/problemset/problem/1471/A)

## cp-note-000034

**Pergunta**

Como maximizar a soma das medianas ao dividir nk valores já ordenados em k grupos de tamanho n? Como descobrir o salto do ponteiro a partir da definição da mediana?

**Resposta**

A mediana está na posição ceil(n/2), base 1: para n par é a mediana inferior. Cada mediana precisa de floor(n/2) elementos maiores ou iguais à sua direita no grupo. Reserve esses elementos a partir do fim e escolha o próximo como mediana. Repita com salto floor(n/2)+1. Os menores elementos restantes preenchem a parte esquerda dos grupos. O argumento greedy evita gastar um candidato grande na parte inferior de um grupo.

```cpp
long long somarMedianas(const vector<long long>& a,int n,int k) {
    int pos=a.size(),salto=n/2+1;
    long long soma=0;
    for(int grupo=0;grupo<k;++grupo){ pos-=salto; soma+=a[pos]; }
    return soma;
}
```

**Complexidade:** O(k) após ler os nk valores; O(nk) incluindo leitura e armazenamento. Array previamente ordenado.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Sum of Medians · problemas · páginas 76, 77](https://codeforces.com/problemset/problem/1440/B)

## cp-note-000035

**Pergunta**

Por que, numa permutação, basta procurar um pico local adjacente para encontrar i<j<k com a[i]<a[j]>a[k]? Como implementar sem três laços?

**Resposta**

Se uma tripla assim existe, em algum ponto o percurso de valores precisa subir e depois descer. Como os elementos da permutação são distintos, uma mudança de subida para descida produz um pico estrito adjacente. Se não há pico, não há esse padrão. A propriedade depende de os valores serem distintos; platôs em arrays gerais exigem outra análise.

```cpp
vector<int> picoLocal(const vector<int>& a) {
    for(int j=1;j+1<(int)a.size();++j)
        if(a[j-1]<a[j] && a[j]>a[j+1]) return {j,j+1,j+2};
    return {};
}
```

**Complexidade:** O(n) de tempo e O(1) de espaço auxiliar; índices de saída base 1.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Three Indices · problemas · páginas 77, 78](https://codeforces.com/problemset/problem/1380/A)

## cp-note-000036

**Pergunta**

Num jogo que remove dois bits adjacentes diferentes de uma string, por que basta contar zeros e uns para saber quem vence?

**Resposta**

Cada jogada remove exatamente um zero e um um. Enquanto ambos existem, há uma fronteira entre caracteres diferentes e alguma jogada é possível. Portanto toda partida tem exatamente min(zeros,uns) jogadas, independentemente das escolhas. Quem começa vence se esse número é ímpar. A estratégia ótima deixa de importar depois que o invariante fixa a duração do jogo.

```cpp
bool primeiroVence(const string& s) {
    int z=count(s.begin(),s.end(),'0');
    int u=(int)s.size()-z;
    return min(z,u)%2==1;
}
```

**Complexidade:** O(n) de tempo e O(1) de espaço; string binária.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [01 Game · problemas · páginas 78](https://codeforces.com/problemset/problem/1373/B)

## cp-note-000037

**Pergunta**

Como analisar operações multiplicar por 2 e dividir por 6 usando expoentes primos? Quando é impossível chegar a 1 e qual o número mínimo de operações?

**Resposta**

Escreva n=2^a*3^b*resto. Dividir por 6 remove um fator 2 e um 3; multiplicar por 2 acrescenta apenas um fator 2. Um primo diferente de 2 ou 3 nunca desaparece. Também é impossível quando a>b, pois faltam fatores 3 para remover todos os fatores 2. Se a<=b, use b-a multiplicações por 2 e b divisões por 6: total 2b-a. Conte os fatores, não simule escolhas.

```cpp
int reduzirUm(long long n) {
    int a=0,b=0;
    while(n%2==0){ n/=2; ++a; }
    while(n%3==0){ n/=3; ++b; }
    if(n!=1 || a>b) return -1;
    return 2*b-a;
}
```

**Complexidade:** O(log n) de tempo e O(1) de espaço; n>=1.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Multiply by 2, Divide by 6 · problemas · páginas 78, 79](https://codeforces.com/problemset/problem/1374/B)

## cp-note-000038

**Pergunta**

Quando podemos trocar bits livremente e apagar cada caractere por custo 1, como obter o maior prefixo que pode ser substituído por bits opostos aos da string original?

**Resposta**

Trocas gratuitas tornam relevante apenas o estoque de zeros e uns. Varra a referência original da esquerda para a direita e consuma um bit oposto para cada posição. Quando o estoque necessário acabar, nenhum resultado mais longo poderá satisfazer esse prefixo. Apague o restante; o custo mínimo é n-comprimentoViável. Frequências permitem simular a disponibilidade sem executar trocas.

```cpp
int custoApagar(const string& s) {
    array<int,2> qtd{}; for(char c:s) ++qtd[c-'0'];
    int usados=0;
    for(char c:s){
        int precisa=1-(c-'0');
        if(qtd[precisa]==0) break;
        --qtd[precisa]; ++usados;
    }
    return (int)s.size()-usados;
}
```

**Complexidade:** O(n) de tempo e O(1) de espaço.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Swap and Delete · problemas · páginas 79, 80](https://codeforces.com/problemset/problem/1913/B)

## cp-note-000039

**Pergunta**

Por que tornar um produto divisível por um primo é diferente de torná-lo divisível por 4? Como minimizar incrementos para k entre 2 e 5?

**Resposta**

Para k primo, basta que algum fator se torne múltiplo de k: o custo é o mínimo de (k-a[i]%k)%k. Para k=4, o produto também pode ganhar os dois fatores 2 em elementos diferentes. Além de tornar um elemento múltiplo de 4, considere obter dois pares: se já há dois, custo 0; um, custo 1; nenhum, custo 2. Compare as alternativas e não multiplique todo o array, pois pode estourar.

```cpp
int incrementosProduto(const vector<int>& a,int k) {
    int melhor=k,pares=0;
    for(int x:a){
        melhor=min(melhor,(k-x%k)%k);
        pares+=(x%2==0);
    }
    if(k==4) melhor=min(melhor,max(0,2-pares));
    return melhor;
}
```

**Complexidade:** O(n) de tempo e O(1) de espaço; 2<=k<=5 e n>=2.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Raspberries · problemas · páginas 80, 81](https://codeforces.com/problemset/problem/1883/C)

## cp-note-000040

**Pergunta**

Como minimizar o custo de espalhar informação quando uma fonte cobra p por pessoa e cada pessoa informada pode compartilhar por custo e capacidade próprios?

**Resposta**

É preciso ativar pelo menos uma pessoa pelo custo p. Ordene as opções por custo de compartilhamento e use primeiro as mais baratas que p, limitando cada uma pela capacidade e pelo número ainda não informado. Podemos escolher a primeira pessoa e a ordem de ativações para disponibilizar cada próximo compartilhador barato: informar alguém já dá acesso à capacidade dessa pessoa. Custos >=p não oferecem vantagem sobre a fonte original. O argumento de troca substitui um compartilhamento caro por um barato disponível sem reduzir capacidade útil.

```cpp
long long informar(int n,long long p,vector<pair<long long,long long>> opcoes) {
    sort(opcoes.begin(),opcoes.end()); // {custo, capacidade}
    long long total=p; int faltam=n-1;
    for(auto [custo,cap]:opcoes){
        if(custo>=p || faltam==0) break;
        int usar=(int)min<long long>(cap,faltam);
        total+=usar*custo; faltam-=usar;
    }
    return total+faltam*p;
}
```

**Complexidade:** O(n log n) de tempo; o vetor de opções ocupa O(n). Assume n>=1 e capacidades positivas.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Helmets in Night Light · problemas · páginas 82, 83](https://codeforces.com/problemset/problem/1876/A)

## cp-note-000041

**Pergunta**

Como maximizar a soma dos mínimos de vários arrays quando cada array pode enviar no máximo um elemento para outro? Por que os dois menores de cada array são suficientes?

**Resposta**

Se um array envia seu menor elemento, seu novo mínimo no máximo chega ao segundo menor. Um array receptor pode concentrar todos os menores enviados; ele paga a perda correspondente ao menor global, em vez de desperdiçar melhorias em vários receptores. Escolha como receptor o array com o menor segundo mínimo. A soma ótima é soma(segundos)-min(segundos)+menorGlobal. Cada array deve ter pelo menos dois elementos; repetições contam como posições distintas.

```cpp
long long somaMinimos(const vector<vector<long long>>& arrays) {
    long long soma=0,menor=LLONG_MAX,segundoMenor=LLONG_MAX;
    for(auto a:arrays){
        nth_element(a.begin(),a.begin()+1,a.end());
        long long primeiro=min(a[0],a[1]),segundo=a[1];
        menor=min(menor,primeiro); segundoMenor=min(segundoMenor,segundo);
        soma+=segundo;
    }
    return soma-segundoMenor+menor;
}
```

**Complexidade:** O(total de elementos) esperado com nth_element; cópias usam O(maior array) auxiliar.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Olya and Game with Arrays · problemas · páginas 83, 84](https://codeforces.com/problemset/problem/1859/B)

## cp-note-000042

**Pergunta**

Como evitar simular golpes repetidos no monstro de maior vida? Como normalizar o resto e ordenar com desempate correto?

**Resposta**

Enquanto algum monstro tem vida >k, um golpe não o mata e reduz sua vida pelo mesmo k. Podemos antecipar essas reduções. A vida imediatamente antes do golpe final é ((vida-1)%k)+1: um múltiplo de k deve representar k, não zero. Todos ficam entre 1 e k e morrem em um golpe. Ordene pela vida normalizada decrescente e, em empate, pelo índice crescente.

```cpp
vector<int> ordemMortes(const vector<long long>& vida,long long k) {
    vector<pair<long long,int>> itens;
    for(int i=0;i<(int)vida.size();++i)
        itens.push_back({(vida[i]-1)%k+1,i+1});
    sort(itens.begin(),itens.end(),[](auto a,auto b){
        return a.first!=b.first ? a.first>b.first : a.second<b.second;
    });
    vector<int> ans; for(auto [resto,id]:itens){(void)resto;ans.push_back(id);}
    return ans;
}
```

**Complexidade:** O(n log n) de tempo e O(n) de espaço; vida>=1 e k>=1.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Monsters · problemas · páginas 84](https://codeforces.com/problemset/problem/1849/B)

## cp-note-000043

**Pergunta**

Como contar subarrays de comprimento pelo menos k em que todos os elementos satisfazem um predicado? Como evitar perder o último bloco?

**Resposta**

Um bloco válido de tamanho L contribui (L-k+1)(L-k+2)/2 quando L>=k: há L-k+1 escolhas para comprimento k, uma a menos para k+1 e assim por diante. Também podemos acumular online: a cada posição válida, se o bloco atual tem tamanho c>=k, surgem c-k+1 subarrays terminando ali. Ao encontrar inválido, zere c. Essa forma já inclui o último bloco e evita esquecer o processamento após o laço.

```cpp
long long ferias(const vector<int>& temperatura,int k,int limite) {
    long long atual=0,total=0;
    for(int x:temperatura){
        atual=(x<=limite ? atual+1 : 0);
        if(atual>=k) total+=atual-k+1;
    }
    return total;
}
```

**Complexidade:** O(n) de tempo e O(1) de espaço; k>=1.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Ski Resort · problemas · páginas 85, 86](https://codeforces.com/problemset/problem/1840/C)

## cp-note-000044

**Pergunta**

Num merge que preserva a ordem interna de dois arrays, como obter a maior sequência consecutiva de um mesmo valor sem testar todas as intercalações?

**Resposta**

Para um valor x, só podemos juntar um bloco contínuo de x de cada array: separar dois blocos do mesmo array exige emitir os valores diferentes que ficam entre eles. Portanto o melhor para x é maiorRunA[x]+maiorRunB[x]. Essa soma é atingível alinhando os dois blocos no merge. Conte runs, não frequência total, e atualize também o bloco final. Use um vetor por valor apenas quando o domínio for pequeno; map serve para domínio geral.

```cpp
map<int,int> maioresRuns(const vector<int>& a) {
    map<int,int> melhor;
    for(int i=0;i<(int)a.size();){
        int j=i; while(j<(int)a.size() && a[j]==a[i]) ++j;
        melhor[a[i]]=max(melhor[a[i]],j-i); i=j;
    }
    return melhor;
}
int maiorMerge(const vector<int>& a,const vector<int>& b) {
    auto A=maioresRuns(a),B=maioresRuns(b); int ans=0;
    for(auto [x,v]:A) ans=max(ans,v+B[x]);
    for(auto [x,v]:B) ans=max(ans,v+A[x]);
    return ans;
}
```

**Complexidade:** O((n+m) log U) com map; O(n+m+U) se usar vetores para domínio limitado.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Array Merging · problemas · páginas 86, 87](https://codeforces.com/problemset/problem/1831/B)

## cp-note-000045

**Pergunta**

Como escolher um corte de string que maximize a soma de caracteres distintos nas duas partes? Por que contar distintos globalmente não basta?

**Resposta**

Um caractere presente dos dois lados contribui duas vezes, então o total global de distintos não responde à pergunta. Faça pref[i] contar distintos em s[0,i) e suf[i] contar em s[i,n). Para cada corte entre 1 e n-1, avalie pref[corte]+suf[corte]. Dois conjuntos de presença ou arrays de 26 posições bastam. Definir intervalos semiabertos evita duplicar ou esquecer o caractere na fronteira.

```cpp
int melhorCorte(const string& s) {
    int n=s.size(); vector<int> p(n+1),q(n+1);
    array<bool,26> visto{};
    for(int i=0;i<n;++i){int c=s[i]-'a';p[i+1]=p[i]+!visto[c];visto[c]=true;}
    visto.fill(false);
    for(int i=n-1;i>=0;--i){int c=s[i]-'a';q[i]=q[i+1]+!visto[c];visto[c]=true;}
    int ans=0;
    for(int i=1;i<n;++i) ans=max(ans,p[i]+q[i]);
    return ans;
}
```

**Complexidade:** O(n+26) de tempo e O(n+26) de espaço; n>=2 e letras a-z.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Distinct Split · problemas · páginas 87, 88](https://codeforces.com/problemset/problem/1791/D)

## cp-note-000046

**Pergunta**

Por que basta procurar divisores até a raiz de n? Como gerar os dois fatores de cada par sem duplicar a raiz quadrada e sem overflow em i*i?

**Resposta**

Se n=a*b e ambos fossem maiores que sqrt(n), o produto excederia n. Logo pelo menos um fator está até a raiz. Ao achar d, o outro é n/d. Para quadrado perfeito, esses fatores são iguais e devem ser adicionados uma vez. A condição d<=n/d evita overflow de d*d. Essa redução também encontra o menor divisor não trivial para Minimum LCM.

```cpp
vector<long long> divisores(long long n) {
    vector<long long> ds;
    for(long long d=1;d<=n/d;++d) if(n%d==0){
        ds.push_back(d);
        if(d!=n/d) ds.push_back(n/d);
    }
    sort(ds.begin(),ds.end()); return ds;
}
```

**Complexidade:** O(sqrt(n)+D log D) incluindo ordenação dos D divisores; O(D) de espaço; n>=1.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Minimum LCM · problemas · páginas 88, 89, 90, 91](https://codeforces.com/problemset/problem/1765/M)

## cp-note-000047

**Pergunta**

Como minimizar lcm(a,b) com a+b=n e a,b positivos? Qual é a relação com o menor divisor não trivial de n?

**Resposta**

Se p é o menor divisor de n maior que 1, escolha a=n/p e b=n-a. Como b=(p-1)a, lcm(a,b)=b. Para justificar a otimalidade, escreva a=g*x, b=g*y, gcd(x,y)=1. Então x+y divide n e é pelo menos p. O lcm é n*x*y/(x+y), e x*y>=(x+y)-1. Logo não pode ser menor que n*(p-1)/p, atingido pela construção. Se n é primo, p=n e a=1.

```cpp
pair<long long,long long> menorLCM(long long n) {
    long long p=n;
    for(long long d=2;d<=n/d;++d)
        if(n%d==0){ p=d; break; }
    long long a=n/p;
    return {a,n-a};
}
```

**Complexidade:** O(sqrt(n)) de tempo e O(1) de espaço; n>=2.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Minimum LCM · problemas · páginas 88, 89, 90, 91](https://codeforces.com/problemset/problem/1765/M)

## cp-note-000048

**Pergunta**

Como calcular, para cada posição de um ciclo, a distância até o próximo evento-alvo em O(n)? Por que duplicar e varrer ao contrário ajuda?

**Resposta**

Duplicar a sequência transforma o cruzamento do fim para o início em um trecho linear. Na varredura da direita para a esquerda, guarde o índice do verde mais próximo já visto: ele é o próximo verde de qualquer posição à esquerda. Avalie somente posições da primeira cópia. Isso troca buscas repetidas pelo uso de memória de um próximo evento. A existência de pelo menos um verde é condição do problema.

```cpp
int espera(const string& s,char cor) {
    if(cor=='g') return 0;
    int n=s.size(),proximo=-1,ans=0; string ciclo=s+s;
    for(int i=2*n-1;i>=0;--i){
        if(ciclo[i]=='g') proximo=i;
        if(i<n && ciclo[i]==cor && proximo!=-1) ans=max(ans,proximo-i);
    }
    return ans;
}
```

**Complexidade:** O(n) de tempo e O(n) para a cópia duplicada.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Traffic Light · problemas · páginas 91, 92](https://codeforces.com/problemset/problem/1744/C)

## cp-note-000049

**Pergunta**

Como formar o máximo de times quando a força de um time é tamanho*maiorForça e precisa ser estritamente maior que D?

**Resposta**

Ordene as forças. Use o mais forte restante como líder. Ele precisa de floor(D/força)+1 pessoas no total; a desigualdade é estrita. Complete com os mais fracos restantes, pois a força individual deles não altera o máximo do time. Consumir os mais fracos preserva os fortes como líderes futuros. Se nem todos os jogadores restantes completam o time com esse líder, nenhum líder menor conseguirá.

```cpp
int times(vector<long long> a,long long D) {
    sort(a.begin(),a.end()); int l=0,r=(int)a.size()-1,ans=0;
    while(l<=r){
        long long precisa=D/a[r]+1;
        if(precisa>r-l+1) break;
        l+=(int)precisa-1; --r; ++ans;
    }
    return ans;
}
```

**Complexidade:** O(n log n) de tempo e O(1) auxiliar além da cópia; forças positivas.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Basketball Together · problemas · páginas 92, 93](https://codeforces.com/problemset/problem/1725/B)

## cp-note-000050

**Pergunta**

Como construir n inteiros não negativos com soma s e soma dos pisos a[i]/k igual a b? Como obter os limites de viabilidade antes de distribuir?

**Resposta**

Escreva a[i]=k*q[i]+r[i], com 0<=r[i]<k. Como a soma dos quocientes é b, a parte fixa da soma é k*b. Os n restos conseguem acrescentar entre 0 e n*(k-1). Logo k*b<=s<=k*b+n*(k-1). Coloque todo o quociente no primeiro elemento e distribua s-k*b como restos limitados a k-1. A verificação por limites evita uma tentativa de construção que falharia no final.

```cpp
vector<long long> construirBonito(int n,long long k,long long b,long long s) {
    long long base=k*b;
    if(s<base || s-base>1LL*n*(k-1)) return {};
    vector<long long> a(n,0); a[0]=base; long long falta=s-base;
    for(auto& x:a){long long dar=min(falta,k-1);x+=dar;falta-=dar;}
    return a;
}
```

**Complexidade:** O(n) de tempo e espaço da saída; n>=1, k>=1 e produtos cabem em 64 bits.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Beautiful Array · problemas · páginas 93, 94](https://codeforces.com/problemset/problem/1715/B)

## cp-note-000051

**Pergunta**

Como minimizar mudanças de um valor v quando cada elemento a[i] exige |v-a[i]|<=x? Por que manter a interseção de possibilidades é melhor que escolher v imediatamente?

**Resposta**

Cada elemento permite v no intervalo [a[i]-x,a[i]+x]. Enquanto a interseção dos intervalos do bloco é não vazia, algum mesmo v atende todos. Atualize o limite inferior pelo máximo e o superior pelo mínimo. Ao esvaziar, uma mudança é inevitável: nenhum v atende o bloco inteiro. Adiar a mudança até esse ponto maximiza o primeiro bloco e deixa o sufixo com o mesmo subproblema. A escolha inicial de v não conta como mudança.

```cpp
int mudancas(const vector<long long>& a,long long x) {
    long long L=a[0]-x,R=a[0]+x; int ans=0;
    for(long long v:a){
        long long l=v-x,r=v+x;
        if(max(L,l)>min(R,r)){++ans;L=l;R=r;}
        else {L=max(L,l);R=min(R,r);}
    }
    return ans;
}
```

**Complexidade:** O(n) de tempo e O(1) de espaço; array não vazio.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Luke Is a Foodie · problemas · páginas 94, 95](https://codeforces.com/problemset/problem/1704/B)

## cp-note-000052

**Pergunta**

Como reorganizar índices dentro de grupos de valores iguais para que ninguém receba o próprio item? Quando a construção é impossível?

**Resposta**

Na entrada ordenada, valores iguais formam blocos. Um bloco de tamanho 1 não tem outro índice compatível: é impossível. Para cada bloco com pelo menos dois elementos, uma rotação cíclica dos índices cria uma permutação sem pontos fixos e mantém os valores iguais. No problema dos sapatos, todos precisam receber tamanho >=ao próprio; a soma dos tamanhos é preservada, então ninguém pode aumentar estritamente sem alguém diminuir. Portanto as trocas ficam entre tamanhos iguais.

```cpp
vector<int> embaralhar(const vector<int>& a) {
    vector<int> p(a.size());
    for(int l=0;l<(int)a.size();){
        int r=l; while(r<(int)a.size() && a[r]==a[l]) ++r;
        if(r-l==1) return {};
        for(int i=l;i<r;++i) p[i]=(i+1<r ? i+2 : l+1);
        l=r;
    }
    return p;
}
```

**Complexidade:** O(n) de tempo e O(n) de espaço da permutação.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Shoe Shuffling · problemas · páginas 95, 96](https://codeforces.com/problemset/problem/1691/B)

## cp-note-000053

**Pergunta**

Como converter caracteres e testar faixas com segurança em C++? Qual é a diferença entre comparar uma faixa e escrever comparações encadeadas?

**Resposta**

Para ASCII, a-z, A-Z e 0-9 são faixas contíguas, mas a<=c<=z não expressa uma faixa em C++: a primeira comparação vira bool. Use duas comparações com && e combine categorias com ||. Funções de cctype, como toupper e isalnum, devem receber unsigned char convertido para int para evitar comportamento indefinido com char negativo. Isso não implementa conversão Unicode geral. Alterar só a primeira letra custa O(1), mas ler/imprimir toda a string custa O(n).

```cpp
string capitalizar(string s) {
    if(!s.empty()) s[0]=(char)toupper((unsigned char)s[0]);
    return s;
}
bool alfanumericoASCII(char c) {
    return ('a'<=c && c<='z') || ('A'<=c && c<='Z')
        || ('0'<=c && c<='9');
}
```

**Complexidade:** O(1) para a operação no primeiro caractere; O(n) incluindo cópia/saída.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Word Capitalization · problemas · páginas 96, 97](https://codeforces.com/problemset/problem/281/A)

## cp-note-000054

**Pergunta**

Como achar o mínimo de mudanças para tornar um segmento de tamanho k inteiramente B? Como atualizar uma janela sem recontar todos os seus elementos?

**Resposta**

O custo de uma janela é o número de W dentro dela. Conte a primeira janela e deslize: acrescente o caractere que entra e retire o que sai. Isso mantém o invariante de que o contador representa exatamente a janela atual. Avalie todas as janelas válidas e guarde o menor custo. Um prefix sum do predicado s[i]==W é outra solução linear; não é necessário implementar as duas ao mesmo tempo.

```cpp
int pintar(const string& s,int k) {
    int brancos=0,melhor=k;
    for(int i=0;i<(int)s.size();++i){
        brancos+=(s[i]=='W');
        if(i>=k) brancos-=(s[i-k]=='W');
        if(i>=k-1) melhor=min(melhor,brancos);
    }
    return melhor;
}
```

**Complexidade:** O(n) de tempo e O(1) de espaço; 1<=k<=n.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Black and White Stripe · problemas · páginas 97, 98](https://codeforces.com/problemset/problem/1690/D)

## cp-note-000055

**Pergunta**

Como combinar busca por chave e ordem de uso para implementar um LRU Cache com get e put em O(1) médio? Mostre como atualizar recência e remover o menos recente.

**Resposta**

Um unordered_map localiza a entrada pela chave, mas não mantém a ordem de recência. Uma lista duplamente encadeada permite mover um nó conhecido em O(1). Guarde no mapa um iterador para o nó; a frente é o mais recente e o fim o menos recente. get e put de chave existente movem a entrada para a frente. Ao exceder a capacidade, remova a chave do mapa e o último nó da lista. std::list gerencia a memória; splice mantém válidos os iteradores dos nós movidos. O custo do hash é médio, não garantia de pior caso.

```cpp
class LRU {
    int cap;
    list<pair<int,int>> ordem; // {chave,valor}, recente na frente
    unordered_map<int,list<pair<int,int>>::iterator> pos;
public:
    explicit LRU(int capacidade):cap(capacidade){}
    int get(int chave){
        auto it=pos.find(chave); if(it==pos.end()) return -1;
        ordem.splice(ordem.begin(),ordem,it->second);
        return it->second->second;
    }
    void put(int chave,int valor){
        if(cap==0) return;
        auto it=pos.find(chave);
        if(it!=pos.end()){
            it->second->second=valor;
            ordem.splice(ordem.begin(),ordem,it->second); return;
        }
        ordem.push_front({chave,valor}); pos[chave]=ordem.begin();
        if((int)pos.size()>cap){
            int antiga=ordem.back().first;
            pos.erase(antiga); ordem.pop_back();
        }
    }
};
```

**Complexidade:** O(1) médio por operação e O(capacidade) de espaço.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [LRU Cache · big-tech-problems · páginas 2, 3, 4, 5](https://leetcode.com/problems/lru-cache/description/)

## cp-note-000056

**Pergunta**

Como remover um nó e inseri-lo depois de head numa lista duplamente encadeada? Por que sentinelas e ordem de atualização dos ponteiros importam?

**Resposta**

Com head e tail sentinelas, cada nó real tem vizinho anterior e próximo. Para desligar n, faça os vizinhos apontarem um para o outro. Para inserir após head, salve a ligação com o antigo primeiro, ajuste seu anterior e só então atualize head->prox. Mudar head->prox cedo demais perde o antigo primeiro. Desligar não destrói: use essa operação para mover um nó de LRU; só use delete ao expulsá-lo definitivamente, depois de apagar referências do mapa.

```cpp
struct No { int chave,valor; No* ant; No* prox; };
void retirar(No* n){
    n->ant->prox=n->prox;
    n->prox->ant=n->ant;
}
void inserirAposHead(No* head,No* n){
    n->prox=head->prox; n->ant=head;
    head->prox->ant=n;
    head->prox=n;
}
```

**Complexidade:** O(1) de tempo e espaço; n deve ser nó real conectado ao retirar, e desconectado ao inserir.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [LRU Cache · big-tech-problems · páginas 2, 3, 4, 5](https://leetcode.com/problems/lru-cache/description/)

## cp-note-000057

**Pergunta**

Qual a diferença entre passar um nó por valor, um ponteiro por valor e uma referência a ponteiro? Como isso afeta alterar o nó ou avançar o ponteiro de quem chamou?

**Resposta**

Passar ListNode por valor copia o objeto. Passar ListNode* por valor copia o endereço, mas permite alterar o objeto original com ->. Reatribuir esse ponteiro local não muda a variável do chamador. Para mudar o ponteiro do chamador, receba ListNode*& ou retorne o novo ponteiro. Declare o ponteiro com *, mas acesse membros com ->; a->val equivale a (*a).val. Sempre confira nullptr antes de desreferenciar.

```cpp
void alterarValor(ListNode* p,int x){
    if(p) p->val=x;
}
void avancarLocal(ListNode* p){
    if(p) p=p->next; // não altera o ponteiro do chamador
}
void avancarChamador(ListNode*& p){
    if(p) p=p->next;
}
```

**Complexidade:** O(1) de tempo e espaço para essas operações.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [LRU Cache · big-tech-problems · páginas 2, 3, 4, 5](https://leetcode.com/problems/lru-cache/description/)
- [Add Two Numbers · big-tech-problems · páginas 14](https://leetcode.com/problems/add-two-numbers/description/)

## cp-note-000058

**Pergunta**

Quando usar find, count e operator[] em um map ou unordered_map? Por que uma consulta com [] pode alterar a estrutura?

**Resposta**

operator[] insere uma chave ausente com valor padrão. Isso é útil para contar frequências e agrupar, mas perigoso para uma consulta que deveria apenas verificar existência, especialmente num cache com limite de capacidade. find retorna um iterador e permite ler o valor sem inserir; count retorna 0 ou 1 para mapas de chave única. Em C++17, use find em vez de contains, que chegou no C++20.

```cpp
int buscar(const unordered_map<int,int>& mp,int chave) {
    auto it=mp.find(chave);
    return it==mp.end() ? -1 : it->second;
}
unordered_map<int,int> frequencias(const vector<int>& a){
    unordered_map<int,int> f;
    for(int x:a) ++f[x]; // inserção intencional, valor inicial 0
    return f;
}
```

**Complexidade:** unordered_map: O(1) médio por acesso; map: O(log U). Frequências usam O(U) espaço.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [LRU Cache · big-tech-problems · páginas 2, 3, 4, 5](https://leetcode.com/problems/lru-cache/description/)
- [Group Anagrams · big-tech-problems · páginas 5](https://leetcode.com/problems/group-anagrams/description/)
- [Top K Frequent Elements · big-tech-problems · páginas 5, 6](https://leetcode.com/problems/top-k-frequent-elements/description/)

## cp-note-000059

**Pergunta**

Como agrupar anagramas sem ordenar cada palavra? Como construir uma chave de frequências que não tenha colisões por concatenação ambígua?

**Resposta**

Para letras a-z, duas palavras são anagramas exatamente quando têm o mesmo vetor de 26 frequências. Serialize os números com separadores: concatenar apenas dígitos confundiria, por exemplo, [1,11] e [11,1]. Use a assinatura como chave de unordered_map e anexe a palavra ao grupo. A chave descreve contagem, não ordem das letras. Hashes podem colidir internamente, mas o mapa também compara a igualdade das strings; isso é diferente de uma chave semanticamente ambígua.

```cpp
string assinatura(const string& palavra){
    array<int,26> f{};for(char c:palavra)++f[c-'a'];
    string chave;
    for(int qtd:f) chave+=to_string(qtd)+"#";
    return chave;
}
vector<vector<string>> agrupar(const vector<string>& palavras){
    unordered_map<string,vector<string>> grupos;
    for(const auto& s:palavras) grupos[assinatura(s)].push_back(s);
    vector<vector<string>> ans;
    for(auto& entrada:grupos) ans.push_back(std::move(entrada.second));
    return ans;
}
```

**Complexidade:** O(total de caracteres + 26N) esperado, incluindo construir chaves; espaço proporcional às palavras e assinaturas.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Group Anagrams · big-tech-problems · páginas 5](https://leetcode.com/problems/group-anagrams/description/)

## cp-note-000060

**Pergunta**

Como obter os k elementos mais frequentes em tempo linear esperado usando buckets? O que representa o índice e por que são n+1 posições?

**Resposta**

Conte cada valor com hashmap. Uma frequência está entre 1 e n; crie n+1 buckets, onde bucket[f] guarda os valores que aparecem f vezes. Percorra as frequências do maior para o menor e pare ao obter k valores. O índice é frequência, não o próprio valor. O bucket n precisa existir. A ordem entre elementos empatados é irrelevante quando o problema permite qualquer ordem.

```cpp
vector<int> topK(const vector<int>& a,int k){
    unordered_map<int,int> f;for(int x:a)++f[x];
    int n=a.size();vector<vector<int>> buckets(n+1);
    for(auto [x,qtd]:f) buckets[qtd].push_back(x);
    vector<int> ans;
    for(int qtd=n;qtd>=1;--qtd) for(int x:buckets[qtd]){
        ans.push_back(x);if((int)ans.size()==k)return ans;
    }
    return ans;
}
```

**Complexidade:** O(n) esperado de tempo e O(n) de espaço; 1<=k<=número de distintos.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Top K Frequent Elements · big-tech-problems · páginas 5, 6](https://leetcode.com/problems/top-k-frequent-elements/description/)

## cp-note-000061

**Pergunta**

Suponha k armazéns, com k par: cada armazém recebe peças de uma única entrega e os k/2 mais cheios são comprometidos. Podemos escolher quantas peças guardar. Como usar um limiar de carga t, blocos completos e restos para maximizar a soma nos armazéns seguros?

**Resposta**

Cada armazém só aceita peças de uma única entrega, embora uma entrega possa ser dividida. Fixe t>=1: cada entrega a forma a/t blocos completos de tamanho t e um resto a%t. Reserve m=k/2 blocos completos aos comprometidos. Se q<m, o limiar é inviável; se q>=k, m armazéns seguros também podem ter t. Se m<=q<k, existem q-m blocos seguros completos e faltam k-q posições, preenchidas pelos maiores restos disponíveis. Varrer os limiares é o método da anotação; a quantidade de blocos é monótona, mas isso não prova que a função objetivo permita busca binária. A aplicação depende destas regras e de k par. Nesta formulação, peças podem ficar sem alocação; se a obrigação fosse guardar todas, seria necessário conferir a viabilidade adicional. Trata-se da regra explicitada neste card, não de uma inferência sobre o enunciado ausente da entrevista.

```cpp
long long seguros(const vector<int>& entregas,int k){
    int M=*max_element(entregas.begin(),entregas.end()),m=k/2;
    long long ans=0;
    for(int t=1;t<=M;++t){
        long long q=0;vector<int> restos;
        for(int x:entregas){q+=x/t;restos.push_back(x%t);}
        if(q<m) break;
        if(q>=k){ans=max(ans,1LL*m*t);continue;}
        long long valor=(q-m)*t;
        sort(restos.rbegin(),restos.rend());
        int usar=min((int)restos.size(),(int)(k-q));
        for(int i=0;i<usar;++i) valor+=restos[i];
        ans=max(ans,valor);
    }
    return ans;
}
```

**Complexidade:** O(M*N log N) de tempo no pior caso e O(N) de espaço; só usar se o limite M permitir.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- Security Delivery Logs · big-tech-problems · páginas 6, 7, 8, 9

## cp-note-000062

**Pergunta**

Como calcular o produto de todos os elementos exceto a[i], sem divisão e em O(n)? Por que os prefixos e sufixos devem excluir o elemento atual?

**Resposta**

Defina esquerda[i] como produto antes de i e direita[i] como produto depois de i. Então resposta[i]=esquerda[i]*direita[i]. O produto vazio é 1, inicializando as extremidades. Essa definição exclui a[i] por construção e funciona mesmo com zeros, ao contrário de dividir o produto total. Em inteiros, confira se todos os produtos intermediários cabem no tipo usado.

```cpp
vector<long long> produtoExceto(const vector<int>& a){
    int n=a.size();vector<long long>L(n,1),R(n,1),ans(n);
    for(int i=1;i<n;++i)L[i]=L[i-1]*a[i-1];
    for(int i=n-2;i>=0;--i)R[i]=R[i+1]*a[i+1];
    for(int i=0;i<n;++i)ans[i]=L[i]*R[i];
    return ans;
}
```

**Complexidade:** O(n) de tempo e O(n) de espaço auxiliar.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Product of Array Except Self · big-tech-problems · páginas 9, 10](https://leetcode.com/problems/product-of-array-except-self/description/)

## cp-note-000063

**Pergunta**

Como reduzir o espaço auxiliar de prefixo/sufixo no produto exceto o elemento atual? Qual invariante deve valer antes de atualizar o acumulador?

**Resposta**

Use a própria saída para guardar os produtos à esquerda na primeira passada. Na passada inversa, mantenha apenas um acumulador do produto à direita. Primeiro multiplique a saída pelo acumulador; só depois inclua o elemento atual nele. Atualizar na ordem inversa incluiria a[i], quebrando a exclusão. O espaço auxiliar é O(1), mas a saída continua ocupando O(n).

```cpp
vector<long long> produtoCompacto(const vector<int>& a){
    int n=a.size();vector<long long>ans(n,1);long long acum=1;
    for(int i=0;i<n;++i){ans[i]=acum;acum*=a[i];}
    acum=1;
    for(int i=n-1;i>=0;--i){ans[i]*=acum;acum*=a[i];}
    return ans;
}
```

**Complexidade:** O(n) de tempo, O(1) auxiliar além dos O(n) da saída; produtos devem caber em long long.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Product of Array Except Self · big-tech-problems · páginas 9, 10](https://leetcode.com/problems/product-of-array-except-self/description/)

## cp-note-000064

**Pergunta**

Como codificar uma lista de strings de modo reversível mesmo quando elas contêm dígitos, delimitadores e strings vazias? Como decodificar sem ambiguidades?

**Resposta**

Para cada string, escreva comprimento#conteúdo. O # encerra o número do comprimento; em seguida, leia exatamente esse número de bytes, sem procurar delimitadores dentro do conteúdo. Assim um # ou dígito no conteúdo não causa conflito. A string vazia é 0#, enquanto uma lista vazia é a codificação vazia. std::string::size conta bytes; encode e decode devem usar a mesma unidade. O código abaixo assume uma codificação válida produzida pelo encoder.

```cpp
string encode(const vector<string>& lista){
    string s;
    for(const auto& x:lista)s+=to_string(x.size())+"#"+x;
    return s;
}
vector<string> decode(const string& s){
    vector<string> ans;size_t i=0;
    while(i<s.size()){
        size_t j=s.find('#',i);
        size_t tamanho=stoull(s.substr(i,j-i));
        i=j+1;ans.push_back(s.substr(i,tamanho));i+=tamanho;
    }
    return ans;
}
```

**Complexidade:** O(T+N+H) de tempo e espaço da saída, T bytes de conteúdo e H dígitos dos cabeçalhos.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Encode and Decode Strings · big-tech-problems · páginas 10, 11](https://leetcode.com/problems/encode-and-decode-strings/description/)

## cp-note-000065

**Pergunta**

Como mapear uma posição (linha,coluna) e um bloco 3x3 do Sudoku para um índice linear? Quando usar divisão inteira e quando usar módulo?

**Resposta**

Uma grade com C colunas usa id=linha*C+coluna, em base zero; a inversão é linha=id/C e coluna=id%C. Para descobrir o bloco do Sudoku, primeiro agrupe: linha/3 e coluna/3 dizem em qual linha e coluna de blocos a célula está. Depois linearize a grade 3x3 de blocos: (linha/3)*3+coluna/3. A divisão identifica o grupo; o módulo identifica a posição dentro do grupo.

```cpp
int indice(int linha,int coluna,int largura){
    return linha*largura+coluna;
}
pair<int,int> coordenadas(int id,int largura){
    return {id/largura,id%largura};
}
int caixaSudoku(int linha,int coluna){
    return (linha/3)*3+coluna/3;
}
```

**Complexidade:** O(1) de tempo e espaço; índices base zero e largura positiva.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Valid Sudoku · big-tech-problems · páginas 11, 12](https://leetcode.com/problems/valid-sudoku/description/)

## cp-note-000066

**Pergunta**

Como usar uma máscara de bits para detectar dígitos repetidos em linhas, colunas e caixas do Sudoku? Qual a ordem de verificar e marcar?

**Resposta**

Associe cada dígito 1..9 ao bit 0..8. Para uma célula, calcule sua caixa e teste se o bit já está em qualquer uma das três máscaras. Se estiver, há repetição; caso contrário, marque-o nas três. Ignore pontos. Isso valida apenas as restrições presentes, não garante que o tabuleiro tenha solução. Fazer OR antes de verificar tornaria todo dígito aparentemente repetido.

```cpp
bool sudokuValido(const vector<string>& tab){
    array<int,9> linhas{},colunas{},caixas{};
    for(int r=0;r<9;++r)for(int c=0;c<9;++c){
        if(tab[r][c]=='.')continue;
        int bit=1<<(tab[r][c]-'1'),b=(r/3)*3+c/3;
        if((linhas[r]&bit)||(colunas[c]&bit)||(caixas[b]&bit))return false;
        linhas[r]|=bit;colunas[c]|=bit;caixas[b]|=bit;
    }
    return true;
}
```

**Complexidade:** O(81) e O(27) para o Sudoku fixo 9x9, portanto O(1).

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Valid Sudoku · big-tech-problems · páginas 11, 12](https://leetcode.com/problems/valid-sudoku/description/)

## cp-note-000067

**Pergunta**

Como ler e inicializar contêineres aninhados em C++17? Qual a diferença entre tamanho/valor com parênteses e lista de elementos com chaves?

**Resposta**

Separe tipo, nome e inicialização. vector<vector<int>> é um vetor cujos elementos são vetores; o construtor externo recebe quantidade de linhas e um vetor padrão de colunas. vector<set<int>> recebe quantidade e um set padrão, copiado em cada posição. vector<int>(3,7) cria três valores 7, enquanto vector<int>{3,7} cria dois elementos, 3 e 7. Os vetores internos são objetos independentes, não referências à mesma linha.

```cpp
vector<vector<int>> matrizZerada(int linhas,int colunas){
    return vector<vector<int>>(linhas,vector<int>(colunas,0));
}
vector<set<int>> tresConjuntos(){
    return vector<set<int>>(3,set<int>{1,2,3});
}
```

**Complexidade:** O(linhas*colunas) para a matriz; cópias do conteúdo de cada contêiner têm custo próprio.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- Inicialização de contêineres compostos · big-tech-problems · páginas 12, 13

## cp-note-000068

**Pergunta**

Qual a diferença entre queue e stack e como usar suas interfaces em C++17? O que pop retorna e quando front/top é válido?

**Resposta**

queue segue FIFO: o primeiro a entrar é o primeiro a sair; consulte front e insira com push. stack segue LIFO: o último a entrar sai primeiro; consulte top. Em ambos, pop remove e retorna void: leia o elemento antes de removê-lo. front e top exigem contêiner não vazio. Esses adaptadores não oferecem iteração comum como vector.

```cpp
pair<vector<int>,vector<int>> ordens(const vector<int>& a){
    queue<int> fila;stack<int> pilha;
    for(int x:a){fila.push(x);pilha.push(x);}
    vector<int> fifo,lifo;
    while(!fila.empty()){fifo.push_back(fila.front());fila.pop();}
    while(!pilha.empty()){lifo.push_back(pilha.top());pilha.pop();}
    return {fifo,lifo};
}
```

**Complexidade:** O(n) de tempo e espaço para armazenar e consumir n elementos.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- Inicialização de contêineres compostos · big-tech-problems · páginas 12, 13

## cp-note-000069

**Pergunta**

Como somar duas linked lists de dígitos em ordem inversa, construindo uma nova lista? Como tratar tamanhos diferentes e o carry final?

**Resposta**

Percorra enquanto houver um nó em qualquer entrada OU carry. Uma lista terminada contribui zero. Some os dois dígitos e o carry anterior; o novo dígito é soma%10 e o próximo carry é soma/10. Conecte um nó à lista de saída e avance cada entrada somente se ela existir. O carry deve participar da condição do laço: 9+1 precisa produzir 0->1, mesmo depois de ambas as entradas terminarem. Um sentinela local simplifica a construção sem precisar de delete para ele.

```cpp
ListNode* somar(const ListNode* a,const ListNode* b){
    ListNode head(0);ListNode* actual=&head;int carry=0;
    while(a || b || carry){
        int soma=carry+(a?a->val:0)+(b?b->val:0);
        carry=soma/10;
        actual->next=new ListNode(soma%10);actual=actual->next;
        if(a)a=a->next;
        if(b)b=b->next;
    }
    return head.next;
}
```

**Complexidade:** O(max(n,m)) de tempo, O(1) auxiliar e O(max(n,m)) para a saída; dígitos entre 0 e 9.

**Critérios de acerto**

- Explicar o invariante ou a justificativa do padrão.
- Reconstruir o uso em C++ e reconhecer as condições de validade.

**Fontes**

- [Add Two Numbers · big-tech-problems · páginas 14](https://leetcode.com/problems/add-two-numbers/description/)
