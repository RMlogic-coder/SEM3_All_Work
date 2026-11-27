// Arrays - Collection of similar data types stored in a continuous memory location

// Array Can be 1D, 2D...

// 🎁      🎁     🎁     🎁    🎁
// 1000  1002   1004   1006  1008

// Address : BA + Weight * (n-i) ;

// WAP to Insert An Element in any position
// #include <stdio.h>
// int main(){
//     int a=20;
//     int pos=2;
//     int* arr[6]={1,34,5,76,873,2313};
//     int* arr2[7];
//     if(pos< size(arr)/size(int)){
//         for(int i=0;i<arr.length+1;i++){
//             if(i==pos) arr2[i]= a;
//             else arr2[i]=arr[i];
//         }
//     }
//     return 0;
// }
class DSA_Lect1{
    public static void main(){
        int[] arr= new int[5];
        for(int i=0; i<5;i++){
            arr[i]=i;
            System.out.print(arr[i]);
        }
        int pos=2;int a=10;
        int[] arr2= new int[6];
        for(int i=5; i>0;i--){
            if(i==pos) {arr2[pos]=a; continue;}
            arr2[i]=arr[i-1];
            System.out.print(arr2[i]+"\n");

        }
        
for(int i=0; i<5;i++){
            System.out.print(arr2[i]);
        }
        


    }
}



// Bubble Sort and Selection sort

