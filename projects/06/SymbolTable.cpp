#include<bits/stdc++.h>
#include"SymbolTable.h"
using namespace std;

SymbolTable::SymbolTable(){
    symbol_table["R0"] = 0;
	symbol_table["R1"] = 1;
	symbol_table["R2"] = 2;
	symbol_table["R3"] = 3;
	symbol_table["R4"] = 4;
	symbol_table["R5"] = 5;
	symbol_table["R6"] = 6;
	symbol_table["R7"] = 7;
	symbol_table["R8"] = 8;
	symbol_table["R9"] = 9;
	symbol_table["R10"] = 10;
	symbol_table["R11"] = 11;
	symbol_table["R12"] = 12;
	symbol_table["R13"] = 13;
	symbol_table["R14"] = 14;
	symbol_table["R15"] = 15;

    symbol_table["SCREEN"] = 16384;
	symbol_table["KBD"] = 24576;

    symbol_table["SP"] = 0;
	symbol_table["LCL"] = 1;
	symbol_table["ARG"] = 2;
	symbol_table["THIS"] = 3;
	symbol_table["THAT"] = 4;
}

bool SymbolTable::contains(string label){
    return (symbol_table.find(label) != symbol_table.end());
}

int SymbolTable::getAddress(string label){
    return symbol_table[label];
}

void SymbolTable::addSymbol(string label, int address){
    symbol_table[label] = address;
}

