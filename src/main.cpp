#include "CWSDK/cwsdk.h"

class Mod : GenericMod {
    virtual int OnChat(std::wstring* message) override {
        // This will be called when the player sends a chat message
    }
    virtual void OnGameTick(cube::Game* game) override {
        // This will be called every frame
    }
    virtual void Initialize() override {
        // This will be called after your mod is loaded. CWSDK internals are initialized at this point, so it's safe to use CWBase() and CWOffset().
    }
};

EXPORT Mod* MakeMod() {
    return new Mod();
}