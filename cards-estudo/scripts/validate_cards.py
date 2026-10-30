#!/usr/bin/env python3
"""Compila o C++17 dos cards e executa cenários independentes por card."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[1]
HEADER = '''#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
struct ListNode { int val; ListNode* next; explicit ListNode(int x):val(x),next(nullptr){} };
void liberar(ListNode* p){ while(p){auto q=p->next; delete p; p=q;} }
'''


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cases', default='tests/historico-cases.json')
    parser.add_argument('--report', default='estado/validacao-historico.json')
    parser.add_argument('--cache-key', default='historico')
    args = parser.parse_args()
    cases = json.loads((ROOT / args.cases).read_text())
    cards = [json.loads((ROOT / f'cards/{key}.json').read_text()) for key in sorted(cases)]
    source = HEADER
    for card in cards:
        ident = card['id']
        assert card['front'] and card['back']['answer'] and card['back']['cpp17']
        namespace = ident.replace('-', '_')
        source += '\nnamespace ' + namespace + ' {\n' + card['back']['cpp17']
        source += '\nvoid testar(){\n' + cases[ident] + '\n}\n}\n'
    source += '\nint main(){\n'
    for card in cards:
        ident = card['id']
        source += f'cout << "{ident}" << endl; {ident.replace("-", "_")}::testar();\n'
    source += '}\n'
    cache = ROOT / '.cache' / args.cache_key
    cache.mkdir(parents=True, exist_ok=True)
    cpp = cache / 'all_cards.cpp'
    binary = cache / 'all_cards'
    cpp.write_text(source)
    subprocess.run(['clang++', '-std=c++17', '-pedantic-errors', '-O1', '-g', '-Wall', '-Wextra', '-Werror',
                    '-fsanitize=address,undefined', str(cpp), '-o', str(binary)], check=True)
    result = subprocess.run([str(binary)], capture_output=True, text=True)
    (cache / 'cpp-test-output.txt').write_text(result.stdout + result.stderr)
    if result.returncode:
        print(result.stdout[-1200:] + result.stderr[-3000:])
        raise SystemExit(result.returncode)
    report = {'status': 'passed', 'compiler': 'clang++ C++17',
              'sanitizers': ['address', 'undefined'], 'tested_cards': {}}
    for card in cards:
        ident = card['id']
        report['tested_cards'][ident] = {
            'code_sha256': hashlib.sha256(card['back']['cpp17'].encode()).hexdigest(),
            'case_sha256': hashlib.sha256(cases[ident].encode()).hexdigest()}
    (ROOT / args.report).write_text(json.dumps(report, indent=2) + '\n')
    print(f'{len(cards)} cards: C++ compilado e cenários executados com ASan/UBSan.')


if __name__ == '__main__':
    main()
