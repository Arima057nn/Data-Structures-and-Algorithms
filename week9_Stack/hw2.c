#include <string.h>
typedef char element;
#include "ListStack.h"

int precedence(char x){
  if(x == '(')
    return 0;
  if(x == '+' || x == '-')
    return 1;
  if(x == '*' || x == '/' || x == '%')
    return 2;
  else return 3;
}
void enterExpression(char express[]){
  printf("Nhap: ");
  scanf("%s%*c",express);
}

void InfixPostfix(char infix[], char postfix[]){
  int i = 0, j = 0;
  char x;
  node *stack;
  initialize(&stack);
  for(i = 0; i< strlen(infix);i++){   
    if(infix[i] >= '0' && infix[i] <= '9'){
      postfix[j] = infix[i];
      j++;
    }
    else if(infix[i] == '('){
      Push(infix[i], &stack);
    }
    else if(infix[i] == ')'){
      while( (x =  Pop(&stack)) != '(' ){
	postfix[j] = x;
	j++;
      }
    }
    else{
      while( !isEmpty(stack) && precedence(infix[i]) <= precedence(Peek(stack)) ){	
	postfix[j] = Pop(&stack);
	j++;
      }
      Push(infix[i],&stack);      
    }
  }
  
  while( !isEmpty(stack)){
    postfix[j++] = Pop(&stack);

  }
  //postfix[j++] = '\0';
}

void calcelate(char postfix[]){
  node *stack;
  int i;
  initialize(&stack);
  int x1,x2,x;
  for(i = 0; postfix[i] != '\0';i++){
    if(postfix[i] >= '0' && postfix[i] <= '9'){
      Push(postfix[i] - '0',&stack);
    }else{
      x1 = Pop(&stack);
      x2 = Pop(&stack);
      if(postfix[i] == '+') x = x1 + x2;
      if(postfix[i] == '-') x = x2 - x1;
      if(postfix[i] == '*') x = x1 * x2;
      if(postfix[i] == '/') x = x2 / x1;
      if(postfix[i] == '%') x = x2 % x1;
      Push(x,&stack);
    }
  }
  printf("\n%d",Pop(&stack));
}
int main(){
  char infix[100], postfix[100];
  int choose,i = 0;

  printf("==================MENU=================\n");
  printf("1.Enter arithmetic expressions in infix notation\n");
  printf("2.Change to postfix\n");
  printf("3.Calculating value\n");
  printf("4.Exit\n");
  do{
    printf("\n-->Choose: ");
    scanf("%d",&choose);
    if(choose !=2 && choose !=3){
      i=1;
    }
    if((choose ==2 || choose ==3) && i == 0 ){
      do{
	printf("Chon 1 de nhap bieu thuc so hoc truoc: ");
	scanf("%d",&choose);
      }while(choose ==2 || choose ==3);
    }
    switch (choose){
    case 1:
      enterExpression(infix);
      break;
    case 2:
      InfixPostfix(infix , postfix);
      printf("%s",postfix);
      break;
    case 3:
      calcelate(postfix);
      break;
      
    case 4: 
        printf("Exit !");
	break;
    default:
      printf("Khong co chuc nang nay");
      break;
    }
  }while(choose != 4);  
  
  
  
  return 0;
}
