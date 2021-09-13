# estrutura do livro: titulo, genero, subgenero, editora, numero de copias em loja e valor

cont = True
livraria = {}
quantidade = 1

for x in range(0,quantidade):
	livro = {}
	livro['titulo'] = (input('Titulo do livro:')).upper()
	livro['genero'] = (input('Genero do livro:')).upper()
	livro['subgenero'] = (input('Subgenero do livro:')).upper()
	livro['editora'] = (input('Editora do livro:')).upper()
	livro['numero_copias'] = input('Numero de copias em loja:')
	livro['valor'] = input('Valor do livro: R$')

	if livro['genero'] not in livraria:
		livraria[livro['genero']] = {}
		livraria[livro['genero']][livro['subgenero']] = []
	elif livro['subgenero'] not in livraria[livro['genero']]:
		livraria[livro['genero']][livro['subgenero']] = []
	livraria[livro['genero']][livro['subgenero']].append(livro)
	print('\n')

for x in livraria:
	print('--- GENERO',x,'---')
	for y in livraria[x]:
		print('------ SUBGENERO',y,'------')
		for livros in livraria[x][y]:
			print('Titulo:',livros['titulo'])
			print('Editora:',livros['editora'])
			print('Copias:',livros['numero_copias'])
			print('Valor: R$',livros['valor'])
			print('\n')
