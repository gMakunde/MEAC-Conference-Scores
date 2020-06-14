#include <iostream>
#include <fstream>
#include<string>
#include "team.h"
using namespace std;
double winspercentage(int, int);

int main() {
  string name1;
  string name2;
  int score1;
  int score2;
  team t;
  fstream file;
  file.open("team.txt", ios::in);
  if (file.is_open()){
    for(int i=0; i < 38; i++){
      file >> name1;
      file >> score1;
      file >> name2;
      file >> score2;
      if(t.exists(name1) == false){
        t.appendNode(name1, 0, 0, 0);
      }
      if(t.exists(name2) == false){
        t.appendNode(name2, 0, 0, 0);
      }
      if (score1 > score2){
        int w = t.returnNode(name1)->wins+1;
        int l = t.returnNode(name1)->losses;
        double wp = winspercentage(w,l);
        t.editNode(name1, w, l, wp);

        int w2 = t.returnNode(name2)->wins;
        int l2 = t.returnNode(name2)->losses+1;
        double wp2 = winspercentage(w2,l2);
        t.editNode(name2, w2, l2, wp2);
      }
      else if (score2 > score1){
        int w = t.returnNode(name1)->wins;
        int l = t.returnNode(name1)->losses+1;
        double wp = winspercentage(w,l);
        t.editNode(name1, w, l, wp);

        int w2 = t.returnNode(name2)->wins+1;
        int l2 = t.returnNode(name2)->losses;
        double wp2 = winspercentage(w2,l2);
        t.editNode(name2, w2, l2, wp2);
      } 
    }
  }
  file.close();
  cout << "MEAC Conference Teams" << endl;
  t.displaylist();
  cout << endl;
  cout << "Teams with Winning records" << endl;
  t.displayWinningTeams();
  

}

double winspercentage(int wins, int loss){
  int total = wins + loss;
  double wp = (double)wins / (double)total;
  return wp;
}
