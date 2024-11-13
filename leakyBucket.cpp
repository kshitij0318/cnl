#include<bits/stdc++.h>
using  namespace std;
int main(){
    int bucket_size, output_rate, input_packet, storage = 0, time = 0;
    cout<<"Enter bucket size: ";
    cin>>bucket_size;
    cout<<"Enter output rate: ";
    cin>>output_rate;

    while(1){
        cout<<"Time "<<++time<<endl;
        cout<<"Enter incoming packet size (0 to stop): ";
        cin>>input_packet;
        if(input_packet == 0) break;
        if(input_packet+storage > bucket_size){
            cout<<"Packet overflow, dropped: "<<input_packet+storage-bucket_size<<endl;
            storage = bucket_size;
        }
        else{
            storage += input_packet;
            cout<<"Packet added, storage = "<<storage<<endl;
        }
        if(storage >= output_rate){
            storage -= output_rate;
            cout<<"Sent "<<output_rate<<" remaning "<<storage<<endl;
        }
        else{
            cout<<"Sent "<<storage<<" Remaning 0"<<endl;
            storage = 0;
        }
    }
    return 0;
}