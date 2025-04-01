// SCRIPT MADE BY capt-jack00 ON GITHUB 
// WAS FULLY WRITTEN IN NEOVIM

#include <iostream>
#include <fstream>
#include <filesystem>


int main(int argc, char* argv[]){
	std::string projectName;
	if(argc == 1){
		projectName = "unnamedProject";
	}
	else{
		projectName = argv[1];
	}
	

	const std::string cmakeContent = 
		"cmake_minimum_required(VERSION 3.10)\n"
		"project(" + projectName + ")\n"
		"\n"
		"add_executable(main main.cpp)";

	const std::string mainContent = 
		"#include <iostream>\n"
		"\n"
		"using namespace std;\n"
		"\n"
		"int main(){\n"
		"\n"
		"}";
	
	if(argc < 2){
		std::cout << "No project name provided " << projectName << " created" << std::endl;
		std::cout << "Usage: cpproject <projectname>" << std::endl;
	}

	if(argc > 2){
		std::cout << "Too much arguments!" << std::endl;
		std::cout << "Usage: cpproject <projectname>" << std::endl;
		return 1;
	}


	// CREATING PROJECT FILES AND FOLDER
	std::filesystem::create_directory(projectName);
	std::ofstream cmakeFile(projectName + "/CMakeLists.txt");
	std::ofstream mainFile(projectName + "/main.cpp");

	//ERRROR HANDLING
	if(!cmakeFile){
		std::cout << "Something went wrong while creating the CMake file!" << std::endl;
		return 5;
	}

	if(!mainFile){
		std::cout << "Something went wrong while creating the main file!" << std::endl;
		return 6;
	}
	
	//WRITING CHANGES TO ALREADY CREATED FILES 
	cmakeFile << cmakeContent; 
	cmakeFile.close();

	mainFile << mainContent;
	mainFile.close();


}
//ERROR CODES:
//0 - NO_ERROR
//1 - TOO_MUCH_ARGS
//5 - CMAKE_FILE_FAILED_TO_CREATE
//6 - CPP_FILE_FAILED_TO_CREATE
