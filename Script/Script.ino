
#include <IRremote.h>   
#include <Servo.h>

#define Tecla_Arriba 0x9F600707    
#define Tecla_Abajo 0x9E610707
#define Tecla_Izquierda 0x9A650707   
#define Tecla_Derecha 0x9D620707 

#define Tecla_1 0xFB040707
#define Tecla_2 0xFA050707 
#define Tecla_3 0xF9060707

#define Tecla_VolMas 0xF8070707
#define Tecla_VolMen 0xF40B0707 

#define Tecla_CanalMas 0xED120707 
#define Tecla_CanalMen 0xEF100707

Servo servoAbajo;
Servo servoAdelante;
Servo servoAgarrar;

int posAbajo = 0;
int posAdelante = 0;
int posAgarrar = 180;

int IR = 8;     
 
void setup() {
  Serial.begin(9600);     
  servoAbajo.attach(9);
  servoAdelante.attach(10);
  servoAgarrar.attach(11);
  IrReceiver.begin(IR, DISABLE_LED_FEEDBACK); 
  posAdelante = 90;
  posAbajo = 90;
  servoAgarrar.write(posAgarrar);
  servoAbajo.write(posAbajo);
  servoAdelante.write(posAdelante);
} 
 
void loop() {
  if (IrReceiver.decode()) {        

    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); 

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_1){
      posAdelante = 90;
      posAbajo = 90;
      servoAbajo.write(posAbajo);
      servoAdelante.write(posAdelante);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_2){
      posAdelante = 90;
      posAbajo = 0;
      servoAbajo.write(posAbajo);
      servoAdelante.write(posAdelante);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_3){
      posAdelante = 90;
      posAbajo = 180;
      servoAbajo.write(posAbajo);
      servoAdelante.write(posAdelante);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_Izquierda){
      if(posAbajo < 165){
        posAbajo = posAbajo + 15;
      }
      servoAbajo.write(posAbajo);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_Derecha){
      if(posAbajo > 15 ){
        posAbajo = posAbajo - 15;
      }
      servoAbajo.write(posAbajo);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_Arriba){
      if(posAdelante < 165){
        posAdelante = posAdelante + 15;
      }
      servoAdelante.write(posAdelante);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_Abajo){
      if(posAdelante > 15 ){
        posAdelante = posAdelante - 15;
      }
      servoAdelante.write(posAdelante);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_CanalMas){
      if(posAgarrar < 165){
        posAgarrar = posAgarrar + 15;
      }
      servoAgarrar.write(posAgarrar);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_Abajo){
      if(posAgarrar > 15 ){
        posAgarrar = posAgarrar - 15;
      }
      servoAgarrar.write(posAgarrar);
    }
    
    IrReceiver.resume();       
  }
  delay (100);            
}