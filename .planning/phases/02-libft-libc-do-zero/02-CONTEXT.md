# Phase 2: libft: libc do Zero - Context

**Gathered:** 2026-05-13
**Status:** Ready for planning

<domain>
## Phase Boundary

Entregar a primeira biblioteca `foundation/libft` com implementacoes educacionais em C para funcoes fundamentais de memoria, strings, conversao e I/O formatado (`ft_printf`), com testes unitarios e documentacao de internals por categoria.

</domain>

<decisions>
## Implementation Decisions

### Escopo de entrega da fase
- **D-01:** A fase 2 deve entregar TODO o escopo de TS-2 ja nesta fase (memory, string, conversao, `ft_printf`, `ft_strsplit`, `ft_malloc/ft_free` com allocator simplificado).

### Contrato de API e comportamento
- **D-02:** Priorizar contrato mais defensivo/safe, com checagens extras e retornos defensivos quando necessario, mesmo que haja divergencia pontual do comportamento exato da libc.

### Estrategia de testes
- **D-03:** Estruturar testes por funcao + matriz de edge cases por categoria (`memory`, `string`, `conv`, `io`) + smoke geral da lib.

### Escopo do ft_printf educacional
- **D-04:** Implementar `ft_printf` v1 com `%c %s %d %i %u %x %%` E incluir largura e precisao ja no v1.

### Organizacao interna da lib
- **D-05:** Organizar `libft` em `src/memory`, `src/string`, `src/conv`, `src/io`; header publico em `include/libft.h`; headers internos em `include/internal/`.

### the agent's Discretion
- Detalhes internos de parser do formato do `ft_printf` (state machine vs parser em etapas), desde que cumpra D-04.
- Estrategia especifica de erro por funcao, desde que documentada e consistente com D-02.
- Escolha da ferramenta de teste C (framework leve ou harness proprio), desde que cumpra D-03.

</decisions>

<canonical_refs>
## Canonical References

**Downstream agents MUST read these before planning or implementing.**

### Fase e requisitos oficiais
- `.planning/ROADMAP.md` — Define goal, plans previstos e criterios de sucesso da Phase 2.
- `.planning/REQUIREMENTS.md` — Define TS-2 completo (funcoes, allocator simplificado, testes e internals).
- `.planning/PROJECT.md` — Define filosofia de implementacao (first-principles, build-from-scratch, C como base).
- `.planning/STATE.md` — Estado atual do projeto e sequencia de fases.

### Convencoes e padroes herdados da fase 1
- `ecosystem/standards/CODING_STANDARDS.md` — Convencoes obrigatorias de estrutura e testes.
- `ecosystem/standards/MODULE_TEMPLATE.md` — Blueprint de modulo para layout canônico.
- `ecosystem/standards/INTERNALS_TEMPLATE.md` — Formato esperado para documentacao de internals.
- `ecosystem/build-system/module.mk` — Contrato de build/test/install padrao para os modulos.

</canonical_refs>

<code_context>
## Existing Code Insights

### Reusable Assets
- `ecosystem/build-system/common.mk` / `ecosystem/build-system/module.mk`: ja fornece alvos `all/test/clean/install` para encaixar `foundation/libft`.
- `ecosystem/standards/*`: templates e standards prontos para guiar organizacao e docs da lib.

### Established Patterns
- Estrutura de modulo padrao em `src/`, `include/`, `tests/` ja definida na fase 1.
- Documentacao de internals e decisoes arquiteturais padronizada por templates.

### Integration Points
- `foundation/libft/` ja existe com estrutura inicial vazia (`src/include/tests`) pronta para implementacao.
- `foundation/libft/Makefile` deve consumir `ecosystem/build-system/module.mk` no plano de execucao.

</code_context>

<specifics>
## Specific Ideas

- Foco em aprendizado profundo de internals de memoria/strings antes de escalar para fases seguintes.
- Decisao explicita por contrato defensivo (safe-first) em vez de clone estrito da libc.
- `ft_printf` com largura e precisao ja no primeiro corte da fase.

</specifics>

<deferred>
## Deferred Ideas

- Nenhuma nova capacidade fora de TS-2 foi adicionada nesta discussao.

</deferred>

---

*Phase: 02-libft-libc-do-zero*
*Context gathered: 2026-05-13*
