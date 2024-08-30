// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/4/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, 
// the screen should be cleared.

//// Replace this comment with your code.

    //total no of registers we need to manipulate -> n
    @8192
    D=A
    @n
    M=D

(LOOP)
    //store base address in address
    @SCREEN
    D=A
    @address
    M=D

    @i
    M=0

    //get keyboard input
    @KBD
    D=M
    @WHITE
    D;JEQ       //if 0 then goto WHITE

    @color      //else goto BLACK
    M=-1
    @START
    0;JMP

(WHITE)
    @color
    M=0

(START)
    //if i = n go to loop
    @i
    D=M
    @n
    D=D-M
    @LOOP
    D;JEQ

    @color
    D=M
    @address
    A=M
    M=D

    //i++
    @i
    M=M+1

    //address++
    @address
    M=M+1

    @START
    0;JMP
