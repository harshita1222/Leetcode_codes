class Solution {
    public int maxArea(int[] height) {
        int maxWater = 0;
        int Lp = 0;
        int Rp = height.length-1;

        while(Lp < Rp){
            //calcuate water
            int ht = Math.min(height[Lp], height[Rp]);
            int width = Rp-Lp;
            int currentWater  = ht*width;
            maxWater = Math.max(maxWater, currentWater);

            //update pointer
            if(height[Lp] < height[Rp]){
                Lp++;
            }else{
                Rp--;
            }
        }
        return maxWater;
    }
}