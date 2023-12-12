#include <SoftwareSerial.h>
#include <Nextion.h>

SoftwareSerial nextionSerial(0, 1); // RX, TX

NexButton b0 = NexButton(0, 1, "b0");
NexButton b1 = NexButton(0, 2, "b1");
NexButton b2 = NexButton(0, 3, "b2");
NexButton b3 = NexButton(1, 3, "b1");

NexNumber n0 = NexNumber(1, 1, "n0");

NexTouch *nex_listen_list[] = {&b0, &b1, &b2, &b3, NULL};

void b0PopCallback(void *ptr) {
 n0.setValue(21);
}

void b1PopCallback(void *ptr) {
 n0.setValue(22);
}

void b2PopCallback(void *ptr) {
 n0.setValue(23);
}
void b3PopCallback(void *ptr) {
  
  nexSerial.print("page 3"); // Cambia a la página 3
  nexSerial.write(0xFF);
  nexSerial.write(0xFF);
  nexSerial.write(0xFF);
  delay(9000); 
  nexSerial.print("page 2"); // Cambia a la página 2
  nexSerial.write(0xFF);
  nexSerial.write(0xFF);
  nexSerial.write(0xFF);
  delay(4000); 
  nexSerial.print("page 0"); // Cambia a la página 0
  nexSerial.write(0xFF);
  nexSerial.write(0xFF);
  nexSerial.write(0xFF);
}




void setup() {
  Serial.begin(9600);
  nextionSerial.begin(9600);
  nexInit();
  b0.attachPop(b0PopCallback);
  b1.attachPop(b1PopCallback);
  b2.attachPop(b2PopCallback);
  b3.attachPop(b3PopCallback);
}

void loop() {
  nexLoop(nex_listen_list);

}
