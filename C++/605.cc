class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++){
            //check if current plot is empty => if not =>skip
            if (flowerbed[i] == 0){
                //Left pos of the current plot or leftmost plot is empty
                bool emptyLeft = (i == 0) || (flowerbed[i-1] == 0);
                //Right pos of the current plot or rightmost plot is empty
                bool emptyRight = (i == flowerbed.size()-1) || (flowerbed[i+1] ==0);
                //if both L&R are empty => can plant
                if (emptyLeft && emptyRight){
                    flowerbed[i] = 1; //planting
                    count++;
                    if (count >= n){
                        return true;
                    }
                }
            }
        }
        return count >=n;
    }
};