#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <filesystem>
#include<bits/stdc++.h>


namespace fs = std::filesystem;


struct Args
{
	std::string data_file;
	std::string data_file_out_abr;
	int from;
	int to;
};

class ParseError : public std::runtime_error
{
public:
	ParseError (void) :
		std::runtime_error ("Parse error")
	{}
};

Args parse_args (int argc, char* argv[])
{
	std::vector<std::string> args (argv, argv + argc);

	try
	{
		int idx = 1;

		auto data_file  = argv [idx++];
		auto data_file_out_abr = argv [idx++];
		auto from  = std::stoi (args.at (idx++));
		auto to    = std::stoi (args.at (idx++));

		return { data_file, data_file_out_abr, from, to };
	}

	catch (...)
	{
		throw ParseError();
	}
}

const char* usage =
	"Usage                                       \n"
	"d2d folder abbreviation form to             \n"
	"                                            \n"
	"   eg. d2d data new_ 2(from) 5(to)          \n";

//************************************************************************//
std::vector<std::string> read_file (std::string file_name);
void write_file (std::string, std::vector<std::string>, int, int);
std::string lastname(std::string str);
std::string rm_dot_ext (std::string str);


int main (int argc, char* argv[])
{
	try
	{
		auto args = parse_args (argc, argv);

		std::string data_folder  = argv [1];
		std::string data_file_out_abr = argv [2];
		int from = std::stoi (argv [3]);
		int to   = std::stoi (argv [4]);
		

		fs::path path = fs::current_path();
		std::cout << "Current path is " << path << '\n';
		fs::current_path( path /= data_folder);	
		//std::cout << "Current path is " << fs::current_path();
	
		for (const auto & entry : fs::directory_iterator(path))
			{//std::cout << entry.path() << std::endl;
			
			fs::path path_name = fs::path (entry.path());

			std::string row_name = path_name.stem().generic_string();
				
			std::string data_file_in  = path_name.filename().generic_string();
			std::string data_file_out = row_name + data_file_out_abr;
			
			std::cout << '\n' << "read from:" << data_file_in << "  write to:" << data_file_out;
			

    	
			std::vector<std::string> table =  read_file (data_file_in);
			write_file (data_file_out, table, from, to);
		}

	}
	catch (ParseError&)
	{
		std::cerr << usage << std::endl;
	}

	return 0;
}
//***************************************************************//
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
	std::cout << " \n no of lines of new file:" << to - from + 1 << std::endl;

	std::ofstream fout (file_name);
	for (int i = from; i <= to; ++i) {
	std::cout << "\n" << table[i];
	fout <<  table [i] << '\n';
	}
	fout.close();
	
	std::cout << "|**************************************|" << std::endl;
}

//****************************************************************//
//****************************************************************//
