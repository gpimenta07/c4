# Batalha Naval com Habilidades Especiais - Nível Mestre

## Descrição do Projeto

Este projeto é uma extensão do clássico jogo de Batalha Naval, desenvolvido em C, que adiciona um elemento estratégico avançado através da implementação de habilidades especiais com áreas de efeito distintas. O objetivo é representar visualmente no tabuleiro as áreas afetadas por habilidades em formatos diferentes: Cone, Cruz e Octaedro.

## Funcionalidades

- Tabuleiro 10x10 para a visualização do jogo.
- Matrizes de habilidades especiais que representam diferentes áreas de efeito:
  - **Cone:** Área em formato de cone, com ponto de origem no topo e expandindo para baixo.
  - **Cruz:** Área em formato de cruz, com ponto de origem central.
  - **Octaedro:** Área em formato de losango, representando a vista frontal de um octaedro, com ponto de origem central.
- Sobreposição das áreas de efeito das habilidades no tabuleiro, com visualização clara dos espaços afetados.
- Diferenciação visual entre água, navios e áreas afetadas pelas habilidades.
- Implementação dinâmica das matrizes de habilidade utilizando loops e condicionais.
- Garantia de que as áreas de efeito não ultrapassem os limites do tabuleiro.

## Como Funciona

1. **Tabuleiro Base:** Mantém o estado inicial com posições de água (0) e navios (3).
2. **Matrizes de Habilidades:** Criadas dinamicamente para representar as formas de área de efeito das habilidades usando valores binários (0 = não afeta, 1 = afeta).
3. **Ponto de Origem:** Cada habilidade tem um ponto central no tabuleiro onde a área de efeito será aplicada.
4. **Sobreposição:** A matriz de habilidade é aplicada sobre o tabuleiro, marcando as posições afetadas com um valor distinto (5).
5. **Exibição:** O tabuleiro é exibido no console, mostrando:
   - `0` para água
   - `3` para navios
   - `5` para área afetada pela habilidade

## Estrutura do Código

- **Inicialização do Tabuleiro:** Define a matriz 10x10 com navios e água.
- **Funções para Construção das Habilidades:**
  - `construirCone()`
  - `construirCruz()`
  - `construirOctaedro()`
- **Função para Aplicar Habilidades:** Sobrepõe a matriz da habilidade sobre o tabuleiro centralizando no ponto de origem.
- **Função para Exibir o Tabuleiro:** Exibe a matriz final no console com os caracteres representativos.

## Instruções para Compilar e Executar

1. Clone ou baixe este repositório.
2. Compile o programa utilizando um compilador C, por exemplo:

   ```bash
   gcc batalha_naval_habilidades.c -o batalha_naval
