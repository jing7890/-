#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE 0 
int N;//���ݸ���
 int K;//���ϸ���
 int *CenterIndex;//��ʼ��������������� 
 double *Center;//���ļ���
 double * CenterCopy;//���ļ��ϸ���
 double * AllData;//���ݼ��� 
 double ** Cluster;//�صļ���
 int*Top;//������Ԫ�صĸ�����Ҳ������ջ����

//������� k����x(0<=x<=n-1)��Ϊ��ʼ�����ļ���
 void CreateRandomArray(int n, int k,int * center)
 {
 int i=0;
 int j=0;
srand((unsigned)time( NULL));
 for( i=0;i<k;++i)//�������K����
{
int a=rand()%n;//����
for(j=0;j<i;j++)
int a=rand()%n;
if(center[j]==a)//�ظ�{
break;
}
if(j>=i)//������ظ�������
{
center[i]=a;
}
else
{ 
     i--;
//����ظ������������������
          }
    }
}
//���ؾ�����С�����ĵ����
int GetIndex(double value,double *center)
{
int i=0;
int index=i;//��С���������
double min=fabs(value-center[i]);//��������С���� for(i=0;i<K;i++){
if(fabs(value-center()<min)//����ȵ�ǰ���뻹С��������С��������ź;���ֵ
{
index=i;
min=fabs(value-center[i]);
}
return index;}
//�����������鵽���� void CopyCenter()
void CopyCenter(){
inti=0;
for(i=0;i<K;i++)
Centercopy1-center:docin.com
}
//��ʼ�����ģ�������ɷ� void InitCenter(){
inti=0;
CreateRandomArray(N,K,CenterIndex);//���������K��<N�Ĳ�ͬ������ for(i=0;i<K;i++){
Center[i]=AllData[CenterIndex[1]];//����Ӧ���ݸ�ֵ����������
CopyCenter();//���������ĸ���
}
//����һ�����ݵ�һ�� Cluster[index]����
{
void AddToCluster(int index,double value)
Cluster[index][Top[index]++]=value;//����ͬ��ջ����
}
