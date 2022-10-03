#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiClientSecure.h>
#include <Arduino.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
//=============================================================YANG HARUS DIGANTI============================================================
IPAddress local_IP(192, 168, 1, 192); // Set your Static IP address  HARUS DIGANTI
IPAddress gateway(192, 168, 1, 1); // Set your Gateway IP address  HARUS DIGANTI
IPAddress subnet(255, 255, 255, 0); 
IPAddress primaryDNS(192, 168, 1, 1); // DISAMAKAN DENGAN GATEWAY
IPAddress secondaryDNS(8,8, 4, 4);
const char* ssid = "RUANG FTM"; //NAMA SSID WIFI
const char* password = "1234567delapan";  //PASSWORD WIFI
String GAS_ID = "AKfycbxSnjjnfgDPpq7N_20Qwj5rnHj2_oWovK7-kg3bDvDS7GrYYabHx3x4hM4KniDrvFJWkw"; // HARUS DIGANTI (ID PENERAPAN)
#include "html.h"
#include "space.h"
//================================================================VOID SETUP=======================================================
void setup() {
 pinMode(gpio13Led, OUTPUT);
 digitalWrite(gpio13Led, LOW);
 pinMode(gpio12Relay, OUTPUT);
 digitalWrite(gpio12Relay, LOW);
 // Configures static IP address to ESP8266
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
  Serial.println("STA Failed to configure");
  }
 //WiFi.mode(WIFI_STA);
 WiFi.begin(ssid, password);
 Serial.begin(115200);
 delay(5000);
 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  client.setInsecure();
  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
    j = 1;
  });
  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    if (request->hasParam(PARAM_INPUT_6)) {
          nama = request->getParam(PARAM_INPUT_1)->value();
          mitra = request->getParam(PARAM_INPUT_2)->value();
          nohp = request->getParam(PARAM_INPUT_3)->value();
          keperluan = request->getParam(PARAM_INPUT_4)->value();
          det_keg = request->getParam(PARAM_INPUT_5)->value();
          linkktp = request->getParam(PARAM_INPUT_6)->value();
    }
    else {
          nama = "No message sent";
          mitra = "No message sent";
          nohp = "No message sent";
          keperluan = "No message sent";
          det_keg = "No message sent";
          linkktp = "No message sent";
          
    }
    Serial.println(nama);
    Serial.println(mitra);
    Serial.println(nohp);
    Serial.println(keperluan);
    Serial.println(det_keg);
    Serial.println(linkktp);
   if(nama==""||mitra==""||nohp==""||det_keg==""||linkktp==""||keperluan==""){
    request->send_P(200, "text/html", index_html);
    }else{request->send(200, "text/html", welcome);
   digitalWrite(gpio13Led, HIGH); //Mati
   digitalWrite(gpio12Relay, HIGH); //buka
   }
   });
   server.on("/back", HTTP_GET, [](AsyncWebServerRequest *request){
     request->send_P(200, "text/html", index_html);
   });
   server.onNotFound(notFound);
   server.begin();
   Serial.println("HTTP server started");
}
//================================================================VOID LOOP=======================================================
void loop() {
  digitalWrite(gpio13Led, LOW);
  digitalWrite(gpio12Relay, LOW);
  Serial.println(WiFi.localIP());
  delspace();
  if(nama==""||mitra==""||nohp==""||det_keg==""||linkktp==""||keperluan==""){
  Serial.println("fail");
  }else{
    sendData1(nama, mitra, nohp, keperluan, det_keg, linkktp);
    //digitalWrite(gpio13Led, HIGH);//Mati
    //digitalWrite(gpio12Relay, HIGH);//buka
  }
  pembersihan();
  getIp();
  if(kirim=="rafi" && tanda1=="kirim" && IPP!=""){sendData2(IPP);
  }else{}
  IPP="";
  delay(1000);
 }
//=====================================================GET IP===============================================================   
   String getIp(){
  WiFiClient client;
  if (client.connect("api.ipify.org", 80)) 
  {
      Serial.println("connected");
      client.println("GET / HTTP/1.0");
      client.println("Host: api.ipify.org");
      client.println();
  } else {
      Serial.println("Connection to ipify.org failed");
      tanda1 = "kirim";
      return String();
  }
  delay(5000);
  String line;
  while(client.available())
  {
    line = client.readStringUntil('\n');
    Serial.println(line);
    IPP = line;
  }
  if(line==""){
  }else{kirim = "rafi";}
  return line;
  }
