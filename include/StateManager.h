#ifndef STATEMANAGER_H
#define STATEMANAGER_H


class StateManager
{
    public:
        StateManager();
        virtual ~StateManager();
        static int stateId; //the id of the actual state
};

#endif // STATEMANAGER_H
