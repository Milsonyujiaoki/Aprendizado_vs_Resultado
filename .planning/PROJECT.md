# Aprendizado_vs_Resultado

## What This Is

Um ecossistema pessoal de engenharia construído do zero, que serve simultaneamente como laboratório de aprendizado profundo e plataforma de engenharia monetizável. Projetado para maximizar o entendimento de sistemas, arquitetura e infraestrutura AI — na filosofia de Karpathy: entender antes de abstrair, construir antes de usar.

## Core Value

Transformar aprendizado em leverage real: cada componente construído deve ser simultaneamente educacional, reusável e potencialmente monetizável.

## Requirements

### Validated

<!-- Nada ainda — shipar para validar -->

(None yet)

### Active

- [ ] foundation/libft — Implementação educacional de libc do zero em C
- [ ] foundation/libds — Estruturas de dados fundamentais (listas, árvores, hash maps, grafos)
- [ ] foundation/libalgo — Algoritmos clássicos com análise de complexidade
- [ ] foundation/libparser — Parser combinators e tokenizers do zero
- [ ] ecosystem/build-system — Makefile/CMake system reutilizável para todos os módulos
- [ ] ecosystem/templates — Templates de projeto para cada categoria do ecossistema
- [ ] ecosystem/standards — Guias de estilo, convenções de código e diretrizes de arquitetura
- [ ] docs/architecture — Documentação de decisões arquiteturais (ADRs)

### Out of Scope (v1)

- SaaS products — deferido para Milestone 3+ após base sólida
- AI inference server — deferido para Milestone 2+ após foundation
- Distributed systems — deferido para Milestone 2+ após runtime/vm
- Cloud platform deployment — deferido para Milestone 3+

## Context

- **Repositório**: Novo, vazio, greenfield
- **Abordagem**: Build from scratch, first principles
- **Linguagens**: C (foundation/systems), C++ (performance-critical), Python (scripting/AI), Go (tooling/infra)
- **Filosofia**: Unix philosophy + Karpathy-style learning
- **Stack**: Local-first, sem dependências externas nas bibliotecas de foundation
- **Inspirações**: xv6, Redis source, CPython internals, Linux kernel, LLVM

## Constraints

- **Linguagem/Foundation**: C puro para libft/libds/libalgo — sem stdlib exceto onde explicitamente permitido
- **Dependências**: Minimizar dependências externas nas libs de foundation
- **Qualidade**: Cada módulo deve ter testes e documentação de internals
- **Progressão**: Sempre implementar versão educacional antes da versão otimizada

## Key Decisions

| Decision | Rationale | Outcome |
|----------|-----------|---------|
| C como linguagem primária de foundation | Máxima exposição a gestão de memória, ponteiros e internals de sistema | — Pending |
| Build system próprio com Make | Evitar dependência de ferramentas complexas no início, entender o processo de build | — Pending |
| Estrutura monorepo por categoria | Permite reuso entre módulos e evolução incremental do ecossistema | — Pending |
| Roadmap coarse-grained | Foco em completar milestones amplos antes de detalhar fases futuras | — Pending |

---
*Last updated: 2026-05-13 — Inicialização do projeto*
