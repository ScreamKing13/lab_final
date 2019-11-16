all: compile run_test

compile:
	g++ -std=c++11 cmd_parse_app.cpp

run_test:
	./a.out --list --version=6 -V6 -hl

clean:
	rm a.out