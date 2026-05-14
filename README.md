# Aprendizado_vs_Resultado

> Um ecossistema pessoal de engenharia construído do zero.  
> Filosofia: entender antes de abstrair, construir antes de usar.

---

## O que é isso?

Um laboratório de engenharia vivo que serve como:

- **Plataforma de aprendizado profundo** — cada componente construído do zero com foco em internals
- **Stack de infraestrutura reutilizável** — libs, tooling e sistemas que se compõem
- **Portfólio de produtos monetizáveis** — componentes que evoluem para produtos reais

Inspirado por: Andrej Karpathy, filosofia Unix, cultura de sistemas, engenharia open source.

---

## Estrutura do Ecossistema

```
Aprendizado_vs_Resultado/
│
├── foundation/         ← Bibliotecas C do zero (libft, libds, libalgo, libparser)
├── monetizable/        ← Componentes com potencial comercial
├── infrastructure/     ← Runtime, VM, networking, distributed systems
├── platform/           ← AI runtime, inference server, vector DB, orchestration
├── products/           ← SaaS, CLI tools, automation, AI tools
├── research/           ← Papers, benchmarks, experimentos, protótipos
├── docs/               ← Arquitetura, diagramas, aprendizado, monetização
└── ecosystem/          ← Build system, templates, padrões, DX
```

---

## Progressão

```
M1: Foundation     → C libs + build system         ← você está aqui
       ↓
M2: Infrastructure → Runtime, VM, Networking
       ↓
M3: Platform       → AI infra, tooling, databases
       ↓
M4: Products       → SaaS, OSS, Enterprise
```

---

## Bootstrap da Foundation

### 1) Criar um modulo novo

Use o template em `ecosystem/standards/MODULE_TEMPLATE.md` para iniciar um modulo com estrutura `src/include/tests`.

### 2) Integrar no build-system compartilhado

No Makefile do modulo, inclua:

```make
ROOT := ../..
MODULE_NAME := nome_do_modulo
SRC_DIR := src
INCLUDE_DIR := include
TEST_DIR := tests

include $(ROOT)/ecosystem/build-system/module.mk
```

### 3) Comandos padrao

- `make` para build da biblioteca
- `make test` para executar testes
- `make install PREFIX=$HOME/.local` para instalar headers e lib

### 4) Standards obrigatorios

- `ecosystem/standards/CODING_STANDARDS.md`
- `ecosystem/standards/ADR_TEMPLATE.md`
- `ecosystem/standards/INTERNALS_TEMPLATE.md`

---

## Começando

```bash
# Clonar o repositório
git clone https://github.com/Milsonyujiaoki/Aprendizado_vs_Resultado.git
cd Aprendizado_vs_Resultado

# Construir uma biblioteca de foundation
cd foundation/libft
make

# Rodar testes
make test

# Ver planejamento do projeto
cat .planning/ROADMAP.md
cat .planning/STATE.md
```

---

## Filosofia

1. **First Principles** — Nunca tratar frameworks como magia. Mostrar como as coisas funcionam internamente.
2. **Build From Scratch** — Reimplementar versões simplificadas antes de usar abstrações.
3. **Progressive Complexity** — `simple → modular → reusable → scalable → production-grade`
4. **Tooling Mindset** — Tudo evolui para: libs reutilizáveis, tooling interno, plataformas de desenvolvimento.
5. **Engineering Taste** — Favorecer clareza, simplicidade, explicitude, composabilidade, debuggabilidade.

---

*Iniciado em 2026-05-13*
