#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
//sdl c++//попробуй.

using namespace std;

const size_t size_X = 80;
const size_t size_Y = 30;

////////////////////////////////////////////////anyStaf///////////////////////////////////////////////

void CompareStrTo2DChar(char base[size_Y][size_X], string import)
{
    int impIndex = 0;
    for (size_t y = 0; y < size_Y; y++) {
        for (size_t x = 0; x < size_X; x++) {
            base[y][x] = import[impIndex];
            impIndex++;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////



struct GameScreen {
    char map[size_Y][size_X];
    string lastTailSet;

    void MapClear()
    {
        for (size_t y = 0; y < size_Y; y++) {
            for (size_t x = 0; x < size_X; x++) {
                map[y][x] = '.';
            }
        }
    }
    void TailsLoad(int index)
    {
        string strInd = "(stri)(48 + index)";///////////////////LTKAFDADFWFAFAFAWFiafoiajwfiojafjjf<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        string path = "tailSets/testLock_" + strInd + ".txt";
        ifstream stream(path);


        stream.close();
    }

    void MapPrint()
    {
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE), {0,0} );

        for (size_t y = 0; y < size_Y; y++) {
            for (size_t x = 0; x < size_X; x++) {
                cout << map[y][x];
            }
            cout << endl;
        }
    }
};

class Gamer {
public:
    int backpointY;
    int backpointX;
    int pointY;
    int pointX;
    GameScreen* gameScreen;

    Gamer (int _y, int _x, GameScreen* _gameScreen)
    {
        gameScreen = _gameScreen;
        pointY = _y;
        pointX = _x;
    }

    void UpdateGamer()
    {
        backpointY = pointY;
        backpointX = pointX;
        //move
        if (GetKeyState(VK_UP) < 0 || GetKeyState(87) < 0)
        {
            if (GetKeyState(VK_SHIFT) < 0) {
                pointY -= 2;
            } else {
                pointY--;
            }

        }
        if (GetKeyState(VK_RIGHT) < 0 || GetKeyState(68) < 0)
        {
            if (GetKeyState(VK_SHIFT) < 0) {
                pointX += 2;
            } else {
                pointX++;
            }

        }
        if (GetKeyState(VK_DOWN) < 0 || GetKeyState(83) < 0)
        {
            if (GetKeyState(VK_SHIFT) < 0) {
                pointY += 2;
            } else {
                pointY++;
            }

        }
        if (GetKeyState(VK_LEFT) < 0 || GetKeyState(65) < 0)
        {
            if (GetKeyState(VK_SHIFT) < 0) {
                pointX -= 2;
            } else {
                pointX--;
            }

        }

        //colision
        if ((gameScreen->map[pointY][pointX] != '.') || (pointY < 0) || (pointY >= size_Y) || (pointX < 0) || (pointX >= size_X))
        {
            pointY = backpointY;
            pointX = backpointX;
        }//нужно допилить
        //


        //inputGamer
        gameScreen->map[pointY][pointX] = '@';


    }

};

int GameProces()
{
    GameScreen* gameScreen = new GameScreen();
    Gamer* gamer = new Gamer(20, 10, gameScreen);
    do
    {
        /* code */
        gameScreen->MapClear();
        //
        gamer->UpdateGamer();


        //
        gameScreen->MapPrint();

        Sleep(60);
    }while (GetKeyState(VK_ESCAPE) >= 0);

    delete gamer;
    delete gameScreen;
    //
    return 0;
}


int main(int argc, char const *argv[])
{

    GameProces();
    //
    return 0;
}
