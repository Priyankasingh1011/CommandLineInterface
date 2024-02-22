// Command function for "set" command
#include <stdlib.h>
#include <string.h>
#include "my_app.h"

// Variable to store the current set get parameter count
static int CurrSetparam = 0;

// command function for "set" command
void setCommand(char* arguments[]) {
	// check if the maximum limit of set get param has exceeded
	if(CurrSetparam < MAXSETGETPARAM)
	{
		strcpy(ValueArray[CurrSetparam].parameters, arguments[0]);
		ValueArray[CurrSetparam].value = atoi(arguments[1]);
		printf("Setting value of %s to: %d\n", ValueArray[CurrSetparam].parameters, ValueArray[CurrSetparam].value);
		CurrSetparam++;	    
	}
	else
	{
		printf("Maximum num of set parameters has exceeded\n");
	}
}

// Command function for "get" command
void getCommand(char* arguments[]) {
	int index;
	for(index = 0; index< CurrSetparam;index++)
	{
		if(strcmp(arguments[0], ValueArray[index].parameters) == 0)
		{
			break;
		}
	}
    printf("The value of: %s is %d\n", ValueArray[index].parameters, ValueArray[index].value);
}
