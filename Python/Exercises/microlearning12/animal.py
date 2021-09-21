# Training import classes
class Animal:
	nome = ''
	especie = ''
	fome = 0

	def __init__(self,nom,esp):
		self.nome = nom
		self.especie = esp

	def __str__(self):
		return ("Nome: {}\nEspecie: {}\nFome: {}\n".format(self.nome,self.especie,self.fome))
	
	def andar(self):
		self.fome = self.fome + 1
	
	def comer(self,quantidade):
		if quantidade > self.fome:
			self.fome = 0
			raise Exception('Animal comeu demais')
		else:
			self.fome = self.fome - quantidade

bicho = Animal('Mallu','Cachorro')	