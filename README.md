# CPU Simulator

Um simulador de processador para uma arquitetura hipotética. Esta arquitetura consiste em _____. O processador que será desenvolvido será monociclo, podendo ser atualzado para um processador pipeline.

## Instruções para implementação

- [ ] add
- [ ] sub
- [ ] mul
- [ ] div
- [ ] cmp_equal
- [ ] cmp_neq
- [ ] load
- [ ] store
- [ ] jump
- [ ] jump_cond
- [ ] mov
- [ ] syscall

A implementação será feita o mais próximo possível da operação real do processador, de forma funcional (não no nível de circuito), separando as diferentes etapas de processamento.


## Processador pipeline

Para a obtenção do conceito A no projeto, será necessário a implementação de um processador pipeline, com os seguintes estágios: 

- [ ] Busca de instrução
- [ ] Decodificação de instrução
- [ ] Leitura de operandos, Execução e Write-back

E também conter um pretidor de desvio dinâmico.

Sugestão: implementar primeiro o modelo monociclo, e depois evoluir para pipeline.

A equipe deverá também escrever códigos assembly para testar o simulador.

