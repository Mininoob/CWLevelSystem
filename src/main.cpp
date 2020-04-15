#include "CWSDK/cwsdk.h"
#include "main.h"
#include <wchar.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

class Mod : GenericMod {

    void SetLevel(int lvl)
    {
        //Change character's level in the txt file as well as inside the game
    }

    void SetExp(int exp)
    {
        //Change character's level in the txt file as well as inside the game
    }

    virtual int OnChat(std::wstring* message) override {
        // This will be called when the player sends a chat message
        wchar_t* msg = (wchar_t*)message->c_str();

        cube::Game* game = cube::GetGame();
        cube::Host* host = &game->host;
        cube::World* world = &host->world;

        int lvl;
        int exp;

        //Scale exp to lvls
        //probably exponential formula 

        //Commands for testing =
        /*
            /setlvl [int] - Sets user's lvl
            /setexp [int] - Sets user's exp
        */

        if (swscanf_s(msg, L"/setlvl %d",&lvl) == 1)
        {
            SetLevel(lvl);
        }

    }
    virtual void OnGameTick(cube::Game* game) override {
        // This will be called every frame
        //Check if player exp level has changed and save it to file
        //Also display xp bar as well as check if an enemy has been killed and awards exp to players who have attacked the enemy
        //Enemies also have levels that will also scale to the player 

        //Disable certain skills and enable them when character reaches a certain level
        //or make new skills that can be obtained when they lvl

        //Also add sound effect when lvl up and add exp orb effects

    }
    virtual void Initialize() override {
        // This will be called after your mod is loaded. CWSDK internals are initialized at this point, so it's safe to use CWBase() and CWOffset().

        //Create a expStat.txt file to store exp levels or load the stats to character

    }
};

EXPORT Mod* MakeMod() {
    return new Mod();
}