//Note to future Wright, 
//Everything works, the only thing that needs to be fixed is at line 252 in the STATS function to print out ALL inventory items
// Features to add: 0) make title screen, 1) a dungeon, 2) Potions, 3) more animations for spells, 4) balence the game, 5) more classes 

#include <iostream>
#include <string>
#include <limits>
#include <vector>
using namespace std;

// bool skellyKey = false, map = false;
vector<string> inventory;

void credits(){
           system("clear");
       cout << "\t\tSo Long Adventurer until Next Time!" << endl;
       for( int x = 0; x < 100; x++){
            system("sleep .2");
            cout << "\n" << flush;
        if (x == 65){
            cout << "\t\tBeta Testers: \n\t\tAB Zach\n\t\t";
        }
        if (x == 60){
            cout << "\t\tQA Testers:\n\t\tSA Brum\n\t\tPFC Bol";
        }
        if (x == 55){
            cout << "\t\tMoral Support: \n\n\t\tAB McLean";
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
    exit(0);
}

void clearContinue(){                
    cout << "\n\n Press Enter to Continue\n\n";
    cin.get();
    cin.get();
    system("clear");
}

void printInColor(string color, string words){
    if (color == "yellow"){
        cout << "\033[1;33m"<< words <<"\033[0m";
    }else if (color == "blue"){
        cout << "\033[1;34m"<< words <<"\033[0m";
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
                    system("sleep .15");
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
    int magic = 0;
    int maxHp = 0;
    int maxMp = 0;
    bool skellyKey = false;
    bool map = false;

public:
// Constructors
Character(void){  //default constructor
    this-> hp = 150;
    this-> mp = 100;
    this-> exp = 0;
    this-> str = 1;
    this-> def = 1;
    this-> magic = 1;
}

Character(int hp, int mp, int exp, int str, int def, int magic){  //nondefault constructor
    this->hp = hp;
    this->mp = mp;
    this->exp = exp;
    this->str = str;
    this->def = def;
    this->magic = magic;
}
// Destructor
~Character(){};
// Setters

void mkChar(int hp, int mp, int exp, int str, int def, int magic){ 
    this->hp = hp;
    this-> maxHp = hp;
    this->mp = mp;
    this-> maxMp = mp;
    this->exp = exp;
    this->str = str;
    this->def = def;
    this->magic = magic;
    
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
void decHP(int hp){
    if(hp > 0)
        this->hp -= hp;
}
void incMp(int mp){
    if(mp > 0 && this->mp <= this ->maxMp)
        this->mp += mp;
    else
        this->mp = this->maxMp;
    
    if (this->mp > maxMp){
        this->mp = maxMp;
    }
}
void decMP(int mp){
    if(mp > 0)
        this->mp -= mp;
}
void setMP(int mp){
    this->mp = mp;
}
void expUp(int xp){
    if(xp > 0)
        this->exp += xp;
}
void setSkellyKey(bool have){
    this->skellyKey = have;
}
void setMap(bool have){
    this->map = have;
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
int getMagic(){
    return this->magic;
}
bool getSkellyKey(){
    return this->skellyKey;
}
bool getMap(){
    return this->map;
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
while(true){
    cout << "What spell would you like to cast?" << endl
         << "1) Fireball - 5mp" << endl
         << "2) Magic Missle - 10mp" << endl
         << "3) Lightning Spell - 20mp" << endl
         << "0) I've changed my mind" << endl;
         
         
    cin >> choice;
    if(choice == 1 && PC->getMp() >= 5 ){
       PC->decMP(5);
       damage = 5;
       }
   else if(choice == 2 && PC->getMp() >= 10){
       PC->decMP(10);
       damage = 10;       
       }
   else if(choice == 3 && PC->getMp() >= 20){
       PC->decMP(20);
       damage = 100; 
       
       colors(lightning, 8, "blue");
              
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
cout << " MAGIC: " <<PC->getMagic() << endl;
cout << " EXP: " <<PC->getexp() << endl ;
if(!inventory.empty()){
    cout << " Your inventory Contains: ";
    for(unsigned int i = 0; i < inventory.size();i++){
        printInColor("yellow", inventory.at(i));
        cout << ", ";
    }
}
}
string enemyPic(){
    
    
    int temp = rand() % 2 + 1;
    string picture = "";
    
    if (temp == 1){
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
    }else if (temp == 2){
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
    }else{
       picture = "how did this happen?";
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
            cout << " Your MAGIC: " <<PC->getMagic() << endl;
            cout << " Your EXP: " <<PC->getexp() << endl ;
            cout << enemyPicture;
            system("sleep .5");
}

bool combat(int hp, int str, int def, Character *PC){

    //~ char bad;
    int damage = 0;
    string playerChoice = "";
    string enemyPicture = enemyPic();
    string attackLines[3] = {"The monster takes a bite of your arm", "The monster jumps on your head", "The monster breathes fire all around you"};
    //~ string beginLines[3] = {"
    cout << "You found a monster with the following stats: " << endl
         << "HP: "<<hp << endl
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
                    return 1;
                }else{
                    combatPrint(hp, str, def, PC, "you cant escape!", enemyPicture);
                }
                
            }
            if(hp <= 0) {
                continue;
            }
            cout << "The monster plots their attack \n";
            cout << "\n\n";
            system("sleep 2");
            //Monster attack
            cout << "The monster leeps down to attack you" << endl << endl;
            if(rand() % str + 3 > PC->getDef()){
                PC->decHP(rand() % str + 1);
                combatPrint(hp, str, def, PC, attackLines[rand() % 3], enemyPicture);
            }else{
                cout << "The monster could not penetrate your defenses" << endl << endl;
            }
       
        
        }
         
         if( hp <= 0){
            cout << "You won the fight!" << endl;
         return true; }
         else{
            cout << "You lost!";
        return false;}
    
}


int main(void){
int choice;
int temp;
Character PC;
system("resize -s 30 100");
system("clear");

    //Character creation

    cout << "Choose your class!\n1)Fighter\n2)Wizard\n3)Bard\n>>";
    cin>> choice;
    if ( choice == 1){
    PC.mkChar(25, 3, 0, 5, 3, 1);
    system("clear");
    cout << "You chose the fighter!\n Your stats are:\n";
    Stats(&PC);
    }
    else if ( choice == 2){
    PC.mkChar(15, 20, 0, 2, 3, 5);
    system("clear");
    cout << "You chose the Wizard!\n Your stats are:\n";
    Stats(&PC);
    
    }
    else if ( choice == 3){
    PC.mkChar(20, 2, 0, 3, 3, 3);
    system("clear");
    cout << "You chose the Bard!\n Your stats are:\n";
    Stats(&PC);
    
    }else if (choice == 73){
        PC.mkChar(10000, 10000, 0, 10000, 10000, 10000);
        system("clear");
        cout << "You chose ";
        printInColor("blue", "Mr G.");
        cout << " YOUR POWER IS UNMATCHED!!! \n Your Godly Stats are:\n";
        Stats(&PC);
        PC.setSkellyKey(true);
        PC.setMap(true);
        inventory.push_back("The Skeleton Key");
        inventory.push_back("A Stange Map");
    }
    cout << "Loading your adventure!" << endl;
      for(int x = 0; x <=3; x++){
          cout << "." << flush;
          system("sleep .5");
      }
      cout << "\n";
     system("clear");
     cout << "Welcome to the WRIGHT adventure!" << endl;     
  
    
    
 
 while(true){
     int option = 0;
     
     if(PC.getMap() == true){   
        cout << "What would you like to do?" << endl
            << " 1) Explore \n 2) Look for a fight! \n 3) Rest \n 4) Display Inventory and Stats \n 5) Pray to the gods for a hint \n 6) Follow the map \n 0) Quit\n";
     }else{
                 cout << "What would you like to do?" << endl
            << " 1) Explore \n 2) Look for a fight! \n 3) Rest \n 4) Display your inventory \n 5) Pray to the gods for a hint \n 0) Quit\n";
         
     }
     cin >> option;
   if(option == 1){
       system("clear");
       temp = 76;//rand() % 101;
       cout << "You explore your surrondings";
       if (temp <= 75)
       cout << " and everything seems peaceful\n" << endl;
       else if (temp > 75 && temp <= 90){
       cout << " you find a map to a strange dungeon!\n" << endl;
       printInColor("yellow", "You Aquired A Strange Map!\n\n");
       inventory.push_back("A Strange Map");
       PC.setMap(true);
       }
       else if (temp > 90 ){
       cout << " you are attacked by a Moster!\n" << endl;
       if(combat((rand() % 25 + 1),(rand() % 5 + 1),(rand() % 5 + 1), &PC))
       PC.expUp(5);
       }
       PC.expUp(1);
   }
   else if(option == 2){
       
       system("clear");
       temp = 25; // rand() % 101;  //Uncomment rand() to be able to have random chance again
       if (temp <= 50){
       cout << "You find a moster to fight!" << endl;
       if(combat((rand() % 25 + 1),(rand() % 5 + 1),(rand() % 5 + 1), &PC)){
            if (temp <= 25){  
                cout << "The monster appears to have dropped something.....*Very Shiny*\n\nDo you investigate?\n1) Yes\n0) No\n";
                int choiceTemp = 0;
                cin >> choiceTemp;
                if(choiceTemp == 1){
                    system("clear");
                    cout << "You lean over to see what the monster dropped, \n\nIt appears to be a key with a skelton head on top\nA \"Skeleton Key\" of Sorts\n\n";
                        printInColor("yellow", "You Aquired the Skeleton Key!");
                        cout << "\n\n";
                        inventory.push_back("Skeleton Key");
                        PC.setSkellyKey(true);
                }else{
                    cout << "You could care less about shiny objects and continue on with your life, unaffected";
                }
            }
            PC.expUp(5);
        }
    }
       else if(temp > 50){
       cout << "Your search brings you in circles, while you realize you have spent hours looking for a creature to murder." << endl
            << "\n\nYou stop to contimplate your sad existence";
       for(int x = 0; x <=5; x++){
          cout << "." << flush;
          system("sleep 2");
      }
      clearContinue();
       PC.expUp(2);}
       
       }
   else if(option == 3){
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
    else if(option == 4){
       system("clear");
       cout << "Your Current Stats are: " << endl;
       Stats(&PC);
       cout << endl << endl;
       }
    else if (option == 6 && PC.getMap() == true){
        int subChoice = 0;
        system("clear");
        cout << "You follow the map through the forrest, passing by many skeltons along the way. \n\nEventually you stumble upon a old stone doorway. \n ";
        cout << "\n\n Press Enter to Continue";
         cin.get();
         cin.get();
        while (true){
            if(PC.getSkellyKey() == false){
                cout <<"What do you do?\n"
                << "1) Look around some more \n"
                << "2) Attack the doorway \n"
                << "0) Give up and leave \n";
                cin >> subChoice;
            }else if (PC.getSkellyKey() == true){
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
                if (PC.getStr() > 100){
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
    else if (option == 5){
        system("clear");
        cout << "You begin to pray to ";
        printInColor("blue", "*Insert Deity Here*");
        printInColor("yellow", "\n\n\"Listen, and listen close.....Try exploring, and maybe keep trying to kill monsters \nin hopes of a rare reward\"");
        cout << "\n\n As the voice fades, you can't help but think\n\n\"I think I know more than that guy\"\n\n";
        clearContinue();
    }
   else if(option == 0){
     credits();
}
 }
}
