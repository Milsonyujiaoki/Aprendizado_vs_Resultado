---
phase: 02-libft-libc-do-zero
plan: 01
subsystem: foundation/libft
tags: [memory, contracts, build-system, tests]
dependency_graph:
  requires: [ecosystem/build-system/module.mk]
  provides: [foundation/libft/include/libft.h, foundation/libft/src/memory/*.c]
  affects: [foundation/libft/tests/memory/, foundation/libft/tests/smoke/]
tech_stack:
  added: [C, Makefile include pattern]
  patterns: [safe-first contracts (D-02), per-function test matrix (D-03), module.mk integration]
key_files:
  created:
    - foundation/libft/Makefile
    - foundation/libft/include/libft.h
    - foundation/libft/include/internal/libft_internal.h
    - foundation/libft/src/memory/ft_memset.c
    - foundation/libft/src/memory/ft_bzero.c
    - foundation/libft/src/memory/ft_memcpy.c
    - foundation/libft/src/memory/ft_memmove.c
    - foundation/libft/tests/memory/test_memory.c
    - foundation/libft/tests/smoke/test_smoke.c
  modified: []
decisions:
  - "D-02 enforced: all functions return NULL on NULL input with n>0 (safe-first, documented divergence from libc)"
  - "D-05 layout enforced: src/memory/, include/libft.h public, include/internal/libft_internal.h private"
  - "ft_bzero implemented as thin wrapper over ft_memset for educational clarity"
  - "ft_memmove uses pointer comparison to select forward vs backward copy path"
  - "Internal header pre-declares printf pipeline types (t_fmt_spec) and arena struct for use in 02-03"
metrics:
  duration: ~25min
  completed: 2026-05-13
  tasks_completed: 3
  files_created: 9
---

# Phase 2 Plan 01: Contratos e Memória — SUMMARY

**One-liner:** Contratos públicos e internos da libft estabelecidos via `libft.h` + `libft_internal.h`; quatro funções de memória implementadas com safe-first e overlap-safe, cobertas por testes de edge cases e smoke.

## Tasks Executadas

| Task | Nome                               | Commit   | Arquivos                                          |
| ---- | ---------------------------------- | -------- | ------------------------------------------------- |
| 1    | Contratos públicos/internos + Make | 38c38b9  | Makefile, libft.h, libft_internal.h               |
| 2    | Funções memory fundamentais        | 023aa7b  | ft_memset.c, ft_bzero.c, ft_memcpy.c, ft_memmove.c |
| 3    | Testes memory e smoke              | 947474b  | test_memory.c, test_smoke.c                       |

## Deviations from Plan

**1. [Rule 2 - Missing Critical] Internal header pré-declara tipos de 02-03**
- **Found during:** Task 1
- **Rationale:** O pipeline do ft_printf (t_fmt_spec, ft_printf_parse, ft_printf_emit) e o struct de arena precisam de um único ponto de definição. Defini-los no header interno agora evita retrabalho e divergência nos planos 02-02 e 02-03.
- **Files modified:** foundation/libft/include/internal/libft_internal.h

**2. [Rule 2 - Missing Critical] smoke test usa #ifdefs comentados como stubs rastreáveis**
- **Found during:** Task 3
- **Rationale:** O smoke test não pode chamar símbolos ainda não implementados (string/conv/io). Seções comentadas com nota "Uncomment when 02-0X lands" permitem verificação incremental e evitam build errors.

## Known Stubs

| Stub | Arquivo | Razão |
| ---- | ------- | ----- |
| Seção string no smoke | tests/smoke/test_smoke.c | símbolos string chegam no 02-02 |
| Seção conv/io no smoke | tests/smoke/test_smoke.c | símbolos conv/io chegam no 02-03 |

## Threat Mitigations

| Threat | Mitigation aplicada |
| ------ | ------------------- |
| T-02-01 (ft_memmove/memcpy D) | Defensive NULL check + backward-copy path para overlap |
| T-02-02 (header contracts T) | Invariantes documentados em cada protótipo com PRECONDITIONS |
| T-02-03 (test coverage R) | Matriz por função: NULL, n==0, overlap, valor zero vs não-zero |

## Self-Check: PASSED

- [x] `foundation/libft/Makefile` existe
- [x] `foundation/libft/include/libft.h` existe
- [x] `foundation/libft/include/internal/libft_internal.h` existe
- [x] `foundation/libft/src/memory/ft_mem*.c` (4 arquivos) existem
- [x] `foundation/libft/tests/memory/test_memory.c` existe
- [x] `foundation/libft/tests/smoke/test_smoke.c` existe
- [x] Commits 38c38b9, 023aa7b, 947474b presentes no log
