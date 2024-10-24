
# Comparativo de desempenho de algoritmos de ordenação em C

Essa pesquisa faz parte da disciplina de Estrutura de Dados e objetiva demonstrar o desempenho de algoritmos de ordenação, semelhante ao trabalho desenvolvido por Souza, Ricarte e de Almeida Lima (2017).

Nove casos foram propostos. Foi necessário utilizar 3 tipos de vetores: ordenados, invertidos e aleatórios (melhor, pior e médio caso respectivamente). O tamanho dos vetores para teste foram de mil, 100 mil e 1 milhão de elementos.

A partir disso, implementei um programa em C com base nos códigos  de ordenação disponibilizados pelo professor [Ednilson](https://github.com/ednilsonrossi), com o acréscimo de contadores de comparações, trocas e tempo de execução, além de adaptações para permitir a execução no Windows manipulando a memória Heap.

Dessa forma, apliquei para cada um dos tamanhos de vetor um teste que executava cada um dos casos (melhor, pior e médio) três vezes e anotei as médias que estão dispostas nas tabelas a seguir.

## Comparativo

<table>
  <thead>
    <tr>
        <th colspan="10">Mil elementos</th>
    </tr>
  </thead>
    <tr>
        <td></td>
        <td colspan="3">MELHOR</td>
        <td colspan="3">PIOR</td>
        <td colspan="3">MÉDIO</td>
    </tr>
    <tr>
        <td></td>
        <td>Comp.</td>
        <td>Trocas</td>
        <td>Tempo</td>
        <td>Comp.</td>
        <td>Trocas</td>
        <td>Tempo</td>
        <td>Comp.</td>
        <td>Trocas</td>
        <td>Tempo</td>
    </tr>
    <tr>
        <td>BUBBLE</td>
        <td>326007</td>
        <td>83032,67</td>
        <td>0,002</td>
        <td>999000</td>
        <td>499500</td>
        <td>0,004</td>
        <td>976023</td>
        <td>251572,33</td>
        <td>0,005</td>
    </tr>
    <tr>
        <td>INSERT</td>
        <td>999</td>
        <td>83032,67</td>
        <td>0,001</td>
        <td>999</td>
        <td>499500</td>
        <td>0,002</td>
        <td>999</td>
        <td>451572,33</td>
        <td>0,002</td>
    </tr>
    <tr>
        <td>SELECTION</td>
        <td>3499500</td>
        <td>1000</td>
        <td>0,003</td>
        <td>499500</td>
        <td>1000</td>
        <td>0,002</td>
        <td>499500</td>
        <td>1000</td>
        <td>0,002</td>
    </tr>
    <tr>
        <td>MERGE</td>
        <td>6250,33</td>
        <td>11397,67</td>
        <td>0,000</td>
        <td>4932</td>
        <td>14908</td>
        <td>0,000</td>
        <td>8688,33</td>
        <td>14284,33</td>
        <td>0,000</td>
    </tr>
    <tr>
        <td>QUICK</td>
        <td>337371</td>
        <td>1475</td>
        <td>0,001</td>
        <td>499999</td>
        <td>999</td>
        <td>0,001</td>
        <td>11274,67</td>
        <td>2406,33</td>
        <td>0,000</td>
    </tr>
</table>

## Gráficos

## Resultados


## Referência

SOUZA, Jackson EG; RICARTE, João Victor G.; DE ALMEIDA LIMA, Náthalee Cavalcanti. Algoritmos
de Ordenação: Um estudo comparativo. Anais do Encontro de Computação do Oeste Potiguar
ECOP/UFERSA (ISSN 2526-7574), n. 1, 2017.
