#ifndef TEAM_H
#define TEAM_H
#include <string>
using namespace std;

class team{
  private:
    struct ListNode {
      string name;
      int wins;
      int losses;
      double win_percentage;
      struct ListNode *next;
    };
    struct ListNode *head;
  public:
    team()
    {head = nullptr;}

    ~team();

    void appendNode(string, int, int,double);
    void editNode(string, int, int,double);
    void deleteNode(string, int, int,double);
    void displaylist() const;
    void displayWinningTeams() const;
    ListNode* returnNode(string);
    bool exists(string);
};

#endif