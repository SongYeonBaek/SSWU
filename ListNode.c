#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode *head, int value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;

	p->link = head;
	head = p;
	return head;
}

//노드 pre뒤에 새로운 노드 삽입
ListNode* insert_next(ListNode* head, ListNode *pre, element value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;

	pre->link = p;
	return head;
}

ListNode* insert_last(ListNode *head, element value) {
	ListNode *temp = head; 

	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;

	if (head == NULL) {
		head = p;
	}
	else {
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = p;
	}
	
	return head;
}

ListNode* delete_first(ListNode *head) {
	ListNode *removed;

	if (head == NULL) printf("삭제할 항목이 없음");
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

//pre가 가리키는 노드의 다음 노드 삭제 
 ListNode* delete_next(ListNode *head, ListNode *pre) {
	 ListNode *removed; 

	 if (head == NULL) printf("삭제할 항목이 없음");
	 removed = pre->link;
	 pre->link = removed->link;
	 free(removed);

	 return head;
 }

 ListNode* delete_last(ListNode *head) {
	 ListNode *temp = head; 
	 ListNode *prevTemp;
	 ListNode *removed;

	if (head == NULL) printf("삭제할 항목이 없음");
	if (head->link == NULL) {
		 removed = head->link;
		 free(removed);
		 head = NULL;
	 }
	 else {
		 while (temp->link != NULL) {
			 prevTemp = temp;
			 temp = temp->link;
		 }
		 prevTemp->link = NULL;
		 removed = temp;
		 free(removed);
	 }
	 return head;
 }

void print_list(ListNode *head) {
	ListNode *p;
	for (p = head; p != NULL; p = p->link)
		printf("%d-> ", p->data);
	printf("NULL \n");
}

ListNode *search(ListNode *head, int x) {
	ListNode *p = head;

	while (p != NULL) {
		if (p->data == x) return p;
		p = p->link;
	}
	return NULL;
}

ListNode *concat(ListNode *head1, ListNode *head2) {
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1; 
	else {

		ListNode *p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;

		return head1;
	}
}

ListNode *reverse(ListNode *head) {
	ListNode *p, *q, *r;
	p = head;
	q = NULL;
	
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}

int is_in_list(ListNode *head, element item) {
	for (ListNode *p = head; p != NULL; p = p->link)
		if (p->data = item) return 1;
	return 0;
}

int get_length(ListNode *head) {
	int count = 0;
	for (ListNode *p = head; p != NULL; p = p->link)
		count++;
	return count;
}

int get_total(ListNode *head) {
	int total = 0;
	for (ListNode *p = head; p != NULL; p = p->link)
		total += p->data;
	return total;
}

element get_entry(ListNode *head, int pos) {
	ListNode *p = head;
	for (int i = 0; i < pos; i++) {
		p = p->link;
	}
	return p->data;
}

ListNode * delete_by_key(ListNode *head, int key) {
	ListNode *pre;
	for (ListNode *p = head; p != NULL; p = p->link) {
		pre = p;
		if (p->data = key) delete_next(head, pre);
	}
}

ListNode * insert_pos(ListNode *head, int pos, element value) {
	ListNode *p = head;
	ListNode *pre = p;

	for (int i = 0; i < pos; i++) {
		pre = p;
		p = p->link;
	}
	insert_next(head, pre, value);
}

ListNode * delete_pos(ListNode *head, int pos) {
	ListNode *p = head;
	ListNode *pre = p;
	for (int i = 0; i < pos; i++) {
		pre = p;
		p = p->link;
	}
	delete_next(head, pre);
}

int main(void) {
	ListNode *list1 = NULL, *list2 = NULL, *list3;
	//list1 = 30->20->10->를 만든다. 이때 10, 20, 30의 순으로 노드를 삽입한다.
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30); // list1을 출력
	printf("list1 = "); print_list(list1);
	//list1의 맨 앞 노드를 삭제한다 즉, list1 = 20->10->
	delete_first(list1);
	// list1을 출력
	print_list(list1);
	//list2 = 11->22->33->44->를 만든다. 이때 11, 22, 33, 44의 순으로 노드를 삽입한다.
	
	
	// list2를 출력
	print_list(list2);
	// list2의 맨 뒤 노드를 삭제한다. 즉, list2 = 11->22->33->

	//delete_(list2, );
	// list2를 출력
	print_list(list2);

	//list3를 출력한다.  
	print_list(list3);
	// list1 = 20->30->33->22->11->를 만든다. 즉, list1과 list3를 합쳐서 list1이 가리키게 한다.

	//list1을 출력한다.
	print_list(list1);