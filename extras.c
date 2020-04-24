#include <stdio.h>
#include <string.h>
#include "extras.h"

// Function: defragment()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: 1 if successful, otherwise 0
// - Leave a brief information about the function
int defragment(Record a[], int n, int *c){
	// TODO: Modify this function as you need
  if((*c)==0)
    return 0;

  for(int i=n; i<(*c)-1; i++){
    strncpy(a[i].name, a[i+1].name, strlen(a[i+1].name));
    strncpy(a[i].p_num, a[i+1].p_num, strlen(a[i+1].p_num));
    strncpy(a[i].bd, a[i+1].bd, strlen(a[i+1].bd));
    strncpy(a[i].id, a[i+1].id, strlen(a[i+1].id));
    strncpy(a[i].pw, a[i+1].pw, strlen(a[i+1].pw));
    strncpy(a[i].book, a[i+1].book, strlen(a[i+1].book));

    a[i+1].name[strlen(a[i+2].name)]='\0';
    a[i+1].p_num[strlen(a[i+2].p_num)]='\0';
    a[i+1].bd[strlen(a[i+2].bd)]='\0';
    a[i+1].id[strlen(a[i+2].id)]='\0';
    a[i+1].pw[strlen(a[i+2].pw)]='\0';
    a[i+1].book[strlen(a[i+2].book)]='\0';
  }
   (*c)--;
    return 1;

}// TODO: return 1 if defragment succeed; return 0 otherwise 


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - 이름순으로 sorting
void sorting_data(Record a[], int c){
	// TODO: Modify this function as you need
  int n=0;
  char save[MAX];
  int swap;
	for(int i=0; i<c; i++){
    for(int j=i+1; j<c; j++){
      n=strcmp(a[i].name, a[j].name);
      if(n>0){
        //swap name
      save[strlen(a[i].name)]='\0';
      strncpy(save, a[i].name ,strlen(a[i].name));
      a[i].name[strlen(a[j].name)]='\0';
      strncpy(a[i].name, a[j].name, strlen(a[j].name));
      a[j].name[strlen(save)]='\0';
      strncpy(a[j].name, save, strlen(save));
      //swap p_num
      save[strlen(a[i].p_num)]='\0';
      strncpy(save, a[i].p_num ,strlen(a[i].p_num));
      a[i].p_num[strlen(a[j].p_num)]='\0';
      strncpy(a[i].p_num, a[j].p_num, strlen(a[j].p_num));
      a[j].p_num[strlen(save)]='\0';
      strncpy(a[j].p_num, save, strlen(save));

      //swap bd
      save[strlen(a[i].bd)]='\0';
      strncpy(save, a[i].bd ,strlen(a[i].bd));
      a[i].bd[strlen(a[j].bd)]='\0';
      strncpy(a[i].bd, a[j].bd, strlen(a[j].bd));
      a[j].bd[strlen(save)]='\0';
      strncpy(a[j].bd, save, strlen(save));

      //swap id
      save[strlen(a[i].id)]='\0';
      strncpy(save, a[i].id ,strlen(a[i].id));
      a[i].id[strlen(a[j].id)]='\0';
      strncpy(a[i].id, a[j].id, strlen(a[j].id));
      a[j].id[strlen(save)]='\0';
      strncpy(a[j].id, save, strlen(save));

      //swap pw
      save[strlen(a[i].pw)]='\0';
      strncpy(save, a[i].pw ,strlen(a[i].pw));
      a[i].pw[strlen(a[j].pw)]='\0';
      strncpy(a[i].pw, a[j].pw, strlen(a[j].pw));
      a[j].pw[strlen(save)]='\0';
      strncpy(a[j].pw, save, strlen(save));

      //swap book
      save[strlen(a[i].book)]='\0';
      strncpy(save, a[i].book ,strlen(a[i].book));
      a[i].book[strlen(a[j].book)]='\0';
      strncpy(a[i].book, a[j].book, strlen(a[j].book));
      a[j].book[strlen(save)]='\0';
      strncpy(a[j].book, save, strlen(save));    
      }

    }
  }
}


// TODO: Add more functions to fulfill the optional requirements

void the_most_like_genre(Record a[], int c){
  int check[SIZE];
  for(int i=0; i<c; i++){
    if((a[i].book[0])=='N')
    check[0] +=1;
    else if((a[i].book[0])=='M')
    check[1] +=1;
    else if((a[i].book[0])=='S')
    check[2] +=1;
    else if((a[i].book[0])=='C')
    check[3] +=1;
    else if((a[i].book[0])=='B')
    check[4] +=1;
    else if((a[i].book[0])=='F')
    check[5] +=1;
  }
  int save=0;
  int count=0;
  for(int i=0; i<6; i++){
    if((check[i])>save){
      save=check[i];
    }
  }
  printf("The most popular genre is ");

      for(int i=0; i<6; i++){
         
        if(i==0){
          if(save==check[0])
          printf("NOVEL");
          else if(save==check[1]){
          printf("MISTERY");
          i=1;
          continue;
          }
          else if(save==check[2]){
          printf("SPORT");
          i=2;
          continue;
          }
          else if(save==check[3]){
          printf("CARTOON");  
          i=3;
          continue;
          }
          else if(save==check[4]){
          printf("BEAUTY");
          i=4;
          continue;
          }
          else if(save==check[5]){
          printf("FATRION");  
          i=5;
          continue;
          }
        }
        if(i==1) {
        if(save==check[1]){
          printf(", MISTERY");
          continue;
          }
          else if(save==check[2]){
          printf(", SPORT");
          i=2;
          continue;
          }
          else if(save==check[3]){
          printf(", CARTOON");  
          i=3;
          continue;
          }
          else if(save==check[4]){
          printf(", BEAUTY");
          i=4;
          continue;
          }
          else if(save==check[5]){
          printf(", FATRION");  
          i=5;
          continue;
          }
        }
        if(i==2) {
          if(save==check[2]){
          printf(", SPORT");
          continue;
          }
          else if(save==check[3]){
          printf(", CARTOON");  
          i=3;
          continue;
          }
          else if(save==check[4]){
          printf(", BEAUTY");
          i=4;
          continue;
          }
          else if(save==check[5]){
          printf(", FATRION");  
          i=5;
          continue;
          }
        }
          if(i==3) {
          if(save==check[3]){
          printf(", CARTOON");  
          continue;
          }
          else if(save==check[4]){
          printf(", BEAUTY");
          i=4;
          continue;
          }
          else if(save==check[5]){
          printf(", FATRION");  
          i=5;
          continue;
          }
        }
        if(i==4) {
          if(save==check[4]){
          printf(", BEAUTY");
          continue;
          }
          else if(save==check[5]){
          printf(", FATRION");  
          i=5;
          continue;
          }
        }
         if(i==5) {
          if(save==check[5]){
          printf(", FATRION");  
          }
        }    
      } 
      printf("\n");
    }
