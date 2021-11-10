[![GitHub license](https://img.shields.io/github/license/larasous/Product-Inventory-Management)](https://github.com/larasous/Product-Inventory-Management/blob/main/LICENSE)

# Sistema-Eleitoral
Projeto desenvolvido com o intuito de realizar uma votação local, usando arquivos em C.

## Membros:
- 👩[ Raina Rodrigues](https://github.com/rainarodrigues)
- 👩[ Lara Amanny](https://github.com/larasous)

### 👉 Pré-requisitos
Antes de começar,você precisará ter as seguintes ferramentas instaladas em sua máquina:
[Git](https://git-scm.com), [GCC](https://gcc.gnu.org/) ou [MinGW](https://sourceforge.net/projects/mingw/).

Além disso, é bom ter um editor para trabalhar com o código como o [VSCode](https://code.visualstudio.com/), ou pode ser a IDE [CLion](https://www.jetbrains.com/pt-br/clion/download/#section=windows).

### Configurando o VSCode para compilar em C/C++:
- Para que o editor possa compilar em C/C++ siga o tutorial deste [link](https://medium.com/@juniortrojilio/preparando-o-vs-code-para-compilar-c-c-no-windows-988f4a91a557).

### Configurando MinGW - Windows:
- Após executar o download baixado, clique em install:
  
  <img style="border-radius: 50%;" src="https://i1.wp.com/terminaldeinformacao.com/wp-content/uploads/2015/10/ming01.png?w=606&ssl=1" width="500px;" alt=""/>

- Prossiga até chegar em uma tela para escolher os recursos que serão instalados, selecione mingw32-base e o mingw32-gcc-g++:

  <img style="border-radius: 50%;" src="https://i0.wp.com/terminaldeinformacao.com/wp-content/uploads/2015/10/ming02.png?resize=768%2C381&ssl=1" width="500px;" alt=""/>

- Após isso, cliquem em Instalattion > Apply Changes.
- Agora, você precisará adicionar o diretório binário do MinGW ao PATH do Windows, para isso, clique no Iniciar, e depois clique com o botão direito em Computador, e em seguida em Propriedades.

  <img style="border-radius: 50%;" src="https://i0.wp.com/terminaldeinformacao.com/wp-content/uploads/2015/10/ming03.png?w=647&ssl=1" width="500px;" alt=""/>

- Clique em Configurações avançadas do sistema:

  <img style="border-radius: 50%;" src="https://i1.wp.com/terminaldeinformacao.com/wp-content/uploads/2015/10/ming04.png?resize=265%2C174" width="300px;" alt=""/>

- Clique em Variáveis de ambiente:
  
  <img style="border-radius: 50%;" src="https://i1.wp.com/terminaldeinformacao.com/wp-content/uploads/2015/10/ming05.png?w=420&ssl=1" width="300px;" alt=""/>

- Encontre a variável PATH, selecione, e clique em editar, no fim dela, adicione um “;” (ponto e vírgula), e coloque o diretório dos binários que foram instalados com o MinGW (geralmente em C:MinGWbin).

  <img style="border-radius: 50%;" src="https://i0.wp.com/terminaldeinformacao.com/wp-content/uploads/2015/10/ming06.png?w=357&ssl=1" width="300px;" alt=""/>

- Para verificar se a instalação foi bem sucedida, abra o Prompt de comando e digite gcc.

   <img style="border-radius: 50%;" src="https://i0.wp.com/terminaldeinformacao.com/wp-content/uploads/2015/10/ming07.png?w=677&ssl=1" width="500px;" alt=""/>

### Configurando GCC - Linux:
- Algumas distribuições já trazem o gcc instalado por padrão, contudo, algumas você precisa instalar a parte como ferramenta, abaixo os comando para instalar no Fedora, OpenSUSE e Ubuntu:

```
Fedora

> sudo yum install gcc

OpenSUSE

> sudo zypper in gcc

Ubuntu

> sudo apt-get update
> sudo apt-get install gcc-4.4 

```
- Para verificar a instalação, execute no terminal:
```
> gcc --help
```
- Mostrará a seguinte tela:

  <img style="border-radius: 50%;" src="https://i1.wp.com/terminaldeinformacao.com/wp-content/uploads/2013/08/gcc1.jpg?resize=768%2C444&ssl=1" width="500px;" alt=""/>
  
### Compilando e executando o arquivo (Linux / Windows)
```
> gcc programa.c -o executavel
ou
> gcc -o executavel programa.c
```
- Se existir algum erro de compilação, mostrará na tela.
- Para executar o arquivo compilado
```
> ./executavel
```

### 🎲 Clonando o repositório via terminal
```bash
# Clone this repository
$ git clone <https://github.com/larasous/Sistema-Eleitoral>
```

## 👉 Funcionalidades
- arquivo main.c
- [x] Cadastro de Estados, Municípios, Zonas, Seções, Eleitores, Ano de Eleição, Candidatos e Partidos
- [x] Listagem de Estados, Municípios, Zonas, Seções, Eleitores, Ano de Eleição, Candidatos e Partidos
- [x] Busca por Estados, Municípios, Zonas, Seções, Eleitores, Ano de Eleição, Candidatos e Partidos
- [x] Atualização Estados, Municípios, Zonas, Seções, Eleitores, Ano de Eleição, Candidatos e Partidos
- [x] Remoção de Estados, Municípios, Zonas, Seções, Eleitores, Ano de Eleição, Candidatos e Partidos

- arquivo main_votacao.c
- [x] Confirmação do título eleitoral
- [x] Operação de voto
- [x] Verificação do candidato
- [x] Resultado da eleição

### Observação!!!
- O código não está totalmente completo para ser um sistema de votação, foi desenvolvido apenas como um projeto de universidade para nota.
- Falta conectar as informações entre si, e operação de voto em branco.

[![Linkedin Badge](https://img.shields.io/badge/-Lara-blue?style=flat-square&logo=Linkedin&logoColor=white&link=https://www.linkedin.com/in/lara-sousa-a365a9205/)](https://www.linkedin.com/in/lara-sousa-a365a9205/) 
[![Gmail Badge](https://img.shields.io/badge/-sousalara822@gmail.com-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:sousalara822@gmail.com)](mailto:sousalara822@gmail.com)
