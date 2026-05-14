---
phase: 02-libft-libc-do-zero
plan: 02
subsystem: foundation/libft
tags: [string, strsplit, tests]
dependency_graph:
  requires: [02-01 (libft.h public API, memory category)]
  provides: [foundation/libft/src/string/*.c, foundation/libft/tests/string/*.c]
  affects: [foundation/libft/include/libft.h (string prototypes already present)]
tech_stack:
  added: []
  patterns: [safe-first contracts (D-02), per-function test matrix (D-03), two-pass split algorithm]
key_files:
  created:
    - foundation/libft/src/string/ft_strlen.c
    - foundation/libft/src/string/ft_strcpy.c
    - foundation/libft/src/string/ft_strcat.c
    - foundation/libft/src/string/ft_strcmp.c
    - foundation/libft/src/string/ft_strdup.c
    - foundation/libft/src/string/ft_strsplit.c
    - foundation/libft/tests/string/test_string.c
    - foundation/libft/tests/string/test_strsplit.c
  modified: []
decisions:
  - "ft_strdup uses stdlib malloc (not ft_malloc) — arena cannot guarantee individually freeable pointers"
  - "ft_strsplit two-pass algorithm: count tokens first, then allocate array, then fill with ft_strdup"
  - "Consecutive delimiter collapse implemented via in_token flag in count_tokens"
  - "ft_strcmp returns 0 on NULL input (documented divergence, safe-first)"
metrics:
  duration: ~20min
  completed: 2026-05-13
  tasks_completed: 3
  files_created: 8
---

# Phase 2 Plan 02: String Category — SUMMARY

**One-liner:** Cinco funções string nucleares (`strlen/strcpy/strcat/strcmp/strdup`) e `ft_strsplit` (dois-passagens, colapso de delimitadores consecutivos) implementadas com safe-first; suites de testes com matriz de edge cases por função.

## Tasks Executadas

| Task | Nome                               | Commit   | Arquivos                                                         |
| ---- | ---------------------------------- | -------- | ---------------------------------------------------------------- |
| 1    | Funções string nucleares           | e75f52d  | ft_strlen/strcpy/strcat/strcmp/strdup                             |
| 2    | ft_strsplit defensivo              | c442292  | ft_strsplit.c                                                    |
| 3    | Testes string e split              | f67e5ab  | test_string.c, test_strsplit.c                                   |

## Deviations from Plan

**1. [Rule 2 - Missing Critical] ft_strdup usa stdlib malloc**
- **Found during:** Task 1
- **Rationale:** ft_strdup deve retornar ponteiros individualmente liberáveis com `free()`. A arena v1 não suporta deallocation individual. Uso de stdlib malloc documentado no cabeçalho da função.
- **Files modified:** foundation/libft/src/string/ft_strdup.c

**2. [Rule 2 - Missing Critical] ft_strsplit usa stdlib malloc internamente**
- **Found during:** Task 2
- **Rationale:** Mesmo motivo que ft_strdup — tokens precisam ser individualmente liberáveis. Função free_partial adicionada para cleanup em falha de alocação intermediária (sem memória leak).
- **Files modified:** foundation/libft/src/string/ft_strsplit.c

## Threat Mitigations

| Threat | Mitigation aplicada |
| ------ | ------------------- |
| T-02-04 (ft_strsplit D) | NULL check no início + free_partial em falha de alloc |
| T-02-05 (string copy T) | Preconditions documentadas em cada função |
| T-02-06 (test coverage R) | Matriz por função com cases nomeados + suite dedicada de split |

## Self-Check: PASSED

- [x] `foundation/libft/src/string/ft_str*.c` (6 arquivos) existem
- [x] `foundation/libft/tests/string/test_string.c` existe
- [x] `foundation/libft/tests/string/test_strsplit.c` existe
- [x] Commits e75f52d, c442292, f67e5ab presentes no log
