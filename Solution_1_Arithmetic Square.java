import java.util.*;
public class Solution{
    public static int calculate(long arr[][]){
        int c=0;
        //Row
        if((arr[0][1]-arr[0][0])==(arr[0][2]-arr[0][1]))
            c++;
        if((arr[1][1]-arr[1][0])==(arr[1][2]-arr[1][1]))
            c++;
        if((arr[2][1]-arr[2][0])==(arr[2][2]-arr[2][1]))
            c++;
        
        //Column
        if((arr[1][0]-arr[0][0])==(arr[2][0]-arr[1][0]))
            c++;
        if((arr[1][1]-arr[0][1])==(arr[2][1]-arr[1][1]))
            c++;
        if((arr[1][2]-arr[0][2])==(arr[2][2]-arr[1][2]))
            c++;
            
        //Diagnol
        if((arr[1][1]-arr[0][0])==(arr[2][2]-arr[1][1]))
            c++;
        if((arr[1][1]-arr[0][2])==(arr[2][0]-arr[1][1]))
            c++;
        return c;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for(int i=0;i<n;i++){
            long arr[][]=new long[3][3];
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(j==1 && k==1)
                        arr[j][k]=0;
                    else{
                        arr[j][k]=sc.nextLong();
                    }
                }
            }
            int ans=0;
            arr[1][1]=(arr[1][0]+arr[1][2])/2;
            int t=calculate(arr);
            if(t>ans)
                ans=t;
            arr[1][1]=(arr[0][0]+arr[2][2])/2;
            t=calculate(arr);
            if(t>ans)
                ans=t;
            arr[1][1]=(arr[0][2]+arr[2][0])/2;
            t=calculate(arr);
            if(t>ans)
                ans=t;
             arr[1][1]=(arr[0][1]+arr[2][1])/2;
            t=calculate(arr);
            if(t>ans)
                ans=t;
            System.out.println("Case #"+(i+1)+": "+ans);
        }
    }
}
