#include <iostream>
using namespace std;
#include<list>
#include <cstdlib> // For rand()
#include <ctime>   // For time()
#include <vector>


class Moves {
public:
    string moveName; //Name of the move
    int power; //Base power of the move
    string type; //Typing of the move


    Moves(string move, int movePower, string moveType) //Constructor
        : moveName(move), power(movePower), type(moveType) {}

};

class Pokemon {
public:
    string name;
    int currHp;
    int maxHp;
    string type;
    std::vector<Moves> move;

    // Constructor
    Pokemon(string pokemonName, int pokemonCurrHp, int pokemonMaxHp, string pokemonType, vector<Moves> pokemonMoves)
        : name(pokemonName), currHp(pokemonCurrHp), maxHp(pokemonMaxHp), type(pokemonType), move(pokemonMoves) {}

    //Move randomizer
    Moves useRandomMove() const {
        int randomIndex = rand() % move.size();
        return move[randomIndex];
    }

    //Take damage function
    void takeDmg(int damage) {
        currHp -= damage;
        if (currHp < 0) currHp = 0;
        cout << name << " took " << damage << " damage." << endl;
        cout << "HP | " << currHp << "/" << maxHp << endl;
    }
    bool isDefeated() const {
        return currHp <=0;
    }

};

    vector<Pokemon> getOpponentPokemon() {
    return {
        Pokemon("Arceus", 200, 200, "Normal", {
            Moves("Punishment", 80, "Dark"),
            Moves("Judgement", 100, "Normal"),
            Moves("Zen Headbutt", 80, "Psychic"),
            Moves("Earth Power", 80, "Ground")
        }),
        Pokemon("Giratina", 200, 200, "Normal", {
            Moves("Punishment", 80, "Dark"),
            Moves("Judgement", 100, "Normal"),
            Moves("Zen Headbutt", 80, "Psychic"),
            Moves("Earth Power", 80, "Ground")
        }),
        Pokemon("Palkia", 200, 200, "Normal", {
            Moves("Punishment", 80, "Dark"),
            Moves("Judgement", 100, "Normal"),
            Moves("Zen Headbutt", 80, "Psychic"),
            Moves("Earth Power", 80, "Ground")
        }),
        Pokemon("Dialga", 200, 200, "Normal", {
            Moves("Punishment", 80, "Dark"),
            Moves("Judgement", 100, "Normal"),
            Moves("Zen Headbutt", 80, "Psychic"),
            Moves("Earth Power", 80, "Ground")
        }),
        Pokemon("Reshiram", 200, 200, "Normal", {
            Moves("Punishment", 80, "Dark"),
            Moves("Judgement", 100, "Normal"),
            Moves("Zen Headbutt", 80, "Psychic"),
            Moves("Earth Power", 80, "Ground")
        }),
        Pokemon("Zekrom", 200, 200, "Normal", {
            Moves("Punishment", 80, "Dark"),
            Moves("Judgement", 100, "Normal"),
            Moves("Zen Headbutt", 80, "Psychic"),
            Moves("Earth Power", 80, "Ground")
        }),
    };
}



/* Old sample code, decided to use a vector instead of list and add more details to moves
Pokemon getRandomOpponent() {
    srand(time(0));

    list<Pokemon> opponents = {
        Pokemon("Arceus", 135, 188, 75, {"Punishment", "Judgement", "Zen Headbutt", "Earth Power"}),
        Pokemon("Giratina", 135, 188, 75, {"Punishment", "Judgement", "Zen Headbutt", "Earth Power"}),
        Pokemon("Palkia", 135, 188, 75, {"Punishment", "Judgement", "Zen Headbutt", "Earth Power"}),
        Pokemon("Dialga", 135, 188, 75, {"Punishment", "Judgement", "Zen Headbutt", "Earth Power"}),
        Pokemon("Pikachu", 135, 188, 75, {"Punishment", "Judgement", "Zen Headbutt", "Earth Power"}),
    };
     // Pick a random opponent
    int index = rand() % opponents.size();
    return opponents[index];
}*/

int main() {
    int exp = rand() % 10000;
    srand(static_cast<unsigned int>(time(0)));  // Seed random number generator

    //Defining player
    Pokemon player("Togepi", 200, 200, "Normal", {
        Moves("Metronome", 50, "Normal")
    });

    //grabbing list of possible enemies
    vector<Pokemon> enemyPokemonList = getOpponentPokemon();

    //picking random enemy
    Pokemon enemy = enemyPokemonList[rand() % enemyPokemonList.size()];
    cout << "A wild " << enemy.name << " appeared!" << endl;

    //Start battle
    //Using the boolean function to basically say while enemy isnt defeated and while player isnt defeated
    while(!enemy.isDefeated() && !player.isDefeated()) {
        Moves playerMove = player.useRandomMove();
        cout << player.name << " used " << playerMove.moveName << "!" << endl;

        //Using the damage function. Will print the void message as well
        enemy.takeDmg(playerMove.power);

        //Check for enemy defeat
        if (enemy.isDefeated()) {
            cout << enemy.name << " Has fled!" << endl;
            cout << "You have gained " << exp << "exp" << endl;
            if (exp > 100 && exp < 999) {
                cout << "Togepi has Leveled up!" << endl;
            }
            else if (exp > 1000) {
                cout << "huh!" << endl;
                cout << " " << endl;
                cout << "Togepi is evolving..." << endl;
                cout << "Togepi has evolved into Togetic!" << endl;
            }
            break;
        };


        int skipTurn = rand() % 100;
            if(skipTurn < 30) {
                cout << enemy.name << " Stares at you menacingly..." << endl;
            }
            else {
                Moves enemyMove = enemy.useRandomMove();
                cout << enemy.name << " used " << enemyMove.moveName << "!" << endl;

                player.takeDmg(enemyMove.power);

            }

        if (player.isDefeated()) {
            cout << player.name << " has fainted..." << endl;
            cout << "you dropped 57600p fleeing to safety" << endl;
            break;
        };




    }

    

    return 0;
}