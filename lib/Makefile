.PHONY: all

all: main
	
main: main.o PrimeFactorization.o
	g++ -Wall -Werror -g -o main main.o PrimeFactorization.o -std=c++0x

PrimeFactorization.o: PrimeFactorization.cpp
	g++ -Wall -Werror -g -c PrimeFactorization.cpp -std=c++0x

clean:
	rm -f main

test:
	@cd cases/ \
		&& files=`ls -1` \
		&& cd ../ \
		&& for file in $$files; do cat cases/$$file | ./main > tmp.txt; diff tmp.txt results/$$file &>/dev/null; if [ $$? -ne 0 ]; then echo "$$file error"; exit 255; else echo "pass $$file"; fi; done \
		&& echo "all pass!!!"
