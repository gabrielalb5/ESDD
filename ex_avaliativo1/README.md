
# Comparativo de desempenho de algoritmos de ordenação em C

Essa pesquisa faz parte da disciplina de Estrutura de Dados e objetiva demonstrar o desempenho de algoritmos de ordenação, semelhante ao trabalho desenvolvido por Souza, Ricarte e de Almeida Lima (2017).

Nove casos foram propostos. Foi necessário utilizar 3 tipos de vetores: ordenados, invertidos e aleatórios (melhor, pior e médio caso respectivamente). O tamanho dos vetores para teste foram de mil, 100 mil e 1 milhão de elementos.

A partir disso, implementei um programa em C com base nos códigos  de ordenação disponibilizados pelo professor [Ednilson](https://github.com/ednilsonrossi), com o acréscimo de contadores de comparações, trocas e tempo de execução, além de adaptações para permitir a execução no Windows manipulando a memória Heap.

Dessa forma, apliquei para cada um dos tamanhos de vetor um teste que executava cada um dos casos (melhor, pior e médio) três vezes e anotei as médias que estão dispostas nas tabelas a seguir.

## Comparativo
### Resultado médio de testes
<table>
  <thead>
    <tr>
      <th colspan=10>Mil elementos</th>
    </tr>
    <tr>
        <th></th>
        <th colspan=3>MELHOR</th>
        <th colspan=3>PIOR</th>
        <th colspan=3>MÉDIO</th>
    </tr>
  </thead>
  <tbody>
    <tr>
        <td></td>
        <td>COMPARAÇÕES</td>
        <td>TROCAS</td>
        <td>TEMPO</td>
        <td>COMPARAÇÕES</td>
        <td>TROCAS</td>
        <td>TEMPO</td>
        <td>COMPARAÇÕES</td>
        <td>TROCAS</td>
        <td>TEMPO</td>
    </tr>
    <tr>
        <td>BUBBLE</td>
        <td>999</td>
        <td>0</td>
        <td>0,0013</td>
        <td>999000</td>
        <td>499500</td>
        <td>0,0040</td>
        <td>964368</td>
        <td>251729</td>
        <td>0,0030</td>
    </tr>
    <tr>
        <td>INSERT</td>
        <td>999</td>
        <td>0</td>
        <td>0,0003</td>
        <td>999</td>
        <td>499500</td>
        <td>0,0020</td>
        <td>999</td>
        <td>251729</td>
        <td>0,0010</td>
    </tr>
    <tr>
        <td>SELECTION</td>
        <td>499500</td>
        <td>1000</td>
        <td>0,0030</td>
        <td>499500</td>
        <td>1000</td>
        <td>0,0020</td>
        <td>499500</td>
        <td>1000</td>
        <td>0,0023</td>
    </tr>
    <tr>
        <td>MERGE</td>
        <td>5044</td>
        <td>9976</td>
        <td>0,0000</td>
        <td>4932</td>
        <td>14908</td>
        <td>0,0000</td>
        <td>8686</td>
        <td>14275</td>
        <td>0,0003</td>
    </tr>
    <tr>
        <td>QUICK</td>
        <td>8834</td>
        <td>193</td>
        <td>0,0000</td>
        <td>8837</td>
        <td>1693</td>
        <td>0,0000</td>
        <td>11766</td>
        <td>2503</td>
        <td>0,0000</td>
    </tr>
  </tbody>
</table>

<table>
  <thead>
    <tr>
      <th colspan=10>100 Mil elementos</th>
    </tr>
    <tr>
        <th></th>
        <th colspan=3>MELHOR</th>
        <th colspan=3>PIOR</th>
        <th colspan=3>MÉDIO</th>
    </tr>
  </thead>
  <tbody>
     <tr>
        <td></td>
        <td>COMPARAÇÕES</td>
        <td>TROCAS</td>
        <td>TEMPO</td>
        <td>COMPARAÇÕES</td>
        <td>TROCAS</td>
        <td>TEMPO</td>
        <td>COMPARAÇÕES</td>
        <td>TROCAS</td>
        <td>TEMPO</td>
    </tr>
    <tr>
        <td>BUBBLE</td>
        <td>99999</td>
        <td>0</td>
        <td>0,0010</td>
        <td>9999900000</td>
        <td>4999950000</td>
        <td>27,7183</td>
        <td>9955500444</td>
        <td>2503891391</td>
        <td>33,1900</td>
    </tr>
    <tr>
        <td>INSERT</td>
        <td>99999</td>
        <td>0</td>
        <td>0,0010</td>
        <td>99999</td>
        <td>4999950000</td>
        <td>12,0623</td>
        <td>99999</td>
        <td>2503891391</td>
        <td>5,8307</td>
    </tr>
    <tr>
        <td>SELECTION</td>
        <td>4999950000</td>
        <td>100000</td>
        <td>8,9123</td>
        <td>4999950000</td>
        <td>100000</td>
        <td>9,0360</td>
        <td>4999950000</td>
        <td>100000</td>
        <td>8,7600</td>
    </tr>
    <tr>
        <td>MERGE</td>
        <td>853904</td>
        <td>1668928</td>
        <td>0,0340</td>
        <td>815024</td>
        <td>2483952</td>
        <td>0,0343</td>
        <td>1536329</td>
        <td>2428689</td>
        <td>0,0383</td>
    </tr>
    <tr>
        <td>QUICK</td>
        <td>1555496</td>
        <td>126196</td>
        <td>0,0047</td>
        <td>1555500</td>
        <td>176196</td>
        <td>0,0043</td>
        <td>2063052</td>
        <td>403540</td>
        <td>0,0110</td>
    </tr>
  </tbody>
</table>

<table>
  <thead>
    <tr>
      <th colspan=10>1 Milhão de elementos</th>
    </tr>
    <tr>
        <th></th>
        <th colspan=3>MELHOR</th>
        <th colspan=3>PIOR</th>
        <th colspan=3>MÉDIO</th>
    </tr>
  </thead>
  <tbody>
    <tr>
        <td></td>
        <td>COMPARAÇÕES</td>
        <td>TROCAS</td>
        <td>TEMPO</td>
        <td>COMPARAÇÕES</td>
        <td>TROCAS</td>
        <td>TEMPO</td>
        <td>COMPARAÇÕES</td>
        <td>TROCAS</td>
        <td>TEMPO</td>
    </tr>
     <tr>
        <td>BUBBLE</td>
        <td>999999</td>
        <td>0</td>
        <td>0,0030</td>
        <td>999999000000</td>
        <td>499999500000</td>
        <td>3191,0133</td>
        <td>998465001534</td>
        <td>250154201104</td>
        <td>3958,679751</td>
    </tr>
    <tr>
        <td>INSERT</td>
        <td>999999</td>
        <td>0</td>
        <td>0,0033</td>
        <td>999999</td>
        <td>499999500000</td>
        <td>1174,3257</td>
        <td>999999</td>
        <td>250154201104</td>
        <td>690,454152</td>
    </tr>
    <tr>
        <td>SELECTION</td>
        <td>499999500000</td>
        <td>1000000</td>
        <td>878,9800</td>
        <td>499999500000</td>
        <td>1000000</td>
        <td>884,9253</td>
        <td>499999500000</td>
        <td>1000000</td>
        <td>977,406707</td>
    </tr>
    <tr>
        <td>MERGE</td>
        <td>10066432</td>
        <td>19951424</td>
        <td>0,0896</td>
        <td>9884992</td>
        <td>29836416</td>
        <td>0,0908</td>
        <td>18672899</td>
        <td>29228704</td>
        <td>4,653309</td>
    </tr>
    <tr>
        <td>QUICK</td>
        <td>18803872</td>
        <td>1209695</td>
        <td>0,0453</td>
        <td>18803872</td>
        <td>1709693</td>
        <td>0,0462</td>
        <td>26890127</td>
        <td>4706043</td>
        <td>0,152607</td>
    </tr>
  </tbody>
</table>

### Gráficos
#### Tempo de execução X Quantidade de elementos
<div style="display: flex">
<img src="https://github.com/user-attachments/assets/d824395d-cada-4a43-8e3a-da02d1c7f827" alt="Melhor caso" width=33%>
<img src="https://github.com/user-attachments/assets/c83fa58f-3f4d-4917-a8d7-696ab351f474" alt="Melhor caso" width=33%>
<img src="https://github.com/user-attachments/assets/98bfe0cd-6a68-47af-8035-1ac605d2f033" alt="Caso médio" width=33%>
</div>

## Resultados

### Bubble sort
A variação utilizada nesse algoritmo de troca é a melhorada. Ele apresenta um **ótimo resultado para vetores ordenados**, mas quando utilizado em vetores invertidos ou aleatórios perde desempenho, além de se tornar o pior dos algoritmos de ordenação para vetores grandes, como no caso de um milhão.

### Insertion sort
O insertion sort apresenta um desempenho melhor em comparação ao bubble sort, obtendo resultados em até **menos da metade do tempo**. Ele segue um padrão de comparação de `n-1`, zero trocas para vetores ordenados e `(n(n-1))/2` para vetores invertidos.

### Selection sort
O **pior** resultado de **tempo** para **vetores ordenados** e também para **vetores pequenos**. Seu tempo de resposta é muito semelhante independente do caso, mudando apenas com a variação de tamanho do vetor e segue o mesmo padrão para todos os casos: `(n(n-1))/2` comparações e `n` trocas.

### Merge sort
Esse tipo de ordenação é **um dos mais rápidos**. O merge sort apresenta o conceito de recurividade e cumpre muito bem seu papel. Entretanto, há uma certa **dificuldade em contabilizar as trocas** quando não é definido exatamente o que é considerado troca. Nesse algoritmo há diversas divisões em outros vetores menores que entram na contagem final, incluindo em vetores já ordenados.

### Quick sort
Condizente com o nome, esse é o algoritmo com o **melhor tempo** de resposta. Ele também apresenta o conceito de recursividade como no merge e é ideal para grandes conjuntos de dados, como pode ser visto no comparativo.

## Referência

SOUZA, Jackson EG; RICARTE, João Victor G.; DE ALMEIDA LIMA, Náthalee Cavalcanti. Algoritmos
de Ordenação: Um estudo comparativo. Anais do Encontro de Computação do Oeste Potiguar
ECOP/UFERSA (ISSN 2526-7574), n. 1, 2017.
