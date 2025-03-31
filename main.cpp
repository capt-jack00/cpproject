// SCRIPT MADE BY capt-jack00 ON GITHUB 
// WAS FULLY WRITTEN IN NEOVIM

#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

int main(int argc, char* argv[]){
	string projectName;
	if(argc == 1){
		projectName = "unnamedProject";
	}
	else{
		projectName = argv[1];
	}
	

	const string cmakeContent = 
		"cmake_minimum_required(VERSION 3.10)\n"
		"project(" + projectName + ")\n"
		"\n"
		"add_executable(main main.cpp)";

	const string mainContent = 
		"#include <iostream>\n"
		"\n"
		"using namespace std;\n"
		"\n"
		"int main(){\n"
		"\n"
		"}";

	if(argc < 2){
		cout << "No project name provided " << projectName << " created" << endl;
		cout << "Usage: cpproject <projectname>" << endl;
		return 0;
	}

	if(argc > 2){
		cout << "Too much arguments!" << endl;
		cout << "Usage: cpproject <projectname>" << endl;
		return 1;
	}
	
	filesystem::create_directory(projectName);

	ofstream cmakeFile(projectName + "/CMakeLists.txt");
	ofstream mainFile(projectName + "/main.cpp");

	if(!cmakeFile){
		cout << "Something went wrong while creating the CMake file!" << endl;
		return 5;
	}

	if(!mainFile){
		cout << "Something went wrong while creating the main file!" << endl;
		return 6;
	}

	cmakeFile << cmakeContent;
	cmakeFile.close();

	mainFile << mainContent;
	mainFile.close();

	//if(argv[1] = "-help"){
	//	cout << "Usage: cpproject <projectname>" << endl;
	//	cout << "Program made by capt-jack00 on github" << endl;
	//}

}


//ERROR CODES:
//0 - NO_ERROR
//1 - TOO_MUCH_ARGS
//5 - CMAKE_FILE_FAILED_TO_CREATE
//6 - CPP_FILE_FAILED_TO_CREATE
