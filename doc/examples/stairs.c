#include <karel.h>

void turn_right(){
    loop(3){
        turn_left();
    }
}

int main(){
    // turn on karel in the world stairs.kw
    turn_on("stairs.kw");

    // pick all beepers on all stairs
    loop(3){
        turn_left();
        step();
        turn_right();
        step();
        pick_beeper();
    }

    // climb the top stair
    turn_left();
    step();
    turn_right();
    step();

    // put all beepers
    while(beepers_in_bag()){
        put_beeper();
    }

    // turn off
    turn_off();
}
