# Coding Standards

## Objetivo

Definir convencoes de codigo para manter consistencia entre modulos do ecossistema.

## Estrutura obrigatoria por modulo

Cada modulo deve seguir a estrutura:

- `src/` codigo fonte da biblioteca
- `include/` headers publicos e internos
- `tests/` testes de unidade e smoke tests

## Naming

- Prefixo por modulo em simbolos publicos (ex.: `ft_`, `ds_`, `algo_`)
- Arquivos em snake_case
- Headers terminam com `.h`
- Funcoes com verbos claros (`init`, `create`, `destroy`, `push`, `pop`)

## Headers

- Cada header deve ter include guard
- Expor API minima necessaria
- Documentar complexidade quando aplicavel

## Test

- Todo modulo deve suportar `make test`
- Testes devem cobrir caso feliz + edge cases
- Cada bug corrigido deve incluir teste de regressao

## Build

- Makefile do modulo deve incluir `ecosystem/build-system/module.mk`
- Defaults de build sao herdados de `common.mk`

## Erros e retorno

- Funcoes devem usar codigos de erro explicitos
- Nunca esconder falhas de alocacao
- Evitar efeitos colaterais silenciosos
