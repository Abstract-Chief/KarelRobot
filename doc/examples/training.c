#include <karel.h>

void turn_right(){
    loop(3){
        turn_left();
    }
}

void jump(){
    turn_left();
    step();
    turn_right();
    step();
    turn_right();
    step();
    turn_left();
}

int main(){
    // turn on karel in the world training.kw
    turn_on("training.kw");

    // pick all beepers on all stairs
    while(!beepers_present()){
        jump();
    }

    // turn off
    turn_off();
}
