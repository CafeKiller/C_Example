class Mercedes : public Car {
    public:
        void assemble() override {
            std::cout << "Assembling Mercedes car." << std::endl;
        }
};

class BMW : public Car {
    public:
        void assemble() override {
            std::cout << "Assembling BMW car." << std::endl;
        }
};

class Maserati : public Car {
    public:
        void assemble() override {
            std::cout << "Assembling Maserati car." << std::endl;
        }
};
