#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* Data alignment */
typedef struct point {
	char x;         //1 byte + 7 bytes padding
	double y;       //8 bytes
	char z;         //7 bytes padding + 1 byte 
}Point;     //Total 24 bytes

// But, if we just rearrange the order of the fields in this struct //
// Then we will be able to see that the size of the struct will be different //
typedef struct point {
	char x;     //1 byte
	char z;     //1 bytes + 6 bytes padding
	double y;   //8 bytes
}Point; //Total 16 bytes

typedef struct point2{
    char t;     //1 byte + 1 byte padding
    short x;    //2 bytes
    char z;     //1 byte + 3 bytes padding
    double y;   //8 bytes
}Point2; //Total 16 bytes

typedef struct point3{
    char t;     //1 byte
    int x;      //3 bytes padding + 4 bytes (int) (Note: exceed 8 bytes)
    char z;     //1 byte + 7 bytes of padding
    double y;   //8 bytes
}Point3;        // Total 24 bytes

typedef struct point4{
    char t;     //1 byte
    char z;     //1 byte + 2 bytes of padding (since int is 4)
    int x;      //4 bytes (Note: total 8, double y is align)
    double y;   //8 bytes
}Point4;        // Total 16 bytes
