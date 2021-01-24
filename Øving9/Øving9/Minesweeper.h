#pragma once
#include <iostream>
#include <ctime>
using namespace std;
struct Tile;

class Minesweeper {
private:
    int bredde;
    int hoyde;
    int miner;
    Tile **ruter;
    // Legg til de medlemsvariablene og hjelpefunksjonene du trenger

public:
    Minesweeper(int width, int height, int mines);
    ~Minesweeper();

    bool isGameOver() const;
    bool gameWonn() const;

    bool isTileOpen(int row, int col) const;
    bool isTileMine(int row, int col) const;

    void openTile(int row, int col);

    int numAdjacentMines(int row, int col) const;

    // Vi slår av autogenerert kopikonstruktør og tilordningsoperator for å unngå feil
    Minesweeper(const Minesweeper &) = delete;
    Minesweeper &operator=(const Minesweeper &) = delete;
};

struct Tile {
    bool open;
    bool mine;
    int adjacentMines;
};
