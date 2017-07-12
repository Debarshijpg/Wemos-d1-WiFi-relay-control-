
#include <WiFiUdp.h>

#include <ESP8266WiFi.h>

const char* ssid="SITGF03";
const char* password="sitsiliguri";
unsigned int localport=5990;
WiFiUDP Udp;
char RecievingBuffer[UDP_TX_PACKET_MAX_SIZE];

void setup() {
  Serial.begin(115200);
  delay(100);
  WiFi.begin(ssid,password);
  Serial.print("Connecting to ---"); 
  Serial.print("ssid");
  while (WiFi.status() !=WL_CONNECTED)
  {
    delay(500);
    Serial.print("*");
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println(" Connected via DHCP and the details are:");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.subnetMask());
  Serial.println(WiFi.gatewayIP());

  
  Udp.begin(localport);

}


void loop() {
  // put your main code here, to run repeatedly:
  int packetSize=Udp.parsePacket();

  if(packetSize){
    //if there is packets I will do this stuff

    Serial.println("Got a packet from the network");
    Serial.print("Message from the ip address: ");
    IPAddress remote=Udp.remoteIP();
    Serial.println(remote);
    Serial.print("And the port number is: ");
    unsigned int port =Udp.remotePort();
    Serial.println(port);
    Serial.print(packetSize);
    Serial.println("Bytes");

    Udp.read(RecievingBuffer,UDP_TX_PACKET_MAX_SIZE);
    Serial.println("Message Received as: ");
    Serial.print(RecievingBuffer);
    }

}
