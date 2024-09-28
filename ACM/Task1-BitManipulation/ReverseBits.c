uint32_t reverseBits(uint32_t n) {
    char binary[33];
    for (int i=0;i<32;++i){
        binary[i]=(n%2)+'0';
        n/=2;
    }
    binary[32]='\0';
    uint32_t reverse=0;
    uint32_t power=1;
    for (int j=31;j>=0;--j){
        if (binary[j]=='1'){
            reverse+=power;
        }
        power=power*2;
    }
    return reverse;
}