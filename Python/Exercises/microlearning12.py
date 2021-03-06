'''Os jogos de simulação são muito famosos e divertidos. Em SimCity, por exemplo, o jogador brinca de gerenciar uma cidade. Já em Tamagoshi, o jogador tem um pequeno dispositivo que simula toda a vida de um animal de estimação. Tendo como referência esses passatempos, que tal fazer uma pequena simulação como se você estivesse construindo uma pequena cópia do Tamagoshi?

Para esta oficina, a partir do que foi aprendido até aqui, você deverá construir uma classe para abstrair um animal qualquer. Nessa abstração, inclua os atributos nome, espécie e fome. Por exemplo, nome e espécie podem ser passados como parâmetro no construtor dessa classe; já a fome deve ser inicializada com valor 0, pois ela é o atributo indicador numérico que armazenará o quanto de fome o animal tem em um dado momento. Assim, 0 (zero) fome significa que ele está satisfeito, ou seja, não tem fome nenhuma. Agora, se tiver 1, significa que ele tem um pouquinho de fome; 2, um pouco mais; e assim por diante.

Como comportamento, você precisará construir o método __str__() para retornar uma string, representando o estado atual de um dado animal, e um método andar(), que simula um passeio com o animal. Ao andar, o valor da fome do animal deve aumentar em 1.

Além desses métodos, você deverá construir um método comer(), que implementa a simulação do ato do animal de se alimentar. Esse método recebe um valor numérico, como parâmetro, que é o número de unidades de comida oferecidas ao animal. Com esse valor, você vai diminuir o atributo fome do animal. Caso o valor de fome do animal seja menor do que o valor de comida oferecido, você deve atualizar o valor de fome para 0 (o valor mínimo possível) e informar ao usuário que o animal comeu até ficar saciado e deixou o resto da comida no prato

Por fim, fora da classe, instancie um objeto Animal com o nome e espécie que você quiser. Feito isso, será possível criar um laço de repetição para interagir com o usuário. Ademais, deve haver um menu com 4 opções: 1 para alimentar o animal; 2 para andar com ele; 3 para mostrar o estado atual do animal; e 4 para finalizar a execução.

O usuário vai digitar a opção que quer, e você vai fazer com que o animal se comporte adequadamente. Na opção 1, você vai apresentar uma nova questão ao usuário para que ele informe o quanto de comida é desejada para dar ao animal. Assim, você vai tratar a possível exceção gerada, informando ao usuário que ele deu comida demais, caso seja a situação. Ao final de cada interação, você vai apresentar o novo estado do animal e, depois, apresentar o menu novamente ao usuário até que ele aperte 3 e finalize a execução do programa.

Empolgado para desenvolver esse joguinho? Então comece a praticar agora!'''

