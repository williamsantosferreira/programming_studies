#include <iostream>
#include<fstream>
#include <string>
#include <sstream>

class File{
	private:
		std::fstream arq;	
		char* filename;
		
		std::string str;
		
	public:
		void file_name(char* name);
		void create_file();
	    int read_file();
	    int write_file(std::string content);
	    void show_info();
	   	    
};

void File::file_name(char* name){
	filename = name;
}

void File::create_file(){ //I can't create a file
	arq.open(filename,std::fstream::out);	
	arq.close();
}

int File::read_file(){
	arq.open(filename,std::fstream::in);
	std::stringstream ss;
	std::string s;
	
	if(arq.good()){
		while(std::getline(arq,s)!= NULL)
			ss << s << std::endl;
		str = ss.str();
		arq.close();	
		return 1;	
	}
	else
		return 0;
}

int File::write_file(std::string content){
	arq.open(filename,std::fstream::app);
	if(arq.good()){
		arq << content;
		arq.close();
		return 1;
	}
	else
		return 0;
}

void File::show_info(){
	std::cout<<str;
}

int main(){
	char name[]= "file.txt";
	File arq;
	std::string frase = "Testando";
	
	
	arq.file_name(name);
	arq.create_file();
	arq.write_file(frase);
	arq.read_file();
	arq.show_info();
	
	return 0;
}
