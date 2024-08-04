// 一个抽象的套餐类（Meal），它包含一个主食和一个饮料的成员变量，并提供一个方法来获取套餐的总价。
class Meal {
    public:
        virtual ~Meal() {}
        virtual double getTotalPrice() = 0;
        virtual std::string getMealDescription() = 0;
};
