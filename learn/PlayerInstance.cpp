#include <iostream>

// 玩家单例
class Player {
    private:
        static Player* instance;

        Player() {
        }

        Player(const Player&) = delete;
        Player& operator=(const Player&) = delete;

    public:
        static Player* getInstance() {
            if (instance == nullptr) {
                instance = new Player();
            }
            return instance;
        }

        void display() {
            std::cout << "Player instance is displayed." << std::endl;
        }
};