#include "../aux.h"
#include "../umix.h"
#include "../mycode4.h"

#define NUMYIELDS	5

static int square, cube;	// global variables, shared by threads

void Main ()
{
	Printf("*************************************************************\n");
	Printf("Reference of t7.\n");
	Printf("*************************************************************\n");

	int i, t, me;
	void printSquares (), printCubes (), proc();

	InitThreads ();

	me = GetThread ();
	t = CreateThread (printSquares, me);
	t = CreateThread (printCubes, t);
	CreateThread (proc, 3);
	CreateThread (proc, 4);
	CreateThread (proc, 5);
	CreateThread (proc, 6);
	CreateThread (proc, 7);
	CreateThread (proc, 8);
	CreateThread (proc, 9);
	CreateThread (proc, 10);

	for (i = 0; i < NUMYIELDS; i++) {
		YieldThread (t);
		Printf ("T%d: square = %d, cube = %d\n", me, square, cube);
	}

	ExitThread ();
}

void printSquares (t)
	int t;				// thread to yield to
{
	int i;

	for (i = 0; i < NUMYIELDS; i++) {
		square = i * i;
		Printf ("T%d: %d squared = %d\n", GetThread (), i, square);
		YieldThread (t);
	}
}

void printCubes (t)
	int t;				// thread to yield to
{
	int i;

	for (i = 0; i < NUMYIELDS; i++) {
		cube = i * i * i;
		Printf ("T%d: %d cubed = %d\n", GetThread (), i, cube);
		SchedThread();
		YieldThread (t);
	}
}

void proc(p) 
	int p;
{
	void proc2();
	DPrintf("Proc %d\n", GetThread());
	CreateThread(proc2, 1);
}
void proc2() {
	DPrintf("Proc %d\n", GetThread());
	YieldThread (GetThread()+1);
	YieldThread (GetThread()+2);
}
