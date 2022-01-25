#include <iostream>
#include <string>
using namespace std;

#define MAX_QUEUE_SIZE 100

typedef struct {
	string name;
	string actor;
	int year;
}Movie;

typedef struct {
	Movie data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void init(QueueType *q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType *q) {
	return (q->front == q->rear);
}

int is_full(QueueType *q) {
	return((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, Movie m) {
	if (is_full(q))
		cout << "큐가 포화상태입니다";
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = m;
}

Movie dequeue(QueueType *q) {
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void main() {
	QueueType q;
	init(&q);

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

		enqueue(&q, movie);
	}

	cout << "\n== 보고 싶은 영화 목록 ==" << endl;
	cout << " 영화편 수 [ " << num << " ] = " << endl;
	QueueType q2 = q;
	while ( q2.front!=q2.rear ) {
		Movie m = dequeue(&q2);
		cout << "\t" << m.name << "\t" << m.actor << "\t" << m.year << endl;
	}

	int num2;
	cout << "본 영화 수 : ";
	cin >> num2;
	for (int i = 0; i < num2; i++) {
		dequeue(&q);
	}

	cout << "아직 못 본 영화 목록 -- \n 영화편 수 [ " << num - num2 << " ] = " << endl;
	for (int i = 0; i < num - num2; i++) {
		Movie m = dequeue(&q);
		cout << "\t" << m.name << "\t" << m.actor << "\t" << m.year << endl;
	}

}