/*
In a game of RisiKo! (the Italian version of the popular board game Risk!), the players throw six-sided dice to conquer territories around a World map.

When two players contend a territory there is a battle, and they throw from 1 up to 3 dice, with each die being an army sent to fight. To establish who loses armies after the battle, the dice are compared starting from the highest value, and proceeding with the comparisons in descending order (eliminating the dice in excess if the amount of thrown dice among the two players is different).

When the rolls are compared, for each comparison the die of the attacking player must have a greater value than the defender's die to win the fight. In the case of a tie, the defender wins the single fight. The loser only loses 1 army per comparison.

Given two arrays att (rolls of the attacker) and def (rolls of the defender), implement a function that returns the armies lost by the defender as an integer.

Examples
risiko([3, 6, 4], [2, 5, 3]) ? 3
// Comparison 1:
// ATT(6) vs. DEF(5): DEF loses an army
// Comparison 2:
// ATT(4) vs. DEF(3): DEF loses an army
// Comparison 3:
// ATT(3) vs. DEF(2): DEF loses an army

risiko([3, 6], [6, 4, 4]) ? 0
// Comparison 1:
// ATT(6) vs. DEF(6): ATT loses an army
// Comparison 2:
// ATT(3) vs. DEF(4): ATT loses an army

risiko([3, 1], [1]) ? 1
// Comparison 1:
// ATT(3) vs. DEF(1): DEF loses an army

*/

#include <iostream>
#include <vector>

std::vector<int> bubble_sort(std::vector<int> vec){
	int swap, n = vec.size();
	
	for(int i = n; i > 0; i--){
		for(int i1 = 0; i1 < i-1; i1++){
			if(vec[i1] > vec[i1+1]){
				swap = vec[i1];
				vec[i1] = vec[i1+1];
				vec[i1+1] = swap;
			}
		}
	}	
	return vec;
}

int risiko(std::vector<int> att, std::vector<int> def){
	att = bubble_sort(att);
	def = bubble_sort(def);
	
	int n1 = att.size(), n2 = def.size(), lose = 0,i = 0;
	
	while(n1 > 0 && n2 > 0){
		i++;
		
		std::cout<<"Comparison "<<i<<" :"<<std::endl;
		std::cout<<"ATT("<<att[n1-1]<<") vs. DEF("<<def[n2-1]<<"): ";
		
		if(att[n1-1] > def[n2-1]){
			lose++;
			std::cout<<"DEF loses an army";
		}
		else
			std::cout<<"ATT loses an army";
		n1--;
		n2--;
		
		std::cout<<std::endl;
	}
	
	return lose;
}



int main(){	
	std::vector<int> att,def;
	
	att.push_back(3);
	att.push_back(6);
	att.push_back(4);
	
	def.push_back(2);
	def.push_back(5);
	def.push_back(3);
	
	std::cout<<risiko(att,def);
	

	
	
	
	
	return 0;
}
