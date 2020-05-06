#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//#define CRC_CCITT 69665
//#define CRC_16 98309
//#define CRC_12 6159
#define DEC 2 //用于控制输出数据的进制表示，默认输出二进制
int e;
unsigned btoi(char pt[])  //此函数用来把二进制字符串转化为十进制整数
{
    int le=0,i;
    unsigned sum=0;
    le=strlen(pt);
    for(i=0;i<le;i++)
    {
        if(pt[i]=='1')
           sum=sum+(unsigned)(pow(2,le-1-i)); 
    }
    return sum;
}
///////////////////////////分界线///////////////////////////////////

unsigned CRC_Calc(unsigned *Kx,unsigned Gx)  //此函数用于计算十进制的冗余码
{
    int bi=0;
    char bu[32];
    itoa(Gx,bu,2);
    bi=strlen(bu);
    *Kx=(*Kx)*(unsigned)pow(2,bi-1);
    return Gx-(*Kx%Gx);
}
int main()
{
    int f=1;  //f表示flag，用于决定是否继续测试
    unsigned g,k,s,r; //分别意为：Gx,Kx,Tx,Rx
    char se[32],rx[32],gi[32],ki[32];
    while(f) 
    {
        system("cls"); //清屏函数
        fflush(stdin); //清空缓冲区


/* ****************二进制输入*********************** */

        printf("请输入二进制信息码：\n");
        gets(ki);
        k=btoi(ki);
        printf("请输入二进制生成码：\n");
        gets(gi);
        g=btoi(gi);
		 printf("\n选择操作（0=计算CRC，1=验证CRC）\n");
        scanf("%d",&e);
		if(e==1){
		if(k%g==0)     ////////////////注释（一）/////////////////////
        {
            printf("\n\t%s和%s的余数为0 验证成功!\n",ki,gi);
        }
        else if(k%g!=0)
        {
            printf("\n\t%s和%s的余数不为0 验证失败!\n",ki,gi);
        }
        printf("\n是否继续（1=是，0=否）\n");
        scanf("%d",&f);}
		else{

 // ------------------------------分界线-----------------------------------     //
        r=CRC_Calc(&k,g);
        s=r+k;
        itoa(r,rx,DEC);
        itoa(s,se,DEC);
        printf("生成码(Gx)：%s\n",gi);
        printf("信息码(Kx)：%s\n",ki);
        printf("发送码(Tx)：%s\n",se);
        printf("冗余码(Rx)：%s\n",rx);
        
        printf("\n是否继续（1=是，0=否）\n");
        scanf("%d",&f);
    }}
    return 0;
}
