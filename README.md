# Cadastro de Clientes (Hash)
Um exercício proposto para um teste seletivo da Lactec, capaz de cadastrar, buscar e excluir clientes de uma estrutura de dados.
Implementado por Mihael Scofield de Azevedo.

## Instalação
O programa foi pensado para rodar no terminal do OS Linux, compilado com gcc.
Para facilitar sua instalação, nos arquivos existe um Makefile.
Pelo terminal, no diretório onde se encontra o programa, basta digitar "Make" que um executável chamado "Cadastramento" aparece.

## Execução
O programa é capaz de fazer inserção (cadastramento), busca e exclusão dentro de uma Tabela Hash Encadeada.
Com um layout através de menus intuitivos e simples, foi pensado para usuários do dia-a-dia, "conversando" com quem o utiliza.

## Estruturação
A implementação através de uma Tabela Hash encadeada teve como objetivo otimizar o tempo de manipulação dos registros.
A Opção de ser uma Hash Encadeada se dá ao fato de facilitar a impressão em ordem, requisitada no tópico 8.2 do exercício.
Para implementa-la, foi utilizada a estratégia de utilizar um vetor, onde cada elemento é uma lista encadeada.
O acesso de cada posição desse vetor, se dá pela função Hash (função modular), feita para separar por idade cada usuário.

### Divisão de Arquivos
O programa foi implementado em 3 arquivos diferentes
  - Main.c - Controla o fluxo do programa principal, impressão do menu principal e a chamada dos demais arquivos.
  - Hash.h/c - Faz a manipulação da Hash e interage com o usuário para levantar os dados necessários.
  - Structs.h - Contém as estruturas de dados utilizadas no programa.
  - Includes.h - Faz a inclusão das bibliotecas, arquivos cabeçalhos e possue as Macros definidas no trabalho.
