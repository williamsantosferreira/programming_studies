def formatar_data(data=(1,1,1)):
	meses = ['jan','fev','mar','abr','mai','jun','jul','ago','set','out','nov','dez']
	(ano,mes,dia) = data
	if (dia < 10):
		dia = '0' + str(dia)
	mes = meses[mes-1]
	return str(dia)+'/'+mes+'/'+str(ano)

def formatar_hora(hora=(1,1)):
	if(hora[0] < 10):
		horario = '0'+str(hora[0])+':'
	else:
		horario = str(hora[0])+':'
	if(hora[1] < 10):
		horario = horario + '0'+str(hora[1])
	else:
		horario = horario + str(hora[1])
	return horario

def imprimir_eventos(eventos,de_data=(1,1,1),ate_data=(9999,12,31)):
	for x in range(len(eventos)):
		if(eventos[x][0] >= de_data and eventos[x][0] <= ate_data):
			print(formatar_data(eventos[x][0])+' - '+formatar_hora(eventos[x][1])+': '+eventos[x][2])


# utilizando a agenda do exemplo fornecido
agenda = [((2020, 1, 13), (11, 50),'Renovar identidade'),((2020, 1, 15), (16, 30),'Fazer compras'),((2020, 1, 25), (8, 45),'Autenticar documentos'),((2020, 2, 29), (14, 15),'Prestar concurso'),((2020, 3, 15), (17, 50),'Buscar bolo pro aniversario da vovo'),((2020, 3, 17), (13, 20),'Consulta de revisao com dentista')]

imprimir_eventos(agenda)
		
	
