  # Aula dia 10 de janeiro 2023
  > ## Linear Regression 
  > Uma reta que encontre uma estimativa de união dos pontos.\
  > Função de custo: Traçar uma reta e calcular o quão distante está o ponto do mesmo ponto da reta\
  > **Cálculo do Erro** = _^y - y_\
  > _^y_ sendo predição ou valor estimado. _y_ sendo valor total.\
  > - **^y = x1w1 + w0** (Equação da reta)\
  > Cálculo do erro para todos os pontos e o somatório deles. Para erros em quantidades iguais em cima e em baixo da reta não se anularem, é feito o cálculo elevado ao quadrado.\
  > - J(w0.w1) -> Função de custo com objetivo de minimização. \
  >arg min J(w0. w1)
  >  
  >
  >

  > ## Multilayer perceptron

  - _barreira_: dados não linearmente separáveis, como a maioria no mundo real.
  - 



  > ## Back-propagation
  >  - FeeedFoward\
  > função de custo\
  > entropia cruzada, médio quadrado\
  > função de ativação: f(x) = l oS (1 + e^x) ---> **SoftPlus**
  >
  > 
  >

  Gradiente Descendente. 
  Para t até T, faça: 
  w1(t+1)=w1(t) - DELTAw1
  W0(t+1)=w0(t) - DELTAw0

  DELTA w1 = derivada parcial da função de custo / DELTA w1
  DELTA w0 = derivada parcial da função de custo / Delta w0


  w0(t+1).  w0(t) - n 1/m m somatório m+! (w0+x1y1 - y) .1
  w0(t+1).  w0(t) - n 1/m m somatório m+! (w0+x1y1 - y) .x1

  Multi-layer Perceptron = Rede Neural - Redes neurais artificiais - RNA
  Coleção de unidades conectadas chamadas neurônios artificiais. 

  Envio de sinais - Número real e a saída de cada neurônio é computada por uma função não linear.
  Pesos aumentam ou diminuem intensidade do sinal.
  Arquitetura: Camada de entrada, camadas intermediárias, camada de saída. 
  B - vetores saem dele, sem entradas no B
  Deficiências - Análise teórica difícil, exige muito processamento e cálculos para o algoritmo de treinamento. 
  Back-propagation: 2 fases:
  Forward phase
  Atualização dos pesos.

  Back propagation é utilizado até hoje como método mais eficiente de atualização dos pesos.
  Cada neurônio performa dois tipos de cálculo: Somatória e função de ativação e cálculo do erro.
  Camadas intermediárias: primeira camada - linhas retas
  segunda - Combina as linhas da camada anterior para formar regiôes convexas.
  terceira - Combina figuras convexas produzindo formatos abstratos.

  funções de ativação podem ser diferentes da apresentada anteriormente.

  modos de treinamento - Batch, online e mini batch. 

  Back- 
  Propagation
  Ajuste dos pesos retropropagando o erro através da rede.
  gradiente descendente.
  Maneira de encontrar todos os parâmetros dela. 
  Através do vetor gradiente, encontrar os valores mínimos em relação a uma superfície. 

  Função de ativação: f(x) = log e(1+e^x)      chamada de softplus

  Todos os neurônios da camada inicial se conectam a todos os neurônios da camada intermediária.
  Rede neural = Composição de funções. (função dentro de função).

  Para t de 1 até t, faça:
  wij(t+1)= wij(t) - n DELTA wij
  Procurar o delta wij, que é o gradiente.

  Regra Delta 
  chamar o trecho que se repete nos deltas do back-propagation de delta (minúsculo)2
  utilização de matrizes para a representação mais econômica das operações do back-propagation. Simplificando grandes linhas, transformando-as em multiplicações entre matrizes. 








