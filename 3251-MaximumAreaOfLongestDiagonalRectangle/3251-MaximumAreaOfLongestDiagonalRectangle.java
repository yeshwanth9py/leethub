// Last updated: 6/11/2026, 11:19:05 AM
class Solution {
    public int areaOfMaxDiagonal(int[][] arr) {
        int n = arr.length;
        // int m = arr[0].length;


        int marea = 0;
        double mdiag = 0;

        for(int i=0; i<n; i++){
            double cdiag = Math.sqrt((arr[i][0]*arr[i][0] + arr[i][1]*arr[i][1]));
            int carea = arr[i][0]*arr[i][1];
            if(mdiag<cdiag){
                mdiag = cdiag;
                marea = carea;
            }else if(mdiag == cdiag){
                marea = Math.max(marea, carea);
            }
        }


        return marea;

    }
}