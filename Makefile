# Makefile to compile Umix Programming Assignment 4 (pa4) [updated: 1/17/18]

LIBDIR = $(UMIXPUBDIR)/lib
# LIBDIR = $(UMIXROOTDIR)/sys

CC 	= cc 
FLAGS 	= -g -L$(LIBDIR) -lumix4

PA4 =	pa4a pa4b pa4c

TESTS = t1 t2 t3 t4 t5 t6 tpa4c
REFES = r1 r2 r3 r4 r5 r6 rpa4c

pa4:	$(PA4)

test: $(TESTS) $(REFES)

pa4a:	pa4a.c aux.h umix.h
	$(CC) $(FLAGS) -o pa4a pa4a.c

pa4b:	pa4b.c aux.h umix.h mycode4.h mycode4.o
	$(CC) $(FLAGS) -o pa4b pa4b.c mycode4.o

pa4c:	pa4c.c aux.h umix.h mycode4.h mycode4.o
	$(CC) $(FLAGS) -o pa4c pa4c.c mycode4.o

mycode4.o:	mycode4.c aux.h umix.h mycode4.h
	$(CC) $(FLAGS) -c mycode4.c

clean:
	rm -f *.o $(PA4) $(TESTS) $(REFES)

t1:	Tests/t1.c aux.h umix.h mycode4.h mycode4.o
	$(CC) $(FLAGS) -o t1 Tests/t1.c mycode4.o

t2:	Tests/t2.c aux.h umix.h mycode4.h mycode4.o
	$(CC) $(FLAGS) -o t2 Tests/t2.c mycode4.o

t3:	Tests/t3.c aux.h umix.h mycode4.h mycode4.o
	$(CC) $(FLAGS) -o t3 Tests/t3.c mycode4.o

t4:	Tests/t4.c aux.h umix.h mycode4.h mycode4.o
	$(CC) $(FLAGS) -o t4 Tests/t4.c mycode4.o

t5:	Tests/t5.c aux.h umix.h mycode4.h mycode4.o
	$(CC) $(FLAGS) -o t5 Tests/t5.c mycode4.o

t6:	Tests/t6.c aux.h umix.h mycode4.h mycode4.o
	$(CC) $(FLAGS) -o t6 Tests/t6.c mycode4.o

tpa4c:	Tests/tpa4c.c aux.h umix.h mycode4.h mycode4.o
	$(CC) $(FLAGS) -o tpa4c Tests/tpa4c.c mycode4.o

r1:	Tests/r1.c aux.h umix.h mycode4.h mycode4.o
	$(CC) $(FLAGS) -o r1 Tests/r1.c mycode4.o
	
r2:	Tests/r2.c aux.h umix.h mycode4.h mycode4.o
	$(CC) $(FLAGS) -o r2 Tests/r2.c mycode4.o

r3:	Tests/r3.c aux.h umix.h mycode4.h mycode4.o
	$(CC) $(FLAGS) -o r3 Tests/r3.c mycode4.o

r4:	Tests/r4.c aux.h umix.h mycode4.h mycode4.o
	$(CC) $(FLAGS) -o r4 Tests/r4.c mycode4.o

r5:	Tests/r5.c aux.h umix.h mycode4.h mycode4.o
	$(CC) $(FLAGS) -o r5 Tests/r5.c mycode4.o

r6:	Tests/r6.c aux.h umix.h mycode4.h mycode4.o
	$(CC) $(FLAGS) -o r6 Tests/r6.c mycode4.o

rpa4c:	Tests/rpa4c.c aux.h umix.h mycode4.h mycode4.o
	$(CC) $(FLAGS) -o rpa4c Tests/rpa4c.c mycode4.o
