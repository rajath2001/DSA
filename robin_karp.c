// string matching (robin-karp algo)
// requires two text file pattern and smallpat

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 100
#define PRIME 7

struct Node{
    char array[4];
    struct Node* next;
};

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

    // FILE *fptr2; 
    // fptr2 = fopen("smallpat", "r"); 
    // char small_pattern[MAX]; 
    // fgets(small_pattern, MAX, fptr2);
    // fclose(fptr2);


    // int length2 = strlen(small_pattern);

    // int in_small_pattern[length2];

    // store_in_arr(in_small_pattern,small_pattern,length2);

    // for(int i = 0 ;i < length2;i++)
    //   {
    //     printf("%d",in_small_pattern[i]);
    //   }

    // hash table
    char small[][4] = {{'1','0','0','1'},
                        {'1','0','0','1'},
                        {'1','0','0','1'}};
    int length2 = 4,hash_key = 0;
    struct Node** arr = (struct Node**)malloc(PRIME*sizeof(struct Node**));
    // for(int i = 0 ;i < PRIME;i++)
    // {
    //     **arr = NULL;
    // }
    int m;
    for( m = 0; m <sizeof(small)/sizeof(small[0]);m++)
    {
        hash_key = 0;
        for(int i = 0; i < length2; i++)
         {
           hash_key = (hash_key * 2 +(small[m][i] - '0')) % PRIME;
         }
            //printf(" %d ",hash_key);
         
         struct Node *new = (struct Node*)malloc(sizeof(struct Node*));
         for(int n = 0;n < length2 ; n++)
           {
               new -> array[n] = small[m][n];
               printf(" %s ",new -> array );

           }
         
            if(arr[hash_key] == NULL)
            {
                new-> next = NULL;
                arr[hash_key] = new;
                //printf("%p \n",arr[hash_key]);

            }
            else{
                new->next = arr[hash_key];
                arr[hash_key] = new;
               // printf("%p \n",arr[hash_key]);

            }
    
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
        
        rolling_hash = (rolling_hash * 2 + in_pattern[i]) % PRIME;

      }  

     //printf("\n key : %d",rolling_hash);
int u = 0;
    for(int j = 0; j < length1 - length2 ; j++)
      {
          if(arr[rolling_hash] != NULL)
          {
            //printf("\n key : %d",rolling_hash);
            
             struct Node *counter =  arr[rolling_hash];
             while(counter != NULL)
             {
                  
                  for( u = 0;u < length2 ; u++)
              {
                   printf("\n  %c %d",counter->array[u],u);

                if(in_pattern[u+j] != counter->array[u])
                  {
                    break;
                  }
                  
             }
             if(u == length2)
                  {
                    printf("there is a match at : %d",j);
                  }
                  counter = counter->next;

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