class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i=0;
        uint32_t number =0;
        while(i<32){
            number = (number<<1)+ (n%2);
            n= n/2;
            i++;
        }
        return number;
    }
};