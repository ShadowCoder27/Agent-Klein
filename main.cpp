#include <bits/stdc++.h>

using ll = long long;

const int NumberOfLevels = 3;
const int CardsOnRow = 4;
const int NumberOfColors = 5;
const int MaxCards = 90;

class Board
{
  int NumberOfPlayers;
  int PlayerID;
  int RoundNumber;
  int CounterGemStack;
  int CounterGoldStack;
  int CounterLevelOneCards;
  int Cards[NumberOfLevels];
  int CounterNobles;
  int Nobles;

  void InputRead()
  {
    CounterGemStack = 0;
    CounterLevelOneCards = 0;
    Nobles = 0;
    for (int i = 0; i < CardsOnRow; ++i)
    {
      Cards[i] = 0;
    }

    std::cin >> NumberOfPlayers;
    std::cin >> PlayerID;
    std::cin >> RoundNumber;
    int position = 1;
    for (int i = 0; i < NumberOfColors; ++i)
    {
      int val;
      std::cin >> val;
      CounterGemStack = val * position;
      position *= 10;
    }
    std::cin >> CounterGoldStack;
    std::cin >> CounterLevelOneCards;
    position = 1;
    for (int i = 0; i < NumberOfLevels; ++i)
    {
      for (int j = 0; j < CardsOnRow; ++j)
      {
        int val;
        std::cin >> val;
        Cards[i] += val * position;
        position *= 100;
      }
    }
    std::cin >> CounterNobles;
    position = 1;
    for (int i = 0; i < CounterNobles; ++i)
    {
      int val;
      std::cin >> val;
      Nobles += val * position;
      position *= 100;
    }
  }
};

class Player
{
  int CounterGemStack;
  int CounterGoldStack;
  int CounterCards;
  int Card[MaxCards];
  int CounterReservedCards;
  int ReservedCards;
  int CounterNobles;
  int Nobles;

  void InputRead()
  {
    CounterGemStack = 0;
    ReservedCards = 0;
    Nobles = 0;

    int position = 1;
    for (int i = 0; i < NumberOfColors; ++i)
    {
      int val;
      std::cin >> val;
      CounterGemStack += val * position;
      position *= 10;
    }
    std::cin >> CounterGoldStack;
    std::cin >> CounterCards;
    for (int i = 0; i < CounterCards; ++i)
    {
      std::cin >> Card[i];
    }
    std::cin >> CounterReservedCards;
    position = 1;
    for (int i = 0; i < CounterReservedCards; ++i)
    {
      int val;
      std::cin >> val;
      if (val > 0)
      {
        ReservedCards += val * position;
        position *= 100;
      }
    }
    std::cin >> CounterNobles;
    position = 1;
    for (int i = 0; i < CounterNobles; ++i)
    {
      int val;
      std::cin >> val;
      Nobles += val * position;
      position *= 10;
    }
  }
};

int main()
{

}
