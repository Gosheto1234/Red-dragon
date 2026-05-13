#include<iostream>
#include"color_console.hpp"

using namespace std;



void nmap(string nmap_address, string range)
{

char buffer[700];
string devices_ip;


string all_info;

string mac_and_device;


string nmap_command = "nmap -sn " + nmap_address + range;
FILE *nmap = popen(nmap_command.c_str(), "r");
while(fgets(buffer, sizeof(buffer), nmap))
{

all_info = buffer;



if(all_info.find("Starting Nmap") < 1000)
{


continue;
}

if(all_info.find("for") < 200)
{
devices_ip = all_info.substr(20, 18);

cout << "\n" << "ip:" << devices_ip << "\r";// \r = go back to the beginning of the line
}


if(all_info.find("MAC Address") < 200)
{
mac_and_device = all_info.substr(12, 50);

cout <<  "device:" << mac_and_device << "\r\n";
}

}


}

string get_ip()
{
string ip_device;
char buffer[100];
FILE *ip = popen("ifconfig", "r");
while(fgets(buffer, sizeof(buffer), ip))
{
ip_device += buffer;

//cout << buffer;
/*
if(ip_device.find("inet") < 1000)
{
//string.substr takes one or two numbers , here 8 is from where it st>
ip_device = ip_device.substr(8, 18);
cout << "\n" << ip_device << "\r\n";
}
*/
}





//If the position is less than 1000, it means it found it
if(ip_device.find("wlan0") < 1000)
{
//string.substr takes one or two numbers , here 8 is from where it starts to get text , 18 where it ends . if the number is one it reads the whole line>
ip_device = ip_device.substr(437, 14);
//cout <<  ip_device;
}
pclose(ip);
return ip_device;
}


int  main()
{



    string ip_range;
    // To get the formatted string
    //cout << console.get("Hello World!", { console.red} ) << endl;

    system("clear");
    system("termimage red_dragon.png");
    cout << console.get("Enter ip range: ", {console.red});
    cin >> ip_range;
    ip_range = "/" + ip_range;
   //cout << ip_range;

     string address = get_ip();
     nmap(address, ip_range);
    return 0;

}





