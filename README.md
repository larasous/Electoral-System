[![GitHub license](https://img.shields.io/github/license/larasous/Product-Inventory-Management)](https://github.com/larasous/Product-Inventory-Management/blob/main/LICENSE)

# Electoral-System
Project developed with the intention of carrying out a local vote, using files in C.

## Members:
- 👩[ Raina Rodrigues](https://github.com/rainarodrigues)
- 👩[ Lara Amanny](https://github.com/larasous)

### 👉 Prerequisites
Before starting, you will need to have the following tools installed on your machine:
[Git](https://git-scm.com), [GCC](https://gcc.gnu.org/) ou [MinGW](https://sourceforge.net/projects/mingw/).

Also, it's nice to have an editor to work with code like the [VSCode](https://code.visualstudio.com/), or it could be the IDE [CLion](https://www.jetbrains.com/pt-br/clion/download/#section=windows).

### Configuring VSCode to compile in C/C++:
- So that the editor can compile in C/C++ follow this tutorial [link](https://medium.com/@juniortrojilio/preparando-o-vs-code-para-compilar-c-c-no-windows-988f4a91a557).

### Configuring MinGW - Windows:
- After running the downloaded download, click install:
  
  <img style="border-radius: 50%;" src="https://i1.wp.com/terminaldeinformacao.com/wp-content/uploads/2015/10/ming01.png?w=606&ssl=1" width="500px;" alt=""/>

- Proceed until you reach a screen to choose which features to install, select mingw32-base and mingw32-gcc-g++:

  <img style="border-radius: 50%;" src="https://i0.wp.com/terminaldeinformacao.com/wp-content/uploads/2015/10/ming02.png?resize=768%2C381&ssl=1" width="500px;" alt=""/>

- After that, click on Install > Apply Changes.
- Now, you will need to add the MinGW binary directory to the Windows PATH, for that, click on Start, then right click on Computer, and then on Properties.

  <img style="border-radius: 50%;" src="https://i0.wp.com/terminaldeinformacao.com/wp-content/uploads/2015/10/ming03.png?w=647&ssl=1" width="500px;" alt=""/>

- Click Advanced System Settings:

  <img style="border-radius: 50%;" src="https://i1.wp.com/terminaldeinformacao.com/wp-content/uploads/2015/10/ming04.png?resize=265%2C174" width="300px;" alt=""/>

- Click Environment Variables:
  
  <img style="border-radius: 50%;" src="https://i1.wp.com/terminaldeinformacao.com/wp-content/uploads/2015/10/ming05.png?w=420&ssl=1" width="300px;" alt=""/>

- Find the PATH variable, select it, and click edit, at the end of it add a “;” (semicolon), and put the directory of the binaries that were installed with MinGW (usually in C:MinGWbin).

  <img style="border-radius: 50%;" src="https://i0.wp.com/terminaldeinformacao.com/wp-content/uploads/2015/10/ming06.png?w=357&ssl=1" width="300px;" alt=""/>

- To verify the installation was successful, open Command Prompt and type gcc.

   <img style="border-radius: 50%;" src="https://i0.wp.com/terminaldeinformacao.com/wp-content/uploads/2015/10/ming07.png?w=677&ssl=1" width="500px;" alt=""/>

### Configuring GCC - Linux:
- Some distributions already have gcc installed by default, however, some you need to install the part as a tool, below are the commands to install on Fedora, OpenSUSE and Ubuntu:

```
Fedora

> sudo yum install gcc

OpenSUSE

> sudo zypper in gcc

Ubuntu

> sudo apt-get update
> sudo apt-get install gcc-4.4 

```
- To verify the installation, run in the terminal:
```
> gcc --help
```
- It will show the following screen:

  <img style="border-radius: 50%;" src="https://i1.wp.com/terminaldeinformacao.com/wp-content/uploads/2013/08/gcc1.jpg?resize=768%2C444&ssl=1" width="500px;" alt=""/>
  
### Compiling and running the file (Linux / Windows)
```
> gcc programa.c -o executavel
ou
> gcc -o executavel programa.c
```
- If there is any compilation error, it will show on the screen.
- To run the compiled file
```
> ./executavel
```

### 🎲 Cloning the repository via terminal
```bash
# Clone this repository
$ git clone <https://github.com/larasous/Electoral-System>
```

## 👉 Functionalities
- file main.c
- [x] Register of States, Municipalities, Zones, Sections, Voters, Year of Election, Candidates and Parties
- [x] Listing of States, Municipalities, Zones, Sections, Voters, Year of Election, Candidates and Parties
- [x] Search by States, Municipalities, Zones, Sections, Voters, Year of Election, Candidates and Parties
- [x] Updating of States, Municipalities, Zones, Sections, Voters, Year of Election, Candidates and Parties
- [x] Removal of States, Municipalities, Zones, Sections, Voters, Year of Election, Candidates and Parties

- file main_votacao.c
- [x] Confirmation of electoral title
- [x] Vote operation
- [x] Candidate Verification
- [x] Election result

### Observation!!!
- The code is not fully complete to be a voting system, it was developed only as a university grade project.
- Missing to connect the information with each other, and blank voting operation.

[![Linkedin Badge](https://img.shields.io/badge/-Lara-blue?style=flat-square&logo=Linkedin&logoColor=white&link=https://www.linkedin.com/in/lara-sousa-a365a9205/)](https://www.linkedin.com/in/lara-sousa-a365a9205/) 
[![Gmail Badge](https://img.shields.io/badge/-sousalara822@gmail.com-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:sousalara822@gmail.com)](mailto:sousalara822@gmail.com)
