# Resolução do Desafio

Este desafio de projeto é intitulado "Previsão de Estoque Inteligente na AWS com SageMaker Canvas". Neste Lab da DIO, foi possível aplicar conceitos práticos de Machine Learning (ML) utilizando o SageMaker Canvas para criar previsões de estoque.

**Objetivo:** Desenvolver um modelo de previsão de estoque utilizando o SageMaker Canvas e documentar o processo em um repositório no GitHub.

## Passo a Passo

1. Selecionar Dataset
O dataset selecionado foi "dataset-1000-com-preco-promocional-e-renovacao-estoque".

### **Análise do Dataset**

ID_PRODUTO: Identificador único do produto.
DATA_EVENTO: Data do evento de registro do estoque.
PRECO: Preço do produto.
FLAG_PROMOCAO: Indicador de promoção (1 para promoção, 0 para não promoção).
QUANTIDADE_ESTOQUE: Quantidade de estoque disponível.

2. Construir e Treinar
Depois de importar o dataset no SageMaker Canvas, configurei as variáveis de entrada e saída de acordo com os dados.

Foi definido QUANTIDADE_ESTOQUE como a variável de saída e ID_PRODUTO, DATA_EVENTO, PRECO e FLAG_PROMOCAO como variáveis de entrada.

3. Analisar

Após o treinamento do modelo, procedi com a análise das métricas de performance para avaliar a eficácia das previsões. As principais métricas examinadas foram:

- **Acurácia**: Mediu a precisão das previsões do modelo, indicando a porcentagem de previsões corretas em relação ao total de previsões.
- **Erro Médio Percentual Absoluto (MAPE)**: Calculou a média dos erros percentuais absolutos das previsões, sendo uma métrica útil para entender a magnitude dos erros em termos percentuais, facilitando a comparação entre diferentes escalas.
- **Erro Percentual Absoluto Ponderado (WAPE)**: Calculou o erro percentual absoluto ponderado, fornecendo uma visão mais equilibrada ao considerar a magnitude dos valores reais na ponderação dos erros.

Além disso, verifiquei as principais características que influenciaram as previsões do modelo através da análise de importância das features. As características mais influentes foram identificadas, o que ajudou a entender quais variáveis tinham maior impacto nas previsões de estoque.

Com base nas métricas de performance e na importância das características, realizei ajustes no modelo conforme necessário. Estes ajustes envolveram a reconfiguração das variáveis de entrada, alteração de parâmetros do modelo e possível inclusão/exclusão de dados. Após os ajustes, testei a opção de retreinar o modelo para verificar se as alterações resultavam em melhorias na performance.

4. Prever

Com o modelo devidamente treinado e ajustado, passei para a fase de previsões de estoque. Utilizei o modelo para fazer previsões tanto com dados novos quanto com o próprio dataset utilizado no treinamento, a fim de validar a eficácia das previsões.

As previsões geradas pelo modelo ajudaram a identificar tendências e padrões no estoque, permitindo uma melhor gestão e planejamento. O modelo se mostrou útil na antecipação de necessidades de reabastecimento e na otimização do estoque, contribuindo para uma operação mais eficiente e econômica.

O processo de prever com o modelo treinado foi intuitivo e rápido, demonstrando o poder do SageMaker Canvas em criar soluções de Machine Learning sem a necessidade de programação avançada.

## Recursos Adicionais

Os materiais complementares disponibilizados foram de grande ajuda:

- Documentação Oficial do SageMaker Canvas: Consulte a [página oficial da AWS](https://aws.amazon.com/sagemaker/canvas/) para obter detalhes técnicos, guias de uso e exemplos práticos do SageMaker Canvas.
- Guia de Introdução ao SageMaker: Explore o [guia de introdução](https://docs.aws.amazon.com/sagemaker/latest/dg/whatis.html) ao Amazon SageMaker, que abrange desde a preparação de dados até a implantação de modelos de ML.
- Tutoriais e Exemplos Práticos: Acesse a seção de [recursos do SageMaker](https://aws.amazon.com/sagemaker/resources/) para tutoriais detalhados e exemplos de casos de uso práticos que podem servir como inspiração para seus próprios projetos.
- Repositório de Exemplo: Confira este [repositório no GitHub](https://github.com/aws/amazon-sagemaker-examples) que contém exemplos de uso do SageMaker, incluindo scripts e notebooks que você pode adaptar para suas necessidades.
- Amazon SageMaker Blog: [O blog oficial do SageMaker](https://aws.amazon.com/blogs/machine-learning/category/artificial-intelligence/sagemaker/) oferece artigos detalhados, estudos de caso e atualizações sobre novos recursos e melhores práticas.
- Towards Data Science - Using Amazon SageMaker: Uma coleção de artigos escritos por especialistas da comunidade que compartilham experiências e dicas práticas sobre o uso do SageMaker.
