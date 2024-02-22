#include<stdio.h>

#define MAXSETGETPARAM        5

// define a structure that can hold the data of particular parameter of set/get cmds
typedef struct {
	char  parameters[10];
	int value;
}ParameterValues;

// Global array to hold hold the data of particular parameter of set/get cmds
ParameterValues ValueArray[MAXSETGETPARAM];

// function prototype
extern void setCommand(char* arguments[]);
extern void getCommand(char* arguments[]);
