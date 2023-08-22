#include <iostream>
#include <string>
#include<bits/stdc++.h>

#include <filesystem>
#include<unistd.h>

namespace fs = std::filesystem;
using namespace std;

string lastname(string str) {
	string name;
	stringstream x(str);
	while (getline (x, name, '/'));
	return name;
	}

string rm_dot_ext (string str) {
	string name;
	stringstream x(str);
 	getline (x, name, '.');
 	return name;
	}
int main()
{

chdir("data");
string path = fs::current_path();
cout << "Current path is " << fs::current_path() << '\n';

const auto &entry = fs::directory_iterator(path);	
	
//string str = entry.path(); // "string1/string2/string3.dt"; 
cout << entry.path() << endl;
//cout << lastname (str) << endl;
//cout << rm_dot_ext (lastname (str)) << endl;
 
}
