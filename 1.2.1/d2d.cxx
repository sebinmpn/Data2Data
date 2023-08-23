#include <iostream>
#include <filesystem>
#include <cstring>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Multiline_Output.H>

#include "file.cxx"

namespace fs = std::filesystem;

void path_cb (Fl_Widget*, void*);
void list_cb (Fl_Widget*, void*);
void convert_cb (Fl_Widget*, void*);
struct in { Fl_Input *folder, *ext, *from, *to; Fl_Multiline_Output *out;};

int main()
{
    Fl_Window win (600, 400, "./d2d");
    win.begin();
    Fl_Button path (50, 250, 100, 30, "path");
    Fl_Output out (160, 250, 400, 30);

    Fl_Button list (50, 100, 100, 50, "list");
    Fl_Multiline_Output list_out ( 160, 100, 400, 100);
    Fl_Button convert(50, 50, 100, 30, "convert");

    Fl_Input folder (200, 50, 50, 30, "folder");
    Fl_Input ext  (300, 50, 50, 30, "ext");
    Fl_Input from (400, 50, 50, 30, "from");
    Fl_Input to (500, 50, 50, 30, "to");
	in inputs {&folder, &ext, &from, &to, &list_out};
	
    win.end();
    win.show();

    path.callback (path_cb, &out);
    list.callback (list_cb, &list_out);
    convert.callback (convert_cb, &inputs);

    return Fl::run();
}

void convert_cb (Fl_Widget*, void* _inputs)
{
    in* inputs = (in*) _inputs;
    Fl_Input* _folder = (Fl_Input*) inputs->folder;
    Fl_Input* _ext = (Fl_Input*) inputs->ext;
    Fl_Input* _from = (Fl_Input*) inputs->from;
    Fl_Input* _to = (Fl_Input*) inputs->to;
    Fl_Multiline_Output* _out = ( Fl_Multiline_Output*) inputs->out;

    const char* folder = _folder->value();
    const char* ext = _ext->value();
    const char* from = _from->value();
    const char* to = _to->value();

//     std::string str = std::string(folder)
//         + " " + std::string(ext)
//         + " from: " + std::string(from)
//         + " to: " + std::string(to);
//     std::cout << str;
    std::string str;
    int cnt = 0;
    fs::path parent_path = fs::current_path();
    chdir (std::string(folder));
    fs::path data_path = fs::current_path();
    auto data_noext = list_file_stem (data_path);
    for (auto datafile : list_file (data_path)) {
        str += datafile;
        str += " -> " ;
        str += data_noext[cnt];
        str += std::string (ext);
        str += "[" ;
        str += std::string (from);
        str += ",";
        str += std::string (to);
        str += "]";
        str += "\n";
        cnt++;
    }
    fs::current_path (parent_path);

    char* ch = new char[str.length() +1];
    strcpy (ch, str.c_str());
    _out->value (ch);
    delete[] ch;
}

void path_cb (Fl_Widget* w, void* ot)
{
    Fl_Output* out = (Fl_Output*) ot;

    std::string str = fs::current_path().generic_string();
    char* ch = new char[str.length() +1];
    strcpy (ch, str.c_str());

     out->value (ch);
     delete[] ch;
}

void list_cb (Fl_Widget* w, void* out)
{
    Fl_Multiline_Output* list_out = (Fl_Multiline_Output*) out;
    std::string str;
    std::vector <std::string> dir_list = list_dir (fs::current_path());

    for (auto dir : dir_list) {
        str += dir;
    	str += "\n";
    }

    char* ch = new char[str.length() +1];
    strcpy (ch, str.c_str());

     list_out->value (ch);
     delete[] ch;
}











