//--------------------------//
//---Name & Surname: İlke Başak Baydar
//---Student Number: 150140709
//--------------------------//

#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <fstream>

#include "pokemon.h"

using namespace std;

int NAME_COUNTER = 0;   //Use this to keep track of the enemy names
int POK_COUNTER = 0;    //Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; //You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  //You don't have to use this variable but its here if you need it


string* readEnemyNames(const char*);
string* readPokemonNames(const char*);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player*, string*, string*);
void catchPokemon(player*, string*);


int main(int argc, char* argv[]){
	system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string* enemyNames = readEnemyNames(argv[1]);         
    string* pokemonNames = readPokemonNames(argv[2]);
    

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n" << endl;
    cout << "Please enter your name: "; 
    cin >> playerName;
    cout << "Please choose one of these Pokemons as your Pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);
    
    int menuChoice;

    while(true){
        mainMenu(); 
        cin>>menuChoice;

        switch (menuChoice){
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout<<newPlayer.showPokemonNumber()<<endl;
            break;
        case 4:
            cout<<newPlayer.showPokeballNumber()<<endl;
            break;
        case 5:
            cout<<newPlayer.showBadgeNumber()<<endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" <<endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;
  
        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};

string* readEnemyNames(const char* argv){
    
    ifstream file(argv);
    string line;
    getline(file,line)
    int numOfEnemy = stoi(line);
    string* enemies;
    enemies = new string[numOfEnemy];
    for(int i = 0;i < numOfEnemy;i++){
        getline(file,line);
        enemies[i] = line;
    }
    file.close();  
    return enemies;
};

string* readPokemonNames(const char* argv){

    ifstream file(argv);
    string line;
    getline(file,line)
    int numOfPokemon = stoi(line);
    string* pokemons;
    enemies = new string[numOfPokemon];
    for(int i = 0;i < numOfPokemon;i++){
        getline(file,line);
        pokemons[i] = line;
    }
    file.close();  
    return pokemons; 
};

player characterCreate(string playerName, int pokemonChoice){
    // 1- Bulbasaur \n2- Charmender \n3- Squirtle \n
    if(pokemonChoice == 1){
        pokemon Bulb("Bulbasaur",20);
        player p(playerName,Bulb);
        return p;
    }else if(pokemonChoice == 2){
        pokemon Charm("Charmender",20);
        player p(playerName,Charm);
        return p;
    }else{
        pokemon Squi("Squirtle",20);
        player p(playerName,Squi);
        return p;
    }
};

void mainMenu(){
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs " << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};

void fightEnemy(player* newPlayer, string* enemyNames, string* pokemonNames){
    (*newPlayer).setfullhp();
    srand(time(0));
    int size = *(&enemyNames + 1) - enemyNames;
    int index = rand()%size;
    string enemyname = enemyNames[index]; 
    size = *(&pokemonNames + 1) - pokemonNames;
    index = rand()%size;
    string hisherpokemon = pokemonNames[index];
    pokemon enemypokemon(hisherpokemon,10); // set attack value 10 for enemy by default
    enemy funenemy(enemyname,enemypokemon);
    cout<<"You encounter with "<<enemyname<<" and his/hers pokemon "<<hisherpokemon<<endl;
    cout<<enemypokemon.getname()<<" Health: "<<enemypokemon.getatkval()<<endl;
    cout<<endl;

    int choice;
    while(funenemy.getPokemon().gethpval() > 0 and (*newPlayer).getPokemon().gethpval() > 0){
        cout<<"1- Fight"<<endl;
        cout<<"2- Runaway"<<endl;
        cout<<"Choice: ";
        cin>>choice;
        if(choice != 1){
          return;
        }
        funenemy.getDamage((*newPlayer).getPokemon().getatkval());
        (*newPlayer).getDamage(funenemy.getPokemon().getatkval());
        cout<<"Your Pokemon's Health: "<<(*newPlayer).getPokemon().gethpval()<<endl;
        cout<<funenemy.getName()<<" Pokemon's Health: "<<funenemy.getPokemon().gethpval()<<endl; 
    }
    if(funenemy.getPokemon().gethpval() <= 0){
        cout<<"You Won!"<<endl;
        (*newPlayer).battleWon();
        (*newPlayer).setfullhp();
    }else{
        cout<<"You Lose!"<<endl;
        (*newPlayer).setfullhp();
    }
};

void catchPokemon(player* newPlayer, string* pokemonNames){
    cout<<"You encounter with "<<pokemonNames[POK_COUNTER]<<" Health: "<<100<<" Attack: "<<PLAYER_POKEMON_ATTACK<<endl;
    pokemon newpoke(pokemonNames[POK_COUNTER],PLAYER_POKEMON_ATTACK);
    cout<<"1- Catch"<<endl;
    cout<<"2- Runaway"<<endl;
    int choice;
    cout<<"Choice: ";
    cin>>choice;
    if(choice != 1){
        return;
    }
    cout<<"You catch "<<pokemonNames[POK_COUNTER]<<endl;   
    POK_COUNTER++;
    (*newPlayer).playerPokedex.updatePokedex(newpoke);
};
