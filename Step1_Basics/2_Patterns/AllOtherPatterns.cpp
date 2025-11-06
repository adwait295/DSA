#include<bits/stdc++.h>
using namespace std;

void pattern2(int n){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern3(int n){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void pattern4(int n){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

void pattern5(int n){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n-i+1);j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
} 

void pattern6(int n){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n-i+1);j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void pattern7(int n){
    for(int i=1;i<=n;i++)
    {
        int m = 2*i-1;
        int k = (2*n-m)/2;
        for(int j=1;j<=k;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=m;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern8(int n){
    for(int i=n;i>=1;i--)
    {
        int m = 2*i-1;
        int k = (2*n-m)/2;
        for(int j=1;j<=k;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=m;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }    
}

void pattern9(int n){
    for(int i=1;i<=n;i++)
    {
        int m = 2*i-1;
        int k = (2*n-m)/2;
        for(int j=1;j<=k;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=m;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i=n;i>=1;i--)
    {
        int m = 2*i-1;
        int k = (2*n-m)/2;
        for(int j=1;j<=k;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=m;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }   
}

void pattern10(int n){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i=n-1;i>=1;i--)
    {
       for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl; 
    }
}

void pattern11(int n){ //For flipping we can do x=1-x
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i%2 == 0){
                if(j%2 ==0){
                    cout<<"1 ";
                }
                else{
                    cout<<"0 ";
                }
            }
            else{
               if(j%2 ==0){
                    cout<<"0 ";
                }
                else{
                    cout<<"1 ";
                } 
            }
        }
        cout<<endl;
    }
}

void pattern12(int n){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }

        for(int j=1;j<=2*(n-i);j++)
        {
            cout<<"  ";
        }

        for(int j=i;j>=1;j--)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void pattern13(int n){
    int m = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<m<<" ";
            m++;
        }
        cout<<endl;
    }
}

void pattern14(int n){
    for(int i=1;i<=n;i++)
    {
        for(char ch='A';ch<='A'+i-1;ch++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void pattern15(int n){
    for(int i=1;i<=n;i++)
    {
        for(char ch='A';ch<='A'+n-i;ch++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void pattern16(int n){
    char ch = 'A';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<ch<<" ";
        }
        ch++;
        cout<<endl;
    }
}

void pattern17(int n){
    for(int i=1;i<=n;i++)
    {
        char ch='A';
        for(int j=n;j>i;j--)
        {
            cout<<"  ";
        }
        int x = 2*i-1;
        for(int j=0;j<x;j++)
        {
            cout<<ch<<" ";
            if(j<(x/2)){
                ch++;
            }
            else ch--;
        }
        cout<<endl;
    } 
}

void pattern18(int n){
    for(int i=n;i>=1;i--)
    {
        char ch='A';
        for(int j=n;j>=i;j--)
        {
            cout<<char(ch+j-1)<<" ";
        }
        cout<<endl;
    }
}

void pattern19(int n){
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }

        for(int j=1;j<=2*(n-i);j++)
        {
            cout<<"  ";
        }

        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }

        for(int j=1;j<=2*(n-i);j++)
        {
            cout<<"  ";
        }

        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern20(int n){
    int space = 2*n-2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }

        for(int j=1;j<=space;j++)
        {
            cout<<"  ";
        }

        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }
        space-=2;
        cout<<endl;    
    }

    space = 2;
    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }

        for(int j=1;j<=space;j++)
        {
            cout<<"  ";
        }

        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }
        space+=2;
        cout<<endl;    
    }


}

void pattern21(int n){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i == 1 || j == 1 || i == n || j == n)
            cout<<"*";
            else 
            cout<<" ";
        }
        cout<<endl;
    }
}

void pattern22(int n){ // best pattern - my way
    int x = n, y=2*n-3;
    for(int i=n;i>=2;i--) 
    {
        for(int j=n;j>=i;j--)
        {
            cout<<j<<" ";
        }

        for(int j=1;j<=y;j++)
        {
            cout<<x<<" ";
        }
        x--,y-=2;

        for(int j=i;j<=n;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    int a=n,m=2*n-1;
    for(int i=1;i<=m;i++)
    {
        if(i<=m/2){
            cout<<a<<" ";
            a--;
        }
        else{
            cout<<a<<" ";
            a++;
        }
    }
    cout<<endl;
  
    for(int i=2;i<=n;i++)
    {
        for(int j=n;j>=i;j--)
        {
            cout<<j<<" ";
        } 

        x++,y+=2;
        for(int j=1;j<=y;j++)
        {
            cout<<x<<" ";
        }

        for(int j=i;j<=n;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void pattern22_1(int n){ // easy/best way of best patttern
    for(int i=0;i<2*n-1;i++)
    {
        for(int j=0;j<2*n-1;j++)
        {
            int top=i;
            int left=j;
            int right=(2*n-2)-j;
            int down=(2*n-2)-i;
            cout<<n-min(min(top,down),min(left,right));
        }
        cout<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        pattern22(n);
    }
    return 0;
}