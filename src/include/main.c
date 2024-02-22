#include<stdio.h>
#include"my_cli.h"
#include"my_app.h"

extern int isLoggedIn;

// command structure initialization for registration
const CommandLineInterface help_command = {"help", helpCommand, "Display help information for all commands", -1};
const CommandLineInterface set_command  = {"set", setCommand, "Set a value", 2};
const CommandLineInterface get_command  = {"get", getCommand, "Get a value", 1};

int main() 
{
    // Registering specified commands
    registerCommand(&help_command);
    registerCommand(&set_command);
    registerCommand(&get_command);

    // Command-line input processing
    char UserinputBuffer[MAX_BUFFER_SIZE];
    char* arguments[10];
    int argIndex;

    while (1) 
	{    
        if(isLoggedIn != FALSE)
        {
            printf("\nEnter command: ");
            if (fgets(UserinputBuffer, sizeof(UserinputBuffer), stdin) == NULL) {
                break; // Exit on EOF
            }

            argIndex = 0;
            // Remove newline character
            size_t len = strlen(UserinputBuffer);
            if (len > 0 && UserinputBuffer[len - 1] == '\n') {
                UserinputBuffer[len - 1] = '\0';
            }

            // Split command and argument
            char* command = strtok(UserinputBuffer, " ");
            
            // add the parameters in the arguments array
            while ((arguments[argIndex] = strtok(NULL, " ")) != NULL) {
                argIndex++;    
            }
        
            // if command is not NULL then process the command
            if (command != NULL) {
               processCommand(command, arguments);
            } 
            else {
                printf("Error: Empty command\n");
            }
        }
        else
        {
            login();
        }     
    }
    
    return 0;
}
