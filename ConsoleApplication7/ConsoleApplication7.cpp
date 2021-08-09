
//ZEYNEP BETÜL ÇELİK


#include <iostream>
#include<string>
#include <vector>
#include<conio.h>
#include<stdio.h>
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include <sstream>
#include<fstream>
using namespace std;


class Player {
public:
    string name;
    string status;
    vector<int>dicelog;
    int stampsingame = 15;
    int brokenflakes = 0;
    int move;
    Player(string name, int stampsingame, int brokenflakes) {
        this->name = name;
        this->brokenflakes = brokenflakes;
        this->stampsingame = stampsingame;
    }
    void setBrokenflakes(int brokenflakes) {
        this->brokenflakes = brokenflakes;
    }
    void setStampsingame(int stampsingame) {
        this->stampsingame = stampsingame;
    }
    int getBrokenflakes() {
        return this->brokenflakes;
    }
    int getStampsingame() {
        return this->stampsingame;
    }

};

class Dice {
public:
    int rol;

};

class Game {
public:
    string turn;


};

int playerbrokens1 = 0;
int playerbrokens2 = 0;

//taş toplamak için kontrol fonksiyonu
bool flakesinareaX(vector<string>vec) {
    bool flag = true;
    for (int i = 0; i < vec.size(); i++) {
        if (i < 6 && i > 11) {
            if (vec[i][1] == 'x') { flag = false; i = vec.size(); }

        }
    }
    return flag;
}

//taş toplamak için kontrol fonksiyonu
bool flakesinareaY(vector<string>vec) {
    bool flag = true;
    for (int i = 0; i < vec.size(); i++) {
        if (i < 18) {
            if (vec[i][1] == 'y') { flag = false; i = vec.size(); }

        }
    }
    return flag;
}

int collectX = 0;
int collectY = 0;

//X oyuncusu için pul toplama
vector<string>collectstampsX(vector<string>vec, int dice) {
    int index = 11 - dice;
    vec[index] = (vec[index][0] - 48) - 1;
    collectX++;
    return vec;

}
//Y oyuncusu için pul toplama
vector<string>collectstampsY(vector<string>vec, int dice) {
    int index = 23 - dice;
    vec[index] = (vec[index][0] - 48) - 1;
    collectY++;
    return vec;
}

//oyuna başlamak için atılan zarlar
vector<int> rolldicesforstart() {
    int no1, no2;
    vector<int>vec;
    srand(time(0));
    no1 = (rand() % 6) + 1;
    cout << "diceno1: " << no1 << endl;
    cout << "please press the enter for second dice";
    getchar();
    srand(time(0));
    no2 = (rand() % 6) + 1;
    cout << "diceno2: " << no2 << endl;
    vec.push_back(no1);
    vec.push_back(no2);
    return vec;
}
//pullar için zar atma
vector<int> rolldices() {
    int no1, no2;
    vector<int>vec;
    srand(time(NULL));
    no1 = (rand() % 6) + 1;
    no2 = (rand() % 6) + 1;

    vec.push_back(no1);
    vec.push_back(no2);
    return vec;
}


fstream FHandle2;

//dat dosyasına table'ları kaydeden fonksiyon
void createtabledat(vector<string>tableprinter, string gamename) {
    FHandle2 << "***********" << gamename << "*************" << endl;
    for (int j = 0; j < 5; j++) {
        if (j == 0 && j != 4) {


            for (int i = 0; i < 12; i++) {
                FHandle2 << "_" << tableprinter[i] << "_";
                FHandle2 << "|";
            }
        }

        else if (j != 0 && j != 4) {
            for (int i = 0; i < 12; i++) {


                FHandle2 << "____|";


            }

        }
        else if (j == 4) {
            for (int i = 12; i < 24; i++) {
                FHandle2 << "_" << tableprinter[i] << "_";
                FHandle2 << "|";

            }

        }
        FHandle2 << endl;


    }

}

//konsola yazdırma
void print_table(vector<string>tableprinter, Player player1, Player player2) {
    for (int j = 0; j < 5; j++) {
        if (j == 0 && j != 4) {


            for (int i = 0; i < 12; i++) {
                cout << "_" << tableprinter[i] << "_";
                cout << "|";
            }
        }

        else if (j != 0 && j != 4) {
            for (int i = 0; i < 12; i++) {


                cout << "____|";


            }

        }
        else if (j == 4) {
            for (int i = 12; i < 24; i++) {
                cout << "_" << tableprinter[i] << "_";
                cout << "|";

            }

        }
        cout << endl;
    }
}


//oyunun bitip bitmediğini kontrol ettiğim fonksyion
bool isgamecontinue(int stampsplayer1, int stampsplayer2) {
    bool flag = true;
    if (stampsplayer1 == 15 || stampsplayer2 == 15)flag = false;
    return flag;
}

//turn değiştiren fonksiyon
string changeturn(string turn) {
    string newturn;
    if (turn == "PlayerX")newturn = "PlayerY";
    else newturn = "PlayerX";

    return newturn;
}

vector<string>readfile(string gamename) { 
    std::ifstream file;
    file.open("table.dat");
    int data = 0;
    file >> data;

    vector<string>vec;

    cout << data;



    return vec;
}
//kırık taş olduğunda oynanacak hamleler (X)
vector<string>playbrokenX(vector<string>vec, int dice) {
    int index = 23;
    int placetogo = 0;


    if (index - dice >= 12)
        placetogo = index - dice + 1;
    else
        placetogo = index - dice - 7 + 1;
x:
    if (vec[placetogo][0] - 48 < 5 && vec[placetogo][1] == 'x') {
        vec[placetogo][0] = (char)((vec[placetogo][0] - 48 + 1) + 48);
    }
    else if (vec[placetogo][1] == 'y' && vec[placetogo][0] - 48 == 1) {

        vec[placetogo] = "1x";
        playerbrokens2++;

    }
    else if (vec[placetogo] == "  ") {
        vec[placetogo] = "1x";


    }



    playerbrokens1--;
    return vec;
}

//kırık taş olduğunda oynanacak hamleler (Y)
vector<string>playbrokenY(vector<string>vec, int dice) {
    int index = 11;
    int placetogo = 0;
    if (index - dice < 0)
        placetogo = index - dice + 1 + 12;
    else
        placetogo = index - dice + 1;
    if (vec[placetogo][1] == 'x' && vec[placetogo][0] - 48 == 1) {
        if (vec[placetogo][0] != ' ') {
            vec[placetogo] = "1y";
            playerbrokens1++;


        }
    }
    else if (vec[placetogo] == "  ") {
        vec[placetogo] = "1y";



    }
    else if (vec[placetogo][1] == 'y' && (vec[placetogo][0] - 48) < 5) {
        vec[placetogo][0] = (char)((vec[placetogo][0] - 48 + 1) + 48);

    }
    playerbrokens2--;
    return vec;
}


//X oyuncusunun hamleleri 
vector<string>playX(vector<string>vec, int dice) {// for turn Player X 

    vector<string>result;
    int chosenindex = 0;
    int placetogo = 0;
    int number = 0;


    cout << "please enter for play to dice  " << dice << endl;
    for (int i = 0; i < vec.size(); i++) {
        int index = i;
        if (vec[i] != " ")
            if (vec[i][1] == 'x') {

                cout << index << endl;
            }
    }
x:
    cin >> chosenindex;
    placetogo = (chosenindex - dice);
    number = vec[chosenindex][0] - 48;
    if (chosenindex <= 18 && chosenindex >= 12 && chosenindex - dice <= 11) {
        placetogo = (dice - 1);

    }
    else if (chosenindex <= 11 && chosenindex >= 0) {
        placetogo = (chosenindex + dice);

    }

    if (vec[placetogo][1] == 'y' && vec[placetogo][0] - 48 == 1) {
        if (vec[placetogo][0] != ' ') {
            vec[chosenindex][0] = (char)((number - 1) + 48);
            if (vec[chosenindex][0] == '0')vec[chosenindex] = "  ";
            vec[placetogo] = "1x";
            playerbrokens2++;




        }
    }
    else if (vec[placetogo] == "  ") {
        vec[placetogo] = "1x";
        vec[chosenindex][0] = (char)((number - 1) + 48);
        if (vec[chosenindex][0] == '0')vec[chosenindex] = "  ";

    }
    else if (vec[placetogo][1] == 'x' && (vec[placetogo][0] - 48) < 5) {
        vec[placetogo][0] = (char)((vec[placetogo][0] - 48 + 1) + 48);
        vec[chosenindex][0] = (char)((number - 1) + 48);
        if (vec[chosenindex][0] == '0')vec[chosenindex] = "  ";
    }
    else if (vec[placetogo] == "5y" || vec[placetogo] == "5x" || (vec[placetogo][0] - 48 > 1 && vec[placetogo][1] == 'y')) { cout << "impossible choice please enter another index" << endl; goto x; }


    result = vec;
    return result;
}

//Y oyuncusunun hamleleri
vector<string>playY(vector<string>vec, int dice) {//for turn Player Y

    int placetogo = 0;
    int number = 0;
    int chosenindex = 0;
    vector<string>result;

    cout << "please enter for play to dice  " << dice << endl;
    for (int i = 0; i < vec.size(); i++) {
        int index = i;
        if (vec[i] != " ")
            if (vec[i][1] == 'y') {

                cout << index << endl;
            }
    }
x:
    cin >> chosenindex;
    placetogo = (chosenindex - dice);
    number = vec[chosenindex][0] - 48;
    if (chosenindex <= 11 && chosenindex >= 0 && chosenindex - dice < 0) {
        placetogo = ((chosenindex - dice + 1) * (-1) + 12);

    }
    else if (chosenindex <= 11 && chosenindex >= 0 && chosenindex - dice >= 0) {
        placetogo = (chosenindex - dice);

    }
    else if (chosenindex >= 12 && chosenindex <= 22) {
        placetogo = (chosenindex + dice);
    }

    if (vec[placetogo][1] == 'x' && vec[placetogo][0] - 48 == 1) {
        if (vec[placetogo][0] != ' ') {
            vec[chosenindex][0] = (char)((number - 1) + 48);
            if (vec[chosenindex][0] == '0')vec[chosenindex] = "  ";
            vec[placetogo] = "1y";
            playerbrokens1++;


        }
    }
    else if (vec[placetogo] == "  ") {
        vec[placetogo] = "1y";
        vec[chosenindex][0] = (char)((number - 1) + 48);
        if (vec[chosenindex][0] == '0')vec[chosenindex] = "  ";

    }
    else if (vec[placetogo][1] == 'y' && (vec[placetogo][0] - 48) < 5) {
        vec[placetogo][0] = (char)((vec[placetogo][0] - 48 + 1) + 48);
        vec[chosenindex][0] = (char)((number - 1) + 48);
        if (vec[chosenindex][0] == '0')vec[chosenindex] = "  ";
    }
    else if (vec[placetogo] == "5y" || vec[placetogo] == "5x" || (vec[placetogo][0] - 48 > 1 && vec[placetogo][1] == 'x')) { cout << "impossible choice please enter another index" << endl; goto x; }

    result = vec;
    return result;



}

int main() {
    fstream FHandle;
    FHandle.open("dicelog.dat", ios::out);
    FHandle2.open("table.dat", ios::out);
    vector<string>flakeslocations;//pulları 24 boyutlu bir vektörde tutuyorum
    vector<int>dices;
    for (int i = 0; i < 24; i++) {      //for create default table
        if (i == 0)flakeslocations.push_back("5y");
        else if (i == 4)flakeslocations.push_back("3x");
        else if (i == 6)flakeslocations.push_back("5x");
        else if (i == 11)flakeslocations.push_back("2y");
        else if (i == 12)flakeslocations.push_back("5x");
        else if (i == 16)flakeslocations.push_back("3y");
        else if (i == 18)flakeslocations.push_back("5y");
        else if (i == 23)flakeslocations.push_back("2x");
        else flakeslocations.push_back("  ");

    }

    Dice diceno1;
    Dice diceno2;
    Player player1("PlayerX", 15, 0);
    Player player2("PlayerY", 15, 0);

    Game game;
    string gamename;
    cout << "please enter name your game" << endl;
    cin >> gamename;
    print_table(flakeslocations, player1, player2);//default table
    createtabledat(flakeslocations, gamename);//default table is printing to dat file
    cout << "The dices are rolled" << endl;

    dices = rolldicesforstart();
    while (dices[0] == dices[1]) {
        cout << "The dices are rolled again" << endl;
        dices = rolldicesforstart();
    }
    player1.dicelog.push_back(dices[0]);
    player2.dicelog.push_back(dices[1]);
    FHandle << "************ " << gamename << " *************" << endl;
    FHandle << dices[0] << " " << dices[1] << endl;
    if (dices[0] > dices[1]) {
        player1.status = "startfirst";
        player2.status = "startsecond";
        game.turn = player1.name;//turn is specified in here
    }
    else if (dices[1] > dices[0]) {
        player1.status = "startsecond";
        player2.status = "startfirst";
        game.turn = player2.name;//turn is specified in here
    }
    cout << "Player1's status has changed as: " << player1.status << endl;
    cout << "Player2's status has changed as: " << player2.status << endl;

    cout << "press enter to start game";
    getchar();
    if (system("CLS")) system("clear");
    print_table(flakeslocations, player1, player2);//default table

    //***********************************************THE REAL GAME STARTS HERE*************************************************************************//

    while (isgamecontinue(collectX, collectY)) {//burada isgamecontinue fonksiyonu bool tipte bir fonksiyondur ve parametreleri x ve y nin topladığı taş sayısıdır ikisinden birisi 15
        //pulun hepsini topladıysa fonksiyon false döndürür döngü kırılır ve oyun biter 
        cout << "PlayerX's total brokenflakes: " << playerbrokens1 << endl;
        cout << "PlayerY's total brokenflakes: " << playerbrokens2 << endl;
        cout << "PlayerX's collectedflakes: " << collectX << endl;
        cout << "PlayerY's collectedflakes: " << collectY << endl;
        cout << "it's " << game.turn << " turn" << endl;
        cout << "press enter for roll the dices" << endl;
        getchar();

        dices = rolldices();
        player1.dicelog.push_back(dices[0]);//for record players dice's log
        player1.dicelog.push_back(dices[1]);

        cout << "the dices are: " << dices[0] << " " << dices[1] << endl;


        if (game.turn == "PlayerX") {
            FHandle << game.turn << " " << dices[0] << " " << dices[1] << endl;
            if (playerbrokens1 == 0) {

                cout << " please enter 1 to play" << endl;



            }
            else if (playerbrokens1 == 0 && flakesinareaX) {//kırık taş var mı ve x in taşlarının hepsi kendi alanında mı diye kontrol ediyorum

                cout << " please enter 3 for collect flakes choice you want to play" << endl;


            }

            else {
                cout << "press 2 for play  brokenflake" << endl;
            }
            int choice;
            cin >> choice;   int statedice = 2;  int state = 2;
            switch (choice) {
            case(1):
                int q;

                if (dices[0] == dices[1])state = 4;
                for (int i = 0; i < state; i++) {

                    cout << " please enter  number of dice you want to play" << endl;
                    cout << "  " << dices[0] << "  " << dices[1] << " " << endl;

                    cin >> q;
                    flakeslocations = playX(flakeslocations, q);
                    print_table(flakeslocations, player1, player2);
                    createtabledat(flakeslocations, gamename);
                }

                break;

            case(2):
                int n;

                if (dices[0] == dices[1]) statedice = 4;
                for (int i = 0; i < statedice; i++) {
                    cout << " please enter number of dice you want to play" << endl;
                    cout << "  " << dices[0] << " " << dices[1] << endl;

                    cin >> n;
                    if (system("CLS")) system("clear");
                    print_table(flakeslocations, player1, player2);
                    if (playerbrokens1 == 0) {
                        flakeslocations = playX(flakeslocations, n);
                        print_table(flakeslocations, player1, player2);
                        createtabledat(flakeslocations, gamename);
                        player1.move--;
                    }
                    else if (playerbrokens1 > 0) {
                        flakeslocations = playbrokenX(flakeslocations, n);//kırık taş var ise kırık taş oynanır move sayısı bitmedi ve kırık taş kalmadıysa normal oyuna yani PlayX
                        //fonksiyonuna geçer
                        print_table(flakeslocations, player1, player2);
                        createtabledat(flakeslocations, gamename);
                        player1.move--;
                    }


                }


                break;
            case(3):
                if (dices[0] == dices[1]) {
                    cout << "congratulations equal dices!" << endl;
                    for (int i = 0; i < 4; i++) {
                        if (system("CLS")) system("clear");
                        print_table(flakeslocations, player1, player2);
                        flakeslocations = collectstampsX(flakeslocations, dices[0]);
                        print_table(flakeslocations, player1, player2);
                        createtabledat(flakeslocations, gamename);
                    }
                }
                else {
                    for (int i = 0; i < 2; i++) {
                        cout << " please enter choice you want to play" << endl;
                        cout << "  " << dices[0] << " " << dices[1] << endl;

                        cin >> n;
                        if (system("CLS")) system("clear");
                        print_table(flakeslocations, player1, player2);
                        flakeslocations = collectstampsX(flakeslocations, n);//taş toplama işlemi bu fonksiyonda yapılıyor
                        print_table(flakeslocations, player1, player2);
                        createtabledat(flakeslocations, gamename);
                    }

                }

                break;

            }
            game.turn = changeturn(game.turn);//oyun sırası karşı tarafa geçiyor


        }


        else if (game.turn == "PlayerY") {
            FHandle << game.turn << " " << dices[0] << " " << dices[1] << endl;
            if (playerbrokens2 == 0) {
                cout << " please enter 1 to play" << endl;


            }
            else if (playerbrokens2 == 0 && flakesinareaY) {//kırık taş var mı ve y nin taşlarının hepsi kendi alanında mı diye kontrol ediyorum

                cout << " please enter 3 for collect flakes choice you want to play" << endl;


            }

            else {
                cout << "press 2 for play for brokenflake" << endl;
            } int state = 2;
            int statedice = 2;
            int choice;
            cin >> choice;
            if (system("CLS")) system("clear");
            switch (choice) {
            case(1):
                int q;

                if (dices[0] == dices[1])state = 4;
                for (int i = 0; i < state; i++) {
                    cout << " please enter number of dice to play" << endl;
                    cout << "  " << dices[0] << "  " << dices[1] << " " << endl;
                    cin >> q;
                    if (system("CLS")) system("clear");
                    print_table(flakeslocations, player1, player2);
                    flakeslocations = playY(flakeslocations, q);
                    print_table(flakeslocations, player1, player2);
                    createtabledat(flakeslocations, gamename);

                }

                break;

            case(2):
                int n;

                if (dices[0] == dices[1]) statedice = 4;
                for (int i = 0; i < statedice; i++) {
                    cout << " please enter number of dice you want to play" << endl;
                    cout << "  " << dices[0] << " " << dices[1] << endl;

                    cin >> n;
                    if (system("CLS")) system("clear");
                    print_table(flakeslocations, player1, player2);
                    if (playerbrokens1 == 0) {
                        flakeslocations = playY(flakeslocations, n);
                        print_table(flakeslocations, player1, player2);
                        createtabledat(flakeslocations, gamename);

                    }
                    else if (playerbrokens1 > 0) {
                        flakeslocations = playbrokenY(flakeslocations, n);//kırık taş var ise kırık taş oynanır move sayısı bitmedi ve kırık taş kalmadıysa normal oyuna yani PlayY
                        //fonksiyonuna geçer (üstteki if cümleciğinde)
                        print_table(flakeslocations, player1, player2);
                        createtabledat(flakeslocations, gamename);

                    }


                }


                break;
            case(3):
                if (dices[0] == dices[1]) {
                    cout << "congratulations equal dices!" << endl;
                    for (int i = 0; i < 4; i++) {
                        if (system("CLS")) system("clear");
                        print_table(flakeslocations, player1, player2);
                        flakeslocations = collectstampsY(flakeslocations, dices[0]);//taş toplama işlemi bu fonksiyonda yapılıyor
                        print_table(flakeslocations, player1, player2);
                        createtabledat(flakeslocations, gamename);
                    }
                }
                else {
                    for (int i = 0; i < 2; i++) {
                        cout << " please enter number of dice you want to play" << endl;
                        cout << "  " << dices[0] << " " << dices[1] << endl;

                        cin >> n;
                        if (system("CLS")) system("clear");
                        print_table(flakeslocations, player1, player2);
                        flakeslocations = collectstampsY(flakeslocations, n);
                        print_table(flakeslocations, player1, player2);
                        createtabledat(flakeslocations, gamename);
                    }

                }

                break;

            }
            game.turn = changeturn(game.turn);//oyun sırası karşı tarafa geçiyor

        }

    }


    return 0;

}


