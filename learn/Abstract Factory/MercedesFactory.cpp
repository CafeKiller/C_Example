class MercedesFactory : public CarFactory {
    public:
        Car* createCar() override {
            return new Mercedes();
        }
};

class BMWFactory : public CarFactory {
    public:
        Car* createCar() override {
            return new BMW();
        }
};

class MaseratiFactory : public CarFactory {
    public:
        Car* createCar() override {
            return new Maserati();
        }
};
