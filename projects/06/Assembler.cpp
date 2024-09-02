#include<iostream>
using namespace std;

#include "Parser.h"
#include "SymbolTable.h"
#include "Code.h"

int main(int argc, char** argv){
    string fileName;

    if(argc < 2){
        throw runtime_error("main() : please specify assembly file name *.asm");
    }
    else{
        fileName = argv[1];
    }

    Parser parser(fileName);
    SymbolTable symbolTable;

    /* first- pass : build symbol table */
    int lineNumber = 0;    
    while(parser.hasMoreCommands()){
        parser.advance();
        char commandType = parser.commandType();

        if(commandType == 'A'){
            cout<<lineNumber<<" Address : "<<parser.symbol() << endl;
            lineNumber++;
        }
        else if(commandType == 'C'){
            cout << lineNumber << " dest: " << parser.dest() << ", comp: " << parser.comp() << ", jump: " << parser.jump() << endl;
            lineNumber++;
        }
        else if(commandType == 'L'){
            cout << "Label : "<< parser.symbol() << endl;
            symbolTable.addSymbol(parser.symbol(), lineNumber);
            continue;
        }
    }

    /* second-pass : translation*/
    parser.reset();
	
	vector<string> machine_code;
	lineNumber = 0;
	int ram_location = 16;
	while (parser.hasMoreCommands()) {
		parser.advance();
		if(parser.commandType() == 'C') {
			cout << lineNumber << " dest: " << parser.dest() << ", comp: " << parser.comp() << ", jump: " << parser.jump() << endl;
			string cmd = "111" + Code::comp(parser.comp()) + Code::dest(parser.dest()) + Code::jump(parser.jump());
			machine_code.push_back(cmd);
			lineNumber++;
		}
		else if(parser.commandType() == 'A'){
			string symbol = parser.symbol();
			string cmd = "";
			cout << lineNumber << " Address: " << symbol << endl;
			if(isalpha(symbol[0])) {
				if(symbolTable.contains(symbol)) {
					cmd = "0" + bitset<15>(symbolTable.getAddress(symbol)).to_string();
				}
				else {
					cmd = "0" + bitset<15>(ram_location).to_string();
					symbolTable.addSymbol(symbol, ram_location);
					ram_location++;
				}
			} 
			else {
				cmd = "0" + bitset<15>(stoi(symbol)).to_string();
			}
			machine_code.push_back(cmd);
			lineNumber++;
		}
		else if(parser.commandType() == 'L'){
			cout << "Ignore Label: " << parser.symbol() << endl;
		}
		else continue;
		cout << endl;
	}
	
	string outfile = fileName.substr(0, fileName.length()-4) + ".hack";
	cout << "Output File: " << outfile << endl << endl;
	ofstream hackfile(outfile);
	
	for(string cmd : machine_code) {
		hackfile << cmd << endl;
		cout << cmd << endl;
	}
	cout << endl;
	hackfile.close();
	
	cout << "Assebly Ended!" << endl;
	return 0;
}