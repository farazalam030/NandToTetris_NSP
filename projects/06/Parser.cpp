#include "Parser.h"

using namespace std;

Parser::Parser(string filename){
    assemblyFile.open(filename);
}

bool Parser::hasMoreCommands(){
    return (assemblyFile.peek() != EOF);
}

void Parser::advance(){
    getline(assemblyFile, currCommand);
}

char Parser::commandType(){
    if(currCommand.find('@') != string::npos)   return 'A';     //A command
    if(currCommand.find('(') != string::npos)   return 'L';     //L command
    if(currCommand.find('=') != string::npos)   return 'C';     //C command
    return 'W';                                                 //Blank line or comments
}

string Parser::symbol(){
    //return symbol for A or L type command
    string sym = "";

    for(int i = 0; i < currCommand.length(); i++){
        char ch = currCommand[i]; 
        if(ch == '(' || ch == ' ' || ch =='@')
            continue;
        else if(ch == ')' || ch == '/')
            break;
        sym += ch;
    }

    return sym;
}
string Parser::dest(){
    return DEST;
}
string Parser::comp(){
    return COMP;
}
string Parser::jump(){
    return JUMP;
}

void Parser::reset() {
    assemblyFile.clear();
    assemblyFile.seekg(0, assemblyFile.beg);
}	

void Parser::setDestCompJump() {
    vector<string> tokens;
    
    DEST = COMP = JUMP = "";
    string tok;
    bool first = true;
    string cmd = "";	
    for(int i = 0; i < currCommand.length(); i++) {
        char c = currCommand[i];
        if(c == ' ' || c == '\t') continue;
        if(c == '=') {
            if(tok.length() != 0) {
                tokens.push_back(tok);
                DEST = tok;
            }
            tok = "";
            cmd += c;
            
        }
        else if(c == ';') {
            if(tok.length() != 0) {
                tokens.push_back(tok);
                COMP = tok;
            }
            tok = "";
            cmd += c;
        }
        else if(c == '/') {
            if(tok.length() != 0) {
                tokens.push_back(tok);
                if(COMP.length() == 0)
                    COMP = tok;
                else
                    JUMP = tok;
            }
            tok = "";
            if(i > 0 && currCommand[i-1] == '/') {
                break;
            }
        }
        else {
            tok += c;
            cmd += c;
        }
    }
    if(tok.length() != 0) {
        tokens.push_back(tok);
        if(COMP.length() == 0)
            COMP = tok;
        else
            JUMP = tok;
    }
}