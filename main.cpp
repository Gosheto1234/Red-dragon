#include<iostream>
#include"color_console.hpp"

using namespace std;



void nmap(string nmap_address)
{

char buffer[700];//TODO fix values ?
string devices_ip;

//string devices_ip_stop = devices_ip.substr("n" , 17)

string all_info;

string mac_and_device;


string nmap_command = "sudo nmap -f -sn " + nmap_address;
FILE *nmap = popen(nmap_command.c_str(), "r");
while(fgets(buffer, sizeof(buffer), nmap))
{
//cout << "\n " << buffer << endl;

all_info = buffer;
if(all_info.find("Starting Nmap") < 1000)
{

//string labe = all_info.substr(67);
continue;
}

if(all_info.find("for") < 200)
{
devices_ip = all_info.substr(21, 18);

cout << "\n" << "ip: " << devices_ip << "\r";// \r = go back to the beginning of the line
}


if(all_info.find("MAC Address") < 200)
{
mac_and_device = all_info.substr(12, 50);

cout <<  "device: " << mac_and_device << "\r\n";
}

}
/
if(all_info.find("Starting Nmap") < 1000)
{

//string labe = all_info.substr(67);
continue;
}
/

/
if(all_info.find("for") < 200)
{
devices_ip = all_info.substr(2, 6);

cout << "ips: " << devices_ip;
}

/


}

string get_ip()
{
string ip_device;
char buffer[100];//TODO fix values ?
FILE *ip = popen("sudo ip add show wlan0 | grep inet", "r");
while(fgets(buffer, sizeof(buffer), ip))
{
ip_device += buffer;

//cout << buffer;

}
//If the position is less than 1000, it means it found it
if(ip_device.find("inet") < 1000)
{
//cout << "ip: " << ip_device.substr(8,18);//string.substr takes one or two numbers , here 8 is from where it starts to get text , 18 where it ends . if the number is one it reads the whole line starting from that number
ip_device = ip_device.substr(8, 18);
}
pclose(ip);
return ip_device;
}


int  main()
{




// To get the formatted string
    //cout << console.get("Hello World!", { console.red} ) << endl;

    system("clear");
    system("red_dragon.png");

     string address = get_ip();
      nmap(address);
    return 0;

}
