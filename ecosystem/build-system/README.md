# Build System

Camada compartilhada de build para qualquer modulo do ecossistema.

## Estrutura

- `common.mk`: defaults de compilador, flags e diretorios
- `module.mk`: targets padrao (`all`, `test`, `clean`, `install`)
- `examples/foundation-libft.mk`: exemplo canonico para modulo da foundation

## Contrato minimo do modulo

Variaveis opcionais (com defaults):

- `MODULE_NAME` (default: `module`)
- `SRC_DIR` (default: `src`)
- `INCLUDE_DIR` (default: `include`)
- `TEST_DIR` (default: `tests`)
- `BUILD_MODE` (`debug` ou `release`)
- `PREFIX` e `DESTDIR` para instalacao

## Integracao minima

```make
ROOT := ../..
MODULE_NAME := libft
SRC_DIR := src
INCLUDE_DIR := include
TEST_DIR := tests

include $(ROOT)/ecosystem/build-system/module.mk
```

## Comandos padrao

- `make` ou `make all`: compila biblioteca estaticas
- `make test`: compila e executa testes do modulo
- `make clean`: remove artefatos de build
- `make install PREFIX=$HOME/.local`: instala headers e lib

## Observacoes

- `BUILD_MODE=debug` e o default
- Use `BUILD_MODE=release` para otimizar binarios
