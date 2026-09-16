class Solution {
    
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x + y < target) return false;
       int gcd = __gcd(x,y);
       //if(gcd%target == 0 || target%gcd == 0) return true;
       if(target%gcd == 0) return true;
       return false; 
    }
};