//https://leetcode.com/problems/reverse-bits/

#include<bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n) {
        //O(1) time
        
        //initially divide the 32 bit interger into 2 parts and reverse them
        n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);

        //then divide the 2*16 bit integer into 2 parts and reverse them
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);

        //divide the 4*8 bit integer into 2 parts and reverse them
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);

        //divide the 8 * 4 bit integers into 2 parts and reverse them
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        
        //now divide the 16* 2 bit integer into 2 parts and reverse them
        //this will give you the reverse of the number
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        
        return n;
    }

    int main()
    {
        uint32_t n=43261596;//00000010100101000001111010011100
        cout<<reverseBits(n);//964176192 (00111001011110000010100101000000)

        return 0;
    }