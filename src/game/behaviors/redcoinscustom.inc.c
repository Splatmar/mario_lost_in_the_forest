void bhv_coinsred(void) {
     if(o->oDistanceToMario < 100.0f){
        obj_mark_for_deletion(o);
        cur_obj_play_sound_2(SOUND_MENU_COLLECT_SECRET );
     }

}

void bhv_grille_loop(void){
    struct Object *monkey;
    switch(o->oAction) {
        case 0: //wait
            monkey = cur_obj_nearest_object_with_behavior(bhvMonkeyBreakGrill);
            if(monkey->oMonkeyBreakTheGrill) {
                o->oAction++;
            }
            break;
        case 1: //break
            if(o->oTimer > 60) {
                    spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
                    spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_YELLOW);
                    cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX);
                    cur_obj_hide();
                    o->oAction++;
                }
            break;
        case 2:
            if(o->oTimer == 0) {
                o->oPosY += 8000;
            }
            break;
    }
}