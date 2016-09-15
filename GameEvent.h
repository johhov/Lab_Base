#pragma once

//Add new events here and in InputHandler::init()
enum class ActionEnum :int {
    NOACTION = 0,
    MOUSEMOTION,
    QUIT,
    NUMBER_OF_GAME_EVENTS
};

/* This struct deals with an agent creating events.  This has an agent number and the action*/
struct GameEvent {
    int agent;
    ActionEnum action;
};