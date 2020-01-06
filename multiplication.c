#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}

int main()
{
    int length1=3,length2=2;
    int num1[10];
    int num2[10];
          


    for(int i = length1-1;i >=0 ;i--)
      {
         
          scanf("%d",&num1[i]);
      }
          

    for(int i = length2-1;i >=0 ;i--)
      {
          scanf("%d",&num2[i]);
      }

      int ans[length1+length2+1] ;
       memset(ans, 0, (length1+length2+1)*sizeof(ans[0])); 
      int carry,j,k;
          


      for( j = 0;j<length1;j++)
      {
         
          carry = 0;
          for( k = 0;k<length2;k++)
          {
              int temp = ans[k+j];
            ans[k+j] = (ans[k+j]+num1[j] * num2[k] + carry) % 10;
            carry    = (temp + num1[j] * num2[k] + carry) / 10;
          }
          ans[k+j] = carry;
      }

      for(int l = length1+length2;l >=0;l--)
      {printf("%d",ans[l]);}                                                         
           
}





