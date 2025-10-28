#include <allegro5/allegro5.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>
#include <stdio.h>
#include "colisao.h"
#include "ler_mapa.h"



int main(){
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_keyboard();

    ALLEGRO_DISPLAY*      disp = al_create_display(576, 384);
    ALLEGRO_TIMER*       timer = al_create_timer(1.0/15.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_FONT*         font = al_load_font("GROBOLD.ttf", 30, 0);
    ALLEGRO_BITMAP* image = al_load_bitmap("sprites.png"); // boneco
    ALLEGRO_BITMAP* fundo = al_load_bitmap("Outside.png"); //imagem do mapa

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    int x = 64;
    int y = 64;
    int x_mapa = 0;
    int y_mapa = 0;
    int flags = 0; //posição da figurinha
    int animacao_y = 0;
    int animacao_x = 0;
    int andar = 0;

    /*matriz*/


    int mapa_atual = 1;

    char mapa[18][12];
    ler_mapa(mapa_atual, mapa);




    ALLEGRO_EVENT event;
    al_start_timer(timer);
    while(1){


        al_wait_for_event(queue, &event);

        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            break;

        }


        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            if(event.keyboard.keycode == ALLEGRO_KEY_Q){
                x = 64;
                y = 64;

                mapa_atual = 1;

                ler_mapa(mapa_atual, mapa);

            }

        }

        if(event.type == ALLEGRO_EVENT_TIMER && al_is_event_queue_empty(queue)){




            ALLEGRO_KEYBOARD_STATE key_state;
            al_get_keyboard_state(&key_state);

            int auxx = x;
            int auxy = y;

            if(al_key_down(&key_state, ALLEGRO_KEY_RIGHT)){
                andar = 1;
                x += 10;
                animacao_y = 3;
            }
            if(al_key_down(&key_state, ALLEGRO_KEY_LEFT)){
                andar = 1;
                x -= 10;
                animacao_y = 1;
            }
            if(al_key_down(&key_state, ALLEGRO_KEY_DOWN)){
                andar = 1;
                y += 10;
                animacao_y = 0;
            }
            if(al_key_down(&key_state, ALLEGRO_KEY_UP)){
                andar = 1;
                y -= 10;
                animacao_y = 2;
            }
            if(andar == 1){

            animacao_x = (animacao_x+1)%5;
            andar = 0;

            }else{

                animacao_x = 0;

            }



                int returno = 0;

                returno = colisao(mapa, x, y);


                if(returno == 2){

                        x = 64;
                        y = 64;

                        mapa_atual++;

                        ler_mapa(mapa_atual, mapa);

                }if(returno == 1){

                x = auxx;
                y = auxy;

                }

            al_clear_to_color(al_map_rgb(150, 150, 200));


            for(int i = 0; i < 12; i++){
                for(int j = 0; j < 18; j++){

                if(mapa[j][i] == '1'){
                al_draw_bitmap_region(fundo,0,6*32,32,32,j*32,i*32,0);


                }if(mapa[j][i] == '0'){
                al_draw_bitmap_region(fundo,4*32,9*32,32,32,j*32,i*32,0);

                }if(mapa[j][i] == '2'){
                al_draw_bitmap_region(fundo,6*32,0*32,32,32,j*32,i*32,0);

                    }if(mapa[j][i] == '3'){
                al_draw_bitmap_region(fundo,7*32,2*32,32,32,j*32,i*32,0);

                    }if(mapa[j][i] == '4'){
                al_draw_bitmap_region(fundo,6*32,87*32,32,32,j*32,i*32,0);

                    }if(mapa[j][i] == '5'){
                al_draw_bitmap_region(fundo,6*32,98*32,32,32,j*32,i*32,0);

                    }

                }
            }
            al_draw_bitmap_region(image,animacao_x*32,animacao_y*32,32,32, x, y, flags);
            al_flip_display();
        }

    }
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
}
