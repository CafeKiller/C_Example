#include <stdio.h>

/*
有限状态机
*/
 
typedef enum {
    START,
    END,
    OPTIONS,
    ABOUT,
    MAX_STATES
} State;

typedef enum {
    START_EVENT,
    END_EVENT,
    OPTIONS_EVENT,
    ABOUT_EVENT,
    MAX_EVENTS
} Event;

typedef struct {
    State currentState;
    void (*stateFunctions[MAX_STATES])(void);
} FSM;

void startState(void);
void endState(void);
void optionsState(void);
void aboutState(void);

void initFSM(FSM *fsm) {
    fsm->currentState = START;
    fsm->stateFunctions[START] = startState;
    fsm->stateFunctions[END] = endState;
    fsm->stateFunctions[OPTIONS] = optionsState;
    fsm->stateFunctions[ABOUT] = aboutState;
}

void transitionState(FSM *fsm, State newState) {
    fsm->currentState = newState;
    fsm->stateFunctions[fsm->currentState]();
}

void handleEvent(FSM *fsm, Event event) {
    switch (event) {
        case START_EVENT:
            transitionState(fsm, START);
            break;
        case END_EVENT:
            transitionState(fsm, END);
            break;
        case OPTIONS_EVENT:
            transitionState(fsm, OPTIONS);
            break;
        case ABOUT_EVENT:
            transitionState(fsm, ABOUT);
            break;
        default:
            printf("Unknown event\n");
            break;
    }
}

void startState(void) {
    printf("Start state\n");
    
}

void endState(void) {
    printf("End state\n");
    
}

void optionsState(void) {
    printf("Options state\n");
    
}

void aboutState(void) {
    printf("About state\n");
    
}

int main() {
    FSM fsm;
    initFSM(&fsm);

    handleEvent(&fsm, START_EVENT);
    handleEvent(&fsm, OPTIONS_EVENT);
    handleEvent(&fsm, ABOUT_EVENT);
    handleEvent(&fsm, END_EVENT);

    return 0;
}
