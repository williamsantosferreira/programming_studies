#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>

struct Data{
	std::string nickname;
	std::string password;
};

void flush();

class Users{
	private:
		struct Data info[100];
		std::ifstream read;
		std::ofstream write;
		std::string arq;
		int pos = 0;
	public:
		Users(std::string& name):
			arq(name+".txt"){
	
			}
						
		int abertura_i(){
			read.open(arq.c_str());
			if(!read.good())
				return 0;
		return 1;
		}
		
		int abertura_o(){
			write.open(arq.c_str());
			if(!write.good())
				return 0;
		return 1;
		}
		
		int write_info(){	
			if(pos == 49)
				return 0;
			else{
				flush();
			std::cout<<"Digite o nickname: ";
				getline(std::cin,info[pos].nickname);
			std::cout<<"Digite a senha: ";
				getline(std::cin,info[pos].password);
			pos++;
			}
			
			return 1;	
		}
		
		void leitura_dados(){
				if(abertura_i()){
				while(getline(read,info[pos].nickname)){
					getline(read,info[pos].password);
					pos++;
				}
				read.close();
			}}
	
		int posicao(){
			return pos;
		}
		
		int verificar(std::string& name,std::string& password,int i){
			if(this->info[i].nickname == name)
				if(this->info[i].password == password)
					return 1;
			return 0;
		}
		
		int gravar(){
			if(abertura_o()){
				for(int i=0;i<pos;i++){
					write<<this->info[i].nickname<<std::endl;
					write<<this->info[i].password<<std::endl;	
			}
			write.close();
				return 1;
			}
			else
				return 0;
		}
};

//-------------------------------------------------------
void cadastro(Users& usuario){
		system("cls");
		std::cout<<"CADASTRO "<<usuario.posicao()<<std::endl;
		
	if(usuario.write_info() && usuario.gravar()){
		std::cout<<"Cadastro realizado com sucesso!\n";
	}
	else
		std::cout<<"Falha no cadastro!\n";
			
	system("pause");
}

void login(Users& usuario){
		int a = 0;
		system("cls");
		std::cout<<"LOGIN"<<std::endl;
	
	std::string name,password;
	
		flush();
	std::cout<<"usuario: ";
		getline(std::cin,name);
	std::cout<<"password: ";
		getline(std::cin,password);
		
	int tamanho = usuario.posicao();
	
	for(int i=0;i<=tamanho;i++){
		if(usuario.verificar(name,password,i)){
			std::cout<<"Logado com sucesso!\n\n";
			a = -1;	
		}
	}	
	if(a == 0)
		std::cout<<"Nenhum login encontrado!"<<std::endl;
	
	system("pause");
}

void flush() {
    //funçao excelente para limpar o buffer de entrada.
    int ch;
    while ( ( ch = fgetc ( stdin ) ) != EOF && ch != '\n' ) {}
}

int main(){
		std::string name = "registro";
		Users usuario(name);
		
		int escolha;
		
		usuario.leitura_dados();
		
		while(1){
			system("cls");
			std::cout<<"REGISTRO\n1.Cadastro\n2.Login\n3.Sair\nEscolha: ";
				std::cin>>escolha;
				
			if(escolha == 1)
				cadastro(usuario);
			else if(escolha == 2)
				login(usuario);
			else if(escolha == 3)
				break;
			else
				std::cout<<"Escolha invalida! Tente novamente!\n";
		}
		std::cout<<"\nObrigado por usar nosso programa!";
		
		
	return 0;
}
