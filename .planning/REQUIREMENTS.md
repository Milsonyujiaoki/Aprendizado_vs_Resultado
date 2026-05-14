# REQUIREMENTS — Aprendizado_vs_Resultado

*Scoped requirements for Milestone 1: Foundation + Ecosystem Bootstrap*

---

## Overview

Construir a base sólida do ecossistema: as bibliotecas de foundation em C, o build system reutilizável e os padrões que guiarão todos os módulos futuros.

---

## Table Stakes (must-have para v1 ser útil)

### TS-1: Build System Funcional

**O quê**: Um Makefile system modular que compila qualquer biblioteca do ecossistema de forma consistente.

**Por quê**: Sem um build system, cada módulo é uma ilha. O build system é a espinha dorsal do ecossistema.

**Critérios de aceitação**:
- `make` compila a lib do diretório corrente
- `make test` roda todos os testes
- `make clean` limpa artefatos
- `make install` instala headers + lib em `~/.local/` ou path configurável
- Suporta flags de debug vs release
- Reutilizável via include em qualquer módulo do ecossistema

---

### TS-2: libft — Reimplementação de libc em C

**O quê**: Implementação educacional das funções fundamentais de libc do zero.

**Por quê**: Força compreensão de gestão de memória, strings, I/O e comportamento de baixo nível antes de usar abstrações.

**Escopo**:
- `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_bzero`
- `ft_strlen`, `ft_strcpy`, `ft_strcat`, `ft_strcmp`, `ft_strdup`, `ft_strsplit`
- `ft_atoi`, `ft_itoa`
- `ft_malloc`/`ft_free` — arena allocator simplificado
- `ft_printf` — implementação educacional (suporte a %c, %s, %d, %i, %u, %x, %%)
- Todos com testes unitários e documentação de internals

---

### TS-3: libds — Estruturas de Dados Fundamentais

**O quê**: Implementação do zero das estruturas de dados clássicas com foco em entendimento dos internals.

**Por quê**: É impossível construir sistemas robustos sem dominar as estruturas que os sustentam.

**Escopo**:
- Dynamic array (vetor genérico com tipo `void*`)
- Linked list (singly + doubly)
- Stack e Queue
- Hash map (open addressing + chaining — comparar as duas)
- Binary search tree
- (stretch) Red-black tree ou AVL tree

**Cada estrutura deve incluir**:
- Diagrama de memória comentado no código
- Complexidade de todas as operações no header
- Testes que demonstram o comportamento com edge cases
- Arquivo `INTERNALS.md` explicando design decisions

---

### TS-4: libalgo — Algoritmos Clássicos

**O quê**: Implementação dos algoritmos fundamentais com análise de complexidade integrada ao código.

**Por quê**: Algoritmos são a base do raciocínio sobre performance e eficiência em sistemas reais.

**Escopo**:
- Sorting: bubble, insertion, selection, merge, quick, heap, radix
- Search: binary search, interpolation search
- Graph: BFS, DFS, Dijkstra, A*, topological sort
- Dynamic programming: exemplos fundamentais (coin change, LCS, knapsack)
- String: KMP, Rabin-Karp

**Cada algoritmo deve incluir**:
- Complexidade de tempo e espaço como constante no header
- Visualização comentada do passo-a-passo
- Benchmark comparativo entre variantes

---

### TS-5: libparser — Parser Fundamentals

**O quê**: Construção de parsers do zero: lexer, tokenizer e parser combinators simples.

**Por quê**: Parsers são necessários em todo lugar: configs, protocolos, linguagens, formatos. Entender parsers é entender como sistemas interpretam o mundo.

**Escopo**:
- Tokenizer genérico (baseado em regex manual)
- Parser de expressões matemáticas (com precedência de operadores)
- Parser de JSON do zero (para demonstrar parsing real)
- (stretch) Parser de um subset de uma linguagem simples (tipo Brainfuck ou LISP mínimo)

---

### TS-6: ecosystem/standards

**O quê**: Guias de convenção de código, estrutura de módulos e padrões de documentação.

**Por quê**: Sem padrões, o ecossistema vira uma coleção de estilos diferentes. Padrões permitem que qualquer módulo seja compreendido instantaneamente.

**Entregáveis**:
- `CODING_STANDARDS.md` — convenções de nomenclatura, formatação, estrutura de arquivos
- `MODULE_TEMPLATE.md` — estrutura canônica de um módulo do ecossistema
- `ADR_TEMPLATE.md` — template para Architecture Decision Records
- `INTERNALS_TEMPLATE.md` — como documentar internals de qualquer componente

---

## Nice-to-Have (v1 se houver tempo)

### N2H-1: ecosystem/developer-experience

- Script de bootstrap para novos módulos: `./scripts/new-module.sh foundation/libX`
- Script de benchmark: `./scripts/bench.sh libds` — roda todos os benchmarks de uma lib

### N2H-2: docs/learning

- `LEARNING_PATH.md` — ordem recomendada de estudo dos módulos
- Um README com o mapa do ecossistema (ASCII art da árvore de módulos)

### N2H-3: libft — Extras avançados

- `ft_gc` — garbage collector mark-and-sweep simplificado
- `ft_regex` — engine de regex minimalista

---

## Out of Scope (Milestone 1)

- AI/ML infrastructure (Platform milestone)
- Networking e distributed systems (Infrastructure milestone)
- SaaS/products (Products milestone)
- Go/Python modules (após foundation C estar sólida)
- VMs e interpreters (Infrastructure milestone)

---

*Last updated: 2026-05-13*
