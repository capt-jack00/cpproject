# cpproject 
This is a small script written in C++ that helps you with creating your base project files like CMakeLists.txt or main.cpp with the basic code already so you don't have to create it every time manually. This is a great solutions for Vim and NeoVim users so they have ability to easily create base project files. There are not much options but I will update it in the near future so it can be more useful. 

# Installation
Unfortunatley, I'm to lazy to submit this project to the apt or any other package manager so you need to install it manually.\
\
While installing the program manually you have two options. First one is to used already compiled code and the second one is to download the source code, modify it with your needs and compile it yourself. 

1. Clone the repository
`git clone https://github.com/capt-jack00/cpproject`
2. Move the executable file to the /usr/bin/ folder
`mv cpproject/build/main /usr/bin/cpproject`
3. Done!
Now you can use the script from the console itself. Usage is described below\

**Note:** Above instructions are made for Arch-based systems. It won't work on Ubuntu or other debian-based systems.

# Usage
This program will only work on linux systems for now but if someone would really like to have it on windows I could try to port it for winows too. 

Basic usage:
    `cpproject <projecyName>`

And yeah, that's all :P 
The `<projectName>` stands for the name of the project that you will have in 'project(projectName)' and for the name of the folder where you'r project will be placed. The script always creates a folder named after <projectName> and inside of it it creates a main.cpp and CMakeLists.txt files with base content in there already.
