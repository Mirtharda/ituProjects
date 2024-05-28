//--- 2023-2024 Spring BLG 252E Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Selin Yýlmaz
//---Student Number: 150210100
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <fstream>

#include "pokemon.h"

using namespace std;

//-------------Do Not Change These Global Variables-------------//
int NAME_COUNTER = 0;   //Use this to keep track of the enemy names
int POK_COUNTER = 0;    //Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; //You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  //You don't have to use this variable but its here if you need it
//--------------------------------------------------------------//

//---If Necessary Add Your Global Variables Here---// 
// 
//
//
//-------------------------------------------------//

//-------------Do Not Change These Function Definitions-------------//
string* readEnemyNames(const char*);
string* readPokemonNames(const char*);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player*, string*, string*);
void catchPokemon(player*, string*);
//------------------------------------------------------------------//

//---If Necessary Add Your Function Definitions Here---// 
//
//
//
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
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
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
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
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readEnemyNames(const char* argv){
    //---Code Here---//
    int size = 0;
    ifstream enemyFile(argv);
    if (!enemyFile.is_open()) {
        cerr << "ERROR: Could not open file: " << "enemyFiles.txt" << endl;
        return NULL;
    }
    enemyFile >> size;
    string* enemyNames = new string[size];
    for (int i = 0; i < size; ++i) {
        enemyFile >> enemyNames[i];
    }
    enemyFile.close();
    return enemyNames;
    //---------------//   
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readPokemonNames(const char* argv){
    //---Code Here---//
    int size = 0;
    ifstream pokemonFile(argv);
    if (!pokemonFile.is_open()) {
        cerr << "ERROR: Could not open file: " << "pokemonFiles.txt" << endl;
        return NULL;
    }
    pokemonFile >> size;
    string* pokemonNames = new string[size];
    for (int i = 0; i < size; ++i) {
        pokemonFile >> pokemonNames[i];
    }
    pokemonFile.close();
    return pokemonNames;
    //---------------//
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
player characterCreate(string playerName, int pokemonChoice){
    //---Code Here---//
    pokemon newPokemon;
    switch (pokemonChoice) {
    case 1:
        newPokemon = pokemon("Bulbasaur", PLAYER_POKEMON_ATTACK);
        break;
    case 2:
        newPokemon = pokemon("Charmender", PLAYER_POKEMON_ATTACK);
        break;
    case 3:
        newPokemon = pokemon("Squirtle", PLAYER_POKEMON_ATTACK);
        break;
    default:
        cerr << "Invalid pokemon choice." << endl;
        player invalidPlayer;
        return invalidPlayer;
    }
    player newPlayer = player(playerName, newPokemon);
    return newPlayer;

    //---------------//
};
//--------------------------------------------//

//-------------Do Not Change This Function-------------//
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
//-----------------------------------------------------//

//-------------Code This Function-------------//
void fightEnemy(player* newPlayer, string* enemyNames, string* pokemonNames){
    //---Code Here---//
    pokemon nPokemon = pokemon(pokemonNames[POK_COUNTER], PLAYER_POKEMON_ATTACK);
    newPlayer->playerPokedex.updatePokedex(nPokemon);

    const string enemyName = enemyNames[NAME_COUNTER];
    enemy newEnemy=enemy(enemyName, nPokemon);
    int choice = 2;

    //simulate a fight
    cout << "You encounter with " << newEnemy.getName() << " and his / hers pokemon " << nPokemon.getName() << endl;
    cout << nPokemon.getName() << "Health : 100 Attack : 10" << endl;
    cout << "\n1 - Fight \n2 - Runaway \nChoice: ";
    cin >> choice;

    int playerHp = newPlayer->getPokemon().getHpValue();
    int enemyHp = newEnemy.getPokemon().getHpValue();

    while (playerHp != 0 && enemyHp != 0 && choice==1) {
        playerHp = playerHp - ENEMY_POKEMON_ATTACK;
        enemyHp = enemyHp - PLAYER_POKEMON_ATTACK;
        cout << "Your Pokemons Healt: " << playerHp << endl;
        cout << "Misty Pokemons Healt : " << enemyHp << endl;
        
        if (enemyHp == 0) { 
            cout << "You Won!" << endl;
            newPlayer->battleWon();
        } else {
            cout << "\n1 - Fight \n2 - Runaway \nChoice : ";
            cin >> choice;
        }        
    }
    if (POK_COUNTER == 5) { POK_COUNTER = 0; }
    else { POK_COUNTER += 1; }
    if (NAME_COUNTER == 4) { NAME_COUNTER = 0; }
    else { NAME_COUNTER += 1; }
    return;
    //---------------//
};
//--------------------------------------------//

//-------------Code This Function-------------//
void catchPokemon(player* newPlayer, string* pokemonNames){
    //---Code Here---//
    pokemon nPokemon = pokemon(pokemonNames[POK_COUNTER], PLAYER_POKEMON_ATTACK);
    newPlayer->playerPokedex.updatePokedex(nPokemon);

    int choice = 2;
    cout << "You encounter with " << nPokemon.getName() << " Health: 100 Attack : 10" << endl;
    cout << "\n1 - Catch \n2 - Runaway \nChoice : ";
    cin >> choice;

    if (choice == 1) {
        newPlayer->catchPokemon();        
    }
    if (POK_COUNTER == 5) { POK_COUNTER = 0; }
    else { POK_COUNTER += 1; }
    //---------------//
};
//--------------------------------------------//
