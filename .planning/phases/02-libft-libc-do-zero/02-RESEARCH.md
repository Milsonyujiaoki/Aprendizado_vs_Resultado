# Phase 2 Research — libft (libc do zero)

## Scope

Cobrir TS-2 completo nesta fase (per D-01):
- Memory primitives
- String primitives e split
- Conversao numerica
- I/O formatado (`ft_printf`) com largura e precisao
- Allocator simplificado (`ft_malloc`/`ft_free`)
- Testes unitarios e internals docs

## Constraints from Context

- D-02: contrato defensivo/safe-first com regras explicitas para entradas invalidas
- D-03: testes por funcao + matriz de edge cases por categoria + smoke geral
- D-04: `ft_printf` com `%c %s %d %i %u %x %%` + largura e precisao no v1
- D-05: layout por dominio (`src/memory`, `src/string`, `src/conv`, `src/io`) + headers internos

## Recommended implementation pattern

1. Interface-first
- Definir prototipos publicos e contratos de erro em `include/libft.h`
- Definir helpers internos em `include/internal/libft_internal.h`

2. Vertical by category
- Memory -> String -> Conv/IO
- Cada categoria com testes dedicados e casos de borda

3. Defensive contracts
- Regras explicitas para ponteiros nulos e tamanhos invalidos
- Documentar divergencias da libc em comentarios de header

4. printf architecture
- Parsing em duas etapas: scan token -> render fragment
- Estruturas internas para flags, width, precision, specifier

5. Allocator simplificado
- Arena linear minima para objetivo educacional
- `ft_free` como no-op documentado no v1 (ou reset por arena), explicitando limites

## Pitfalls to avoid

- Misturar contratos de erro diferentes entre funcoes similares
- Implementar `printf` sem separar parser de emissao
- Falta de testes para overlap (`memmove`) e limites de `width/precision`
- Acoplar testes de todas categorias em um unico arquivo gigante

## Verification strategy

- Verificacao estrutural via `rg` para prototipos e organizacao de arquivos
- Verificacao funcional via suite de testes por categoria
- Smoke geral consolidando fluxo minimo de build/test

---
Generated on 2026-05-13
