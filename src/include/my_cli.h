#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of commands
#define MAX_COMMANDS 10
#define MAX_BUFFER_SIZE 50
#define MAX_USERNAME_SIZE 20
#define MAX_PASSWORD_SIZE 20

#define TRUE       1
#define FALSE      0

// Define function prototype for command functions which will be provided by application
typedef void (*CommandFunction)(char* []);

// Define a structure for command registration
typedef struct {
    const char* command;     // name of the command
    CommandFunction function; // function pointer for the particular command
    const char* helpText;  // Help text for the command
    int expectedParams;  // Expected number of parameters for the command
} CommandLineInterface;

// Global array to store commands
CommandLineInterface CommandInterfaceArray[MAX_COMMANDS];



// function prototypes
extern void login();
extern void helpCommand(char* argument[]);
extern void processCommand(const char* inputCommand,char* arguments[]);
extern void displayHelp();
extern void registerCommand(const CommandLineInterface * const inputcommands);


