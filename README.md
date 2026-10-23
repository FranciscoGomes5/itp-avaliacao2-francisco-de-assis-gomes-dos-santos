# itp-avaliacao2-francisco-de-assis-gomes-dos-santos
Avaliação 2 da disciplina de ITP


# Boletim de uma Pequena Turma - ITP (Avaliação 2)

## Identificação
 * **Aluno:** [Francisco de Assis Gomes dos Santos]
 * **Opção de Projeto Escolhida:** Opção 1 - Boletim de uma pequena turma

---

## Descrição do Projeto
 O objetivo deste projeto em linguagem C é auxiliar no registro e na análise do desempenho acadêmico de uma pequena turma (entre 1 e 10 estudantes).

### Funcionalidades Implementadas:
 * **Cadastro de Turma e Estudantes:** Leitura validada do número de alunos e armazenamento de seus respectivos nomes em uma matriz de caracteres.
 * **Leitura e Validação de Notas:** Coleta de 3 notas por estudante, armazenadas em uma matriz `notas[10][3]`, garantindo que os valores estejam estritamente no intervalo de 0 a 10.
 * **Alocação Dinâmica e Cálculo de Médias:** Função dedicada que preenche um vetor alocado dinamicamente (`malloc`) na memória *heap* com as médias aritméticas dos alunos.
 * **Exibição do Boletim:** Impressão de tabela formatada contendo Nome, Notas, Média Final e Situação (*"atingiu a meta"* para média $\ge 6.0$ e *"abaixo da meta"* para os demais casos).
 * **Estatísticas Gerais:** Cálculo da média geral da turma e identificação do(s) estudante(s) com a maior média, tratando empates.
 * **Gestão Responsável de Memória:** Checagem de ponteiro nulo e liberação de memória com `free()`.

---

## Compilação e Execução

### Pré-requisitos
 * Compilador C (ex: `gcc`) instalado no sistema.

### Passo a Passo
 Utilize o arquivo main.c no seu IDE de preferência.

 ###TESTES 

 Exemplos de Teste
Exemplo 1: Funcionamento Normal (Caso Válido)
• Entradas:
	• Quantidade de estudantes: 2
	• Estudante 1: Ana Silva | Notas: 7.0, 8.0, 9.0
	• Estudante 2: Bruno Costa | Notas: 5.0, 6.0, 5.0
• Resultado Esperado:
	• Ana Silva: Média 8.00 | Situação: atingiu a meta
	• Bruno Costa: Média 5.33 | Situação: abaixo da meta
	• Média Geral da Turma: 6.67
	• Maior Média: 8.00 (Ana Silva)
Exemplo 2: Entrada Inválida e Limites
• Entradas:
	• Quantidade de estudantes: 15 $\rightarrow$ Rejeitada (deve ser entre 1 e 10)
	• Quantidade corrigida: 1
	• Nome do Estudante: Carlos
	• Nota 1: 11.0 $\rightarrow$ Rejeitada (deve ser entre 0 e 10)
	• Nota 1 corrigida: 5.0
	• Nota 2: 6.0
	• Nota 3: 7.0
• Resultado Esperado:
	• Carlos: Média 6.00 | Situação: atingiu a meta
	• Média Geral da Turma: 6.00
	• Maior Média: 6.00 (Carlos)


  ### Link do vídeo no YouTube: https://youtu.be/ID7mwC2_Dm0
