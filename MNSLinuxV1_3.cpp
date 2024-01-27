
//Note to future Wright,
//Everything works, the only thing that needs to be fixed is at line 252 in the STATS function to print out ALL inventory items
// Features to add: 1) a dungeon, 2) Potions, 3) more animations for spells, 4) balence the game, 5) more classes
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <limits>
#include <vector>
//#include <chrono>
#include <thread>

using namespace std;

bool speedMode = false;
bool godSpeed = false;
vector<string> inventory;
vector<string> fighterDrops;
// fighterDrops.push_back("Belt of Vitality");
// fighterDrops.push_back("Shield of Shielding");
// vector<string> wizardDrops = "Helment of Knowledge", "Battle Mages Cloak", "Staff that just looks like a tree branch";
// vector<string> bardDrops = "Shoes of Drip", "\"Yeezys\"", "Plasma Guitar";
string diety = "Developers";
string favThing = "Coding";
string playerName = "Dev Tester";

//Function Prototype
void clearContinue();
void printInColor(string color, string words);


void printWithDelay(const std::string& text, int delayMilliseconds = 0, const std::string& color = "") {
    
    if (godSpeed == true){
		printInColor(color, text);
	}else if(speedMode == true){
        for (char c : text) {
            printInColor(color, std::string(1, c));
            cout << flush;
            system("sleep .001");
            
        }
    }else if(speedMode == false){
            for (char c : text) {
            printInColor(color, std::string(1, c));
            cout << flush;
            system("sleep .05");
        }
    }
}
void rickRoll() {
    // Replace the URL with the Rick Roll link or any other link you want to open
    const char* url = "https://www.youtube.com/watch?v=dQw4w9WgXcQ";

    // The actual command to open the URL
    const char* command = "start %s";  // For Windows

    // Execute the command
    char buffer[256];
    std::sprintf(buffer, command, url);
    std::system(buffer);
}
void dietySays(string words){
    string tempString = diety + ": "+ words;
    printWithDelay(tempString, 50, "yellow");
}
void changeSpeed(){
    string input;
    cout << "0) Set all text to fast mode \n1) Set all text to normal speed\n3) God Speed *cant be turned off del before release*\n>";
    cin >> input;
    if (input == "0")
        speedMode = true;
    else if (input == "3")
        godSpeed = true;
    else if(input == "1"){
		speedMode = false;

}
//~ void sleep(int time){
	//~ time x= 10
    //~ std::chrono::milliseconds dura(time);
    //~ std::this_thread::sleep_for( dura );

//~ }
}
void printDots(int howManyDots){
    
    if (godSpeed == true){
		for(int i = 0; i <= howManyDots; i++){
            cout << ".";
            cout << flush;
            //system("sleep .000001");
        }
	}else if (speedMode == false){
        for(int i = 0; i <= howManyDots; i++){
            cout << ".";
            cout << flush;
            system("sleep 1");
        }
    }else if (speedMode == true){
            for(int i = 0; i <= howManyDots; i++){
            cout << "." << flush;
            system("sleep .1");
        }

    }
}
void openingScene(){
    //11changeSpeed();
    string tempString;
    printWithDelay("In a world where mosters roam the earth....\n\n", 50);
    printDots(3);
    printWithDelay("\n\nAnd skeltons lurk around every corner.....\n\n", 50);
    printDots(3);
    printWithDelay("\n\nA hero rises up to take on the challenge...\n\n", 50);
    printDots(3);
    printWithDelay("\n\nDo you have what it takes to save the World?",50, "red");
    clearContinue();

    cout << R"(
___  ___ _____  _____  _____  _____ ______  _____
|  \/  ||  _  |/  ___||_   _||  ___|| ___ \/  ___|
| .  . || | | |\ `--.   | |  | |__  | |_/ /\ `--.
| |\/| || | | | `--. \  | |  |  __| |    /  `--. \
| |  | |\ \_/ //\__/ /  | |  | |___ | |\ \ /\__/ /
\_|  |_/ \___/ \____/   \_/  \____/ \_| \_|\____/

                                    |\     ____
  _____       ___   _   _ ______    | \.-./ .-'
 /     \     / _ \ | \ | ||  _  |    \ _  _(
| () () |   / /_\ \|  \| || | | |    | .)(./
 \  ^  /    |  _  || . ` || | | |    |   \(    /\
  |||||     | | | || |\  || |/ /     |     \   ||
  |||||     \_| |_/\_| \_/|___/      |  \vvv   ||
                                     |  |__    ||
                                    /      `-. |
 _____  _   __ _____  _    _____  _____  _   _  _____
/  ___|| | / /|  ___|| |  |_   _||  _  || \ | |/  ___|
\ `--. | |/ / | |__  | |    | |  | | | ||  \| |\ `--.
 `--. \|    \ |  __| | |    | |  | | | || . ` | `--. \
/\__/ /| |\  \| |___ | |____| |  \ \_/ /| |\  |/\__/ /
\____/ \_| \_/\____/ \_____/\_/   \___/ \_| \_/\____/

  ___        __  __      _   _    __      __
 | _ )_  _  |  \/  |__ _| |_| |_  \ \    / /
 | _ \ || | | |\/| / _` |  _|  _|  \ \/\/ /
 |___/\_, | |_|  |_\__,_|\__|\__|   \_/\_/
      |__/

    )";
    clearContinue();

    printWithDelay("A voice echos down from the heavens,\n\n", 50);
    printInColor("yellow", "Ahh your finally ready");
    printWithDelay("\n\nYou recognize the voice as the Diety you've been worshiping your whole life. \n\n*What was their name again?*\n>", 50);
    ws(cin);
    getline(cin, diety);
    cout << endl;
    dietySays("Thank you for not forgetting me, anyways I have a few questions before we begin...\nMy first Question, are you in a rush?\n\n");
    changeSpeed();
    if (speedMode == true){
        dietySays("Good, me too lets get this show on the road!");
}
    else{
        dietySays("Perfect, not too eager, I think you and I will get along great!");
    }
    cout << "\n\n";
    dietySays("And whats your name again?");
    cout << "\n>";
    ws(cin);
    getline(cin, playerName);
    dietySays(playerName);
    printDots(3);
    printInColor("yellow", "\nA fine name if I do say so myself\n\n");
    dietySays("Now Remind me, what type of individual are you\n\n");
}
void credits(){
           system("clear");
       cout << "\t\tSo Long Adventurer until Next Time!" << endl;
       for( int x = 0; x < 100; x++){
            system("sleep .4");
            cout << "\n" << flush;
        if (x == 65){
            cout << "\t\tBeta Testers: \n\t\tAB Zach\n\t\tSR Zhang";
        }
        if (x == 60){
            cout << "\t\tQA Testers:\n\t\tSA Brum\n\t\tPFC Bol (RIP)";
        }
        if (x == 55){
            cout << "\t\tDesign Team: \n\n\t\tAB McLean";
        }
        if (x == 50)
            cout << "\t\tScript Kiddies:\n\n\t\tA1C Wright!!!!!! \n\n\t\t:D" << endl;
        if (x == 45)
            cout << "\t\t\tCredits\n\n\n  \n\n\n\t\tReal Programmers: \n\n\n\n\t\tMr. G" << endl;
        if (x == 15)
            cout << "\t\tWe hope you had a good time!" << endl;
        if (x == 25){
            cout << "\t\tCome back again!" << endl;
            system("sleep .2");
        }
       }
       cout << "And a big thank you to ";
       printInColor("yellow", "YOU");
       cout << " for playing my crappy little game!";
         cout << "\n\nPress Enter to end the game!\n\n";
         cin.get();
         cin.get();
    exit(0);
}
void clearContinue(){
    cout << "\n\nPress Enter TWICE to Continue\n\n";
    cin.get();
    cin.get();
    system("clear");
}
void printInColor(string color, string words){
    if (color == "yellow"){
        cout << "\033[1;33m"<< words <<"\033[0m";
    }else if (color == "blue"){
        cout << "\033[1;34m"<< words <<"\033[0m";
    }else if (color == "red"){
        cout << "\033[1;31m"<< words <<"\033[0m";
    }else{
        cout << words;
    }



}
void colors(std::string& words, int loop, string color) {

    string one = "\033[1;31m";
    string two = "\033[0m\n";
    string y;
    //~ //string done;
    char x;
    if (color == "random"){
        while(loop)
        {
            for (int i = 1; i <=7; i++){
            y = to_string(i);
            x = y[0];
            one.at(5) = x;
            //~ //cout << one.at(5);
            cout << one << words << two;
            system("sleep .15");
            system("clear");
            //cout << done;


        }

        loop --;
       }
    }else if(color == "blue"){
        while(loop){
            system("clear");
            //only use 33 34 37
            for (int i = 3; i <= 7; i++){
                if (i == 3 || i ==4 || i == 7){
                    y = to_string(i);
                    x = y[0];
                    one.at(5) = x;
                    cout << one << words << two;
                    system("sleep .150");
                    system("clear");
                }
            }
            loop --;
        }
    }else if(color == "red"){
        while(loop){
            system("clear");
            //only use 31 33
            for (int i = 1; i <= 3; i++){
                if (i == 1 || i ==3){
                    y = to_string(i);
                    x = y[0];
                    one.at(5) = x;
                    cout << one << words << two;
                    system("sleep .150");
                    system("clear");
                }
            }
            loop --;
        }
    }



}
class Character {
private:
    int hp = 0;
    int mp = 0;
    int exp = 0;
    int str = 0;
    int def = 0;
    int level = 0;
    int maxHp = 0;
    int maxMp = 0;
    int gold = 0;
    bool skellyKey = false;
    bool map = false;
    string Class = "";

public:
// Constructors
Character(void){  //default constructor
    this-> hp = 150;
    this-> mp = 100;
    this-> exp = 0;
    this-> str = 1;
    this-> def = 1;
    this-> level = 1;
    this->gold = 0;
}

Character(int hp, int mp, int exp, int str, int def, int magic){  //nondefault constructor
    this->hp = hp;
    this->mp = mp;
    this->exp = exp;
    this->str = str;
    this->def = def;
    this->level = 0;
    this->gold = 0;
}
// Destructor
~Character(){};


//Initial Character Maker
void mkChar(int hp, int mp, int exp, int str, int def, int magic, string Class){
    this->hp = hp;
    this-> maxHp = hp;
    this->mp = mp;
    this-> maxMp = mp;
    this->exp = exp;
    this->str = str;
    this->def = def;
    this->level = 0;
    this->Class = Class;
    this->gold = 0;
}


//Setters
void setMP(int mp){
    this->mp = mp;
}
bool levelUp(){

    bool leveled = false;
    if(this->level == 0  && this->exp >= 10){
        this->level = 1;
        leveled = true;
        incAll();
    }if(this-> level == 1 && this->exp >= 20){
        this->level = 2;
        leveled  = true;
        incAll();
    }if(this->level == 2 && this->exp >= 30){
        this->level = 3;
        leveled = true;
        incAll();
    }if(this->level == 3 && this->exp >= 40){
        this->level = 4;
        leveled = true;
        incAll();
    }if(this->level == 4 && this->exp >= 50){
        this->level = 5;
        leveled = true;
        incAll();
    }if(this->level == 5 && this->exp >= 60){
        this->level = 6;
        leveled = true;
        incAll();
    }if(this->level == 6 && this->exp >= 70){
        this->level = 7;
        leveled = true;
        incAll();
    }if(this->level == 7 && this->exp >= 80){
        this->level = 8;
        leveled = true;
        incAll();
    }if(this->level == 8 && this->exp >= 90){
        this->level = 9;
        leveled = true;
        incAll();
    }if(this->level == 9 && this->exp >= 100){
        this->level = 10;
        leveled = true;
        incAll();
    }
    
    
        return leveled;

}
void setSkellyKey(bool have){
    this->skellyKey = have;
}
void setMap(bool have){
    this->map = have;
}

//Increase Setters
void incMaxHp(int max){
	this->maxHp += max;
	this->hp = this->maxHp;
}void incMaxMp(int max){
	this->maxMp += max;
	this->mp = this->maxMp;
}
void incHp(int hp){
    if(hp > 0 && this->hp <= this ->maxHp)
        this->hp += hp;
    else
        this->hp = this->maxHp;
    if (this->hp > maxHp){
        this->hp = maxHp;
    }
}
void incMp(int mp){
    if(mp > 0 && this->mp <= this ->maxMp)
        this->mp += mp;
    else
        this->mp = this->maxMp;

    if (this->mp > maxMp){
        this->mp = maxMp;
    }
}void incStr(int str){
	this->str += str;
}void incDef(int def){
	this->def += def;
}
void incAll(){
			
			if(this->Class == "Fighter"){
				incMaxHp(7);
				incMaxMp(1);
				incStr(5);
				incDef(5);
			}else if(this->Class == "Wizard"){
				incMaxHp(5);
				incMaxMp(5);
				incStr(3);
				incDef(3);
			}else if(this->Class == "Bard"){
				incMaxHp(8);
				incMaxMp(5);
				incStr(2);
				incDef(3);
			}else if(this->Class == "Thief"){
				incMaxHp(4);
				incMaxMp(2);
				incStr(6);
				incDef(1);
			}else if(this->Class == "God"){
				incMaxHp(1);
				incMaxMp(1);
				incStr(1);
				incDef(1);
			}
}

void expUp(int xp){
    if(xp > 0){
        this->exp += xp;
        if (levelUp()){
            system("clear");
            if(this->level == 1){
            cout << R"(
__   __             ______                    _                _
\ \ / /             | ___ \                  | |              | |
 \ V / ___   _   _  | |_/ / ___   __ _   ___ | |__    ___   __| |
  \ / / _ \ | | | | |    / / _ \ / _` | / __|| '_ \  / _ \ / _` |
  | || (_) || |_| | | |\ \|  __/| (_| || (__ | | | ||  __/| (_| |
  \_/ \___/  \__,_| \_| \_|\___| \__,_| \___||_| |_| \___| \__,_|


             _                        _      __
            | |                      | |    /  |
            | |      ___ __   __ ___ | |    `| |
            | |     / _ \\ \ / // _ \| |     | |
            | |____|  __/ \ V /|  __/| |    _| |_
            \_____/ \___|  \_/  \___||_|    \___/
            )";
            }else if(this->level == 2){
            cout << R"(
__   __             ______                    _                _
\ \ / /             | ___ \                  | |              | |
 \ V / ___   _   _  | |_/ / ___   __ _   ___ | |__    ___   __| |
  \ / / _ \ | | | | |    / / _ \ / _` | / __|| '_ \  / _ \ / _` |
  | || (_) || |_| | | |\ \|  __/| (_| || (__ | | | ||  __/| (_| |
  \_/ \___/  \__,_| \_| \_|\___| \__,_| \___||_| |_| \___| \__,_|

             _                        _       _____
            | |                      | |     / __  \
            | |      ___ __   __ ___ | |     `' / /'
            | |     / _ \\ \ / // _ \| |       / /
            | |____|  __/ \ V /|  __/| |     ./ /___
            \_____/ \___|  \_/  \___||_|     \_____/
            )";


            }else if(this->level == 3){
            cout << R"(
__   __             ______                    _                _
\ \ / /             | ___ \                  | |              | |
 \ V / ___   _   _  | |_/ / ___   __ _   ___ | |__    ___   __| |
  \ / / _ \ | | | | |    / / _ \ / _` | / __|| '_ \  / _ \ / _` |
  | || (_) || |_| | | |\ \|  __/| (_| || (__ | | | ||  __/| (_| |
  \_/ \___/  \__,_| \_| \_|\___| \__,_| \___||_| |_| \___| \__,_|

             _                        _       _____
            | |                      | |     |____ |
            | |      ___ __   __ ___ | |         / /
            | |     / _ \\ \ / // _ \| |         \ \
            | |____|  __/ \ V /|  __/| |     .___/ /
            \_____/ \___|  \_/  \___||_|     \____/

            )";


            }else if(this->level == 4){
            cout << R"(
__   __             ______                    _                _
\ \ / /             | ___ \                  | |              | |
 \ V / ___   _   _  | |_/ / ___   __ _   ___ | |__    ___   __| |
  \ / / _ \ | | | | |    / / _ \ / _` | / __|| '_ \  / _ \ / _` |
  | || (_) || |_| | | |\ \|  __/| (_| || (__ | | | ||  __/| (_| |
  \_/ \___/  \__,_| \_| \_|\___| \__,_| \___||_| |_| \___| \__,_|

             _                        _         ___
            | |                      | |       /   |
            | |      ___ __   __ ___ | |      / /| |
            | |     / _ \\ \ / // _ \| |     / /_| |
            | |____|  __/ \ V /|  __/| |     \___  |
            \_____/ \___|  \_/  \___||_|         |_/
            )";


            }else if(this->level == 5){
            cout << R"(
__   __             ______                    _                _
\ \ / /             | ___ \                  | |              | |
 \ V / ___   _   _  | |_/ / ___   __ _   ___ | |__    ___   __| |
  \ / / _ \ | | | | |    / / _ \ / _` | / __|| '_ \  / _ \ / _` |
  | || (_) || |_| | | |\ \|  __/| (_| || (__ | | | ||  __/| (_| |
  \_/ \___/  \__,_| \_| \_|\___| \__,_| \___||_| |_| \___| \__,_|

             _                        _       _____
            | |                      | |     |  ___|
            | |      ___ __   __ ___ | |     |___ \
            | |     / _ \\ \ / // _ \| |         \ \
            | |____|  __/ \ V /|  __/| |     /\__/ /
            \_____/ \___|  \_/  \___||_|     \____/
            )";


            }else if(this->level == 6){
            cout << R"(
__   __             ______                    _                _
\ \ / /             | ___ \                  | |              | |
 \ V / ___   _   _  | |_/ / ___   __ _   ___ | |__    ___   __| |
  \ / / _ \ | | | | |    / / _ \ / _` | / __|| '_ \  / _ \ / _` |
  | || (_) || |_| | | |\ \|  __/| (_| || (__ | | | ||  __/| (_| |
  \_/ \___/  \__,_| \_| \_|\___| \__,_| \___||_| |_| \___| \__,_|

             _                        _        ____
            | |                      | |      / ___|
            | |      ___ __   __ ___ | |     / /___
            | |     / _ \\ \ / // _ \| |     | ___ \
            | |____|  __/ \ V /|  __/| |     | \_/ |
            \_____/ \___|  \_/  \___||_|     \_____/


            )";


            }else if(this->level == 7){
            cout << R"(
__   __             ______                    _                _
\ \ / /             | ___ \                  | |              | |
 \ V / ___   _   _  | |_/ / ___   __ _   ___ | |__    ___   __| |
  \ / / _ \ | | | | |    / / _ \ / _` | / __|| '_ \  / _ \ / _` |
  | || (_) || |_| | | |\ \|  __/| (_| || (__ | | | ||  __/| (_| |
  \_/ \___/  \__,_| \_| \_|\___| \__,_| \___||_| |_| \___| \__,_|

             _                        _       ______
            | |                      | |     |___  /
            | |      ___ __   __ ___ | |        / /
            | |     / _ \\ \ / // _ \| |       / /
            | |____|  __/ \ V /|  __/| |     ./ /
            \_____/ \___|  \_/  \___||_|     \_/


            )";


            }else if(this->level == 8){
            cout << R"(
__   __             ______                    _                _
\ \ / /             | ___ \                  | |              | |
 \ V / ___   _   _  | |_/ / ___   __ _   ___ | |__    ___   __| |
  \ / / _ \ | | | | |    / / _ \ / _` | / __|| '_ \  / _ \ / _` |
  | || (_) || |_| | | |\ \|  __/| (_| || (__ | | | ||  __/| (_| |
  \_/ \___/  \__,_| \_| \_|\___| \__,_| \___||_| |_| \___| \__,_|

             _                        _       _____
            | |                      | |     |  _  |
            | |      ___ __   __ ___ | |      \ V /
            | |     / _ \\ \ / // _ \| |      / _ \
            | |____|  __/ \ V /|  __/| |     | |_| |
            \_____/ \___|  \_/  \___||_|     \_____/
            )";


            }else if(this->level == 9){
            cout << R"(
__   __             ______                    _                _
\ \ / /             | ___ \                  | |              | |
 \ V / ___   _   _  | |_/ / ___   __ _   ___ | |__    ___   __| |
  \ / / _ \ | | | | |    / / _ \ / _` | / __|| '_ \  / _ \ / _` |
  | || (_) || |_| | | |\ \|  __/| (_| || (__ | | | ||  __/| (_| |
  \_/ \___/  \__,_| \_| \_|\___| \__,_| \___||_| |_| \___| \__,_|

             _                        _       _____
            | |                      | |     |  _  |
            | |      ___ __   __ ___ | |     | |_| |
            | |     / _ \\ \ / // _ \| |     \____ |
            | |____|  __/ \ V /|  __/| |     .___/ /
            \_____/ \___|  \_/  \___||_|     \____/
            )";


            }else if(this->level == 10){
            cout << R"(
__   __             ______                    _                _
\ \ / /             | ___ \                  | |              | |
 \ V / ___   _   _  | |_/ / ___   __ _   ___ | |__    ___   __| |
  \ / / _ \ | | | | |    / / _ \ / _` | / __|| '_ \  / _ \ / _` |
  | || (_) || |_| | | |\ \|  __/| (_| || (__ | | | ||  __/| (_| |
  \_/ \___/  \__,_| \_| \_|\___| \__,_| \___||_| |_| \___| \__,_|

             _                        _       __   _____
            | |                      | |     /  | |  _  |
            | |      ___ __   __ ___ | |     `| | | |/' |
            | |     / _ \\ \ / // _ \| |      | | |  /| |
            | |____|  __/ \ V /|  __/| |     _| |_\ |_/ /
            \_____/ \___|  \_/  \___||_|     \___/ \___/
            )";
            }
        }
    }
}

//Decrease Setters
void decHP(int hp){
    if(hp > 0)
        this->hp -= hp;
}
void decMP(int mp){
    if(mp > 0)
        this->mp -= mp;
}


// Getters
int getHp(){
    return this->hp;
}
int getMaxHp(){
    return this->maxHp;
}
int getMp(){
    return this->mp;
}
int getMaxMp(){
    return this->maxMp;
}
int getexp(){
    return this->exp;
}
int getDef(){
    return this->def;
}
int getStr(){
    return this->str;
}
int getLevel(){
    return this->level;
}
bool getSkellyKey(){
    return this->skellyKey;
}
bool getMap(){
    return this->map;
}
string getClass(){
    return this->Class;
}

//combat
int Spell(Character* PC){
    int choice = 0;
    int damage = 0;
    string lightning = R"(
                zeeeeeeeeee-
               d$$$$$$$$$$"
              d$$$$$$$$$$"
            d$$$$$$$$$$P
          .$$$$$4$$$$$"
        4$$$$$$$$$$$"
       z$$$$$$$$$$$"
      "$$$$$$$$$$P
            d$$$$"
          .$$$$$"
         z$$$$$"
        z$$$$P
       d$$$$$$$$$$"
      *******$$$"
           .$$$"
          .$$"
         4$P"
        z$"
       zP
      z"
     /
    ^
    )";
    string fireball1 = R"(
                                @      @        @@
                              @/    .@,    /@&&@@
                        ,@@@&&@@@@@&&&@@@@&&@
                       @&#%&@@@&&##&&@@@&&#&@
                  @%#((#%@@@###&@@@@@###@@@#
              @@@@(//((@&/####@@@@@###@@@@&&@
         @@#####(((##((##/##@@@&#((#%@@@&&@#
       @@##((///((/((////(((##///((@@@%#@@
    @@/((//,,,,,,,/((((//#((#####@@##/&@
    @@/,,,,..,..,,.,,//,*/##((/(#@@//(@@
  **%%,..,,,..  ....,,,***////(##((/(@@@**
  @@,,,,,..       .....,,,//#######@@@&&@@
  @@//,..     ..  .  ...,/((((##(##@@#@@
    @@/..    .       ....,,,//(((//#%@.
    @@,,,..  .  .....,,,,.//((###((@@
      @////,,.....,,,,,/////((#&@
       @@/////,,,,,,,//(((((##@/
           @@@@@(((((((@@@@@
                @@@@@@@
    )";
    string fireball2 = R"(

               (##.        ,,,
               (##.           ###      **,  .**.
                        ###   ######     .##*  (##
               ,**      ##############(  .##*  (##
                  (##.  ####################*
            *##   (#####   #########***#####*  (##***
            *###########***###########(***########(((
          ,,,//(########***######(((##(***###########
         .##,  /#################***##(***###########
         .##,  /###########***###***##(*****/########
         .##############***###*****************(##   ###
         .###########************   ***********(########
            *#####*********   ***   **,   *****(########
            *#####******               *****/########
            ,//###/*****...            *****/########
               ######******            *****/########
               #########***************###########
                     (###################*

    )";
while(true){
    cout << "What spell would you like to cast?" << endl
         << "1) Heal (10 Hp) - 5mp" << endl
         << "2) Fireball (10 Damage) - 10mp" << endl
         << "3) Lightning Spell (25 Damage) - 20mp" << endl
         << "0) I've changed my mind" << endl;


    cin >> choice;
    if(choice == 1 && PC->getMp() >= 5 ){
       PC->decMP(5);
       PC->incHp(10);
       damage = 0;
       }
   else if(choice == 2 && PC->getMp() >= 10){
       PC->decMP(10);
       damage = 10;
       colors(fireball1, 3, "red");
       colors(fireball2, 3, "red");
       }
   else if(choice == 3 && PC->getMp() >= 20){
       PC->decMP(20);
       damage = 25;

       colors(lightning, 6, "blue");

       }
   else if(choice == 0){
       damage = 0;
       }

       return damage;
}
}

};
void Stats(Character* PC){
cout << " HP: " << PC->getHp() << endl;
cout << " MP: " <<PC->getMp() << endl;
cout << " STR: " <<PC->getStr() << endl;
cout << " DEF: " <<PC->getDef() << endl;
cout << " Level: " <<PC->getLevel() << endl;
cout << " EXP: " <<PC->getexp() << endl ;
if(!inventory.empty()){
    cout << " Your inventory Contains: ";
    for(unsigned int i = 0; i < inventory.size();i++){
        printInColor("yellow", inventory.at(i));
        cout << ", ";
    }
}
}
string enemyPic(int worldLevel){


    int temp = rand() % 2 + 1;
    string picture = "";

    if (temp == 1 && worldLevel == 2){
        picture = R"(
        .-"""".
       /       \
   __ /   .-.  .\
  /  `\  /   \/  \
  |  _ \/   .==.==.
  | (   \  /_____()(_()
    \ \            '---._
     \                   \_
  /\ |`       (__)-_______/
 /  \|     /\___/
|    \     \||VV
|     \     \|"""",
|      \     ______)
\       \  /`
         \(
Its Dracula!

)";
    }else if (temp == 2 && worldLevel == 2){
         picture = R"(
        \****__              ____
         |    *****\_      --/ *\-__
         /_          (__   ./ ,/----'
AHH a      \_           (_./  /
Dragon!      \__              \___----^__
               _/   _                    \
        |    _/  __/ )\'\ _____          *\
        |\__/   /    ^ ^       \____       )
         \___--'                    \_____  )
                                           '
)";
    }

    else if (temp == 1 && worldLevel == 1){
       picture = R"(
                              __
                     /\    .-" /
                    /  ; .'  .'
                   :   :/  .'
                    \  ;-.'
       .--""""--..__/     `.
     .'           .'    `o  \
    /                    `   ;
   :                  \      :
 .-;        -.         `.__.-'
:  ;          \     ,   ;
'._:           ;   :   (
    \/  .__    ;    \   `-.
 bug ;     "-,/_..--"`-..__)
     '""--.._:

       )";
    }else if (temp == 2 && worldLevel == 1){
       picture = R"(
               _     __,..---""-._                 ';-,
        ,    _/_),-"`             '-.                `\\
       \|.-"`    -_)                 '.                ||
       /`   a   ,                      \              .'/
       '.___,__/                 .-'    \_        _.-'.'
          |\  \      \         /`        _`""""""`_.-'
             _/;--._, >        |   --.__/ `""""""`
           (((-'  __//`'-......-;\      )
                (((-'       __//  '--. /
                          (((-'    __//
                                 (((-'
       )";
    }else if (worldLevel == 10){
		picture = R"(
  _,-""`""-~`)
(`~_,=========\
 |---,___.-.__,\
 |        o     \ ___  _,,,,_     _.--.
  \      `^`    /`_.-"~      `~-;`     \
   \_      _  .'                 `,     |
     |`-                           \'__/ 
    /                      ,_       \  `'-. 
   /    .-""~~--.            `"-,   ;_    /
  |              \               \  | `""`
   \__.--'`"-.   /_               |'
              `"`  `~~~---..,     |
                             \ _.-'`-.
                              \       \
                               '.     /
                                 `"~"`
		)";
	}
    //~ picture = "not working";
    return picture;

}
void combatPrint(int monstHp, int monstStr, int monstDef, Character *PC, string title, string enemyPicture){
            system("clear");
        cout << title << endl;
            //~ cout << "Monster HP             Your HP" << endl;
            //~ cout << monstHp << "                    "<< PC->getHp() << endl;
            cout << " Your HP: " << PC->getHp() << "            " << "Monster Hp: "<< monstHp <<endl;
            cout << " Your MP: " <<PC->getMp() << "            " << "Monster Str: "<< monstStr  << endl;
            cout << " Your STR: " <<PC->getStr() << "            " << "Monster Def: "<< monstDef   << endl;
            cout << " Your DEF: " <<PC->getDef() << endl;
            cout << " Your Level: " <<PC->getLevel() << endl;
            cout << " Your EXP: " <<PC->getexp() << endl ;
            cout << enemyPicture;
            system("sleep 1.5");
}
bool combat(int hp, int str, int def, Character *PC, int worldLevel){

    //~ char bad;
    int damage = 0;
    string playerChoice = "";

    string enemyPicture = enemyPic(worldLevel);
    string world1AttackLines[3] = {"The creature takes a bite of your arm", "The monster jumps on your head", "The creature scratches your face"};
    string bearAttackLines[3] = {"Bear bite you rar", "Bear scrathc you ow", "Bear look at you so mean it hurt your head"};
    
    //~ string beginLines[3] = {"
    
    if(worldLevel == 1){
    cout << "You encounter a small creature with the following stats: " << endl;
	}else if (worldLevel == 10){
	cout << "You encounter The Coolest Bear you've ever seen with the following stats: " << endl;	
	}
	
    cout << "HP: "<< hp << endl
         << "Stength: " << str << endl
         << "Defence:" <<def << endl << endl << endl
         << enemyPicture;

         cout << "\n\n Press Enter to Continue";
         cin.get();
         cin.get();

        combatPrint(hp, str, def, PC, "What will you do first", enemyPicture);

        while ( hp > 0 && PC->getHp() > 0){

            cout << R"(

        ===========================================
        \       What would you like to do         /
         \ 1) Attack the monster normally        /
          \ 2) Just let the monster attack you  /
           \ 3) Cast a spell                   /
            \ 4) Try and run away             /
             =================================

            )";
            cin >> playerChoice;
           //Player normal attack
            if(playerChoice == "1"){
                if(rand() % PC->getStr() + 3 > def){
                    hp -=(rand() % PC->getStr() );
                    combatPrint(hp, str, def, PC, "you attack the monster", enemyPicture);
                }else{
                   combatPrint(hp, str, def, PC, "you attempt to attack the monster, but they block the attack", enemyPicture);
                }
            }

            else if (playerChoice == "3"){
                damage = PC->Spell(PC);
                hp -= damage;
                combatPrint(hp, str, def, PC, "You Cast your spell sucessfully", enemyPicture);
                if (hp <= 0) {
                   continue;
                }
           }
            else if (playerChoice == "4"){
                int randInt = rand() % 101;
                string youRun = R"(
                                   .-.  .--''` )
                                _ |  |/`   .-'`
                               ( `\      /`
                               _)   _.  -'._
                             /`  .'     .-.-;
                             `).'      /  \  \
                            (`,        \_o/_o/__
                             /           .-''`  ``'-.
                             {         /` ,___.--''`
                             {   ;     '-. \ \
           _   _             {   |'-....-`'.\_\
          / './ '.           \   \          `"`
       _  \   \  |            \   \
      ( '-.J     \_..----.._ __)   `\--..__
     .-`                    `        `\    ''--...--.
    (_,.--""`/`         .-             `\       .__ _)
            |          (      }    .__ _)
            \_,         '.               }_  - _.'
               \_.            } `'--'
   You Escape     '._.     ,_)          /
                     |    /           .'
                        _||   _||__   __
  CHICKEN!!      _ __.-` "`)(` `"  ```._)
                (_`,-   ,-'  `''-.   '-._)
               (  (    /          '.__.'
                `"`'--'




                )";
                if (randInt <= 50){
                    system("clear");
                    colors(youRun, 5, "random");
                    return false;
                }else{
                    combatPrint(hp, str, def, PC, "you cant escape!", enemyPicture);
                }

            }
            if(hp <= 0) {
                continue;
            }
            cout << "The monster plots their attack \n";
            printDots(3);
            cout << "\n\n";
            system("clear");
            
            //Monster attack
            cout << "The monster leeps down to attack you" << endl << endl;
            if(rand() % str + 3 > PC->getDef()){
                PC->decHP(rand() % str + 1);
                if(worldLevel == 1){
					combatPrint(hp, str, def, PC, world1AttackLines[rand() % 3], enemyPicture);
				}else if (worldLevel == 10){
					combatPrint(hp, str, def, PC, bearAttackLines[rand() % 3], enemyPicture);
				}
            }else{
                combatPrint(hp, str, def, PC, "The Monster Could not penetrate your defenses", enemyPicture);;
            }


        }

         if( hp <= 0){
            cout << "You won the fight!" << endl;
         return true; }
         else{
            cout << "You lost!";
            if (PC->getHp() <= 0){
                cout << "you died, bozo";
                clearContinue();
                credits();
            }
        return false;}

}

void outsideDungeon(Character *PC){
	int subChoice = 0;
	printWithDelay("Arriving at the dungeon, you find it nestled within a moss-covered mound, its stone façade weathered by time and cloaked in an aura of ancient mystery.\n\nThe entrance beckons with an imposing presence, promising untold challenges and hidden treasures beneath its solemn exterior. \n\n");
	while (true){
            if(PC->getSkellyKey() == false){
                cout <<"What do you do?\n"
                << "1) Look around some more \n"
                << "2) Attack the doorway \n"
                << "0) Give up and leave \n";
                cin >> subChoice;
            }else if (PC->getSkellyKey() == true){
                cout <<"What do you do?\n"
                << "1) Look around some more \n"
                << "2) Attack the doorway \n"
                << "3) Use the ";
                printInColor("yellow", "Skeleton Key");
                cout << "\n0) Give up and leave \n";
                cin >> subChoice;
            }
            if (subChoice == 1){

                cout << "\n\nYou look around and see that there is a small keyhole with a skelton figure right above it. \n I wonder what that could mean? \n";
                 clearContinue();

            }else if(subChoice == 2){
                if (PC->getStr() > 100){
                    cout << "\n\nYou are so strong you bust down the door and enter the dungeoun \n";
                    cout << "*insert a dungeon here*";
                    clearContinue();
                    break;

                }else{
                    cout << "\n\nYour blow bounces off of the doorway like a child attacking a giant, \n \n Although you can't prove it, the door seems to be mocking you";
                    clearContinue();
                }
            }else if(subChoice == 3){
                string win = "YOU WIN";
                colors(win, 10, "random");
                cout << "\n\n\n\n\n Roll credits";
                clearContinue();
                credits();
            }
            else if (subChoice == 0){
                system("clear");
                cout << "\n\nYou give up on your quest of awesomeness and go back to doing lame things. \n";
                clearContinue();
                break;
            }
    }

}

void mapWoods(Character *PC){
    system("clear");
    string subChoice = "";
    
    //Old hut encounter
    printWithDelay("You follow the map through the woods, the first thing you come across is an old hut, \n\n");
    printWithDelay("The weathered hut stands stoically amidst the wilderness, its thatched roof sagging under the weight of moss, and a creaking door suggesting both abandonment and mystery.\n\n");
    printWithDelay("The exterior bears the scars of time, with a rustic charm that hints at untold stories hidden within its walls.\n\n");
    while(true){
		printWithDelay("Do you look inside?\n\n1)Yes \n0)No\n>");
		ws(cin);
		getline(cin, subChoice);
		if(subChoice == "1"){
			system("clear");
			printWithDelay("Approaching the hut, you eagerly anticipated hidden treasures, only to discover it was the perfect setting for a \"Hide and Seek\" championship with absolutely no one participating.");
			printWithDelay("\n\nYou exit the hut down the creaky stairs and look back down at the map deciding where to go next");
			clearContinue();
			break;
		}else{
		printWithDelay("Deciding against the hut, you flaunted your talent for mastering the art of non-curiosity, leaving the exploration to those who haven't quite unlocked the skill yet.");
		clearContinue();
		break;
		}	
	}
	
	//Elfs in the woods
	printWithDelay("Continuing your journey beyond the hut, you stumble upon a quaint clearing where a lively group of peculiar creatures is engaged in a spirited game of musical chairs.\n\n");
	printWithDelay("The whimsical scene unfolds with laughter and merriment, providing a delightful contrast to the earlier mysterious atmosphere.\n\n");
	printWithDelay("You decide that you can either interact with them or leave them to their mysterious escapades.\n\n");
	printWithDelay("0)Leave them be\n1)Say hello\n>");
	ws(cin);
	getline(cin, subChoice);
	system("clear");
	if(subChoice == "1"){
	printWithDelay("Approaching the peculiar elf-like creatures in the clearing, you notice their diminutive stature and cheeky expressions.\n\n");
	printWithDelay("As you attempt to interact, they playfully mock your attempts, dancing away with laughter as if engaged in a game of \"Tag, You're It,\" leaving you with an unspoken challenge to join their elusive escapade.\n\n");
	printWithDelay("Dissapointed in your lack of new friends, you continue along the path the map lays out for you.\n\n");
	
	}else{
	printWithDelay("Choosing not to engage with the playful elf-like creatures, you stand there, perhaps contemplating the meaning of life or the advantages of a nap.\n\n");
	printWithDelay("Unimpressed by your lack of curiosity, the creatures exchange amused glances before vanishing into the woods, leaving you alone with your deep thoughts and a lingering sense of missed whimsy.");
}
	clearContinue();
	
	
	// Bears Den
	printWithDelay("Next along your path, you pass by a ");
	printInColor("red", "Bear's Den");
	printWithDelay("\n\nYou notice a mysterious glimmer and the silhouette of a skeleton key emanating from within.\n\nThe air is charged with an aura of intrigue, tempting you to investigate the enigmatic secrets hidden in the bear's sanctuary.\n\n");
	printWithDelay("Do you choose to investigate?\n\n");
	printWithDelay("1) Yes\n0) No\n>");
	ws(cin);
	getline(cin, subChoice);
	if(subChoice == "1"){ //Bear Combat
		
		if(combat(50, 10, 5, PC, 10)){
			clearContinue();
			cout << R"(
  _,-""`""-~`)
(`~_,      X  \
 |    X        \
 |        o     \ ___  _,,,,_     _.--.
  \      /^\    /`_.-"~      `~-;`     \
   \_      _  .'                 `,     |
     |`-                           \'__/ 
    /                      ,_       \  `'-. 
   /    .-""~~--.            `"-,   ;_    /
  |              \               \  | `""`
   \__.--'`"-.   /_               |'
              `"`  `~~~---..,     |
                             \ _.-'`-.
                              \       \
                               '.     /
                                 `"~"`
			)";
			printWithDelay("\n\nYou have litterally murdered the bear, and you decide to investiagte the rest of the den\n\n");
			printDots(2);
			printWithDelay(" \"Ew not that\" ");
			printDots(2);
			printWithDelay(" \"OHHH that's what that is\" ");
			printDots(2);
			printWithDelay("You look at the end of the cave and there appears to be something magical that is quite litterally casting light onto a key\n\n");
			printWithDelay("You lean over to see what to investigate, \n\nIt appears to be a key with a skelton head on top\nA \"Skeleton Key\" of Sorts\n\n");
			clearContinue();
			printInColor("yellow", "You Aquired the Skeleton Key!\n");
			string key = R"(
                             ⣀⣠⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⢀⣶⠶⣾⣿⣿⡏⠛⠻⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⢘⣿⣤⣿⣿⣿⣀⢠⣾⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⣸⣿⣿⡿⢿⣿⠛⠻⠿⣿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⢹⣿⡁⠀⣠⣿⣇⢠⣾⣿⡉⠻⣷⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠈⠿⣷⣾⣿⣿⣿⣿⣏⠙⢿⣦⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠀⠉⠉⠉⠀⠉⠻⣷⡄⠁⢴⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠙⠻⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⢿⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢻⣿⣦⣄⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢴⠟⢙⣿⣿⣷⣦⡀⠀⠀⠀
			⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣦⣄⠀
			⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠋⣻⣿⠛⠛⠁⠀
			⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠾⠋⠀⢀⣾⠟⠁⠀⠀⠀⠀
			⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠋⠀⠀)";
			cout << key;
			cout << "\n\n";
			inventory.push_back("Skeleton Key");
			PC->setSkellyKey(true);
			clearContinue();
			printWithDelay("Emerging triumphant from an epic battle with the bear, you, though bruised, recall your quest and press on with determination.\n\nThe map's route guides you towards the looming dungeon, promising greater challenges and untold treasures on the horizon.\n\n");
		}
	}else {
	printWithDelay("Choosing to ignore the bear's den, you opt for a thrilling adventure in the realm of indifference.\n\nThe mysteries remain unexplored, and skeleton keys are relics of someone else's amusement.\n\nAs you stroll away, the forest creatures exchange bemused glances, wondering if curiosity will ever find its way to your side.");
	printWithDelay("\n\n You continue on your route the map takes you with your pride just a little hurt.");
	clearContinue();
	}
	
    outsideDungeon(PC);
}

void dungeon(){

}
void printCharPic(Character*PC){

string god = R"(
________                                                _________
\________\--------___       ___         ____----------/_________/
    \_______\----\\\\\\   //_ _ \\    //////-------/________/
        \______\----\\|| (( ~|~ )))  ||//------/________/
            \_____\---\\ ((\ = / ))) //----/_____/
                 \____\--\_)))  \ _)))---/____/
                       \__/  (((     (((_/
                       |  -)))  -  ))
)";
string fighter = R"(
      _,.
    ,` -.)
   ( _/-\\-._
  /,|`--._,-^|            ,
  \_| |`-._/||          ,'|
    |  `-, / |         /  /
    |     || |        /  /
     `r-._||/   __   /  /
 __,-<_     )`-/  `./  /
'  \   `---'   \   /  /
    |           |./  /
    /           //  /
\_/' \         |/  /
 |    |   _,^-'/  /
 |    , ``  (\/  /_
  \,.->._    \X-=/^
  (  /   `-._//^`
   `Y-.____(__}
    |     {__)
          ()
)";

string wizard = R"(
                        ,---.
                       /    |
                      /     |
                     /      |
                    /       |
               ___,'        |
             <  -'          :
              `-.__..--'``-,_\_
                 |0/ ` :0)_`>
                 :/ `     ||/)
                 (_.).__,-` |\
                 /( `.``   `| :
                 \'`-.)  `  ; ;
                 | `       /-<
                 |     `  /   `.
 ,-_-..____     /|  `    :__..-'\
/,'-.__\\  ``-./ :`      ;       \
`\ `\  `\\  \ :  (   `  /  ,   `. \
  \` \   \\   |  | `   :  :     .\ \
   \ `\_  ))  :  ;     |  |      ): :
  (`-.-'\ ||  |\ \   ` ;  ;       | |
   \-_   `;;._   ( `  /  /_       | |
    `-.-.// ,'`-._\__/_,'         ; |
       \:: :     /     `     ,   /  |
        || |    (        ,' /   /   |
        ||                ,'   /    |)";
string bard = R"(                         __
                       /`  `'-.
                      |     _  `\
                      \'-,'` \   |
                       /a a  |  /
                       |/_   //)
                       \ __, `/
                     .'`\___.'('-.__
                    /__ ;    /_   \ `\
                   .`))'`\.'`  \___\  \
 .--._          /    ((  |o       ))\_.|
`-,   `',,,._.-' '-./))  |        (.'   /
   '--`//// '-._ _.' (( _|o      .'  _.'
       \```';-._'-._ ))( `-._.-'/__ /,
        `""`    '-._'-;_)      /  /   \
                    '-,_'-._(`-||||    \
                   _.-' '-.//-.\\\\_.-.|
                  (     .-' _.. ````;-.|
                   '--;-.`-'   '._.'   /
                     /   `'.         .'
                    /      /`'-----'`|
                   /      /    |     |
                  /     /`     |     |
                 |_    /       |     \
                 |     |       |_    |
                 |     /        \     \
                 |     |         \     \
                 /     \            )-.__,'
               _.'`----;          .'     |
             (`     .`-'         (     .-'
              '---'`               `"""`)";
string thief = R"()";
if(PC->getClass() == "Wizard"){
    cout << wizard;
}else if(PC->getClass() == "Fighter"){
    cout << fighter;
}else if(PC->getClass() == "Bard"){
    cout << bard;
}else if(PC->getClass() == "God"){
    cout << god;
}

}


int main(void){
int choice;
int temp;
Character PC;
system("clear");


openingScene();    //UNCOMMENT BEFORE RELEASE FOR OPENING SCENE



//Character creation

cout << "Choose your class!\n1) Fighter\n2) Wizard\n3) Bard\n4) Thief\n>>";
cin>> choice;

    if ( choice == 1){ //Fighter class
        PC.mkChar(25, 10, 0, 15, 5, 1, "Fighter");
        system("clear");
        cout << "You chose the fighter!\n Your stats are:\n";
        Stats(&PC);
        printCharPic(&PC);
    }
    else if ( choice == 2){ //Wizard Class
        PC.mkChar(15, 25, 0, 3, 3, 5, "Wizard");
        system("clear");
        cout << "You chose the Wizard!\n Your stats are:\n";
        Stats(&PC);
        printCharPic(&PC);
        cout << "\n\n";
    }
    else if ( choice == 3){ //Bard Class
        PC.mkChar(20, 15, 0, 10, 5, 3, "Bard");
        system("clear");
        cout << "You chose the Bard!\n Your stats are:\n";
        Stats(&PC);
        printCharPic(&PC);

    }else if ( choice == 4){ //Thief Class
        PC.mkChar(20, 15, 0, 10, 5, 3, "Thief");
        system("clear");
        cout << "You chose the Thief!\n Your stats are:\n";
        Stats(&PC);
        printCharPic(&PC);

    }else if (choice == 73){ // Mr G class
        PC.mkChar(10000, 10000, 0, 10000, 10000, 10000, "God");
        system("clear");
        cout << "You chose ";
        printInColor("blue", "GOD.");
        cout << " YOUR POWER IS UNMATCHED!!! \n Your Godly Stats are:\n";
        Stats(&PC);
        PC.setSkellyKey(true);
        PC.setMap(true);
        inventory.push_back("The Skeleton Key");
        inventory.push_back("A Stange Map");
        printCharPic(&PC);

    }else{ // idiot class
        PC.mkChar(1, 1, 0, 1, 1, 1, "Idiot");
        system("clear");
        cout << "You chose ";
        printInColor("blue", "to be an idiot.");
        cout << " Maybe watch what you enter next time \n Your crappy stats are:\n";
        Stats(&PC);
        //rickRoll();
    }

cout << "Loading your adventure!" << endl;
printDots(4);
cout << "\n";
system("clear");
dietySays("Welp, you're on your own now, Good Luck \nAnd don't call if you need anything!\n\n");

 while(true){
     int option = 0;

     if(PC.getMap() == true){   //gives you options if you have the map
        //system("clear");
        printCharPic(&PC);
        cout << "\n";
        cout << "What would you like to do?" << endl
             << " 1) Explore \n 2) Look for a fight! \n 3) Rest \n 4) Display Inventory and Stats \n 5) Pray to the gods for a hint \n 6) Settigs  \n 7) Follow the map \n 0) Quit\n";
     }else{ //gives you options if you dont have the map
        //system("clear");
        printCharPic(&PC);
        cout << "\n";
        cout << "What would you like to do?" << endl
             << " 1) Explore \n 2) Look for a fight! \n 3) Rest \n 4) Display your inventory \n 5) Pray to the gods for a hint \n 6) Settigs  \n 0) Quit\n";

     }
     cin >> option; // gets your option
    if(option == 1){ //Explore your surroundings

       string exploringQuotes[6] = {"A gentle breeze whispers through the leaves, carrying with it the earthy scent of pine, enhancing the serene ambiance of the woods.", "Moss-covered rocks dot the forest floor, creating natural stepping stones as you navigate through the peaceful expanse.",
       "The rustling leaves underfoot provide a soothing soundtrack, complementing the calming symphony of chirping birds overhead.", "You stumble upon a group of squirrels engaged in a heated debate over the best technique for gathering acorns, inadvertently becoming the unwitting judge of their acorn Olympics.",
       "Enthusiastically trying to perform a woodland cartwheel, you misjudge the uneven terrain, resulting in an unexpected encounter between your face and the forest floor. Ouch!",
       "While examining a mushroom, a small spider unexpectedly descends, prompting you to unleash an involuntary dance move in startled surprise."};
       system("clear");
       temp = rand() % 101;
       cout << "You explore your surrondings\n\n";
       if (temp <= 65){
            cout << exploringQuotes[rand() % 7] << endl;
            clearContinue();
        }else if (temp > 65 && temp <75 ){
            cout << "Just as you pause to admire a particularly majestic tree, a booming voice echoes through the woods, and you realize it's ";
            printInColor("yellow", diety);
            cout << "\n\n";
            dietySays("\"Nice detour, hero. Maybe next time, you'll save the world instead of playing hide-and-seek with tree\"");
            cout << "\n\n";
            cout << "As you trudge forward on your quest, you can't help but love and hate the deity's meddling,\ngrateful for the guidance but secretly hoping they find a celestial hobby other than ridiculing your woodland escapades.";
            clearContinue();
        }
       else if (temp > 75 && temp <= 90){
            cout << " you find a map to a strange dungeon!\n" << endl;
            printInColor("yellow", "You Aquired A Strange Map!\n\n");
            inventory.push_back("A Strange Map");
            PC.setMap(true);
            clearContinue();
       }
       else if (temp > 90 ){
            cout << " you are attacked by a Moster!\n" << endl;
            if(combat((rand() % 25 + 1),(rand() % 5 + 1),(rand() % 5 + 1), &PC, 1))
                PC.expUp(5);
            }
       PC.expUp(1);
   }
    else if(option == 2){ // Combat Option selection

       system("clear");
       temp = rand() % 101;  //Uncomment rand() to be able to have random chance again
       if (temp <= 50){
       cout << "You find a moster to fight!" << endl;
       if(combat((rand() % 25 + 1),(rand() % 10 + 1),(rand() % 5 + 1), &PC, 1)){ // 50% chance to find a monster with rand health
            PC.expUp(5);
        }
    }
    else if(temp > 50){ //your dont find anything loop
        cout << "Your search brings you in circles, while you realize you have spent hours looking for a creature to murder." << endl
             << "\n\nYou stop to contimplate your sad existence\n";
        printDots(3);
        clearContinue();
        PC.expUp(2);
       }
    }
    else if(option == 3){ //Rest selection
       system("clear");
       PC.incMp(rand() % PC.getMaxMp() + 1);
       PC.incHp(rand() % PC.getMaxHp() + 1);
       cout << "Your Current Stats Are\n";
       Stats(&PC);
       cout << R"(
                                      (                 ,&&&.
                                       )                .,.&&
                                      (  (              \=__/
                                          )             ,'-'.
                                    (    (  ,,      _.__|/ /|
                                     ) /\ -((------((_|___/ |
                            You    (  // | (`'      ((  `'--|
                            Rest  _ -.;_/ \\--._      \\ \-._/.
                             by  (_;-// | \ \-'.\    <_,\_\`--'|
                            The  ( `.__ _  ___,')      <_,-'__,'
                            Fire  `'(_ )_)(_)_)'



       )";
       }
    else if(option == 4){ //Inventory and stats selection
       system("clear");
       cout << "Your Current Stats are: " << endl;
       Stats(&PC);
       cout << endl << endl;
       }
    else if (option == 7 && PC.getMap() == true){ //If user has map give them option to follow
       mapWoods(&PC);
    }
    else if (option == 5){ // Pray for a hint
        system("clear");
        cout << "You begin to pray to ";
        printInColor("blue", diety);
        cout << "\n\n";
        dietySays("Listen, and listen close.....Try exploring, and maybe keep trying to kill monsters \nin hopes of a rare reward");
        cout << "\n\n As the voice fades, you can't help but think\n\n\"I think I know more than that guy\"\n\n";
        clearContinue();
    }
    else if(option == 0){ //ROLL CREDITS
     credits();
    }else if(option == 6){ // Settings
    changeSpeed();
    }else if(option == 69){
        int tempInt;
        cout << "\nEnter EXP amount\n>";
        cin >> tempInt;
        PC.expUp(tempInt);
    }
 }
}
