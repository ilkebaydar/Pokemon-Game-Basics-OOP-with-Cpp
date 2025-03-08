//--------------------------//
//---Name & Surname: İlke Başak Baydar
//---Student Number: 150140709
//--------------------------//


#include <iostream>
#include <stdio.h>
#include <string.h>

#include "pokemon.h"

using namespace std;


pokemon::pokemon(string n, int a_val){
	this->name = n;
	this->atkValue = a_val;
	this->hpValue = 100;
}
pokemon::pokemon(pokemon p){
	this->name = p.getname();
	this->hpValue = p.gethpval();
	this->atkValue = p.getatkval();
}
string pokemon::getname(){return this->name;}
int pokemon::gethpval(){return this->hpValue;}
int pokemon::getatkval(){return this->atkValue;}
void pokemon::setname(string n){this->name = n;}
void pokemon::sethpval(int h){this->hpValue = h;}
void pokemon::setatkval(int a){this->atkValue = a;}


void pokedex::updatePokedex(pokemon p){
	if(value == 0){
		pokedexArray[0].setname(p.getname());
		pokedexArray[0].sethpval(p.gethpval());
		pokedexArray[0].setatkval(p.getatkval());
		value++;
		return;
	}
	for(int i = 0; i < value;i++){
		if(pokedexArray[i].getname() == p.getname()){
			return;
		}
	}
	pokedexArray[value].setname(p.getname());
	pokedexArray[value].sethpval(p.gethpval());
	pokedexArray[value].setatkval(p.getatkval());
	value++;	
}
void pokedex::printPokedex(){
	if(value == 0){return;}
	for(int i = 0; i < value;i++){
		cout<<pokedexArray[i].getname()<<endl;
	}
}


player::player(string n,pokemon p){
	this->name = n;
	this->playerPokemon.setname(p.getname());
	this->playerPokemon.sethpval(p.gethpval());
	this->playerPokemon.setatkval(p.getatkval());
}

enemy::enemy(string n, pokemon p){
	this->name = n;
	this->enemyPokemon.setname(p.getname());
	this->enemyPokemon.sethpval(p.gethpval());
	this->enemyPokemon.setatkval(p.getatkval());
}
