class MealBuilder {
    public:
        virtual ~MealBuilder() {}
        virtual Meal* createMeal() = 0;
};
