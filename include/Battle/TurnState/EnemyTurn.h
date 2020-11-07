#ifndef ENEMYTURN_H
#define ENEMYTURN_H


class EnemyTurn
{
    private:

    public:
        EnemyTurn();
        virtual ~EnemyTurn();

        void nextState();
        void attack();
};

#endif // ENEMYTURN_H
