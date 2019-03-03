#include "../aux.h"
#include "../umix.h"
#include "../mycode4.h"

#define NUMYIELDS	5

static int square, cube;	// global variables, shared by threads

void Main ()
{
	int i, t, me;
	void printSquares (), printCubes (), proc();

	MyInitThreads ();

	me = MyGetThread ();
	t = MyCreateThread (printSquares, me);
	t = MyCreateThread (printCubes, t);
	MyCreateThread (proc, 3);
	MyCreateThread (proc, 4);
	MyCreateThread (proc, 5);
	MyCreateThread (proc, 6);
	MyCreateThread (proc, 7);
	MyCreateThread (proc, 8);
	MyCreateThread (proc, 9);
	MyCreateThread (proc, 10);

	for (i = 0; i < NUMYIELDS; i++) {
		MyYieldThread (t);
		Printf ("T%d: square = %d, cube = %d\n", me, square, cube);
	}

	MyExitThread ();
}

void printSquares (t)
	int t;				// thread to yield to
{
	int i;

	for (i = 0; i < NUMYIELDS; i++) {
		square = i * i;
		Printf ("T%d: %d squared = %d\n", MyGetThread (), i, square);
		MyYieldThread (t);
	}
}

void printCubes (t)
	int t;				// thread to yield to
{
	int i;

	for (i = 0; i < NUMYIELDS; i++) {
		cube = i * i * i;
		Printf ("T%d: %d cubed = %d\n", MyGetThread (), i, cube);
		MySchedThread();
		MyYieldThread (t);
	}
}

void proc(p) 
	int p;
{
	void proc2();
	DPrintf("Proc %d\n", MyGetThread());
	MyCreateThread(proc2, 1);
}
void proc2() {
	DPrintf("Proc %d\n", MyGetThread());
	MyYieldThread (MyGetThread()+1);
	MyYieldThread (MyGetThread()+2);
}



