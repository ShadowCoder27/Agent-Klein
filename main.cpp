#include <bits/stdc++.h>

using ll = long long;

#define MaxReserved 3
#define NumberOfLevels 3
#define CardsOnRow 4
#define NumberOfColors 5
#define NobleData 5
#define CardBonus 5
#define MaxNobles 6
#define TotalCardData 7
#define TotalNobles 10
#define MaxMoves 39
#define MaxCards 90

const int CardsData[MaxCards][TotalCardData] =
{
 { 0, 0, 0, 3, 0, 0, 0 },
 { 3, 0, 0, 0, 0, 1, 0 },
 { 0, 0, 0, 0, 3, 2, 0 },
 { 0, 0, 3, 0, 0, 3, 0 },
 { 0, 3, 0, 0, 0, 4, 0 },
 { 0, 1, 2, 0, 0, 0, 0 },
 { 0, 0, 1, 2, 0, 1, 0 },
 { 0, 0, 0, 1, 2, 2, 0 },
 { 2, 0, 0, 0, 1, 3, 0 },
 { 1, 2, 0, 0, 0, 4, 0 },
 { 0, 0, 0, 4, 0, 0, 1 },
 { 0, 0, 0, 0, 4, 1, 1 },
 { 4, 0, 0, 0, 0, 2, 1 },
 { 0, 4, 0, 0, 0, 3, 1 },
 { 0, 0, 4, 0, 0, 4, 1 },
 { 2, 0, 0, 2, 0, 0, 0 },
 { 2, 0, 2, 0, 0, 1, 0 },
 { 0, 2, 0, 0, 2, 2, 0 },
 { 0, 0, 2, 0, 2, 3, 0 },
 { 0, 2, 0, 2, 0, 4, 0 },
 { 0, 1, 1, 1, 1, 0, 0 },
 { 1, 0, 1, 1, 1, 1, 0 },
 { 1, 1, 0, 1, 1, 2, 0 },
 { 1, 1, 1, 0, 1, 3, 0 },
 { 1, 1, 1, 1, 0, 4, 0 },
 { 0, 1, 1, 2, 1, 0, 0 },
 { 1, 0, 1, 1, 2, 1, 0 },
 { 2, 1, 0, 1, 1, 2, 0 },
 { 1, 2, 1, 0, 1, 3, 0 },
 { 1, 1, 2, 1, 0, 4, 0 },
 { 0, 1, 0, 2, 2, 0, 0 },
 { 2, 0, 1, 0, 2, 1, 0 },
 { 2, 2, 0, 1, 0, 2, 0 },
 { 0, 2, 2, 0, 1, 3, 0 },
 { 1, 0, 2, 2, 0, 4, 0 },
 { 1, 0, 0, 1, 3, 0, 0 },
 { 0, 1, 3, 1, 0, 1, 0 },
 { 1, 3, 1, 0, 0, 2, 0 },
 { 0, 0, 1, 3, 1, 3, 0 },
 { 3, 1, 0, 0, 1, 4, 0 },
 { 0, 0, 0, 0, 5, 0, 2 },
 { 0, 5, 0, 0, 0, 1, 2 },
 { 0, 0, 5, 0, 0, 2, 2 },
 { 5, 0, 0, 0, 0, 3, 2 },
 { 0, 0, 0, 5, 0, 4, 2 },
 { 6, 0, 0, 0, 0, 0, 3 },
 { 0, 6, 0, 0, 0, 1, 3 },
 { 0, 0, 6, 0, 0, 2, 3 },
 { 0, 0, 0, 6, 0, 3, 3 },
 { 0, 0, 0, 0, 6, 4, 3 },
 { 0, 0, 0, 3, 5, 0, 2 },
 { 0, 3, 5, 0, 0, 1, 2 },
 { 0, 0, 3, 5, 0, 2, 2 },
 { 5, 0, 0, 0, 3, 3, 2 },
 { 3, 5, 0, 0, 0, 4, 2 },
 { 0, 2, 4, 1, 0, 0, 2 },
 { 0, 0, 2, 4, 1, 1, 2 },
 { 1, 0, 0, 2, 4, 2, 2 },
 { 4, 1, 0, 0, 2, 3, 2 },
 { 2, 4, 1, 0, 0, 4, 2 },
 { 2, 0, 0, 2, 3, 0, 1 },
 { 0, 0, 3, 2, 2, 1, 1 },
 { 3, 2, 2, 0, 0, 2, 1 },
 { 2, 3, 0, 0, 2, 3, 1 },
 { 0, 2, 2, 3, 0, 4, 1 },
 { 2, 0, 3, 0, 3, 0, 1 },
 { 3, 2, 0, 3, 0, 1, 1 },
 { 0, 3, 2, 0, 3, 2, 1 },
 { 3, 0, 3, 2, 0, 3, 1 },
 { 0, 3, 0, 3, 2, 4, 1 },
 { 0, 7, 0, 0, 0, 0, 4 },
 { 0, 0, 7, 0, 0, 1, 4 },
 { 0, 0, 0, 7, 0, 2, 4 },
 { 0, 0, 0, 0, 7, 3, 4 },
 { 7, 0, 0, 0, 0, 4, 4 },
 { 3, 7, 0, 0, 0, 0, 5 },
 { 0, 3, 7, 0, 0, 1, 5 },
 { 0, 0, 3, 7, 0, 2, 5 },
 { 0, 0, 0, 3, 7, 3, 5 },
 { 7, 0, 0, 0, 3, 4, 5 },
 { 3, 6, 3, 0, 0, 0, 4 },
 { 0, 3, 6, 3, 0, 1, 4 },
 { 0, 0, 3, 6, 3, 2, 4 },
 { 3, 0, 0, 3, 6, 3, 4 },
 { 6, 3, 0, 0, 3, 4, 4 },
 { 0, 3, 5, 3, 3, 0, 3 },
 { 3, 0, 3, 5, 3, 1, 3 },
 { 3, 3, 0, 3, 5, 2, 3 },
 { 5, 3, 3, 0, 3, 3, 3 },
 { 3, 5, 3, 3, 0, 4, 3 },
};

const int NoblesData[TotalNobles][NobleData] =
{
  { 4, 4, 0, 0, 0 },
  { 0, 4, 4, 0, 0 },
  { 0, 0, 4, 4, 0 },
  { 0, 0, 0, 4, 4 },
  { 4, 0, 0, 0, 4 },
  { 3, 3, 3, 0, 0 },
  { 0, 3, 3, 3, 0 },
  { 0, 0, 3, 3, 3 },
  { 3, 0, 0, 3, 3 },
  { 3, 3, 0, 0, 3 },
};
   
struct board
{
  int NumberOfPlayers;
  int PlayerID;
  int RoundNumber;
  int CounterGemStack[NumberOfColors];
  int CounterGoldStack;
  int CounterLevelOneCards;
  int Card[NumberOfLevels][CardsOnRow];
  int CounterNobles;
  int Nobles[MaxNobles];

  void InputRead()
  {
    std::cin >> NumberOfPlayers;
    std::cin >> PlayerID;
    std::cin >> RoundNumber;
    for (int i = 0; i < NumberOfColors; ++i)
    {
      std::cin >> CounterGemStack[i];
    }
    std::cin >> CounterGoldStack;
    std::cin >> CounterLevelOneCards;
    for (int i = 0; i < NumberOfLevels; ++i)
    {
      for (int j = 0; j < CardsOnRow; ++j)
      {
        std::cin >> Card[i][j];
      }
    }
    std::cin >> CounterNobles;
    for (int i = 0; i < CounterNobles; ++i)
    {
      std::cin >> Nobles[i];
    }
  }
}Board;

struct player
{
  int CounterGemStack[NumberOfColors];
  int CounterGoldStack;
  int CounterCards;
  int Card[MaxCards];
  int CounterReservedCards;
  int ReservedCards[MaxReserved];
  int CounterNobles;
  int Nobles[MaxNobles];
  int CounterCardGem[NumberOfColors];

  void InputRead()
  {
    for (int i = 0; i < NumberOfColors; ++i)
    {
      std::cin >> CounterGemStack[i];
    }
    std::cin >> CounterGoldStack;
    std::cin >> CounterCards;
    for (int i = 0; i < CounterCards; ++i)
    {
      std::cin >> Card[i];
    }
    std::cin >> CounterReservedCards;
    for (int i = 0; i < CounterReservedCards; ++i)
    {
      std::cin >> ReservedCards[i];
    }
    std::cin >> CounterNobles;
    for (int i = 0; i < CounterNobles; ++i)
    {
      std::cin >> Nobles[i];
    }
  }
  void CountCardGems()
  {
    for (int i = 0; i < CounterCards; ++i)
    {
      ++CounterCardGem[CardsData[Card[i]][CardBonus]];
    }
  }
}Player;

struct move
{
  std::string Moves[MaxMoves];
  int CounterMoves;
  
  bool CanBuyCard(int CardID)
  {
    int GoldLeft = Player.CounterGoldStack;
    for (int i = 0; i < TotalCardData; ++i)
    {
      if (Player.CounterCardGem[i] + Player.CounterGemStack[i] + GoldLeft < CardsData[CardID][i])
      {
        return false;
      }
      if (Player.CounterCardGem[i] + Player.CounterGemStack[i] < CardsData[CardID][i])
      {
	GoldLeft -= CardsData[CardID][i] - Player.CounterCardGem[i] - Player.CounterGemStack[i];
      }
    }
    return true;
  }
  void GenerateAllMoves()
  {
    CounterMoves = 0;
    for (int i = 0; i < NumberOfColors; ++i)
    {
      for (int j = i + 1; j < NumberOfColors; ++j)
      {
        for (int k = j + 1; k < NumberOfColors; ++k)
        {
            if (Board.CounterGemStack[i] && Board.CounterGemStack[j] && Board.CounterGemStack[k])
            {
              Moves[CounterMoves++] = "1 " + std::to_string(i) + " " + std::to_string(j) + " " + std::to_string(k);
            }
        }
      }
    }
    for (int i = 0; i < NumberOfColors; ++i)
    {
      if (Board.CounterGemStack[i])
      {
        Moves[CounterMoves++] = "2 " + std::to_string(i);
      }
    }
    for (int i = 0; i < NumberOfLevels; ++i)
    {
      for (int j = 0; j < CardsOnRow; ++j)
      {
        if (Board.Card[i][j] && Player.CounterReservedCards != 3)
        {
          Moves[CounterMoves++] = "3 " + std::to_string(Board.Card[i][j]);
        }
      }
    }
    for (int i = 0; i < NumberOfLevels; ++i)
    {
      for (int j = 0; j < CardsOnRow; ++j)
      {
        if (Board.Card[i][j] && CanBuyCard(Board.Card[i][j]))
        {
          Moves[CounterMoves++] = "4 " + std::to_string(Board.Card[i][j]);
        }
      }
    }
  }
  void PickMove()
  {
    srand(time(0));
    std::cout << Moves[rand() % CounterMoves];
  }
  void Take3(int color1, int color2, int color3)
  {
    std::cout << "1 "  << color1 << ' ' << color2 << ' ' << color3 << '\n';
  }
  void Take2(int color)
  {
    std::cout << "2 "  << color << '\n';
  }
  void Reserve(int card)
  {
    std::cout << "3 " << card << '\n';
  }
  void Buy(int card)
  {
    std::cout << "4 " << card << '\n';
  }
}Move;

int main()
{
  Board.InputRead();
  Player.InputRead();
  Move.GenerateAllMoves();
  Move.PickMove();
}
