#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include<bits/stdc++.h>

#include<unistd.h> // may use // chdir()
//#include<direct.h> // may use
namespace fs = std::filesystem;

std::vector<std::string> read_file (std::string file_name);
void write_file (std::string file_name,
				 std::vector<std::string> table, int from, int to);
std::string lastname(std::string str);
std::string rm_dot_ext (std::string str);

//****************************************************************//
int main()
{

	chdir("data");
	std::string path = fs::current_path();
	std::cout << "Current path is " << fs::current_path() << '\n';
	
	for (const auto & entry : fs::directory_iterator(path))
		{//std::cout << entry.path() << std::endl;
			
		std::string name;
		name = lastname (entry.path());	
		std::cout << "name.fr:" << name << std::endl;
		
		std::string row_name = rm_dot_ext (name);
		std::cout << "row_name:" << row_name << std::endl;	
		std::string data_file_in  = name;
		std::string data_file_out = row_name + "_r.csv";

    
		std::vector<std::string> table =  read_file (data_file_in);
		write_file (data_file_out, table, 0, 1);
		}
}

//*****************************************************************//
std::string lastname(std::string str) {
	std::string name;
	std::stringstream x(str);
	while (getline (x, name, '/'));
	return name;
	}

std::string rm_dot_ext (std::string str) {
	std::string name;
	std::stringstream x(str);
 	getline (x, name, '.');
 	return name;
	}


//***************************************************************//
std::vector<std::string> read_file (std::string file_name)
{
	std::ifstream fin;
	fin.open (file_name, std::ios::in);

	std::vector<std::string> row;
	std::vector<std::string> table;
	std::string line, word, temp;

	int cnt = 0;
	while (getline(fin, line))
	{
		row.clear();
		std::stringstream s (line);

		while (getline (s, word))
			row.push_back (word);

		table.push_back (word);
		cnt++;
	}
	fin.close();

	std::cout << " \n no of lines of row file:" << cnt << std::endl;

	return table;
}

//****************************************************************//
void write_file (std::string file_name,
				 std::vector<std::string> table, int from, int to)
{
	std::ofstream fout (file_name);
	for (int i = from; i <= to; ++i) {
	std::cout << "\n" << table[i];
	fout <<  table [i] << '\n';
	}
	fout.close();
	std::cout << " \n no of lines of new file:" << to - from + 1 << std::endl;
	std::cout << "|**************************************|" << std::endl;
}

//****************************************************************//
//****************************************************************//
