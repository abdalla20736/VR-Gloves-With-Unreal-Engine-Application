
#define WIFI_NETWORK "Etisalat-ZS5b"
#define WIFI_PASSWORD "31994622"
#define WIFI_TIMEOUT_MS 20000

void connectToWifi(){
  Serial.print("Connecting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);
  unsigned long StartAttempt = millis();
  while(WiFi.status() != WL_CONNECTED && millis() - StartAttempt < WIFI_TIMEOUT_MS){

  }
  if(WiFi.status() == WL_CONNECTED){
      Serial.println("Connected");
      Serial.println(WiFi.localIP());
  }
}



