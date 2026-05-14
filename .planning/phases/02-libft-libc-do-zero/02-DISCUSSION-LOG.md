# Phase 2: libft: libc do Zero - Discussion Log

> **Audit trail only.** Do not use as input to planning, research, or execution agents.
> Decisions are captured in CONTEXT.md — this log preserves the alternatives considered.

**Date:** 2026-05-13
**Phase:** 02-libft-libc-do-zero
**Areas discussed:** escopo, contrato API, testes, ft_printf, organizacao interna

---

## Escopo do primeiro corte da libft

| Option | Description | Selected |
|--------|-------------|----------|
| A | Entregar todo TS-2 na fase 2 | ✓ |
| B | Entregar core agora e adiar parte para fase seguinte | |
| C | Outro | |

**User's choice:** A
**Notes:** Usuario quer abrangencia total do TS-2 ja nesta fase.

---

## Contrato de API e comportamento

| Option | Description | Selected |
|--------|-------------|----------|
| A | Alinhar maximo possivel com libc | |
| B | Contrato safe com checagens extras e retornos defensivos | ✓ |
| C | Outro | |

**User's choice:** B
**Notes:** Preferencia por seguranca/comportamento explicito mesmo com divergencia pontual de libc.

---

## Estrategia de testes

| Option | Description | Selected |
|--------|-------------|----------|
| A | Teste por funcao + edge cases por categoria + smoke geral | ✓ |
| B | Apenas integracao por grupo | |
| C | Outro | |

**User's choice:** A
**Notes:** Cobertura orientada por categoria e granularidade por funcao.

---

## ft_printf educacional

| Option | Description | Selected |
|--------|-------------|----------|
| A | Subset basico sem largura/precisao | |
| B | Incluir largura e precisao no v1 | ✓ |
| C | Outro | |

**User's choice:** B
**Notes:** Nivel de desafio maior ja no primeiro ciclo do printf.

---

## Organizacao interna da libft

| Option | Description | Selected |
|--------|-------------|----------|
| A | `src/memory`, `src/string`, `src/conv`, `src/io`; `include/libft.h`; `include/internal/` | ✓ |
| B | `src/` unico + header unico | |
| C | Outro | |

**User's choice:** A
**Notes:** Estrutura modular para suportar crescimento e debug por dominio.

---

## the agent's Discretion

- Implementacao interna do parser de formato do `ft_printf`.
- Escolha da abordagem de harness/framework de testes em C.
- Politica detalhada de erro por funcao, desde que consistente e documentada.

## Deferred Ideas

None.
