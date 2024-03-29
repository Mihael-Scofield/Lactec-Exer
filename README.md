# Sistema de Cadastramento de Clientes (Hash)
Um exercício proposto para um teste seletivo da Lactec, capaz de cadastrar, buscar, excluir e listar clientes em uma estrutura de dados.

Implementado por Mihael Scofield de Azevedo.

## Instalação
O programa foi pensado para rodar no terminal do OS Linux, compilado com **gcc** e debugado pelo **gdb**. 

Para facilitar sua instalação, nos arquivos existe um Makefile.
Pelo terminal, no diretório onde se encontra o programa, basta digitar "make" que um executável chamado "Cadastramentos" aparece.

## Execução
O programa é capaz de fazer inserção (cadastramento), busca, exclusão e listagem de clientes dentro de uma Tabela Hash Encadeada.
Com um layout de menus intuitivos e simples, foi pensado para usuários do dia-a-dia, "conversando" com quem o utiliza.

## Estruturação
A implementação através de uma Tabela Hash Encadeada teve como objetivo otimizar o tempo de manipulação dos registros.
A Opção de ser uma Hash Encadeada se dá ao fato de facilitar a listagem em ordem, requisitada no tópico 8.2 do exercício.

Para implementa-la, foi adotada a estratégia de utilizar um vetor, onde cada elemento é uma lista encadeada.
O acesso de cada posição desse vetor, se dá pela função Hash (função modular), feita para separar por idade cada usuário.

### Divisão de Arquivos
O programa foi implementado em 4 arquivos diferentes

  - Main.c 
  
  Controla o fluxo do programa principal, impressão do menu principal e a chamada dos demais arquivos.
  
  - Hash.h/c
  
  Faz a manipulação da Hash e interage com o usuário para levantar os dados necessários. 
  
  Dividida em **Funções Utilitárias** — com operações curtas, mas com muitas repetições ao longo do código, e **Funções Principais** — com poucas chamadas, mas que utilizam as Funções Utilitárias para controlar o fluxo da manipulação da Tabela Hash.
  
  - Structs.h
  
  Contém as estruturas de dados utilizadas no programa.
  
  - Includes.h 
  
  Faz a inclusão das bibliotecas, arquivos cabeçalhos e possue as Macros definidas no trabalho.
  
## Agradecimentos

Gostaria de agradecer a Lactec pela oportunidade de poder fazer, não só este projeto, como também o teste seletivo. A experiência até aqui foi incrível e me proporcionou, não só motivação para seguir em frente com o meu curso (pois percebi o quão divertido/estressante/recompensador pode ser trabalhar com desenvolvimento de software), como também um aprendizado enorme. Minha caixa de ferramentas e soluções aumentou muito e foi ótimo poder aplicar na prática algo que só havia visto em teoria.

Agradeço também ao apoio familiar e de meus amigos durante o desenvolvimento deste projeto, me deram um amparo emocional e motivacional fundamental para o término do projeto.

Obrigado.
