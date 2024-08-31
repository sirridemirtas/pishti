#pragma once

// When the following events occur, subscribed observers will be notified
enum class PishtiEvent: uint8_t {
    GAME_START, // When the game starts, payload: nullptr
    ROUND_START, // When a round starts, payload: round number
    ROUND_END, // When a round ends, payload: the player who won the round
    THROWN_CARD, // When a player throws a card, payload: the thrown card
    CARDS_COLLECTED, // When a player collects cards from the table, payload: the player
    PISHTI, // When a player makes a pishti, payload: the player
    TURN, // When it is a player's turn, payload: the player
    GAME_OVER, // When the game ends, payload: the player who won the game
};

inline std::string eventToString(PishtiEvent event) {
    switch (event) {
        case PishtiEvent::GAME_START:
            return "GAME_START";
        case PishtiEvent::ROUND_START:
            return "ROUND_START";
        case PishtiEvent::ROUND_END:
            return "ROUND_END";
        case PishtiEvent::THROWN_CARD:
            return "THROWN_CARD";
        case PishtiEvent::CARDS_COLLECTED:
            return "CARDS_COLLECTED";
        case PishtiEvent::PISHTI:
            return "PISHTI";
        case PishtiEvent::TURN:
            return "TURN";
        case PishtiEvent::GAME_OVER:
            return "GAME_OVER";
        default:
            return "INVALID_EVENT";
    }
}
