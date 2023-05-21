#define SERVER "191.168.1.121"
#define PORT 3002

AsyncUDP udpClient;

 
void UDPConnect(){
    IPAddress ipadd = IPAddress();
    ipadd.fromString(SERVER);
    udpClient.connect(ipadd, PORT);
    Serial.println("Server Connected");
}

void UDPSendData(String message){

    char charBuffer[1024];
    message.toCharArray(charBuffer,1024);

    if(udpClient.connected()){
      udpClient.broadcastTo(charBuffer, PORT);
    }else {
      Serial.println("Server Not Connected");
      UDPConnect();
    }
}

void UDPReceiveData(){
  if(udpClient.listen(3002)){
      udpClient.onPacket([](AsyncUDPPacket packet) {


           
            String Data = String((char *)packet.data());
            if(Data == "Reset"){
              mpu.resetOffset();
            }
        });

  }

}