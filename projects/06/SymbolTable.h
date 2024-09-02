#include<bits/stdc++.h>
using namespace std;

class SymbolTable{
    public:
    unordered_map<string, int> symbol_table;

    SymbolTable();
    int getAddress(string);
    bool contains(string);
    void addSymbol(string, int);
};