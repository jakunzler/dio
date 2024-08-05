# Previsão de Estoque Inteligente na AWS com SageMaker Canvas

## Estrutura do Projeto

### Passo a Passo

#### 1. Selecionar Dataset

1. **Navegue até a pasta `datasets` do repositório**:
   - Faça um fork do repositório [digitalinnovationone/lab-aws-sagemaker-canvas-estoque](https://github.com/digitalinnovationone/lab-aws-sagemaker-canvas-estoque).
   - Clone o repositório para sua máquina local.

   ```bash
   git clone https://github.com/SEU_USUARIO/lab-aws-sagemaker-canvas-estoque.git
   ```

2. **Escolha o dataset**:
   - Navegue até a pasta `datasets` e escolha o dataset que será usado para treinar seu modelo de previsão de estoque. Sinta-se à vontade para gerar ou enriquecer seus próprios datasets.

3. **Faça o upload do dataset no SageMaker Canvas**:
   - Acesse o SageMaker Canvas no console AWS.
   - Faça o upload do dataset escolhido.

#### 2. Construir e Treinar

1. **Importe o dataset no SageMaker Canvas**:
   - No SageMaker Canvas, importe o dataset que você selecionou.

2. **Configure as variáveis de entrada e saída**:
   - Configure as variáveis de entrada (features) e a variável de saída (target) de acordo com os dados do seu dataset.

3. **Inicie o treinamento do modelo**:
   - Inicie o treinamento do modelo. Isso pode levar algum tempo, dependendo do tamanho do dataset.

#### 3. Analisar

1. **Examine as métricas de performance do modelo**:
   - Após o treinamento, examine as métricas de performance do modelo, como acurácia, precisão, recall, etc.

2. **Verifique as principais características que influenciam as previsões**:
   - Analise as principais características (features) que influenciam as previsões do modelo.

3. **Faça ajustes no modelo, se necessário**:
   - Se necessário, faça ajustes no modelo (como seleção de features ou ajustes nos hiperparâmetros) e re-treine até obter um desempenho satisfatório.

#### 4. Prever

1. **Use o modelo treinado para fazer previsões de estoque**:
   - Use o modelo treinado para fazer previsões de estoque em novos dados.

2. **Exporte os resultados e analise as previsões geradas**:
   - Exporte os resultados das previsões e analise as previsões geradas para entender melhor o comportamento do modelo.

3. **Documente suas conclusões**:
   - Documente suas conclusões e qualquer insight obtido a partir das previsões no README do seu repositório GitHub.

### Estrutura do README.md

Aqui está um exemplo de como estruturar o seu README.md no repositório GitHub:

```markdown
# Previsão de Estoque Inteligente na AWS com SageMaker Canvas

Este projeto demonstra como usar o Amazon SageMaker Canvas para criar um modelo de previsão de estoque. 

## Passo a Passo

### 1. Selecionar Dataset
- Escolhemos o dataset `nome_do_dataset.csv` da pasta `datasets`.
- Fizemos o upload do dataset no SageMaker Canvas.

### 2. Construir e Treinar
- Importamos o dataset no SageMaker Canvas.
- Configuramos as variáveis de entrada e saída:
  - Variáveis de entrada: `feature1`, `feature2`, ...
  - Variável de saída: `target`
- Iniciamos o treinamento do modelo.

### 3. Analisar
- Examinamos as métricas de performance do modelo:
  - Acurácia: `valor`
  - Precisão: `valor`
  - Recall: `valor`
- Verificamos as principais características que influenciam as previsões.
- Fizemos ajustes no modelo e re-treinamos até obter um desempenho satisfatório.

### 4. Prever
- Usamos o modelo treinado para fazer previsões de estoque.
- Exportamos os resultados e analisamos as previsões geradas.
- Conclusões e insights:
  - Insight 1
  - Insight 2
  - ...

## Conclusão

Este projeto mostrou como o Amazon SageMaker Canvas pode ser usado para criar modelos de previsão de estoque de maneira intuitiva, sem a necessidade de programação.

## Links Úteis

- [Documentação Oficial do SageMaker Canvas](https://docs.aws.amazon.com/sagemaker/latest/dg/canvas.html)
- [Guia de Introdução ao SageMaker](https://docs.aws.amazon.com/sagemaker/latest/dg/whatis.html)
- [Repositório de Exemplo do SageMaker](https://github.com/aws/amazon-sagemaker-examples)

## Autor

- [Seu Nome](https://github.com/SEU_USUARIO)
```

### Conclusão

Seguindo esses passos e documentando todo o processo no seu repositório GitHub, você estará pronto para enviar a URL do seu repositório como solução na plataforma da DIO. Boa sorte no desafio e aproveite para expandir suas habilidades em Machine Learning no-code com o Amazon SageMaker Canvas!
