// string matching (robin-karp algo)

#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 100
#define PRIME 7

void store_in_arr(int arr[],char intial[],int length)
{
    for(int i = 0 ;i < length;i++)
      {
        arr[i] = intial[i] - '0';
      }
}

int main()
  {
    FILE *fptr1; 
    fptr1 = fopen("pattern", "r"); 
    char pattern[MAX]; 
    fgets(pattern, MAX, fptr1);
    fclose(fptr1);

    int length1 = strlen(pattern);

    int in_pattern[length1];

    store_in_arr(in_pattern,pattern,length1);

    for(int i = 0 ;i < length1;i++)
      {
        printf("%d",in_pattern[i]);
      }
      printf("\n");

    // to check with small pattern

    FILE *fptr2; 
    fptr2 = fopen("smallpat", "r"); 
    char small_pattern[MAX]; 
    fgets(small_pattern, MAX, fptr2);
    fclose(fptr2);


    int length2 = strlen(small_pattern);

    int in_small_pattern[length2];

    store_in_arr(in_small_pattern,small_pattern,length2);

    for(int i = 0 ;i < length2;i++)
      {
        printf("%d",in_small_pattern[i]);
      }

    // Naive solution
    // int i,j;

    // for( i = 0;i < length1-length2 ; i++)
    //   {
    //       for( j = 0;j < length2 ; j++)
    //         {
    //             if(in_pattern[i+j] != in_small_pattern[j])
    //               {
    //                 break;
    //               }
                  
    //         }
    //         if(j == length2)
    //               {
    //                 printf("there is a match at : %d",i);
    //               }
    //   }  

    // converting 1001 to decimal then comparing
    int key = 0,k;
    int rolling_hash = 0;
    for(int i = 0; i < length2; i++)
      {
        key = (key * 2 + in_small_pattern[i]) % PRIME;
        rolling_hash = (rolling_hash * 2 + in_pattern[i]) % PRIME;

      }  

    printf("\n key : %d",key);

    for(int j = 0; j < length1 - length2 ; j++)
      {
          if(key == rolling_hash)
          {
             for( k = 0;k < length2 ; k++)
            {
                if(in_pattern[k+j] != in_small_pattern[k])
                  {
                    break;
                  }
                  
            }
            if(k == length2)
                  {
                    printf("there is a match at : %d",j);
                  }
          }
          rolling_hash = (rolling_hash * 2 + in_pattern[j+length2] - pow(2,length2) * in_pattern[j]) ;
          rolling_hash = rolling_hash % PRIME;
          if(rolling_hash < 0)
          {
              rolling_hash += PRIME;
          }

      }



  }