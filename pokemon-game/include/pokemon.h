
//--------------------------//
//---Name & Surname: İlke Başak Baydar
//---Student Number: 150140709
//--------------------------//

#ifndef _H
#define _H

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


class pokemon{
    private:
        string name;
        int hpValue;
        int atkValue;
    public:
        pokemon() = default;
        pokemon(string n ,int a_val);
        pokemon(pokemon p);
        void setname(string n);
        void sethpval(int h);
        void setatkval(int a);
        string getname();
        int gethpval();
        int getatkval();
};

class pokedex{
    private:
        pokemon pokedexArray[100];
        int value;
    public:
       pokedex(){this->value = 0;}
       void updatePokedex(pokemon p);
       void printPokedex();
};

class player{
    private:
        string name;
        int pokemonNumber;
        int pokeballNumber;
        int badgeNumber;
        pokemon playerPokemon;
    public:
        player() = default;
        player(string n,pokemon p);
        pokedex playerPokedex;
        int showPokemonNumber(){return this->pokemonNumber;}
        int showPokeballNumber(){return this->pokeballNumber;}
        int showBadgeNumber(){return this->badgeNumber;}
        pokemon getPokemon(){return this->playerPokemon;}
        void battleWon(){
            badgeNumber++;
            pokeballNumber = pokeballNumber + 3;
        }
        void catchPokemon(){
            pokemonNumber++;
            pokeballNumber--;
        }
        void getDamage(int damage){
            playerPokemon.sethpval(playerPokemon.gethpval()- damage);
        }
        void setfullhp(){
            playerPokemon.sethpval(100);
        }
};

class enemy{
    private:
        string name;
        pokemon enemyPokemon;
    public:
        enemy() = default;
        enemy(string n, pokemon p);
        pokemon getPokemon(){return this->enemyPokemon;}
        string getName(){return this->name;}
        void getDamage(int damage){
            enemyPokemon.sethpval(enemyPokemon.gethpval()- damage);
        }
        void setfullhp(){
            enemyPokemon.sethpval(100);
        }
};

#endif
