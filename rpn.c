#include "rpn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int operate(int first,int second,char operator){
	switch(operator){
					case '+': return (second + first); 	
					case '-': return (second - first);
					case '*': return (second * first);
					case '/': return(first)?(second / first):0;
					default:  return 0;
				}
};



Result evaluate(char* expression){
	Result getResult;
	int i = 0,result,count,data,j=-1,last,operand=0 ,operator=0,status;
	int* first,*second,length = strlen(expression);
	char str[256];
	Stack stack = createStack();
	strcpy(str,expression);

	while(i<length){
		if(str[i]>='0' && str[i] <='9'){
			(str[i+1]!=' ' && j == -1)?(j = i) : j;
			if(str[i+1]==' '){ 
				operand++;
				data = (j<0)? atoi(&str[i]) : atoi(&str[j]);
				push(stack,(void*)data);
				j =-1;
			}
		}
		if(str[i]=='-' || str[i] =='*' || str[i] =='/' || str[i] =='+'){
			operator++;
			first = pop(stack);
			second = pop(stack);
			result = operate((int)first, (int)second, str[i]);
			push(stack,(void*)result);
		}
		i++;
	}
	if(operand != operator+1){
		Result getResult = {0,0};
		return getResult;
	}
	getResult.error = 1;
	getResult.status = (int)(*stack.top)->data;
	return getResult;
};




















// if(str[i]=='=' && str[i+1]=='='){
// 			first = pop(stack);
// 			last = atoi(&str[i+2]);
// 			getResult.status = ((int)first==last)?1:0;
// 			return getResult;
// 		}