#include "../include/Deck.h"
#include "../include/CardFactory.h"

// Add all 52 cards to the deck
Deck::Deck() {
    CardFactory &factory = CardFactory::getInstance();

    for (int suit = static_cast<int>(Suit::HEARTS); suit <= static_cast<int>(Suit::SPADES); ++suit) {
        for (int rank = static_cast<int>(Rank::ACE); rank <= static_cast<int>(Rank::KING); ++rank) {
            addCard(factory.getCard(static_cast<Suit>(suit), static_cast<Rank>(rank)));
        }
    }
}
