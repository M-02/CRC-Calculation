#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//#define CRC_CCITT 69665
//#define CRC_16 98309
//#define CRC_12 6159
#define DEC 2 //���ڿ���������ݵĽ��Ʊ�ʾ��Ĭ�����������
int e;
unsigned btoi(char pt[])  //�˺��������Ѷ������ַ���ת��Ϊʮ��������
{
    int le=0,i;
    unsigned sum=0;
    le=strlen(pt);
    for(i=0;i<le;i++)
    {
        if(pt[i]=='1')
           sum=sum+(unsigned)(pow(2,le-1-i)); //ע�ͣ�һ��
    }
    return sum;
}
///////////////////////////�ֽ���///////////////////////////////////

unsigned CRC_Calc(unsigned *Kx,unsigned Gx)  //�˺������ڼ���ʮ���Ƶ�������
{
    int bi=0;
    char bu[32];
    itoa(Gx,bu,2);
    bi=strlen(bu);
    *Kx=(*Kx)*(unsigned)pow(2,bi-1);//ע�ͣ�����
    return Gx-(*Kx%Gx);
}
int main()
{
    int f=1;  //f��ʾflag�����ھ����Ƿ��������
    unsigned g,k,s,r; //�ֱ���Ϊ��Gx,Kx,Tx,Rx
    char se[32],rx[32],gi[32],ki[32];
    while(f) 
    {
        system("cls"); //��������
        fflush(stdin); //��ջ�����


/* ****************����������*********************** */

        printf("�������������Ϣ�룺\n");
        gets(ki);
        k=btoi(ki);
        printf("����������������룺\n");
        gets(gi);
        g=btoi(gi);
		 printf("\nѡ�������0=����CRC��1=��֤CRC��\n");
        scanf("%d",&e);
		if(e==1){
		if(k%g==0)     ////////////////ע�ͣ�һ��/////////////////////
        {
            printf("\n\t%s��%s������Ϊ0 ��֤�ɹ�!\n",ki,gi);
        }
        else if(k%g!=0)
        {
            printf("\n\t%s��%s��������Ϊ0 ��֤ʧ��!\n",ki,gi);
        }
        printf("\n�Ƿ������1=�ǣ�0=��\n");
        scanf("%d",&f);}
		else{

 // ------------------------------�ֽ���-----------------------------------     //
        r=CRC_Calc(&k,g);
        s=r+k;
        itoa(r,rx,DEC);
        itoa(s,se,DEC);
        printf("������(Gx)��%s\n",gi);
        printf("��Ϣ��(Kx)��%s\n",ki);
        printf("������(Tx)��%s\n",se);
        printf("������(Rx)��%s\n",rx);
        
        printf("\n�Ƿ������1=�ǣ�0=��\n");
        scanf("%d",&f);
    }}
    return 0;
}