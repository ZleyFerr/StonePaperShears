#include <iostream>
#include <cstdlib>

int main()
{
    setlocale(LC_ALL, "Ru");

    int tryes = 0;
    std::cout << "Количество попыток = ";
    std::cin >> tryes;

    int randomNumber = 0, randomNumber2 = 0;
    float Player1Win = 0, Player2Win = 0, Draw = 0;
    int tryNumber = 0;
    int maxWinsPlayer1 = 0, maxWinsPlayer2 = 0, maxWinsDraw = 0;
    int winStreakP1 = 0, winStreakP2 = 0, winStreakDraw = 0;

    for (int i = 0; i < tryes; i++)
    {
        int randomNumber = (rand() % 3) + 1;
        int randomNumber2 = (rand() % 3) + 1;
        tryNumber++;

        if (randomNumber == randomNumber2)
        {
            Draw++;
            std::cout << "Ничья." << std::endl << tryNumber << std::endl;
            winStreakDraw++;
            winStreakP2 = 0;
            winStreakP1 = 0;
        }
        if ((randomNumber == 1 && randomNumber2 == 2) || (randomNumber == 3 && randomNumber2 == 1) || (randomNumber == 2 && randomNumber2 == 3))
        {
            Player1Win++;
            std::cout << "Игрок 1 победил." << std::endl << tryNumber << std::endl;
            winStreakDraw = 0;
            winStreakP2 = 0;
            winStreakP1++;
        }
        if ((randomNumber == 2 && randomNumber2 == 1) || (randomNumber == 1 && randomNumber2 == 3) || (randomNumber == 3 && randomNumber2 == 2))
        {
            Player2Win++;
            std::cout << "Игрок 2 победил." << std::endl << tryNumber << std::endl;
            winStreakDraw = 0;
            winStreakP2++;
            winStreakP1 = 0;
        }
        if (maxWinsDraw < winStreakDraw) 
            maxWinsDraw = winStreakDraw; 

        if (maxWinsPlayer1 < winStreakP1)
            maxWinsPlayer1 = winStreakP1;

        if (maxWinsPlayer2 < winStreakP2)
            maxWinsPlayer2 = winStreakP2;
    }

    float player1Winrate = Player1Win / tryes * 100;
    float player2Winrate = Player2Win / tryes * 100;
    float drawWinrate = Draw / tryes * 100;

    float WinrateRaznica1 = player1Winrate - player2Winrate;
    float WinrateRaznica2 = player2Winrate - player1Winrate;
    float WinrateRaznica3 = drawWinrate - player1Winrate;
    float WinrateRaznica4 = drawWinrate - player2Winrate;

    std::cout << "-----------------------------------------------" << std::endl <<
        "Количество ничей: " << Draw << std::endl <<
        "Количество побед игрока 1: " << Player1Win << std::endl <<
        "Количество побед игрока 2: " << Player2Win << std::endl <<
        "-----------------------------------------------" << std::endl <<
        "Винрейт игрока 1: " << player1Winrate << "%" << std::endl <<
        "Винрейт игрока 2: " << player2Winrate << "%" << std::endl <<
        "Винрейт ничьи: " << drawWinrate << "%" << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;

    if (player1Winrate > player2Winrate) 
        std::cout << "Игрок 1 выигрывает на " << WinrateRaznica1 << "% чаще чем игрок 2" << std::endl;

    if (player2Winrate > player1Winrate)
        std::cout << "Игрок 2 выигрывает на " << WinrateRaznica2 << "% чаще чем игрок 1" << std::endl;
    if (player2Winrate == player1Winrate)
        std::cout << "Игрок 1 и игрок 2 имеют одинаквый винрейт" << std::endl;

    if ((drawWinrate > player1Winrate) && (drawWinrate > player2Winrate))
    {
        std::cout << "Ничья выигрывает чаще на " << WinrateRaznica3 << "% чаще чем игрок 1" << std::endl;
        std::cout << "Ничья выигрывает чаще на " << WinrateRaznica4 << "% чаще чем игрок 2" << std::endl;
    }

    if (player2Winrate == player1Winrate && player1Winrate == drawWinrate && player2Winrate == drawWinrate)
        std::cout << "Винрейты ничьи и обоих игроков одинаковы" << std::endl;

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Стрик побед ничьи: " << maxWinsDraw << std::endl;
    std::cout << "Стрик побед игрока 1: " << maxWinsPlayer1 << std::endl;
    std::cout << "Стрик побед игрока 2: " << maxWinsPlayer2 << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
}
