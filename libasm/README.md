# Libasm
## Este projeto faz parte da galáxia de aprendizado da escola 42 São Paulo. Projeto faz parte do C4.
## Com intuíto de familiarizar o aluno com a linguagem Assebly (Assembler), o mesmo deverá reproduzir algumas funções conhecidas como:
### ◦ ft_strlen (man 3 strlen)
### ◦ ft_strcpy (man 3 strcpy)
### ◦ f_strcmp (man 3 strcmp)
### ◦ ft_write (man 2 write)
### ◦ ft_read (man 2 read)
### ◦ ft_strdup (man 3 strdup, you can call to malloc) 
### todas em assembly.

# Copilando arquivos em Assembly
## Para copilar arquivos em Assembly iremos utilizar o NASM

### Instalando o NASM
#### sudo apt-get update -y
#### sudo apt-get -y install nasm

### Copilando com NASM em 64bits
#### nasm -f elf64 file.asm - cria o um object file *.o com base no arquivo em assembly "file.asm"
#### ld file.o -o teste - cria um executavel "teste" com base no arquivo objeto
#### Uma segunda forma de fazer a criação do object file e o executável é:
##### ld -m elf_i386 hello.o -o hello

# Estrutura dos arquivos em Assembly
## Section
### Visando estruturar e tornar o código legível, o mesmo deverá ser estruturado em blocos de informações, esses blocos são chamados de Section
### Possuímos 3 section's:
#### - .data section - é uma região do código que será usada para tratar as informações, os dados, as variáveis. Nesse trecho (geralmente o inicial), declaramos e inicializamos as variáveis.
#### - .bss section funciona como a .data section, porém não inicializamos as informações
#### - .text section é o local onde ficará armazenadas as rotinas, instruções que deverão ser seguidas, para trabalhar os dados previamente declarados. 
####    Essa section é obrigatória, pois nela estará contida a label(rótulo)_start, que é o local onde os executáveis são inicializados. em outras linguagens como C a label e denominada "main".
### Resumindo teremos:
### section .dat
###     ;declaração e inicialização de dados
### section .bss
###     ;declaração sem inicialização das informações que serão usadas
### section .text
###     ;o programa começa a rodar aqui, a partir da start.
### EX:
###     section .data
###     msg     db      'Como programar em Assembly',0ah
###     len     equ     $-msg
###     
###     section .text
###     global  _start
###     _start: mov     edx, len
###             mov     ecx, msg
###             mov     ebx, 1
###             mov     eax, 4
###             int     80h
###     
###             mov     ebx, 0
###             mov     eax, 1
###             int     80h




# Bibliografia utilizada:
## www.programacaoprogressiva.net/p/curso-de_assembly.html