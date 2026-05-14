# Learning Path

Ordem recomendada para obter alavancagem tecnica no ecossistema.

## Milestone 1 (Foundation + Ecosystem Bootstrap)

1. `ecosystem/build-system`
- Entender `common.mk` e `module.mk`
- Rodar `make`, `make test`, `make install` em um modulo de exemplo

2. `ecosystem/standards`
- Ler `CODING_STANDARDS.md`
- Aplicar `MODULE_TEMPLATE.md` para criar um modulo novo

3. `foundation/libft`
- Implementar funcoes basicas de memoria e string
- Validar API publica por testes

4. `foundation/libds`
- Construir estruturas core (array, list, stack, queue)
- Medir complexidade e comportamento em edge cases

5. `foundation/libalgo`
- Implementar sorting e search com benchmark
- Registrar tradeoffs entre algoritmos

6. `foundation/libparser`
- Implementar tokenizer
- Evoluir para parser de expressoes e JSON

## Milestones seguintes

- Milestone 2: runtime, vm, networking, distributed systems
- Milestone 3: ai runtime, vector database, orchestration
- Milestone 4: products (saas, cli, enterprise tooling)

## Regra de progressao

So avancar quando o modulo atual tiver:
- build reproduzivel
- test suite minima
- INTERNALS documentado
