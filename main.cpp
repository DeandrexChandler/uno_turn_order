#include "List.h"
#include "Player.h"
#include <iostream>

int main()
{
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse ==" << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----
    std::unique_ptr<List<Player>> players = makeList<Player>();
    players->addFront(new Player(1, "Ben"));
    players->addFront(new Player(2, "Deandre"));
    players->addFront(new Player(3, "Benny"));
    std::cout << "3 players enter table 1, and plays a couple cards:" << std::endl;
    players->print();

    std::cout << "\nThen a new player Benyamin, enters the game:" << std::endl;
    players->addAnywhere(1, new Player(4, "Benyamin"));
    players->print();

    std::cout << "\nSomeone plays a reverse card:" << std::endl;
    players->reverse();
    players->print();

    std::cout << "\nThen I, Deandre (the greatest uno player ever) wins and leaves the table:"
              << std::endl;
    players->deleteAnywhere(1);
    players->print();

    std::cout << "\nThen a new table is formed with 2 new players:" << std::endl;
    std::unique_ptr<List<Player>> newTable = makeList<Player>();
    newTable->addFront(new Player(5, "Benjamin"));
    newTable->addFront(new Player(6, "Ben2"));
    newTable->print();

    std::cout << "\nBoth tables end their game and combine into one table:" << std::endl;
    players->concat(newTable.get());
    players->print();
    newTable->print();
    return 0;
}
