/*
 * path.cpp
 * Michelle Ferdinands
 * CS 232
 * March 3, 2021
 */
#include "path.h"
#include <sstream>


/*constructor
 *@param - none
 *postcondition - path constructed from environment variable
 *source - www.csplusplus.com/reference/stdlib/getenv
 */
Path::Path() {;
	string pPath = getenv("PATH");
	stringstream stream (pPath);
	string divider;
	while(getline(stream, divider, ':')) {
		directory.push_back(divider);
	}
}

/* path finder
 * @param string of program
 * return index of program
 * www.stackoverflow.com/questions/6252060/check-folder-path
 */

int Path::find(const string &program) const {
	DIR *dir;
	struct dirent *entry;
	for(unsigned i = 0; i < directory.size(); i++) {
		if((dir = opendir(directory[i].c_str())) != NULL) {
			while((entry = readdir(dir)) != NULL) {
			       if(entry->d_name == program) {
			 		return i;
			       }
			}		       

	}
		closedir(dir);
	}
	return -1;
}
/* find directory
 * @param - an int
 * returns a string
 */
string Path::getDirectory(int i) const {
	return directory[i];
}
