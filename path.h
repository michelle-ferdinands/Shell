 Path.h
 *
 * Michelle Ferdinands
 * Professor Norman
 * CS232
 * March 3, 2021
 *
 */

#ifndef PATH_H_
#define PATH_H_

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
using namespace std;

class Path {
public:
	Path();
	int find(const string& program) const;
	string getDirectory(int i) const;
private:
	vector<string> directory;
};

#endif /*PATH_H */
