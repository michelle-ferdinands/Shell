/* shell.cpp
 *
 * March 3, 20201
 * Michelle Ferdinands
 * Professor Norman
 * CS 232 at Calvin University
 */
#include "shell.h"
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <cerrno>
using namespace std;

shell::shell(){
	myPrompt = Prompt();
}
void shell::run() {
	while(true) {
		cout << myPrompt.get() << flush;
		CommandLine command_line(cin);
		string command = command_line.getCommand();
		if(command == "exit") {
		       break;
		}
 		else if (command == "cd") {
			int change = chdir(command_line.getArgVector(1));
			chdir(command_line.getArgVector(1));
			if (change == -1) {
				cerr << "cannot change directory"  << endl;
			}
			myPrompt.set();
		
		}
		else if (command == "pwd") {
			// source - stackoverflow.com/questions/3485166/change-the-current-working-directory-in-c
			char buff[FILENAME_MAX];
			char *path = getcwd(buff, FILENAME_MAX);
			string current_path = string(path);
			cout << current_path << endl;
		}
		else {
			Path myPath;
			if (myPath.find(command) == -1) {
				cout << command << "command not found" << endl;
			}
			else {
				//create for execution command
				pid_t pid = fork();
				if(pid == -1) {
					cout << "fork error" << endl;
				}
				else if(pid == 0) {
					//execution of system program
				string filename = myPath.getDirectory(myPath.find(command))	+ "/" + command;
				int error = execve(filename.c_str(), command_line.getArgVector(), NULL);
			
				if(error == -1) {
					cout << "can't execute command: " << endl;
				}
				
			}
				else if (command_line.noAmpersand()) {
					waitpid(pid, NULL,0);
			}
		}
	}
}
}
