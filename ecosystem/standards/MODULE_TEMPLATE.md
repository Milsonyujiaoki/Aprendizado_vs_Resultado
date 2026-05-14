# Module Template

Template canônico para novos modulos do ecossistema.

## Estrutura

```
module-name/
  include/
    module_name.h
  src/
    module_name.c
  tests/
    test_module_name.c
  Makefile
  README.md
  INTERNALS.md
```

## Makefile minimo

```make
ROOT := ../..
MODULE_NAME := module_name
SRC_DIR := src
INCLUDE_DIR := include
TEST_DIR := tests

include $(ROOT)/ecosystem/build-system/module.mk
```

## README minimo

- Objetivo do modulo
- API principal
- Como compilar (`make`)
- Como testar (`make test`)
- Como instalar (`make install`)

## Checklist de criacao

- [ ] Estrutura `src/include/tests` criada
- [ ] Header com include guard
- [ ] Smoke test em `tests/`
- [ ] Makefile com include do `module.mk`
- [ ] `INTERNALS.md` criado
