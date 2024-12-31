class Solution {
    public int candy(int[] rat) {
        int n=rat.length;
        int a[]=new int[n];
        Arrays.fill(a,1);

        for(int i=1;i<n;i++){
            if(rat[i]>rat[i-1]){
                a[i]=a[i-1]+1;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(rat[i]>rat[i+1]){
               a[i]=Math.max(a[i],a[i+1]+1);      
            }
        }
        int s=0;
        for(int i:a){
            s+=i;
        }
        return s;


    }
}