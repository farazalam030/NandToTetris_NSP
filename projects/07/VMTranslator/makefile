VMTranslator: main.o Parser.o CodeWriter.o
	g++ -std=c++2a main.o Parser.o CodeWriter.o -o VMTranslator.o;

main.o: main.cpp
	g++ -std=c++2a -c main.cpp

Parser.o: Parser.cpp Parser.h
	g++ -std=c++2a -c Parser.cpp

CodeWriter.o: CodeWriter.cpp CodeWriter.h
	g++ -std=c++2a -c CodeWriter.cpp

clean:
	rm *.o *.exe *.out *.exe.*