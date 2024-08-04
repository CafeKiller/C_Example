// 服务员类
class Waiter {
    private:
        MealBuilder* mealBuilder;

    public:
        Waiter(MealBuilder* mealBuilder) {
            this->mealBuilder = mealBuilder;
        }

        Meal* constructMeal() {
            return mealBuilder->createMeal();
        }
};
