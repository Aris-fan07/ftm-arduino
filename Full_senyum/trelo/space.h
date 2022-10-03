//======================================Variabel Global================================================
const char* PARAM_INPUT_1 = "nama";
const char* PARAM_INPUT_2 = "mitra"; 
const char* PARAM_INPUT_3 = "nohp";
const char* PARAM_INPUT_4 = "keperluan";
const char* PARAM_INPUT_5 = "det_keg";
const char* PARAM_INPUT_6 = "linkktp";
const char* host = "script.google.com";
const int httpsPort = 443;
int i =1;
int j = 2;
int gpio13Led = 13;
int gpio12Relay = 12;
String nama;
String mitra;
String nohp;
String keperluan;
String det_keg;
String linkktp;
String IPP;
String tanda1 = "kirim";
String kirim;
AsyncWebServer server(255);// SERVICE PORT <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
MDNSResponder mdns;
WiFiClientSecure client;
//================================================================VOID sendData=======================================================
void sendData1(String nama, String mitra, String nohp, String keperluan, String det_keg, String linkktp) {
  Serial.println("==========");
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }
  //-------------------------deklarasi variabel lokal
  String string_nama =  String(nama);
  String string_mitra = String(mitra);
  String string_nohp = String(nohp);
  String string_keperluan = String(keperluan);
  String string_det_keg = String(det_keg);
  String string_linkktp = String(linkktp);
  String url = ("https://script.google.com/macros/s/" + GAS_ID + 
  "/exec?nama=" + string_nama +
  "&mitra=" + string_mitra +
  "&nohp=" + string_nohp +
  "&keperluan=" + string_keperluan +
  "&detkeg=" + string_det_keg+ +
  "&linkktp=" + linkktp);
  //-----------------kode pengiriman ke google sheet
  Serial.print("requesting URL: ");
  Serial.println(url);
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
         "Host: " + host + "\r\n" +
         "User-Agent: BuildFailureDetectorESP8266\r\n" +
         "Connection: close\r\n\r\n");
  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  Serial.print("reply was : ");
  Serial.println(line);
  Serial.println("closing connection");
  Serial.println("==========");
  Serial.println();
}
//===================================================================Void IPP==========================================================
void sendData2(String IPP) {
  Serial.println("==========");
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }
  //-------------------------deklarasi variabel lokal
  String string_IPP =  String(IPP);
  String url = ("https://script.google.com/macros/s/" + GAS_ID + "/exec?IPP=" + string_IPP);
  //-----------------kode pengiriman ke google sheet
  Serial.print("requesting URL: ");
  Serial.println(url);
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
         "Host: " + host + "\r\n" +
         "User-Agent: BuildFailureDetectorESP8266\r\n" +
         "Connection: close\r\n\r\n");
  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  tanda1="sudah";
  Serial.print("reply was : ");
  Serial.println(line);
  String reply = line;
  Serial.println("closing connection");
  Serial.println("==========");
  Serial.println();
}
//================================================================VOID notFound=======================================================
void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
  }
//================================================================VOID delspace================================================
 void delspace(){
 int a = nama.length();
 int b = mitra.length();
 int c = nohp.length();
 int d = keperluan.length();
 int e = det_keg.length();
 int f = linkktp.length();
 for (int i = 0; i <a; i++){
   if(nama[i] == ' '){
     nama.replace(nama[i],'|');
   }else{}}
 for (int i = 0; i <b; i++){
   if(mitra[i] == ' '){
    mitra.replace(mitra[i],'|');
   }else{}}
 for (int i = 0; i <c; i++){
  if(nohp[i] == ' '){
    nohp.replace(nohp[i],'|');
  }else{}}
 for (int i = 0; i <d; i++){
  if(keperluan[i] == ' '){
     keperluan.replace(keperluan[i],'|');
  }else{}}
 for (int i = 0; i <e; i++){
  if(det_keg[i] == ' '){
     det_keg.replace(det_keg[i],'|');
  }else{}}
for (int i = 0; i <f; i++){
  if(linkktp[i] == ' '){
    linkktp.replace(linkktp[i],'|');
  }else{}}
}
//============================================================VOID Pembersihan=============================================================================
void pembersihan(){
 nama = "";
 mitra = "";
 nohp = "";
 keperluan = "";
 det_keg = "";
 linkktp="";
 }
