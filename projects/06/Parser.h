#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Parser{
private:
    ifstream assemblyFile;
    string DEST, COMP, JUMP;
    string currCommand;

public:
    Parser(string fileName);

    bool hasMoreCommands();

    void advance();
    char commandType();
    string symbol();
    string dest();
    string comp();
    string jump();
    void reset();
    void setDestCompJump();
};

/*
Routine             Arguments       Returns         Function

Constructor         input file      -               Opens the input file/stream and gets ready to parse it.
hasMoreCommands     -               Booleans        Are there more commands in the input?
advance             -               -               Reads the next command from the input and makes it the current command.
                                                    #Should be called only if hasMoreCommands() is true. Initially there is no current command.
commandType         -               A, C, L         returns the type of currrent command.
symbol              -               string          Returns the symbol or decimal Xxx of the current command @Xxx or (Xxx).
                                                    #Should be called only when commandType() is A_COMMAND or L_COMMAND.
dest                -               string          Returns the dest mnemonic in the current C-command (8 possibilities).
                                                    #Should be called only when commandType() is C_COMMAND.
comp                -               string          Returns the comp mnemonic in the current C-command (28 possibilities).
                                                    #Should be called only when commandType() is C_COMMAND.
jump                -               string          Returns the jump mnemonic in the current C-command (8 possibilities).
                                                    #Should be called only when commandType() is C_COMMAND.



*/