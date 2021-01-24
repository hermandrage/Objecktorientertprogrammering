#include "Minesweeper.h"

Minesweeper::Minesweeper(int width, int height, int mines):bredde(width), hoyde(height), miner(mines){
    ruter=new Tile*[bredde];
    for (int i=0; i<bredde; i++) {
        ruter[i]=new Tile[hoyde];
        for (int j=0; j<hoyde; j++) {
            ruter[i][j].open=false;
            ruter[i][j].mine=false;
            ruter[i][j].adjacentMines=0;
        }
    }
    while (miner>0) {
        int rad=rand()%(hoyde);
        int colonne=rand()%(bredde);
        if(!ruter[colonne][rad].mine){
            ruter[colonne][rad].mine=true;
            miner--;
            if (((bredde-1)-colonne)>0 && ((hoyde-1)-rad)>0) {
                ruter[colonne+1][rad+1].adjacentMines++;
            }
            if (((bredde-1)-colonne)>0){
                ruter[colonne+1][rad].adjacentMines++;
            }
            if (((hoyde-1)-rad)>0) {
                ruter[colonne][rad+1].adjacentMines++;
            }
            if (colonne>0 && rad>0) {
                ruter[colonne-1][rad-1].adjacentMines++;
            }
            if (colonne>0) {
                ruter[colonne-1][rad].adjacentMines++;
            }
            if (rad>0) {
                ruter[colonne][rad-1].adjacentMines++;
            }
            if (colonne>0 && ((hoyde-1)-rad)>0) {
                ruter[colonne-1][rad+1].adjacentMines++;
            }
            if (((bredde-1)-colonne)>0 && rad>0) {
                ruter[colonne+1][rad-1].adjacentMines++;
            }
        }
    }
}

Minesweeper::~Minesweeper() {
    for (int i=0; i<bredde; i++) {
        delete []ruter[i];
        ruter[i]=nullptr;
    }
    delete []ruter;
    ruter=nullptr;
}

bool Minesweeper::isGameOver() const {
    for (int i=0; i<bredde; i++) {
        for (int j=0; j<hoyde; j++) {
            if (ruter[i][j].open && ruter[i][j].mine) {
                return true;
            }
        }
    }
    return false;
}

bool Minesweeper::gameWonn() const{
    for (int i=0; i<bredde; i++) {
        for (int j=0; j<hoyde; j++) {
            if (!ruter[i][j].open && !ruter[i][j].mine) {
                return false;
            }
        }
    }
    return true; 
}

bool Minesweeper::isTileOpen(int row, int col) const {
    return ruter[col][row].open;
}

bool Minesweeper::isTileMine(int row, int col) const {
    return ruter[col][row].mine;
}

void Minesweeper::openTile(int row, int col) {
    
    ruter[col][row].open=true;
    int startRow=row-1;
    int startCol=col-1;
    int endRow=row+1;
    int endCol=col+1;
    if ((numAdjacentMines(row, col)==0)) {
        /*if (((bredde-1)-col)>0 && ((hoyde-1)-row)>0 && !ruter[col+1][row+1].open) {
            openTile(col+1, row+1);
        }
        if (((bredde-1)-col)>0 && !ruter[col+1][row].open){
            openTile(col+1,row);
        }
        if (((hoyde-1)-row)>0 && !ruter[col][row+1].open) {
            openTile(col,row+1);
        }
        if (col>0 && row>0 && !ruter[col-1][row-1].open) {
            openTile(col-1,row-1);
        }
        if (col>0 && !ruter[col-1][row].open) {
            openTile(col-1,row);
        }
        if (row>0 && !ruter[col][row-1].open) {
            openTile(col,row-1);
        }
        if (col>0 && ((hoyde-1)-row)>0 && !ruter[col-1][row+1].open) {
            openTile(col-1,row+1);
        }
        if (((bredde-1)-col)>0 && row>0 && !ruter[col+1][row-1].open) {
            openTile(col+1,row-1);
        }*/
        if (row==0) {
            startRow=row;
        }
        if (row==(hoyde-1)) {
            endRow=row;
        }
        if (col==0) {
            startCol=col;
        }
        if (col==(bredde-1)) {
            endCol=col;
        }
        for (int i=startCol; i<=endCol; i++) {
            for (int j=startRow; j<=endRow; j++) {
                if (!ruter[i][j].open) {
                    openTile(j, i);
                }
                
            }
        }
    }
}

int Minesweeper::numAdjacentMines(int row, int col) const {
    return ruter[col][row].adjacentMines;
}
