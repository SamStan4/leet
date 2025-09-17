#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <ios>
#include <iostream>

class FoodItem {

  private:

    std::string foodName;

    int foodRating;

  public:

    FoodItem(const std::string& newFoodName, const int newRating)
      : foodName(newFoodName), foodRating(newRating) {};

    FoodItem(const FoodItem& other)
      : foodName(other.foodName), foodRating(other.foodRating) {};

    ~FoodItem() = default;

    std::string getFoodName(void) const {
      return this->foodName;
    }

    int getFoodRating(void) const {
      return this->foodRating;
    }

    void setFoodRating(const int newFoodRating) {
      this->foodRating = newFoodRating;
    }

    FoodItem& operator=(const FoodItem& other) {
      if (this != &other) {
        this->foodName = other.foodName;
        this->foodRating = other.foodRating;
      }
      return *this;
    }

    bool operator<(const FoodItem& other) const {
      if (this->foodRating != other.foodRating) {
        return this->foodRating < other.foodRating;
      }
      return this->foodName > other.foodName;
    }
};

class FoodRatings {

  private:
  
    std::unordered_map<std::string, std::set<FoodItem>> foodStore;
    std::unordered_map<std::string, std::string> foodToCuisine;
    std::unordered_map<std::string, int> foodToRating;

    void insertNewFood(const std::string& cuisine, const std::string& foodName, const int rating) {
      this->foodToCuisine[foodName] = cuisine;
      this->foodToRating[foodName] = rating;
      this->foodStore[cuisine].insert(FoodItem(foodName, rating));
    }

  public:

    FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings) {
      const int n = static_cast<int>(foods.size());
      for (int i = 0; i < n; ++i) {
        this->insertNewFood(cuisines[i], foods[i], ratings[i]);
      }
    }
    
    void changeRating(std::string food, int newRating) {
      const std::string& cuisine = this->foodToCuisine[food];
      const int rating = this->foodToRating[food];
      this->foodStore[cuisine].erase(FoodItem(food, rating));
      this->foodStore[cuisine].insert(FoodItem(food, newRating));
      this->foodToRating[food] = newRating;
    }
    
    std::string highestRated(std::string cuisine) {
      FoodItem item = *(this->foodStore[cuisine].rbegin());
      return item.getFoodName();
    }
};

static int init = []() {
  std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr),
    std::cout.tie(nullptr);
  return 0;
} ();