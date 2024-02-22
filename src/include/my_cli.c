#include"my_app.h"
#include"my_cli.h"

// User credentials
const char* validUsername = "Priyanka";
const char* validPassword = "password";


// global flag to indicate if user is loggedin or not
int isLoggedIn = 0;

// global flag to keep track of command count
int commandCount = 0;


// Function to register a new command and its corresponding function
void registerCommand(const CommandLineInterface * const inputcommands) {
    
    // Only register specified commands
    if (commandCount < MAX_COMMANDS) {
        CommandInterfaceArray[commandCount] = *inputcommands;
        commandCount++;
    } else {
        fprintf(stderr, "Maximum number of commands reached\n");
    }
}

// Function to display help information for all registered commands
void displayHelp() {
    printf("Available commands:\n");
    int cmd_index;
    for ( cmd_index = 0; cmd_index < commandCount; ++cmd_index) {
        if (CommandInterfaceArray[cmd_index].command != NULL) {
            printf("%s: %s\n", CommandInterfaceArray[cmd_index].command, CommandInterfaceArray[cmd_index].helpText);
        }
    }
}

// Function to process and execute the command
void processCommand(const char* inputCommand,char* arguments[]) {
	int cmd_index;
    for (cmd_index = 0; cmd_index < commandCount; ++cmd_index) {
        if (strcmp(inputCommand, CommandInterfaceArray[cmd_index].command) == 0) {
            // Check if the correct number of parameters is provided
            int expectedParams =  CommandInterfaceArray[cmd_index].expectedParams;
            int providedParams = 0;
            
			// calculate the provided num of parameters by user 
            while (arguments[providedParams] != NULL) {
                providedParams++;
            }
            
            // function pointer should be called only if the number of parameters matches the expected one or it is s help cmd
            if ((expectedParams == -1) || (expectedParams == providedParams)) {
                // Call the corresponding function using function pointer
                CommandInterfaceArray[cmd_index].function(arguments);
                return;
            }
            else {
                printf("Error: Incorrect number of parameters for '%s' command\n", inputCommand);
                return;
            }
        }
    }

    printf("Error: Unknown command: %s\n", inputCommand);
    displayHelp();
}

// Command function for "help" command
void helpCommand(char* argument[]) {
    if (argument[0] != NULL) {
    	int index;
        // Display help for a specific command
        for (index = 0; index < MAX_COMMANDS; ++index) {
            if (CommandInterfaceArray[index].command != NULL && strcmp(argument[0], CommandInterfaceArray[index].command) == 0) {
                printf("Help for command '%s': %s\n", argument[0], CommandInterfaceArray[index].helpText);
                return;
            }
        }
        printf("Error: Unknown command: %s\n", argument[0]);
    }   
    else {
        // Display general help for all commands
        displayHelp();
    }
}

// Function to handle user login
void login() {
    char username[MAX_USERNAME_SIZE];
    char password[MAX_PASSWORD_SIZE];

    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);

    // Remove newline character
    size_t len = strlen(username);
    if (len > 0 && username[len - 1] == '\n') {
        username[len - 1] = '\0';
    }

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    // Remove newline character
    len = strlen(password);
    if (len > 0 && password[len - 1] == '\n') {
        password[len - 1] = '\0';
    }

    // Perform basic login validation
    if (strcmp(username, validUsername) == 0 && strcmp(password, validPassword) == 0) {
        printf("Login successful. Welcome, %s!\n", validUsername);
        isLoggedIn = TRUE;
    } else {
        printf("Invalid login credentials. Please try again.\n");
        isLoggedIn = FALSE;
    }
}
