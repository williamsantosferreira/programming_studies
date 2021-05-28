//Programa para testar a biblioteca Bookshop_System.h
#include <iostream>
#include "Bookshop_System.h"

int main(){
	Bookshop obj;
	
	obj.define_file_books("book.txt");
	obj.define_file_login("login.txt");
	
	if(obj.read_books() && obj.read_login()){
		obj.show_book();
		obj.show_login();
	}
	return 0;
}
