#include <iostream>
#include <string>
using namespace std;

class Fish{
public:
  int age;
  int neededSpace;
  int size;
  int freeSpace = 22;
  string name;
  string species;
  string food;
  bool isAggressive;

  void Info(){
      cout << "Name:  " << name;
      cout << " ; Species: " << species;
      cout << " ; Food:  " << food;
      cout << " ; Size: " << size;
      cout << " ; Age: " << age;
      cout << " ; Need Space: " << neededSpace;
      cout << " ; Aggressive:  " << isAggressive << endl;
  }
  void printname(){
    cout << name << endl;
  }
  void printsize(){
    cout << size << endl;
  }
  Fish(){};
  Fish(string name,string species,string food,int size,
    int age,int neededSpace,bool isAggressive){
    this->  name = name;
    this->  species = species;
    this->  food = food;
    this->  size = size;
    this->  age = age;
    this->  neededSpace = neededSpace;
    this->  isAggressive = isAggressive;
  }
};
class Aquarium{
public:
  int numberoffish = 0;
  Fish Clipboard[1];
  int Space=22;
  Fish arrayfish[100];

  void FishAdd(Fish Fishes)
  {
     arrayfish[numberoffish] = Fishes;
     numberoffish++;
  }
  void SeeAllFish(){
    for(int i = 0; i < numberoffish; i++){
      arrayfish[i].Info();
    }
  }
  void ThreeBiggest(){
    for (int i = 1; i < numberoffish; i++)
    {
       for (int j = 1; j < numberoffish ; j++)
       {
         if (arrayfish[j].size > arrayfish[j - 1].size)
         {
           Clipboard[0]=arrayfish[j];
           arrayfish[j]=arrayfish[j - 1];
           arrayfish[j - 1]= Clipboard[0];
         }
       }
     }
     std::cout << "Stronger" << '\n';
     for(int i=0; i< 3; i++)
     {
       arrayfish[i].Info();
     }
  }
  void PrintVolume_Space(){
    for (int i = 0; i < numberoffish; i++) {
      Space += arrayfish[i].neededSpace;
   }
   std::cout << "Fish comfort space: " <<Space <<'\n';
  }
};


int main() {
  Fish Sudak("Sudak","aquatic","Dry foods",23,5,1,true);
  Fish Bersh("Bersh","aquatic","Dry foods",44,6,2,true);
  Fish Okun("Okun","aquatic","Vacation food",42,9,1,true);
  Fish Chop("Chop","aquatic","Vacation food",57,12,2,false);
  Fish Schyka("Schyka","aquatic","Vacation food",99,25,4,true);
  Fish Plotva("Plotva","aquatic","Vacation food",12,4,1,false);
  Fish Korop("Korop","aquatic","Dry foods",38,8,2,false);
  Fish Karas("Karas","aquatic","Dry foods",31,3,1,false);
  Fish Pidyst("Pidyst","aquatic","Dry foods",49,8,2,true);
  Fish Som("Som","aquatic","Vacation food",71,10,4,true);
  cout << "Danger aquarium" << '\n';
  Aquarium  Danger;
  Danger.FishAdd(Pidyst);
  Danger.FishAdd(Som);
  Danger.FishAdd(Okun);
  Danger.FishAdd(Schyka);
  Danger.FishAdd(Sudak);
  Danger.FishAdd(Bersh);
  Danger.SeeAllFish();
  Danger.ThreeBiggest();
  Danger.PrintVolume_Space();
  cout << "Safe aquarium" << '\n';
  Aquarium Safe;
  Safe.FishAdd(Chop);
  Safe.FishAdd(Plotva);
  Safe.FishAdd(Korop);
  Safe.FishAdd(Karas);
  Safe.SeeAllFish();
  Safe.ThreeBiggest();
  Safe.PrintVolume_Space();
}