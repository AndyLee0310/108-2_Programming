#include <stdio.h>
#include <string.h>
#define ShapeText(TYPE) double (*perimeter)(struct TYPE*);

typedef struct shape_s {
	ShapeText(shape_s);
} 	shape_t;

typedef struct circle_s {
	ShapeText(circle_s);
	double radius;
} 	circle_t;

typedef struct rectangle_s {
	ShapeText(rectangle_s);
	double length;
	double width;
} 	rectangle_t;

typedef struct square_s {
	ShapeText(square_s);
	double edge;
} 	square_t;

typedef struct triangle_s {
	ShapeText(triangle_s);
	double edge1;
	double edge2;
	double edge3;
} 	triangle_t;

double shapep(shape_t *obj) {return 0;}
void shape_new(shape_t *obj) {obj->perimeter = shapep;}

double circlep(circle_t *obj) {return 2*3.14 * obj->radius;}
void circle_new(circle_t *obj) {obj->perimeter = circlep;}

double rectanglep(rectangle_t *obj) {return 2 * (obj->length + obj->width);}
void rectangle_new(rectangle_t *obj) {obj->perimeter = rectanglep;}

double squarep(square_t *obj) {return 4 * obj->edge;}
void square_new(square_t *obj) {obj->perimeter = squarep;}

double trianglep(triangle_t *obj) {return obj->edge1 + obj->edge2 + obj->edge3;}
void triangle_new(triangle_t *obj) {obj->perimeter = trianglep;}

int main(void) {
	int x;
	char ty;
	double tl;

	scanf("%d\n", &x);
	shape_t *list[x];

	circle_t c;
	rectangle_t r;
	square_t s;
	triangle_t t;

	for (int i = 0; i < x; i++) {
		scanf("%c ", &ty);
		switch (ty) {
			case 'C':
				circle_new(&c);
				scanf("%lf", &c.radius);
				getchar();
				list[i] = (shape_t*)&c;
				break;
			case 'R':
				rectangle_new(&r);
				scanf("%lf%lf", &r.length, &r.width);
				getchar();
				list[i] = (shape_t*)&r;
				break;
			case 'S':
				square_new(&s);
				scanf("%lf", &s.edge);
				getchar();
				list[i] = (shape_t*)&s;
				break;
			case 'T':
				triangle_new(&t);
				scanf("%lf%lf%lf", &t.edge1, &t.edge2, &t.edge3);
				getchar();
				list[i] = (shape_t*)&t;
				break;
		}
		shape_t *o = list[i];
		printf("%.2lf\n", o->perimeter(o));
		tl += o->perimeter(o);
	}
	printf("%.2lf\n", tl);
	
	return 0;
}
