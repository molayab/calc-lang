all: calc

OBJECTS=calc.o scanner.o token.o ast.o parser.o calculator.o compiler.o

calc: $(OBJECTS)
	$(CXX) -g -o $@ $(OBJECTS)

calc.o: calc.C scanner.h token.h
	$(CXX) -g -c calc.C

calculator.o: calculator.C calculator.h parser.h ast.h
	$(CXX) -g -c calculator.C

scanner.o: scanner.C scanner.h token.h
	$(CXX) -g -c scanner.C

token.o: token.C token.h
	$(CXX) -g -c token.C

ast.o: ast.C ast.h
	$(CXX) -g -c ast.C

parser.o: parser.C parser.h
	$(CXX) -g -c parser.C

compiler.o: compiler.C compiler.h calc.h token.h
	$(CXX) -g -c compiler.C

clean:
	rm -f *.ewe
	rm -f *.o
	rm -f calc
