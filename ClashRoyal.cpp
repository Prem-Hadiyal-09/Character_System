#include <iostream>
#include "Character.cpp"
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

class ClashRoyal
{
public:
    static void actioInGame()
    {
        displyAllCharacter();
        fight();
    }

    static vector<Character *> allPlayers;
    static void displyAllCharacter()
    {
        // Disaplay Our Troops..
        cout << "\nOur allPlayer : ";
        for (int i = 0; i < allPlayers.size(); ++i)
        {
            cout << i + 1 << "." << allPlayers[i]->name << "   ";
        }

        // Display Opponent Troops..
        cout << "\n\nOponent Troops: ";
        srand(time(NULL));
        for (int i = 0; i < allPlayers.size(); ++i)
        {
            int chooseOpponents = rand() % allPlayers.size();
            cout << i + 1 << "." << allPlayers[chooseOpponents]->name << "   ";
        }
    }

    static vector<Character *> chooseCharacter()
    {
        // Choose Our Player..
        cout << "\n\nChoose Chatacter: ";
        int choose;
        cin >> choose;

        Character *charcterOwn = allPlayers[choose - 1];

        // Opponent Player...
        srand(time(NULL));
        int chooseOpponent = rand() % allPlayers.size();
        Character *opponent = allPlayers[chooseOpponent];

        cout << "\nYou select: [" << charcterOwn->name << "], Opponent Select: [" << opponent->name << "]\n\n";

        return {charcterOwn, opponent};
    }

    static void fight()
    {
        auto selectCharcter = chooseCharacter();

        int player = 0;
        int opponent = 1;
        string playerName = selectCharcter[player]->name;
        string opponentName = selectCharcter[opponent]->name;
        int consoleWidth = 170;

        int position1 = 0;
        int position2 = consoleWidth - opponentName.length();

        while (abs(position1 - position2) > playerName.length())
        {
            system("cls");

            cout << string(position1, ' ') << playerName << endl;
            cout << string(position2, ' ') << opponentName << endl;

            Sleep(150);

            position1 += 2;
            position2 -= 2;

            position1 %= consoleWidth;
            position2 %= consoleWidth;
        }

        selectCharcter[player]->attackType();
        while (true)
        {
            if (selectCharcter[player]->hitPoint <= 45 && selectCharcter[player]->hitPoint >= 10)
            {
                int ability;
                cout << "Your character HitPoint Low Active Ability." << endl;
                cin >> ability;

                if (ability == 0)
                {
                    cout << "Active Ability";
                    continue;
                }
                else
                {
                    goto Con;
                }
            }
        Con:
            if (selectCharcter[player] == selectCharcter[opponent])
            {
                cout << "\nMatch Tie" << endl;
                break;
            }
            if (selectCharcter[opponent]->hitPoint > 0 && selectCharcter[player]->hitPoint > 0)
            {
                cout << endl;
                selectCharcter[player]->attackOpponent(selectCharcter[opponent]);
                cout << endl;
                Sleep(270);
            }
            else
            {
                return;
            }
            if (selectCharcter[opponent]->hitPoint > 0 && selectCharcter[player]->hitPoint > 0)
            {
                cout << endl;
                selectCharcter[opponent]->attackOpponent(selectCharcter[player]);
                cout << endl;
                Sleep(1100);
            }
            else
            {
                return;
            }
        }
    }
};

vector<Character *> ClashRoyal::allPlayers = {
    new Ground_Character("Gaint", 250, 25, "Atack Type is Short_Rang."),
    new Ground_Character("Knights", 150, 20, "Defense From cnnon glass."),
    new Ground_Character("Archer", 125, 17, "It's Throw Multiple Arrow Toword to Enemy."),
    new Fly_Character("Bats", 100, 20, "Nothing."),
    new Fly_Character("Lava Hound", 250, 25, "When it's Destroy it split into Six lava pups."),
    new Fly_Character("Dragon", 300, 35, "Fire Attack.")};
