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

#include "pokemon.h"

using namespace std;

//-------------You Can Add Your Functions Down Below-------------//
pokemon::pokemon() {
	name = "";
	hpValue = 0;
	atkValue = 0;
}

pokemon::pokemon(string name, int atkValue) {
	//set default pokemon hp to 100
	this->name = name;
	this->atkValue = atkValue;
	this->hpValue = 100;
}

pokemon::pokemon(const pokemon& original_pokemon) 
	: name{ original_pokemon.name }, hpValue{original_pokemon.hpValue}, atkValue{original_pokemon.atkValue}
{}

string pokemon::getName() const{return name;}
int pokemon::getHpValue() {return hpValue = this->hpValue;}
int pokemon::getAtkValue() {return atkValue = this->atkValue;}


pokedex::pokedex() {
	this->value = 0;
}

//add new pokemons to dex
//check for duplicates
void pokedex::updatePokedex(const pokemon& newPokemon) {
	for (int i = 0; i < value; i++) {
		if (pokedexArray[i].getName() == newPokemon.getName()) {
			//cout << newPokemon.getName() << " is already in the Pokedex." << endl;
			return;
		}
	}

	pokedexArray[value++] = newPokemon;
	//cout << newPokemon.getName() << " added to the Pokedex." << endl;
	//check these comment lines from calico file
}

void pokedex::printPokedex() const {
	for (int i = 0; i < value; i++) {
		cout << pokedexArray[i].getName() << endl;
	}
}


player::player() {
	name = "";
	pokemonNumber = 0;
	pokeballNumber = 0;
	badgeNumber = 0;
	playerPokemon = pokemon();
	playerPokedex = pokedex();
}
player::player(const string newName, pokemon& newPokemon) {
	name = newName;
	pokemonNumber = 0;
	pokeballNumber = 10;
	badgeNumber = 0;
	playerPokemon = newPokemon;
	//playerPokedex.updatePokedex(newPokemon);
}

int player::showPokemonNumber() const {return pokemonNumber;}
int player::showPokeballNumber() const {return pokeballNumber;}
int player::showBadgeNumber() const {return badgeNumber;}
pokemon player::getPokemon() {return playerPokemon;}

//method to update badgeNumber and pokeballNumber
void player::battleWon() {
	//everytime you win a battle badgeNumber++, pokeballNumber+3
	badgeNumber += 1;
	pokeballNumber += 3;
}

//method update your pokemonNumber and pokeballNumber
void player::catchPokemon() {
	//everytime you catch a pokemon pokemonNumber+1, pokeballNumber-1
	pokemonNumber += 1;
	pokeballNumber -= 1;
}

enemy::enemy() {
	name = "";
	enemyPokemon = pokemon();
}
enemy::enemy(const string enemyName, pokemon& Pokemon) {
	name = enemyName;
	enemyPokemon = Pokemon;
}

pokemon enemy::getPokemon() {return enemyPokemon;}
string enemy::getName() const {return name;}