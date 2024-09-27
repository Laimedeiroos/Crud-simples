# CRUD Simples de Usuários

![CRUD Logo](https://miro.medium.com/v2/resize:fit:768/1*gjA78w2_Q8lSNZAnTMScqA.png) <!-- Adicione um link para uma imagem se desejar -->

## Descrição

Este é um sistema simples de CRUD (Criar, Ler, Atualizar, Deletar) de usuários em C, utilizando a biblioteca **ncurses** para uma interface de usuário no terminal. O sistema permite gerenciar usuários, com funcionalidades para cadastro, autenticação e gerenciamento de senhas.

## Funcionalidades

- **Criar Usuário**: Adiciona um novo usuário, garantindo que não haja duplicatas.
- **Ler Usuários**: Exibe todos os usuários cadastrados no sistema.
- **Atualizar Usuário**: Modifica a senha de um usuário existente.
- **Deletar Usuário**: Remove um usuário do sistema.
- **Autenticar Usuário**: Verifica as credenciais de um usuário.

## Tecnologias Utilizadas

- **Linguagem**: C
- **Biblioteca**: ncurses (para interface de terminal)

## Requisitos

Para compilar e executar o projeto, você precisará ter instalado:

- GCC (GNU Compiler Collection)
- Bibliotecas de desenvolvimento do `ncurses`

### Instalação do ncurses

No Ubuntu ou Debian, você pode instalar as bibliotecas necessárias com:

```bash
sudo apt-get install libncurses5-dev libncursesw5-dev
