#include <filesystem>
#include <vector>
#include <string>
#include <iostream>

namespace fs = std::filesystem;

std::vector <std::string> list_dir (fs::path path)
{
	std::vector <std::string> dir_list;
	for (const auto & entry : fs::directory_iterator(path))
		 if(fs::is_directory (entry.path().filename()))
		 	dir_list.push_back(entry.path().filename().generic_string());
	return dir_list;
}
std::vector <std::string> list_file (fs::path path)
{
	std::vector <std::string> file_list;
	for (const auto & entry : fs::directory_iterator(path))
		 if(fs::is_regular_file (entry.path().filename()))
		 	file_list.push_back(entry.path().filename().generic_string());
	return file_list;
}

std::vector <std::string> list_file_stem (fs::path path)
{
	std::vector <std::string> file_list;
	for (const auto & entry : fs::directory_iterator(path))
		 if(fs::is_regular_file (entry.path().filename()))
		 	file_list.push_back(entry.path().stem().generic_string());
	return file_list;
}

void chdir (std::string folder)
{
	fs::path path = fs::current_path();
	path /= folder;
	fs::current_path (path);
}

/*
int main()
{
fs::path path = fs::current_path();
std::cout << "Current path is " << path << '\n';

std::vector <std::string> filelist = list_dir (path);

for ( auto entry : filelist)
	std::cout << entry << std::endl;
	
	filelist.clear();
	filelist = list_file (path);

for ( auto entry : filelist)
	std::cout << entry << std::endl;
		
}*/
