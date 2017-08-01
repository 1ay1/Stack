#include <stdio.h>
#include <stdlib.h>
#define MaxDegree 10

typedef struct
{
  int CoeffArray[ MaxDegree +1 ];
  int HighPower;
} *Polynomial; //Polynomial is POINTER to the structure we will make

void SetZero( Polynomial Poly)
{
  for(int i = 0; i <= MaxDegree; i++) {
    Poly->CoeffArray[i] = 0;
  }
  Poly->HighPower =0;
}

int Max(const Polynomial Poly1, const Polynomial Poly2)
{
  int max;
  if(Poly1->HighPower > Poly2->HighPower)
    max = Poly1->HighPower;
  else
    max = Poly2->HighPower;
  return max;
}

void AddPoly( const Polynomial Poly1, const Polynomial Poly2, Polynomial SumPoly)
{
  SetZero(SumPoly);

  SumPoly->HighPower =  Max(Poly1, Poly2);

  for(int i = SumPoly->HighPower; i >= 0; i--)
    {
      SumPoly->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
    }
}

void MulPoly( Polynomial Poly1,  Polynomial Poly2, Polynomial ProPoly)
{
  SetZero(ProPoly);
  ProPoly->HighPower = Poly1->HighPower + Poly2->HighPower;

  if(ProPoly->HighPower > MaxDegree) {
    puts("This operation is going to overflow the DS!");
    exit(1);
  }

  for(int i = 0; i <= MaxDegree; i++) {
    for(int j = 0; j <=MaxDegree; j++) {
      ProPoly->CoeffArray[i+j] += ProPoly->CoeffArray[i] * ProPoly->CoeffArray[j];
    }
  }
}
  

int main()
{
  Polynomial any = malloc(sizeof(Polynomial));
  Polynomial any2 = malloc(sizeof(Polynomial));
  Polynomial Mul = malloc(sizeof(Polynomial));
  for(int i = 0; i <=MaxDegree; i ++) {
    any->CoeffArray[i] = i;
    any2->CoeffArray[i] = i;
  }
  any->HighPower= 10;
  any2->HighPower = 10;
  MulPoly(any, any2,Mul );
  return 0;
}
