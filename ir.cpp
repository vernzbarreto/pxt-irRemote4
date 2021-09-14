#include "pxt.h"
#include <map>
#include <vector>
#include "ReceiverIR.h"
using namespace pxt;
typedef vector<Action> vA; 
typedef vector<Action> EM_vA;

enum class Pins{
  P0=  3,
  P1=  2,
  P2=  1,
  P3=  4,
  P4=  5,
  P5=  17,
  P6=  12,
  P7=  11,
  P8=  18,
  P9=  10,
  P10= 6,
  P11= 26,
  P12= 20,
  P13= 23,
  P14= 22,
  P15= 21,
  P16= 16,
  P19= 0,
  P20= 30
};

enum class V2Pins{
  P0=  2,
  P1=  3,
  P2=  4,
 // P3=  4,
 // P4=  5,
  P5=  14,
 // P6=  12,
 // P7=  11,
  P8=  10,
  P9=  9,
 // P10= 6,
 // P11= 26,
  P12= 12,
 // P13= 23,
  P14= 1,
  //P15= 21,
 // P16= 16,
 // P19= 0,
 // P20= 30
};

enum class EM_RemoteButton {
      //% block=A
      A = 0x45,
      //% block=B
	  B = 0x46,
      //% block=C
	  C = 0x47,
      //% block=D
	  D = 0x44,
      //% block=UP
	  UP = 0x40,
      //% block=+
	  Add = 0x43,
      //% block=LEFT
	  Left = 0x07,
      //% block=OK
	  Ok = 0x15,
      //% block=RIGHT
	  Right = 0x09,
      //% block=DOWN
      Down = 0x19,
	  //% block=-
	  EQ = 0x0d,
      //% block=0
	  NUM0 = 0x16,
      //% block=1
	  NUM1 = 0x0c,
      //% block=2
	  NUM2 = 0x18,
      //% block=3
	  NUM3 = 0x5e,
      //% block=4
	  NUM4 = 0x8,
      //% block=5
	  NUM5 = 0x1c,
      //% block=6
	  NUM6 = 0x5a,
      //% block=7
	  NUM7 = 0x42,
      //% block=8
	  NUM8 = 0x52,
      //% block=9
	  NUM9 = 0x4A
};

enum RemoteButton {
    //% block=1
    NUM1 = 0x20,
    //% block=2
    NUM2 = 0x46,
    //% block=3
    NUM3 = 0x47,
    //% block=4
    NUM4 = 0x44,
    //% block=5
    NUM5 = 0x40,
    //% block=6
    NUM6 = 0x43,
    //% block=7
    NUM7 = 0x07,
    //% block=8
    NUM8 = 0x15,
    //% block=9
    NUM9 = 0x09,
    //% block=*
    Star = 0x16,
    //% block=0
    NUM0 = 0x19,
    //% block=C
    Well = 0x0d,
    //% block=UP
    UP = 0x18,
    //% block=LEFT
    Left = 0x08,
    //% block=OK
    Ok = 0x1c,
    //% block=RIGHT
    Right = 0x5a,
    //% block=DOWN
    Down = 0x52,
};

enum class MODE {
    _Remote = 0,
    EM_Remote = 1,
};
//% color=50 weight=19 icon="\uf1eb"
//% block="IrRemote"
namespace IrRemote { 
  map<RemoteButton, vA> actions;
  map<RemoteButton, uint32_t> lastact;
  map<EM_RemoteButton, EM_vA> EM_actions;
  map<EM_RemoteButton, uint32_t> EM_lastact;
  Timer tsb; 
  uint8_t buf[32];
  uint32_t now;
  ReceiverIR *rx;
  RemoteIR::Format fmt = RemoteIR::UNKNOWN;

  /**
  * button pushed.
  */
  //%
  void onPressEvent(RemoteButton btn, Action body) {
    //if(actions.find(btn) == actions.end()) actions[btn] = new vector();
    actions[btn].push_back(body);
  }
	
 /**
  * button pushed.
  */
  //%
  void onPressEvent_EM(EM_RemoteButton btn, Action body) {
    EM_actions[btn].push_back(body);
  }

  void cA(vA runner){for(int i=0;i<runner.size();i++){runAction0(runner[i]);} }
  void EM_cA(EM_vA runner){for(int i=0;i<runner.size();i++){runAction0(runner[i]);} }

  void onReceivable(){
    int x = rx->getData(&fmt, buf, 32 * 8);
	  uBit.serial.send("buf[2]: ");
	  uBit.serial.send(buf[2]);
	  uBit.serial.send("\r\n");
    if(actions.find((RemoteButton)buf[2]) == actions.end()) return;
    now = tsb.read_ms();
    if(now - lastact[(RemoteButton)buf[2]] < 100) return;
    lastact[(RemoteButton)buf[2]] = now;
    cA(actions[(RemoteButton)buf[2]]); 
  }
	
  void onReceivable_EM(){
    int x = rx->getData(&fmt, buf, 32 * 8);
	  uBit.serial.send("buf[2]: ");
	  uBit.serial.send(buf[2]);
	  uBit.serial.send("\r\n");
    if(EM_actions.find((EM_RemoteButton)buf[2]) == EM_actions.end()) return;
    now = tsb.read_ms();
    if(now - EM_lastact[(EM_RemoteButton)buf[2]] < 100) return;
    EM_lastact[(EM_RemoteButton)buf[2]] = now;
    EM_cA(EM_actions[(EM_RemoteButton)buf[2]]); 
  }
	

  void monitorIR(){
    while(1){
      while(rx->getState() != ReceiverIR::Received){ 
        uBit.sleep(50);
      }
        onReceivable();
    }
  }

  void monitorIR_EM(){
    while(1){
      while(rx->getState() != ReceiverIR::Received){ 
        uBit.sleep(50);
      }
        onReceivable_EM();
    }
  }
	  
  /**
  * initialises local variablesssss
  */
  //%
  void IrRemote_init(Pins pin, int mode){
    rx = new ReceiverIR((PinName)pin);
    tsb.start(); //interrupt timer for debounce
    if (mode == 0) {
        create_fiber(monitorIR);
    }else if (mode == 1) {
       create_fiber(monitorIR_EM);
    }
  }
	
  /**
  * initialises local variablesssss
  */
  //%
  void IrRemote_init_V2(V2Pins pin, int mode){
    rx = new ReceiverIR((PinName)pin);
    tsb.start(); //interrupt timer for debounce
    if (mode == 0) {
        create_fiber(monitorIR);
    }else if (mode == 1) {
       create_fiber(monitorIR_EM);
    }
  }
}
