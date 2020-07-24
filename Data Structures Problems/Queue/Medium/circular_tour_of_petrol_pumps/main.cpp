// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}
// } Driver Code Ends


/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
/*You are required to complete this method*/
int tour(petrolPump p[],int n){
    if(n == 1) return 0;

    queue<petrolPump> q;

    for(int i = 0 ;i < n ;i++)
        q.emplace(p[i]);

    int i = 0;
    int current_petrol=0;
    int current_distance=0;
    int start_index = 0;
    int distance_covered = 0;
    petrolPump current_petrol_pump;
    while(true){
        current_petrol_pump = q.front();
        current_petrol += current_petrol_pump.petrol;
        current_distance = current_petrol_pump.distance;

        if(current_petrol < current_distance){ // IF CANT REACH THE NEXT PETROL PUMP
            current_petrol = 0;
            distance_covered = 0;
            start_index = i+1;    // START FROM THE NEXT PETROL PUMP AGAIN
            if(start_index >= n)
                return -1;
        }else{                       // IF PETROL IS ENOUGH TO TRAVEL TO NEXT PETROL PUM
            if(distance_covered == n-1) // IF IT TRAVEL ALL THE PETROL PUMMS
                return start_index;

            distance_covered++;
            current_petrol -= current_distance;
        }

        q.emplace(q.front());
        q.pop();
        i++;
    }
}














