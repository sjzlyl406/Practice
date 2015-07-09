/*************************************************************************
	> File Name: test71.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月09日 星期四 08时59分54秒
 ************************************************************************/

/**************************************************************
 * A Program to transform words;
 * Takes two arguments: The first is name of the word transformation file
 *						The seconds is name of the input to transform
 * ************************************************************/
#include<iostream>
#include<map>
#include<string>
#include<stdexcept>
#include<fstream>
#include<sstream>

using namespace std;
// opens in binding it to the given file
ifstream& open_file(ifstream &in, const string &file)
{
	in.close();     // close in case it was already open
	in.clear();     // clear any existing errors
    // if the open fails, the stream will be in an invalid state
	in.open(file.c_str()); // open the file we were given
	 return in; // condition state is good if open succeeded
}

int main(int argc,char*argv[])
{
	// map to hold the word transformation pairs;
	// key is the word to look for in the input; 
	// value is the word to use in the output;
	map<string, string> trans_map;
	string key, value;
	if(argc != 3)
		throw runtime_error("wrong number of argrments");
	//open transformation file and check that open succeeded
	ifstream map_file;
	if(!open_file(map_file, argv[1]))
		throw runtime_error("no transformation file");
	while(map_file >> key >> value)
		trans_map.insert(make_pair(key, value));

	ifstream input;
	if (!open_file(input, argv[2]))
		throw runtime_error("no input file");
	string line;

	while (getline(input, line)) {
		istringstream stream(line);
		string word;
		bool firstword = true;
		while(stream >> word) {
			map<string, string>::const_iterator  map_it =
				trans_map.find(word);

			if(map_it != trans_map.end())
				word = map_it -> second;
			if(firstword)
				firstword = false;
			else
				cout << " ";
			cout << word;
		}
		cout << endl;
	}
	return 0;
	
}
