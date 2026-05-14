# Phase 1 Research — Ecosystem Infrastructure

## Scope

Fase 1 cobre TS-1 e TS-6:
- Build system modular em Make para todos os modulos
- Standards e templates para padronizar novos modulos

## Recommended Stack

- Build: GNU Make
- Compiler defaults: cc (override por variaveis)
- Test runner: alvo padrao `make test` por modulo
- Install target: PREFIX configuravel, default `$(HOME)/.local`

## Architecture Patterns

1. Layered Make includes
- Root configura variaveis globais
- `module.mk` define alvos comuns
- Modulo apenas declara metadata (`MODULE_NAME`, `SRC_DIR`, `INCLUDE_DIR`)

2. Convention over configuration
- Estrutura canônica: `src/`, `include/`, `tests/`
- Alvos obrigatorios: `all`, `test`, `clean`, `install`

3. Reuse-first templates
- Template de modulo ja com Makefile, README, teste smoke
- Templates de docs para ADR e INTERNALS

## Common Pitfalls

- Acoplar flags de debug e release no mesmo alvo sem isolamento
- Hardcode de paths absolutos
- Ignorar `DESTDIR`/`PREFIX` no install
- Nao expor interface minima de variaveis para modulos

## Security/Trust Notes

- Boundary principal: entrada de ambiente/shell para variaveis Make
- Mitigar com defaults seguros e sem execucao de comandos externos dinamicos

## Decisions For Planning

- Usar Make como sistema principal da fase (sem CMake nesta fase)
- Entregar script bootstrap de modulo como parte de DX baseline
- Entregar docs padrao em `ecosystem/standards`

---
Generated on 2026-05-13
