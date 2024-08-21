const int SUIT = 4;
const int FACE = 13;
const int CARDS = SUIT * FACE;

class DeckOfCards
{
public:
    DeckOfCards();
    void shuffleAndDeal();
    void printCard(const int, const int);
private:
    int deck_[SUIT][FACE];
};

