#include <stdio.h>

int dp[55][55];
char map[55][55];
int N;

typedef struct Block{
    //rot == rotation status :: vertical = 1, horizontal = 0
    int cx, cy, rot;
} block;

void setX(block *b, int x){
    b->cx = x;
}

void setY(block *b, int y){
    b->cy = y;
}

void setRotation(block *b, int rot){
    b->rot = rot;
}

void changeRotation(block *b){
    b->rot = !b->rot;
}

int getX(block b){
    return b.cx;
}

int getY(block b){
    return b.cy;
}

int getRotationStatus(block b){
    return b.rot;
}

void initBlock(block *b, int x, int y, int rot){
    setX(b, x);
    setY(b, y);
    setRotation(b, rot);    
}

int main(){
    char tmp;
    int cnt = 0;
    block b;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%c", &tmp);
            map[i][j] = tmp;
            if(tmp == 'H' && ++cnt ==2) {
                
            }
        }
    }


}