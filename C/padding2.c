#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* Struct inside a struct */ 

typedef struct a {
	short val1;     //2 bytes + 2 bytes padding
	int val2;       //4 bytes
	char val3;      //1 byte + 3 bytes padding
}A; //Total 12 bytes

typedef struct b {
	char val1;   //1 byte + 3 bytes padding
	int val2;   //4 bytes
	A val3;     //12 bytes (similar above)
}B;

int main()
{
	unsigned int totalBytesA = sizeof(A);
	unsigned int totalBytesB = sizeof(B);
	B b1;
	b1.val1 = 0xFF;
	b1.val2 = 0x12341234;
	b1.val3.val1 = 0xBBDD;
	b1.val3.val2 = 0xAACCEEFF;
	b1.val3.val3 = 0x99;
	return 0;
}