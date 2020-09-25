#include <stdio.h>
#include <stdlib.h>
#define GATEVALUE(TYPE) int(*GateValue)(int a, int m)

typedef struct _Gate {GATEVALUE();}	Gate;
typedef struct _GateAnd {GATEVALUE();}	GateAND;
typedef struct _GateOR {GATEVALUE();}	GateOR;
typedef struct _GateXOR {GATEVALUE();}	GateXOR;
typedef struct _GateNOT {GATEVALUE();}	GateNOT;

int GGV(int n, int m){return n;}
void CG(Gate *obj) {obj->GateValue = GGV;}

int GAV(int n, int m){return n&m;}
void CGA (GateAND *obj) {obj->GateValue = GAV;}

int GOV(int n, int m){return n|m;}
void CGO(GateOR *obj) {obj->GateValue = GOV;}

int GXORV(int n, int m){return n^m;}
void CGXOR(GateXOR *obj) {obj->GateValue = GXORV;}

int GNV(int n, int m){return !n;}
void CGN(GateNOT *obj) {obj->GateValue = GNV;}


int test(char x, int m, int n) {
	Gate gate;
	GateAND and;
	GateOR or;
	GateXOR xor;
	GateNOT not;

	switch(x) {
		case 'A':
			CGA(&and);
			return and.GateValue(m, n);
			break;
		case 'O':
			CGO(&or);
			return or.GateValue(m, n);
			break;
		case 'X':
			CGXOR(&xor);
			return xor.GateValue(m, n);
			break;
		case 'N':
			CGN(&not);
			return not.GateValue(m, m);
			break;
		case 'E':
			CG(&gate);
			return gate.GateValue(m, m);
			break;
	}
}

int main(void) {
	int x[4], o;
	scanf("%d,%d,%d,%d\n", &x[0], &x[1], &x[2], &x[3]);

	char a[6];
	for (int i = 0; i < 6; i++) {
		scanf("%c", &a[i]);
		getchar();
	}

	o = test(a[1], test(a[0], x[0], x[0]), x[1]);
	printf("%d,", o);

	o = test(a[3], test(a[2], o, x[2]), o);
	printf("%d,", o);

	o = test(a[5], test(a[4], x[3], x[3]), o);
	printf("%d\n", o);

	return 0;
}
