#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

typedef struct {
	int key1;
	int key2;
}element;

element hash_table[TABLE_SIZE];
int crash_count = 0;
int overflow_count = 0; 

void init_table(element ht[]) {
	int i;
	for (i = 0; i < TABLE_SIZE; i++) {
		ht[i].key1 = NULL;
		ht[i].key2 = NULL;
	}
}

int hash_function(int key) {
	return key % 10;
}

void hash_lp_add(int item, element ht[]) {
	int i, hash_value;
	hash_value = i = hash_function(item);
	
	while ((ht[i].key1 != NULL) && (ht[i].key2!=NULL)) {
		if (item == ht[i].key1) {
			fprintf(stderr, "탐색키가 중복되었습니다.\n");
			exit(1);
		}
		if (item == ht[i].key2) {
			fprintf(stderr, "탐색키가 중복되었습니다.\n");
			exit(1);
		}

		overflow_count++;

		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "테이블이 가득찼습니다.\n");
			exit(1);
		}
	}

	if (ht[i].key1 == NULL) {
		ht[i].key1 = item;
		printf("해시테이블 [%d]번째 버킷의 첫번째 슬롯에 %d가 저장되었습니다. \n ", i, item);
	}
	else if (ht[i].key2 == NULL) {
		ht[i].key2 = item;
		crash_count++;
		printf("해시테이블 [%d]번째 버킷의 두번째 슬롯에 %d가 저장되었습니다. \n ", i, item);
	}
}

void hash_lp_search(int item, element ht[]) {
	int i, hash_value;
	hash_value = i = hash_function(item);
	
	while ((ht[i].key1 != NULL) && (ht[i].key1 != NULL)) {
		if (item == ht[i].key1) {
			fprintf(stderr, "탐색 %s: 위치 = %d번째 버킷, 1번째 슬롯\n", item, i);
			return;
		}
		else if (item == ht[i].key2) {
			fprintf(stderr, "탐색 %s: 위치 = %d번째 버킷, 2번째 슬롯\n", item, i);
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "찾는 값이 테이블에 없음\n");
			return;
		}
	}
	fprintf(stderr, "찾는 값이 테이블에 없음\n");
}

void hash_lp_print(element ht[]) {
		int i;
		printf("\n=============================\n");
		for (i = 0; i < TABLE_SIZE; i++) {
			printf("[%d] %d", i, ht[i].key1);
			printf(" %d\n", ht[i].key2);
		}
		printf("=============================\n\n");
}

int main(void) {
	int *n[12] = { 53, 374, 255, 557, 19, 100, 763, 812, 65, 710, 123, 818};
	int e;

	init_table(hash_table);

	for (int i = 0; i < 12; i++) {
		e = n[i];
		hash_lp_add(e, hash_table);
		hash_lp_print(hash_table);
	}
	
	printf("충돌 횟수는 총 %d번, 오버플로우는 총 %d번 일어났다.", crash_count, overflow_count);
	return 0;
}
