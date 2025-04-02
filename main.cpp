// SCRIPT MADE BY capt-jack00 ON GITHUB 
// WAS FULLY WRITTEN IN NEOVIM

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

//TODO: Debug the program, when creating the project with option "-qt" at the end it shows
// error messeage saying that creating a directory failed but it creates anyways. For some 
// reason it also creates the files with the standard content instead of those meant for Qt5
//
// Last update: 01.04.2025

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

	const std::string qtCmakeContent = 
		"cmake_minimum_required(VERSION 3.10)\n"
		"project(" + projectName + " VERSION 1.0 LANGUAGES CXX)\n"
		"\n"
		"set(CMAKE_CXX_STANDARD 17)\n"
		"set(CMAKE_CXX_STANDARD_REQUIRED ON)\n"
		"\n"
		"find_package(Qt5 REQUIRED COMPONENTS Widgets)\n"
		"\n"
		"add_executable(" + projectName + " main.cpp)\n"
		"\n"
		"target_link_libraries(" + projectName + " PRIVATE Qt5::Widgets)";

	const std::string qtMainContent = 
		"#include <QApplication>\n"
		"#include <QMainWindow>\n"
		"#include <QString>\n"
		"\n"
		"QString projectName = \"" + projectName + "\";"
		"\n"
		"int main(int argc, char *argv[]){\n"
		"QApplication app(argc, argv);\n"
		"\n"
		"QMainWindow mainWindow;\n"
		"mainWindow.setWindowTitle(projectName);\n"
		"mainWindow.resize(800, 600);\n"
		"mainWindow.show();\n"
		"\n"
		"return app.exec();\n"
		"\n"
		"}";

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

	if(argc > 3){
		std::cout << "Too much arguments!" << std::endl;
		std::cout << "Usage: cpproject <projectname>" << std::endl;
		return 1;
	}


	// CREATING PROJECT FILES AND FOLDER
	std::filesystem::create_directory(projectName);
	if(!std::filesystem::create_directory(projectName)){
		std::cout << "Something went wrong while creating the directory. Please check if you have required priviliges and if the folder already exists" << std::endl;
	}


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
	
	if(argc > 2 && std::string(argv[2]) == "-qt"){
		cmakeFile << qtCmakeContent;
		cmakeFile.close();

		mainFile << qtMainContent;
		mainFile.close();
	}
	else{
		cmakeFile << cmakeContent;
		cmakeFile.close();

		mainFile << mainContent;
		mainFile.close();
	}
	
}

