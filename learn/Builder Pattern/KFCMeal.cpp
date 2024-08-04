// 一个具体的套餐类（KFCMeal），它继承自Meal类，并实现了getTotalPrice和getMealDescription方法。
class KFCMeal : public Meal {
    private:
        std::string mainCourse;
        std::string drink;

    public:
        KFCMeal(std::string mainCourse, std::string drink) {
            this->mainCourse = mainCourse;
            this->drink = drink;
        }

        double getTotalPrice() override {
            // 根据主食和饮料的价格计算套餐的总价
            // 这里假设主食的价格为10元，饮料的价格为5元
            return 10 + 5;
        }

        std::string getMealDescription() override {
            return "KFC套餐：主食：" + mainCourse + "，饮料：" + drink;
        }
};
