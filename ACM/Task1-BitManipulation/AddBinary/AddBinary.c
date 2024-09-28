#include<string.h>
#include<stdlib.h>
char* addBinary(char* a,char* b) {
    int lenA=strlen(a),lenB=strlen(b),maxLen=(lenA>lenB)?lenA:lenB;
    char* result=(char*)malloc((maxLen+2)*sizeof(char));
    result[maxLen+1]='\0';
    int carry=0,index=maxLen;
    while(lenA>0||lenB>0||carry>0) {
        int sum=carry;
        if(lenA>0) {
            sum+=(a[lenA-1]-'0');
            lenA--;
        }
        if(lenB>0) {
            sum+=(b[lenB-1]-'0');
            lenB--;
        }
        result[index]=(sum%2)+'0';
        carry=sum/2;
        index--;
    }
    return strdup(&result[index+1]);
}
