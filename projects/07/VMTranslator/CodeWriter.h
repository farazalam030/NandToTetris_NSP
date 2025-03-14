#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string SP = "SP";
const string LCL = "LCL";
const string ARG = "ARG";
const string THIS = "THIS";
const string THAT = "THAT";
const string TEMP = "5";

const string addr = "addr";

const bool INC = true;
const bool DCR = false;

class CodeWriter
{
	ofstream asmFile;
	string asmFileName;
	string currentVmFile;
	bool debug;
	int label_no;

public:
	CodeWriter(string outputFile);

	void setFileName(string fileName);

	void writeArithmetic(string cmd);

	void writePushPop(string cmd, string segment, int index);

	void close();

	void setDebug(bool dbg);

private:
	// helper methods

	string generateAsmPush(string segment, int index);

	string generateAsmPop(string segment, int index);

	string i_to_ptr(string ptr, string i);

	string vrb_to_ptr(string ptr, string vrb);

	string ptr_to_vrb(string vrb, string ptr);

	string ptr_to_ptr(string ptr1, string ptr2);

	string inc_or_dcr_vrb(string vrb, bool inc);

	string i_th_segment(string dest, string segment, string i);

	string arithmetic_logical(string opr);

	string neg_or_not(string opr);

	string comparision(string cmp);

	string getBaseFileName(string filename);
};

/*

[ Arithmetic operations - add, sub, neg, eq, gt, lt, and, or, not]

------------------------------  CodeWriter class ------------------------------------------------
Constructor - Output file / stream -- Opens the output file/stream and gets ready to write into it.

setFileName - fileName (string) -- Informs the code writer that the translation of a new VM file is started.

writeArithmetic - command (string) -- Writes the assembly code that is the translation of the given arithmetic command.

WritePushPop - command (C_PUSH or C_POP),segment (string),index (int) -- Writes the assembly code that is the translation
				of the given command, where command is either C_PUSH or C_POP.

Close -- -- Closes the output file
*/
