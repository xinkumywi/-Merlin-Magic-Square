#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "windows.h"
#include "board.h"
#include <stdbool.h>
#include <conio.h>

bool compared = false ;
int g_parserX ;
int g_boardstatus = 0;
int board_init(){
    int j = 0;
    for(int i = 0 ; i < 9 ; i++ ){

        j = rand() % 2;
        g_boardstatus = g_boardstatus << 1 ;
        g_boardstatus |= j ;
       

    }
    //g_boardstatus = 0B010110011;
}
int change_status(){

    switch(g_parserX){

        case 2:
            g_boardstatus ^= 0b000011011;
            break;
        case 1:
            g_boardstatus ^= 0b000000111;
            break;
        case 0:
            g_boardstatus ^= 0b000110110;
            break;
        case 5:
            g_boardstatus ^= 0b001001001;
            break;
        case 4:
            g_boardstatus ^= 0b010111010;
            break;
        case 3:
            g_boardstatus ^= 0b100100100;
            break;
        case 8:
            g_boardstatus ^= 0b011011000;
            break;
        case 7:
            g_boardstatus ^= 0b111000000;
            break;
        case 6:
            g_boardstatus ^= 0b110110000;
            break;

    }

}
int sohw_board(){

    int temp = g_boardstatus;
    
    if(!compared){

        compared = true ;
        goto Show ;
    }
    return 0 ;
    Show :
        system("cls");
        
        for(int loop = 0 ; loop <3 ; loop -= -1 ){
            
            
            switch(temp & 0b111){

                case 0:
                    ZZZ();
                    break;
                case 1:
                    ZZO();
                    break;
                case 2:
                    ZOZ();
                    break;
                case 3:
                    ZOO();
                    break;
                case 4:
                    OZZ();
                    break;
                case 5:
                    OZO();
                    break;
                case 6:
                    OOZ();
                    break;
                case 7:
                    OOO();
                    break;
                
            }
            temp = temp >> 3;
        }
        printf("\r %d  ",g_parserX+1);

        if((g_boardstatus ^ 0b111111111) == 0){
            system("cls");

            printf("you WIN !!");

            Sleep(5000);
            exit(0);
        }


}
int user_interface(){

    char cod;
    
    
    if(_kbhit()){

        cod = _getch();
        if(cod == -32){
            cod = _getch();

            switch(cod){

                case 72://up
                    g_parserX = (g_parserX - 3) ;
                    break;
                case 75://left
                    g_parserX = (g_parserX - 1) ;
                    break;
                case 77://right
                    g_parserX = (g_parserX + 1) ;
                    break;
                case 80://down
                    g_parserX = (g_parserX + 3) ;
                    break;
                default:
                    goto EXIT ;
                    break;

            }
            TOGGLE :
                if(g_parserX<0)
                    g_parserX -=- 9;
                if(g_parserX>8)
                    g_parserX +=- 9;
                compared = false ;
            EXIT :
                return 0;
        }
        else if(cod == 'z'){

            change_status();
            compared = false ;

        }
    }
    
    

}
int main(){
    srand(time(NULL));
    board_init();
    while(1){
    sohw_board();
    user_interface();
    Sleep(0.05);
    }

    return 0 ;
}