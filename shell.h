/*
 * shell.h
 *
 * March 3, 2021
 * CS 232, Calvin University
 * Professor Norman
 * Written by Michelle Ferdinands
 */

#ifndef SHELL_H_
#define SHELL_H_
#include "path.h"
#include "prompt.h"
#include "commandline.h"
using namespace std;

class shell {
public:
	shell();
	void run();
	virtual ~shell(){};
public:
	Prompt myPrompt;
};
#endif /*SHELL_H_ */
