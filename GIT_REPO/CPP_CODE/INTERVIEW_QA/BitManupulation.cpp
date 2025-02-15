#include <iostream>
#define SEPARATOR { std::cout << "\n\n-----------\n\n"; }
using namespace std;

/*-----------------------------------------*
||  Print the numbber to binary format
*------------------------------------------*/
void binFmt(int n) {
    if(n > 0)
        binFmt(n >> 1);
    std::cout << (n & 1);
}
/*-----------------------------------------*
||  Check if a number is power of 2 power n
||  Logic is expliained below :
*------------------------------------------*/
/*
8 -> 0000 1000
7 -> 0000 0111  (&)
--------------------
     0000 0000 = 0

((n & (n - 1)) == 0) then Power of 2.
*/
bool checkIf2PowerN(int n) {
    return (n & (n - 1) ? false : true);
}
/*-----------------------------------------*
||  Check if k th bit of number is set(1)
||  Logic is expliained below :
*------------------------------------------*/
/*
k = 3
12     -> 0000 1100
1 << 3 -> 0000 0100 (&)
---------------------------
(&)	      0000 0100 != 0  ==> So bit is not set

Formula :
    n & (1 << (k - 1)) == 0 then bit set.
*/
bool checkIfBitSet(int n, int k) {
    return (n & (1 << k - 1) ? true : false);
}

/*-----------------------------------------*
||  Set bit i.e if 0 ==> 1
||  Logic is expliained below :
*------------------------------------------*/
/*
k = 3
12       -> 0000 1100
1 << 5   -> 0001 0000
---------------------------
(|)	        0001 1100 ==> 5rd bit is cleared.

Formula :
    n = n | (1 << (k - 1))
*/
void setBit(int *n, int k) {
    *n = (*n | (1 << k - 1));
}

/*-----------------------------------------*
||  Clearing the bit i.e if 1 ==> 0
||  Logic is expliained below :
*------------------------------------------*/
/*
k = 3
12          -> 0000 1100
~(1 << 3)   -> 1111 1011
---------------------------
(&)	           0000 1000 ==> 3rd bit is cleared.

Formula :
    n = n & ~(1 << (k - 1))
*/
void clearingBit(int *n, int k) {
    *n = (*n & (~(1 << k - 1)));
}

/*-----------------------------------------*
||  Toggling bit i.e if 1 ==> 0 , 0 ==> 1
||  Logic is expliained below :
*------------------------------------------*/
/*
k = 3
12       -> 0000 1100
1 << 3   -> 0000 0100
---------------------------
(^)	        0000 1000 ==> 3rd bit is cleared.

Formula :
    n = n ^ (1 << (k - 1))
*/
void toggleBit(int *n, int k) {
    *n = (*n ^ (1 << k - 1));
}

/*-----------------------------------------*
||  KB to Byte Conversion i.e 1KB = 2 ^ 10 Byte
||  GB to Byte Conversion i.e 1GB = 2 ^ 20 Byte
||  TB to Byte Conversion i.e 1TB = 2 ^ 30 Byte
||  Logic is expliained below :
*------------------------------------------*/
/*
12       -> 0000 1100 << 10
---------------------------
Formula :
    n = n << 10;
    n = n << 20;
    n = n << 30;
*/
unsigned long kbToByte(int n) {
    return n << 10;
}

unsigned long gbToByte(int n) {
    return n << 20;
}

unsigned long tbToByte(int n) {
    return n << 29;
}

int main()
{
    int n = 12;
    std::cout << "n ::: ";
    binFmt(n);
    SEPARATOR

    checkIf2PowerN(n) ? (cout << "Power of 2") : (cout << "Not power of 2 !!");
    SEPARATOR

    int k = 3;
    binFmt(n);
    std::cout << std::endl;
    checkIfBitSet(n, k) ? (cout << "Field set") : (cout << "Field not set");
    SEPARATOR

    binFmt(n);
    std::cout << std::endl;
    clearingBit(&n, k);
    binFmt(n);
    SEPARATOR

    k = 5;
    binFmt(n);
    std::cout << std::endl;
    setBit(&n, k);
    binFmt(n);
    SEPARATOR

    k = 3;
    binFmt(n);
    std::cout << std::endl;
    toggleBit(&n, k);
    binFmt(n);
    std::cout << std::endl;
    toggleBit(&n, k);
    binFmt(n);
    SEPARATOR

    unsigned long byte = kbToByte(n);
    std::cout << n << "KB = " << byte << " bytes." << std::endl;

    byte = gbToByte(n);
    std::cout << n << "GB = " << byte << " bytes." << std::endl;

    n = 5;
    byte = tbToByte(n);
    std::cout << n << "TB = " << byte << " bytes." << std::endl;

    return 0;
}