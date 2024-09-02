#include "Code.h"
using namespace std;

string Code::dest(string destField){
    if(destField == "null")     return "000";
    if(destField == "M")        return "001";
    if(destField == "D")        return "010";
    if(destField == "MD")       return "011";
    if(destField == "A")        return "100";
    if(destField == "AM")       return "101";
    if(destField == "AD")       return "110";
    if(destField == "AMD")      return "111";

    return "Invalid";
}

string Code::comp(string compField){
    if(compField == "0")        return "0101010";
    if(compField == "1")        return "0111111";
    if(compField == "-1")       return "0111010";
    if(compField == "D")        return "0001100";
    if(compField == "A")        return "0110000";
    if(compField == "!D")       return "0001101";
    if(compField == "!A")       return "0110001";
    if(compField == "-D")       return "0001111";
    if(compField == "-A")       return "0110011";
    if(compField == "D+1")      return "0011111";
    if(compField == "A+1")      return "0110111";
    if(compField == "D-1")      return "0001110";
    if(compField == "A-1")      return "0110010";
    if(compField == "D+A")      return "0000010";
    if(compField == "D-A")      return "0010011";
    if(compField == "A-D")      return "0000111";
    if(compField == "D&A")      return "0000000";
    if(compField == "D|A")      return "0010101";

    
    if(compField == "M")        return "1110000";
    if(compField == "!M")       return "1110001";
    if(compField == "-M")       return "1110011";
    if(compField == "M+1")      return "1110111";
    if(compField == "M-1")      return "1110010";
    if(compField == "D+M")      return "1000010";
    if(compField == "D-M")      return "1010011";
    if(compField == "M-D")      return "1000111";
    if(compField == "D&M")      return "1000000";
    if(compField == "D|M")      return "1010101";

    return "Invalid";
}

string Code::jump(string jumpField){
    if(jumpField == "null")     return "000";
    if(jumpField == "JGT")      return "001";
    if(jumpField == "JEQ")      return "010";
    if(jumpField == "JGE")      return "011";
    if(jumpField == "JLT")      return "100";
    if(jumpField == "JNE")      return "101";
    if(jumpField == "JLE")      return "110";
    if(jumpField == "JMP")      return "111";

    return "Invalid";
}