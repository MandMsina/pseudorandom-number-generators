COMPILER=gcc
FLAG= -std=c99
HEADERS = random_generators.h LKM.h Mersenne_twister.h Middle_square.h Mother_of_all.h Xorshift.h
SOURCES= LKM.o Mersenne_twister.o Middle_square.o Mother_of_all.o Xorshift.o

algorithms.exe: $(SOURCES) main.o random_generators.o
	$(COMPILER) -o algorithms.exe random_generators.o main.o LKM.o Mersenne_twister.o Middle_square.o Mother_of_all.o Xorshift.o

main.o: random_generators.o main.c
	$(COMPILER) $(FLAG) -c main.c -o main.o

random_generators.o: random_generators.c random_generators.h $(SOURCES)
	$(COMPILER) $(FLAG) -c random_generators.c -o random_generators.o

LKM.o: LKM.c LKM.h random_generators.h
	$(COMPILER) $(FLAG) -c LKM.c -o LKM.o

Mersenne_twister.o: Mersenne_twister.c Mersenne_twister.h random_generators.h
	$(COMPILER) $(FLAG) -c Mersenne_twister.c -o Mersenne_twister.o

Middle_square.o: Middle_square.c Middle_square.h random_generators.h
	$(COMPILER) $(FLAG) -c Middle_square.c -o Middle_square.o

Mother_of_all.o: Mother_of_all.c Mother_of_all.h random_generators.h
	$(COMPILER) $(FLAG) -c Mother_of_all.c -o Mother_of_all.o

Xorshift.o: Xorshift.c Xorshift.h random_generators.h
	$(COMPILER) $(FLAG) -c Xorshift.c -o Xorshift.o

clean:
	del algorithms.exe $(SOURCES) main.o random_generators.o