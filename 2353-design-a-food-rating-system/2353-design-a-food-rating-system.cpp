#define umap unordered_map
#define vs vector<string>
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(),x.end()
class FoodRatings 
{
public:
    // Data Members...
    int n;
    umap<string, string> cuisine_of; 
    umap<string, int> rating_of;      // It is required to locate
    umap< string, set<pair<int, string>> >best;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
    {
        int n = foods.size();
        for(int i = 0; i < n; ++i)
        {
            cuisine_of[foods[i]] = cuisines[i];
            rating_of[foods[i]] = ratings[i];
            best[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) 
    {
        string c = cuisine_of[food];
        int old_rating = rating_of[food];
        best[c].erase({-old_rating, food});
        rating_of[food] = newRating;              // update rating
        best[c].insert({-rating_of[food], food});
    }
    
    string highestRated(string cuisine) 
    {
        auto it = best[cuisine].begin();
        return it->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */