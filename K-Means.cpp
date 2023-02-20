#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE 0 
int N;//数据个数
 int K;//集合个数
 int *CenterIndex;//初始化质心数组的索引 
 double *Center;//质心集合
 double * CenterCopy;//质心集合副本
 double * AllData;//数据集合 
 double ** Cluster;//簇的集合
 int*Top;//集合中元素的个数，也会用作栈处理

//随机生成 k个数x(0<=x<=n-1)作为起始的质心集合
 void CreateRandomArray(int n, int k,int * center)
 {
 int i=0;
 int j=0;
srand((unsigned)time( NULL));
 for( i=0;i<k;++i)//随机生成K个数
{
int a=rand()%n;//判重
for(j=0;j<i;j++)
int a=rand()%n;
if(center[j]==a)//重复{
break;
}
if(j>=i)//如果不重复，加入
{
center[i]=a;
}
else
{ 
     i--;
//如果重复，本次重新随机生成
          }
    }
}
//返回距离最小的质心的序号
int GetIndex(double value,double *center)
{
int i=0;
int index=i;//最小的质心序号
double min=fabs(value-center[i]);//距质心最小距离 for(i=0;i<K;i++){
if(fabs(value-center()<min)//如果比当前距离还小，更新最小的质心序号和距离值
{
index=i;
min=fabs(value-center[i]);
}
return index;}
//拷贝质心数组到副本 void CopyCenter()
void CopyCenter(){
inti=0;
for(i=0;i<K;i++)
Centercopy1-center:docin.com
}
//初始化质心，随机生成法 void InitCenter(){
inti=0;
CreateRandomArray(N,K,CenterIndex);//产生随机的K个<N的不同的序列 for(i=0;i<K;i++){
Center[i]=AllData[CenterIndex[1]];//将对应数据赋值给质心数组
CopyCenter();//拷贝到质心副本
}
//加入一个数据到一个 Cluster[index]集合
{
void AddToCluster(int index,double value)
Cluster[index][Top[index]++]=value;//这里同进栈操作
}
