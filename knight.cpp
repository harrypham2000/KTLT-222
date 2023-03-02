#include "knight.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
    const int BowserSurrendered=0;
    const int MeetMadBear=1;
    const int MeetBandit=2;
    const int MeetLordLupin=3;
    const int MeetElf=4;
    const int MeetTroll=5;
    const int MeetShaman=6;
    const int MeetSirenVajsh=7;
    const int PickUpMushMario=11;
    const int PickUpMushFib=12;
    const int PickUpMushGhost=13;
    const int ObtainRemedy=15;
    const int ObtainMaidenKiss=16;
    const int ObtainPhoenixDown=17;
    const int MeetMerlin=18;
    const int MeetAsclepius=19;
    const int MeetBowser=99;
    const int MaxLevel=10;

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
float baseDmg(int event){
        float dmg=0.0;
        switch(event){
            case MeetMadBear:
                dmg= int(1.0);
                break;
            case MeetBandit:
                dmg= 1.5;
                break;
            case MeetLordLupin:
                dmg= 4.5;
                break;
            case MeetElf:
                dmg= 7.5;
                break;
            case MeetTroll:
                dmg= 9.5;
                break;
            default:
                break;
    return dmg;
    }
void getInput(string input_string,int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue, int events[100]){
    stringstream ss(input_string);
    if(ss.peek() == '\n') ss.ignore();
    string line;
    getline(ss,line);
    stringstream line_ss(line);
    line_ss >> HP >> level >> remedy >> maidenkiss >> phoenixdown >> rescue;
    string event_line;
    stringstream event_ss(event_line);
    int event_count=1;
    while(event_ss >> events[event_count]){
        event_count++;
    }
}
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    ifstream input_file(file_input);
    if (!input_file.is_open())
    {
        cerr << "Cannot open file!";
        return;
    }
    int events[100]={0};
    string input_string;
    getline(input_file,input_string);
    getInput(input_string,HP, level,remedy,maidenkiss,phoenixdown,rescue,events);
    int num_events = sizeof(events) / sizeof(events[0]);
    int MaxHP=min(HP,172);
    for (int i=1;i <num_events&&HP>0&&level<=10&&rescue==0;i++) {
        int event=events[i];
        int levelO=0;
        if (event>=MeetMadBear&&event<=MeetSirenVajsh){
            int b=i%10;
            levelO=i>6?(b>5?b:5):b;
            if (level>levelO) {
                level=min(10,level++);
            }
            else if(level == levelO){
                level=level;
            }
            else if(level < levelO) {
                float dmg=baseDmg(event[i])*levelO*10;
                HP=int(HP-dmg);
            }
            if(HP<=0&&phoenixdown==0){
                rescue=-1;
                break;
            }
            else{
                continue;
            }
        }
    }
        switch(event){
            case BowserSurrendered: //Bowser surrendered and handed over the princess
                rescue=1;
                break;
            case MeetMadBear: //Meet MadBear
                break;
            case MeetBandit: //Meet Bandit
                break;
            case MeetLordLupin: //Meet LordLupin
                break;
            case MeetElf: //Meet Elf
                break;
            case MeetTroll: //Meet Troll
                break;
            case MeetShaman: //Meet Shaman
                break;
            case MeetSirenVajsh: //Meet Siren Vajsh
                break;
            case PickUpMushMario: //Pick up the power-up mushroom MushMario
                break;
            case PickUpMushFib: //Pick up the Fibonacci mushroom MushFib
                break;
            case PickUpMushGhost: //Pick up the ghost mushroom MushGhost
                break;
            case ObtainRemedy: //Obtain recovery potion Remedy
                break;
            case ObtainMaidenKiss: //Obtain the antidote MaidenKiss
                break;
            case ObtainPhoenixDown: //Pick up the phoenix tear PhoenixDown
                break;
            case MeetMerlin: //Meet Merlin
                break;
            case MeetAsclepius: //Meet Asclepius
                break;
            case MeetBowser: //Meet Bowser
                break;
            default:
                cerr << "Invalid event";
                return;   
        
        }
    }
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);

    cout << "Function isn't implemented" << endl;
}