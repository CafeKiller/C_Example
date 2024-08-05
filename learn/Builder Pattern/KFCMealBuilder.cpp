// 一个具体的创建者类（KFCMealBuilder），它继承自MealBuilder类，并实现了createMeal方法。
class KFCMealBuilder : public MealBuilder {
    public:
        Meal* createMeal() override {
            // 根据顾客的要求，一步一步装配套餐的组成部分
            // 这里假设顾客要求的是汉堡和可乐
            std::string mainCourse = "汉堡";
            std::string drink = "可乐";

            return new KFCMeal(mainCourse, drink);
        }
};

