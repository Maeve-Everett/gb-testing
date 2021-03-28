#include <gb/gb.h>
#include <stdio.h>
#include "BirdSprite.c"

INT8 playerLocation[2]; // stores two INT8, x and y of player
INT8 gravity = -1;
INT16 currentSpeedY;


void performantDelay(UINT8 numLoops) { // more efficient delay method
    UINT8 i;
    for (i = 0; i < numLoops; i++) {
        wait_vbl_done(); // waits until the frame has been drawn, ie frames
    }
}

void main() {

    set_sprite_data(0, 1, Bird); // loads player sprites as sprite '0'
    set_sprite_tile(0, 0); // sets sprite '0' to sprite index '0'

    playerLocation[0] = 58;
    playerLocation[1] = 68;
    currentSpeedY = 0;

    move_sprite(0, playerLocation[0], playerLocation[1]); // moves the sprite to roughly the centre of the screen
    
    DISPLAY_ON;
    SHOW_SPRITES; // shows the sprites on the gb screen

    while(1) {
        
        if (joypad() & J_A) {
            currentSpeedY = 5;
        }

        currentSpeedY = currentSpeedY + gravity;

        if (!(playerLocation[1] - currentSpeedY > 160)) {
            playerLocation[1] = playerLocation[1] - currentSpeedY;
            move_sprite(0, playerLocation[0], playerLocation[1]);
        }

        //performantDelay(10);
        delay(100);

    }

}