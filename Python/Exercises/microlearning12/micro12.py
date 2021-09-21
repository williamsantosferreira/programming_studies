from animal import Animal

name = input('Digite o nome do seu animal: ')
especie = input('Digite a especie do seu animal: ')

bicho = Animal(name,especie)

escolha = 1

while (escolha != 4):
	escolha = int(input('Escolha:\n1.Alimentar {}\n2.Andar com {}\n3.Estado de {}\n4.Sair\nO que deseja fazer:'.format(bicho.nome,bicho.nome,bicho.nome)))
	if(escolha == 1):
		quantidade = int(input('Qual a quantidade de comida: '))
		try:
			bicho.comer(quantidade)
		except Exception as excp:
			print(excp)
	elif(escolha == 2):
		print('Andando com {}'.format(bicho.nome))
		bicho.andar()
	elif(escolha == 3):
		print(bicho)
