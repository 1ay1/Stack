#include <stdio.h>
#define type int
#define MAX 5

struct que
{
  int size;
  type queue[MAX];
  int front;
  int rare;
};

int main()
{
  struct que q1;
  q1.front= 0;
  q1.rare = 0;
  q1.size = 0;
  int a;
  int b;
  printf("A queue is running here!\n");
  while(1)
    {
      printf("You wanna Add(1) or Delete(2)?\n");
      scanf("%d", &a);
      if(a == 1)
	{
	  if(q1.size >= MAX)
	    {
	      printf("The queue is full actually!\n");
	      continue;
	    }
	  printf("Enter the value to add: ");
	  scanf("%d", &b);
	  q1.queue[q1.rare] = b;
	  if(q1.rare== MAX-1) q1.rare = 0;
	  
	  else q1.rare++;
	  q1.size++;
	  printf("Your value is added to the que! :)\n");
	}
      if(a == 2)
	{
	  if(q1.size <= 0)
	    {
	      printf("The queue is empty really!\n");
	      continue;
	    }
	  printf("deletion happening :)\n");
	  printf("deletion DONE\n");
	  if(q1.front==MAX-1) q1.front =0;
	  else q1.front++;
	  q1.size--;
	}
    }
  return 0;
}
		 
