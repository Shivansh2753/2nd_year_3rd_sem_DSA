#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printarr(char str[]){
    int len = strlen(str);
    for(int i=0;i<len;i++){
        printf("%c",str[i]);
    }
    printf("\n");
}
void reset(char str[]){
    //memset(str, 0, sizeof(str));
    int len = strlen(str);
    for(int i=0;i<len;i++){
        str[i]=0;
    }
}
void rev(char str[]){
    int len = strlen(str);
    char temp;
    for(int i=0;i<len/2;i++){
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void add(char str1[],char str2[],char fibo[]){
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    int len,a,b,c,carry;
    rev(str1);
    rev(str2);
    len = (l1>l2) ? l1 : l2;
    
    for(int i=0;i<len;i++){
        carry=0,a=0,b=0,c=0;
        if(str1[i]-'0'!=-48)
            a=str1[i]-'0';
        if(str2[i]-'0'!=-48)
            b=str2[i]-'0';
        if(fibo[i]-'0'!=-48)
            c=fibo[i]-'0';

        carry=(a+b+c)/10;
        fibo[i]=((a+b+c)%10)+'0';
        if(carry!=0)
            fibo[i+1]= carry +'0';
    }
    rev(str1);
    rev(str2);
    rev(fibo);
}
int main()
{
    int n;
    printf("Enter a number:\t");
    scanf("%d",&n);
    char str1[100000]="0",str2[100000]="1",fibo[100000];
    if(n==1)fibo[0]='0';
    if(n==2)fibo[0]='1';
    for(int i=3;i<=n;i++){
        reset(fibo);
        add(str1,str2,fibo);
        reset(str1);
        strcpy(str1, str2);
        reset(str2);
        strcpy(str2,fibo);
    }
    printf("Your Fibonacii Number is : \t");
    printarr(fibo);

    printf("\n\nNumber of digits in your fibonacii is :\t");

    printf("%d\n",strlen(fibo));

    return 0;
}