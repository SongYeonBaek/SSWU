#include <iostream>
#include <string>
using namespace std;

#define MAX_STACK_SIZE 100

typedef struct {
	string name;
	string actor;
	int year;
}Movie;

typedef struct {
	Movie data[MAX_STACK_SIZE];
	int top;
}stack;

void init(stack *s) {
	s->top = -1;
}

int is_empty(stack *s) {
	return (s->top == -1);
}

int is_full(stack *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(stack *s, Movie m) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}

	else s->data[++(s->top)] = m;
}

Movie pop(stack *s) {
	return s->data[(s->top)--];
}

Movie peek(stack *s) {
	return s->data[s->top];
}

void main() {

	stack s;
	init(&s);

	cout << "=== 보고 싶은 영화 정보목록 작성 ==="
		<< "\n 보고 싶은 영화 수를 입력하시오 : ";
	int num;
	cin >> num;
	
	for (int i = 0; i < num; i++) {
		Movie movie;

		cout << "\n영화제목 : ";
		cin >> movie.name;
		cout << "주연 : ";
		cin >> movie.actor;
		cout << "개봉년도 : ";
		cin >> movie.year;

		push(&s, movie);
	}

	cout << "\n== 보고 싶은 영화 목록 ==" << endl;
	cout << " 영화편 수 [ " << num << " ] = " << endl;
	stack s2 = s;
	while(s2.top!= 0) {
		Movie m = pop(&s2);
		cout << "\t" << m.name << "\t" << m.actor << "\t" << m.year << endl;
	}

	int num2;
	cout << "본 영화 수 : ";
	cin >> num2; 
	for (int i = 0; i < num2; i++) {
		pop(&s);
	}

	cout << "아직 못 본 영화 목록 -- \n 영화편 수 [ " << num - num2 << " ] = " <<endl;
	for (int i = 0; i < num - num2; i++) {
		Movie m = pop(&s);
		cout << "\t" << m.name << "\t" << m.actor << "\t" << m.year << endl;
	}
	
}