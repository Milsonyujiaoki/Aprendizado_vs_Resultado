# ROADMAP — Aprendizado_vs_Resultado

*Coarse-grained roadmap: 4 milestones, construídos progressivamente do mais fundamental ao mais complexo*

---

## Milestone 1 — Foundation + Ecosystem Bootstrap

**Objetivo**: Construir as bibliotecas C fundamentais e a infraestrutura de desenvolvimento que sustentará todo o ecossistema.

**Estado**: `active`

---

### Phase 1 — Ecosystem Infrastructure

**Goal**: Build system, templates e padrões que permitem construir qualquer módulo de forma consistente.

**Requirements**: TS-1, TS-6

**Plans**: 3 plans

Plan files:
- [x] 01-01-PLAN.md — Build system modular reutilizavel em `ecosystem/build-system/`
- [x] 01-02-PLAN.md — Standards e templates em `ecosystem/standards/`
- [x] 01-03-PLAN.md — Onboarding e mapa do ecossistema em `README.md` e `docs/`

**Success Criteria**:
- `make` compila qualquer módulo com `include $(ROOT)/ecosystem/build-system/module.mk`
- Templates existem para criar novos módulos em < 5 minutos
- Learning path está documentado

---

### Phase

**Goal**: Implementar as funções fundamentais de libc para construir entendimento profundo de memória e strings em C.

**Requirements**: TS-2

**Plans**: 3 plans

Plan files:
- [ ] 02-01-PLAN.md — Base contratual + memory primitives + testes iniciais
- [ ] 02-02-PLAN.md — Categoria string completa + strsplit + testes
- [ ] 02-03-PLAN.md — Conversao, printf (width/precision), allocator e INTERNALS

**Success Criteria**:
- 100% das funções implementadas com testes passando
- Cada função tem comentário explicando comportamento interno e edge cases
- `ft_printf` suporta %c, %s, %d, %i, %u, %x, %%

---

### Phase 3 — libds: Estruturas de Dados

**Goal**: Implementar as estruturas de dados clássicas do zero com foco em internals e comparação de implementações.

**Requirements**: TS-3

**Plans**:
- [ ] 3.1 — Sequenciais: dynamic array, linked list (singly + doubly), stack, queue
- [ ] 3.2 — Hash map: duas implementações (open addressing vs chaining) com benchmark comparativo
- [ ] 3.3 — Árvores: BST com todas as operações + análise de desbalanceamento

**Success Criteria**:
- Cada estrutura tem `INTERNALS.md` com diagrama de memória
- Complexidade de todas as operações documentada nos headers
- Benchmarks mostram diferença entre implementações

---

### Phase 4 — libalgo + libparser

**Goal**: Algoritmos fundamentais com análise de complexidade integrada + parsing do zero.

**Requirements**: TS-4, TS-5

**Plans**:
- [ ] 4.1 — Sorting: bubble→insertion→merge→quick→heap com benchmark comparativo
- [ ] 4.2 — Graph algorithms: BFS, DFS, Dijkstra com visualização de execução
- [ ] 4.3 — libparser: tokenizer → parser de expressões → JSON parser do zero

**Success Criteria**:
- Benchmark mostra curvas de complexidade reais (não só teóricas)
- JSON parser passa na test suite pública do JSON.org
- Graph algorithms têm visualização de estados intermediários em ASCII

---

## Milestone 2 — Infrastructure: Runtime + VM + Networking

**Objetivo**: Construir infraestrutura de sistemas: um runtime, uma VM de bytecode, primitivas de networking e fundamentos de sistemas distribuídos.

**Estado**: `planned`

### Phase 5 — Memory Runtime + Allocators

**Goal**: Arena allocator, pool allocator, slab allocator — entender como sistemas gerenciam memória de verdade.

### Phase 6 — VM de Bytecode

**Goal**: Uma máquina virtual de stack-based bytecode (inspirada em CPython/Lua VM) com disassembler e debugger.

### Phase 7 — Networking Primitives

**Goal**: TCP/IP do zero com epoll/kqueue, HTTP/1.1 server from scratch, protocol parsing.

### Phase 8 — Distributed Systems Fundamentals

**Goal**: Implementar Raft consensus, consistent hashing, e um key-value store distribuído simples.

---

## Milestone 3 — Platform: AI Infrastructure + Tooling

**Objetivo**: Infraestrutura AI-native: inference server, vector database, embedding pipeline, orchestration.

**Estado**: `planned`

### Phase 9 — AI Runtime + Inference

**Goal**: Implementar forward pass de um transformer do zero (Python/C), ONNX loader, inference server com API REST.

### Phase 10 — Vector Database

**Goal**: Vector index from scratch (HNSW), similaridade coseno, storage persistente, query engine.

### Phase 11 — Orchestration + Pipelines

**Goal**: Task queue (inspirado em Celery/BullMQ), workflow engine, pipeline de processamento de dados.

### Phase 12 — Developer Tooling

**Goal**: CLI framework reutilizável (Go), observability primitives (métricas, traces, logs), profiler simples.

---

## Milestone 4 — Products: Monetizable Engineering

**Objetivo**: Transformar componentes do ecossistema em produtos reais com valor de mercado.

**Estado**: `future`

### Phase 13 — SaaS Platform

**Goal**: Usar o ecossistema para construir um SaaS real: um dos produtos em `products/saas/`.

### Phase 14 — Open Source Tooling

**Goal**: Publicar as melhores libs do ecossistema como projetos open source com documentação profissional.

### Phase 15 — Enterprise Tooling

**Goal**: Adaptar componentes de observability e tooling para uso enterprise, com pricing strategy.

---

## Milestone Map

```
M1: Foundation     → C libs + build system         (current)
       ↓
M2: Infrastructure → Runtime, VM, Networking       (next)
       ↓
M3: Platform       → AI infra, tooling, databases  (future)
       ↓
M4: Products       → SaaS, OSS, Enterprise         (future)
```

---

*Last updated: 2026-05-13 — Roadmap inicial*
