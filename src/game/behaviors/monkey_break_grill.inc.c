
void bhv_monkey_break_grill_init(void) {
    o->oGravity = 2.5f;
    o->oFriction = 0.8f;
    o->oBuoyancy = 1.3f;
    o->oInteractionSubtype = INT_SUBTYPE_NPC;
    o->oMonkeyBreakTheGrill = FALSE;
}

static void monkey_break_grill_act_idle(void) {
    s16 animFrame = o->header.gfx.animInfo.animFrame;

    // vec3f_copy(&o->oBobombBuddyPosCopyVec, &o->oPosVec);

    object_step();

    if ((o->oTimer % 100) == 0) {
        cur_obj_play_sound_2(SOUND_OBJ_UKIKI_CHATTER_SHORT);
    }

    if (o->oDistanceToMario < 1000.0f) {
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);
    }

    if (o->oInteractStatus == INT_STATUS_INTERACTED) {
        o->oAction = 1;
    }
}

static void monkey_break_grill_act_turn_to_talk(void) {
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);

    if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
        o->oAction = 2;
    }

    cur_obj_play_sound_2(SOUND_OBJ_UKIKI_CHATTER_SHORT);
}

static void monkey_break_grill_cannon_dialog(s16 dialogFirstText, s16 dialogSecondText) {
    struct Object *grill;
    s16 buddyText, cutscene;

    if(count_objects_with_behavior(bhvCoinsred) > 0) {
        buddyText = cutscene_object_with_dialog(CUTSCENE_DIALOG, o, dialogSecondText);
        if (buddyText != DIALOG_RESPONSE_NONE) {
            set_mario_npc_dialog(MARIO_DIALOG_STOP);
            o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
            o->oInteractStatus = INT_STATUS_NONE;
            o->oAction = BOBOMB_BUDDY_ACT_IDLE;
        }
    } else {
        switch (o->oBobombBuddyCannonStatus) {
            case 0: // cannonDoor not open
                buddyText = cutscene_object_with_dialog(CUTSCENE_DIALOG, o, dialogFirstText);
                if (buddyText != DIALOG_RESPONSE_NONE) {
                    grill = cur_obj_nearest_object_with_behavior(breaking_surface);
                    if (grill != NULL) {
                        o->oBobombBuddyCannonStatus = 1;
                        o->oMonkeyBreakTheGrill = TRUE;
                    } else {
                        o->oBobombBuddyCannonStatus = 3;
                    }
                }
                break;

            case 1: //grill opening
                grill = cur_obj_nearest_object_with_behavior(breaking_surface);
                cutscene = cutscene_object(CUTSCENE_PREPARE_CANNON, grill);
                if (cutscene == -1) {
                    o->oBobombBuddyCannonStatus = 2;
                }
                break;

            case 2: //grill already open
                buddyText = cutscene_object_with_dialog(CUTSCENE_DIALOG, o, dialogSecondText);
                if (buddyText != DIALOG_RESPONSE_NONE) {
                    o->oBobombBuddyCannonStatus = BOBOMB_BUDDY_CANNON_STOP_TALKING;
                }
                break;

            case 3: //stop talking
                set_mario_npc_dialog(MARIO_DIALOG_STOP);

                o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
                o->oBobombBuddyHasTalkedToMario = BOBOMB_BUDDY_HAS_TALKED;
                o->oInteractStatus = INT_STATUS_NONE;
                o->oAction = BOBOMB_BUDDY_ACT_IDLE;
                o->oBobombBuddyCannonStatus = 2;
                break;
        }
    }

}

static void monkey_break_grill_act_talk(void) {
    
    if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_DOWN) == MARIO_DIALOG_STATUS_SPEAK) {
        
        o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        monkey_break_grill_cannon_dialog(DIALOG_079, DIALOG_080);
    }
}

static void bhv_monkey_break_grill_actions(void) {
    switch (o->oAction) {
        case 0: //idle
            monkey_break_grill_act_idle();
            break;

        case 1: //turn to mario
            monkey_break_grill_act_turn_to_talk();
            break;

        case 2: //talk
            monkey_break_grill_act_talk();
            break;
    }

    set_object_visibility(o, 3000);
    o->oInteractStatus = INT_STATUS_NONE;
    o->oIntangibleTimer = 0;
}

void bhv_monkey_break_grill_loop(void) {
    bhv_monkey_break_grill_actions();
}