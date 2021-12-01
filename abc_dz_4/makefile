# makefile for perimeter.asm
task: main.c input.c inrnd.c output.c filtrator.o
	gcc -g -o task main.c input.c inrnd.c output.c filtrator.o -no-pie
filtrator.o: filtrator.asm
	nasm -f elf64 -g -F dwarf filtrator.asm -l filtrator.lst
