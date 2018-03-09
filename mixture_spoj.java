import java.util.*;
import java.lang.*;

class Main
{
	public static void main(String[] args) throws Exception {
       /* InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);*/
       Scanner input = new Scanner(System.in);
        int n;
       // System.out.println("Enter the number of element");
        n = input.nextInt();
        // System.out.println("here is n"+n);
        int arr[] = new int[n];
      //  System.out.println("Enter the element of the array");
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        int sol_arr_1[][] = new int[n][n], sol_arr_2[][] = new int[n][n];
        
       //*****intialization*****//
       for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
             sol_arr_1[i][j]=0;
             sol_arr_2[i][j]=0;
            }
        }
       //*****end*****//
        
        
        
        
        
        int k_for_j = 1;
        int i = 0, j = 1;
        for (int q = 0; q < n - 1; q++) {
           // System.out.println("q="+q);
            j = k_for_j;
            i=0;
           if (q == 0) {
                while (j < n) {
                    sol_arr_1[i][j] = (arr[i] + arr[j]) % 100;
                    sol_arr_2[i][j] = (arr[i] * arr[j]);
                    i++;
                    j++;
                }
            }
            else
            {
               while(j<n)
               {
               int color1,smog1;
               color1=(arr[j]+sol_arr_1[i][j-1])%100;
               smog1=sol_arr_2[i][j-1]+(arr[j]*sol_arr_1[i][j-1]);
               int color2,smog2;
               color2 =(sol_arr_1[i+1][j]+arr[j-2])%100;
               smog2=(sol_arr_1[i+1][j]*arr[j-2])+sol_arr_2[i+1][j];
               if(smog1>smog2)
               {
                   sol_arr_1[i][j]=color2;
                   sol_arr_2[i][j]=smog2;
               }
               else
               {
                   sol_arr_1[i][j]=color1;
                   sol_arr_2[i][j]=smog1;
               }
               i++;
               j++;
            }
            }
            k_for_j++;
        }
        System.out.println(sol_arr_2[0][n-1]);
    }
}