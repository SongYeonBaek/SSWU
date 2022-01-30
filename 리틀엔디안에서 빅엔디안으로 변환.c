#include <stdio.h>

struct bitfield {
	unsigned int bit0 : 1; 
	unsigned int bit1 : 1; 
	unsigned int bit2 : 1; 
	unsigned int bit3 : 1; 
	unsigned int bit4 : 1; 
	unsigned int bit5 : 1; 
	unsigned int bit6 : 1; 
	unsigned int bit7 : 1; 
	unsigned int bit8 : 1;
	unsigned int bit9 : 1;
	unsigned int bit10 : 1;
	unsigned int bit11 : 1;
	unsigned int bit12 : 1;
	unsigned int bit13 : 1;
	unsigned int bit14 : 1;
	unsigned int bit15 : 1;
};

union uniset {
	struct bitfield bit;
	unsigned int number;
	char ch[4];
};

int main() {
	union uniset uni;
	uni.number = 0x12345678;

	printf("uni.number = 0x%x\n", uni.number);
	printf("size of int: %d\n", sizeof(int));
	printf("size of char: %d\n", sizeof(char));

	printf("Hexa of ch[0], chi[1], ch[2], ch[3]\n: %x, %x, %x, %x\n",
		uni.ch[0], uni.ch[1], uni.ch[2], uni.ch[3]);
	printf("bits of ch[0]: [ %x, %x, %x, %x ], [ %x, %x, %x, %x ]\n",
		uni.bit.bit7, uni.bit.bit6, uni.bit.bit5, uni.bit.bit4, uni.bit.bit3, uni.bit.bit2, uni.bit.bit1, uni.bit.bit0);
	printf("bits of ch[1]: [ %x, %x, %x, %x ], [ %x, %x, %x, %x ]\n",
		uni.bit.bit15, uni.bit.bit14, uni.bit.bit13, uni.bit.bit12, uni.bit.bit11, uni.bit.bit10, uni.bit.bit9, uni.bit.bit8);

	printf("Address of array ch[0], ch[1], ch[2], ch[3]\n : %u, %u, %u, %u\n",
		&uni.ch[1], &uni.ch[2], &uni.ch[3]);
	printf("ch[0] > > 4 &0x0f: %x\n", uni.ch[0] >> 4 & 0x0f); //7
	printf("ch[0] > > 0 & 0xf0: %x\n", uni.ch[0] >> 0 & 0xf0); //70

	printf("What does the numbers mean below?\n");
	printf("uni.number >> 4 & 0x0000000f: %x\n", uni.number >> 4 & 0x0000000f); //7
	printf("uni.number >> 0 & 0x0000000f: %x\n", uni.number >> 0 & 0x0000000f); //8
	printf("uni.number & 0x000f0000: %x\n", uni.number & 0x000f0000); //4

	printf("uni.number > > 0 & 0xf0000000: %x in hexa decimal\n", uni.number >> 0 & 0xf0000000); // 0x1000 0000

	return 0;
}