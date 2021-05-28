 //Bookshop Inventory System
//Projeto de maio - deadline até o fim de 05/2021
//De: William Santos
/*
Objetivo: Fazer um inventário de uma livraria. 
- A ideia é ter uma área para um cliente e outro para o funcionário;
- O cliente poderá fazer a busca pelo livro e comprar;
- O funcionário poderá adicionar ou remover livros do catálogo;
- Importante termos um sistema de login;
- Vamos trabalhar com uma classe principal que será a Bookshop, será feita
em um programa separado.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

struct Inventory{
	std::string name;
	std::string author;
	std::string departament; //type of book
	float price;
	int amount; 
	
	Inventory *next = NULL;
};

struct Login{
	std::string name;
	std::string email;
	std::string password;
		
	Login *next = NULL;
};

class Bookshop{
	private:
		Inventory *start_book = NULL;
		Login *start_login = NULL;
		
		std::ofstream write;
		std::ifstream read;
		std::string file_books;
		std::string file_login;	
		
		int pass; 
	public:
		Bookshop(){ };
		
		void define_file_books(std::string f_book); 
		void define_file_login(std::string f_login);
		
		int open_write(int option);
		int open_read(int option);
		
		void close_write();
		void close_read(); 
		
		void new_book(Inventory book);
		void show_book(); 
		
		void new_login(Login user);
		void show_login(); // Be careful with this function! 
		
		
		int write_books(); 
		int read_books(); 
		
		int write_login(); 
		int read_login(); 
		
		int sign_in(std::string email,std::string password);
		
		Inventory* search_name(Inventory *b,std::string book);
		Inventory* search_author(Inventory *b,std::string writer);
		Inventory* search_department(Inventory *b,std::string dep);	
		
		int delete_login(std::string login,std::string password); 
		int delete_book(std::string book); 
		
		int purchase_book(std::string name,int amount); 
	
		Inventory* p_start_book(); 
		
		int edit_book(Inventory search,Inventory new_b); 
		int edit_login(Login search,Login new_login); 
		
};
void Bookshop::define_file_books(std::string f_book){
	//string file need to have the extension
	file_books = f_book;
}

void Bookshop::define_file_login(std::string f_login){
	//string file need to have the extension
	file_login = f_login;
}

int Bookshop::open_write(int option){
	//1 --> books
	// 2 --> login
	
	if(option == 1){
	write.open(file_books.c_str()); //return a string like a vector of characters
	if(write.good())
		return 1;
	return 0;
	}
	else if(option == 2){
		write.open(file_login.c_str()); 
		if(write.good())
			return 1;
		return 0;	
	}
	return 0;
}

int Bookshop::open_read(int option){
	//1 --> books
	//2 --> login
	
	if(option == 1){
		read.open(file_books.c_str());
		if(read.good())
			return 1;
		return 0;
	}
	else if(option == 2){
		read.open(file_login.c_str());
		if(read.good())
			return 1;
		return 0;
	}
	return 0;
}

void Bookshop::close_read(){
	read.close();
}

void Bookshop::close_write(){
	write.close();
}

void Bookshop::new_book(Inventory book){
		Inventory *b = new Inventory;
		Inventory *b2 = new Inventory;
		
	if(start_book == NULL)
		start_book = b2;
	else{
		b = start_book;
		while(b->next!= NULL)
			b = b->next;		
	}
		b->next = b2;
		b2->amount = book.amount;
		b2->author = book.author;
		b2->departament = book.departament;
		b2->name = book.name;
		b2->price = book.price;
		
		b2->next = NULL;		
}

int Bookshop::write_books(){
	
	if(!this->open_write(1))
		return 0;
	else{
		if(start_book == NULL){
			this->close_write();
			return 1;
		}
		Inventory *b = new Inventory;
		b = start_book;
		while(b != NULL){
			write<<b->amount<<std::endl;
			write<<b->author<<std::endl;
			write<<b->departament<<std::endl;
			write<<b->name<<std::endl;
			write<<b->price<<std::endl;
			
			b = b->next;
		}
		this->close_write();
		return 1;
	}	
}

int Bookshop::read_books(){
	
	if(!this->open_read(1))
		return 0;
	else{
		Inventory b;
		
		std::string amount,price;
			
		while(getline(read,amount)){
			b.amount = atoi(amount.c_str());
			getline(read,b.author);
			getline(read,b.departament);
			getline(read,b.name);
			getline(read,price);
			b.price = atof(price.c_str());
							
			new_book(b);
	}
	}
	this->close_read();
	return 1;
}

void Bookshop::show_book(){
	Inventory *b = new Inventory;
	b = start_book;

	while(b != NULL){
		std::cout<<b->amount<<std::endl;
		std::cout<<b->author<<std::endl;
		std::cout<<b->departament<<std::endl;
		std::cout<<b->name<<std::endl;
		std::cout<<b->price<<std::endl;
				
		b = b->next;
	}
}

int Bookshop::write_login(){
	if(!this->open_write(2))
		return 0;
	else{
		if(start_login == NULL)
			return 1;
		Login *user = new Login;
		
		user = start_login;
		
		while(user != NULL){
				
			write<<user->email<<std::endl;
			write<<user->name<<std::endl;
			write<<user->password<<std::endl;
			
			user = user->next;
		}
		this->close_write();
		return 1;
	}
}

int Bookshop::read_login(){
	if(!this->open_read(2))
		return 0;
	else{
		Login user;
		
		while(getline(read,user.email)){
			getline(read,user.name);
			getline(read,user.password);
			new_login(user);
		}
			return 1;
		}
		}	


void Bookshop::new_login(Login user){
	Login *u= new Login;
	Login *u2 = new Login;
	if(start_login == NULL)
		start_login = u2;
	else{
		u = start_login;
		while(u->next != NULL){
			u = u->next;
		}
		u->next = u2;
	}
		u2->email = user.email;
		u2->name = user.name;
		u2->password = user.password;
		u2->next = NULL;
}

void Bookshop::show_login(){
	Login *user = new Login;
	
	if(start_login != NULL){
		user = start_login;
		while(user != NULL){
			std::cout<<user->email<<std::endl;
			std::cout<<user->name<<std::endl;
			std::cout<<user->password<<std::endl;
			
			user = user->next;
		}}}
int Bookshop::sign_in(std::string email,std::string password){	
	Login *user = start_login;

	while(user != NULL){
		if(user->email == email && user->password == password)
			return 1;
		user = user->next;
	}
	return 0;
}

Inventory* Bookshop::search_name(Inventory *b,std::string name){
	while(b!= NULL){
		if(b->name == name)
			return b;
		b = b->next;
	}
	return NULL;
}

Inventory* Bookshop::search_department(Inventory *b,std::string department){
	while(b != NULL){
		if(b->departament == department)
			return b;
		b = b->next;
	}
	return NULL;
}

Inventory* Bookshop::search_author(Inventory *b, std::string author){
	while(b != NULL){
		if(b->author == author)
			return b;
		b = b->next;
	}
	return NULL;
}

Inventory* Bookshop::p_start_book(){
	return start_book;
}


int Bookshop::delete_login(std::string login,std::string password){
	Login *user = start_login;
	Login *aux;
	
	if(user == NULL)
		return 0;
	aux = user;
	while((user->email != login && user->password != password) && user->next != NULL){
		aux = user;
		user = user->next;
	}
	if(user->email == login && user->password == password){
		if(user == start_login){
			if(user->next != NULL)
				start_login = user->next;
			else
				start_login = NULL;
		return 1;
		}	
		else if(user != NULL){
			aux->next = user->next;
			delete user;
		
			return 1;
		}
	}
	return 0;
}

int Bookshop::delete_book(std::string name){
	Inventory *book = start_book;
	Inventory *aux;
	
	if(book == NULL)
		return 0;
	aux = book;
	while(book->name != name && book->next != NULL){
		aux = book;
		book = book->next;
	}
	if(book->name == name){
		if(book == start_book){
			if(book->next != NULL)
				start_book = book->next;
			else
				start_book = NULL;
		return 1;
	}
		else if(book != NULL){
			aux->next = book->next;
			delete book;
		return 1;
	}}
	return 0;
}


int Bookshop::purchase_book(std::string name, int amount){
	Inventory *book;
	book = this->search_name(start_book,name);
	
	if(book != NULL){
		if(book->amount > 0 && amount <= book->amount){
			book->amount = book->amount - amount;
			return 1;}
		else
			return 0;		
	}
	return 0;
		
}

int Bookshop::edit_book(Inventory search,Inventory new_b){
	Inventory *aux = start_book;
	
	while(aux != NULL){
		aux = this->search_author(aux,search.author);
		if(aux != NULL){
			if(aux->name == search.name && aux->author == search.author && aux->departament == search.departament){
				aux->amount = new_b.amount;
				aux->author = new_b.author;
				aux->departament = new_b.departament;
				aux->name = new_b.name;
				aux->price = new_b.price;
				
				return 1;
			}
			aux = aux->next;
		}
	}
	return 0;
}

int Bookshop::edit_login(Login search,Login new_login){
	Login *aux = start_login;
	
	while(aux != NULL){
		if(aux->email == search.email && aux->password == search.password){
			aux->email = new_login.email;
			aux->name = new_login.name;
			aux->password = new_login.password;
			
			return 1;
		}
		aux = aux->next;
	}
	return 0;
}
		
void flush() {
    //funçao excelente para limpar o buffer de entrada.
    int ch;
    while ( ( ch = fgetc ( stdin ) ) != EOF && ch != '\n' ) {}
}



