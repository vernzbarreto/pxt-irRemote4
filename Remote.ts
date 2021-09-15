/*
ken@emakefun.com
modified from pxt-servo/servodriver.ts
load dependency
"magicbit": "file:../pxt-magicbit"
*/

enum RemoteButton {
    //% block=*
    A = 0x16,
    //% block=#
    B = 0x0D,
    //% block=UP
    UP = 0x18,
    //% block=LEFT
    Left = 0x08,
    //% block=OK
    Ok = 0x1C,
    //% block=RIGHT
    Right = 0x5A,
    //% block=DOWN
    Down = 0x52,
    //% block=0
    NUM0 = 0x19,
    //% block=1
    NUM1 = 0x45,
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
    NUM9 = 0x09
};

 enum  IrPins{
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

enum  V2Pins{
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
  P14= 1
};

enum EM_RemoteButton {
    //% block=A
    EM_A = 0x45,
    //% block=B
    EM_B = 0x46,
    //% block=C
    EM_C = 0x47,
    //% block=D
    EM_D = 0x44,
    //% block=+
    EM_Add = 0x43,
    //% block=-
    EM_Sub = 0x0d,
    //% block=UP
    EM_UP = 0x40,
    //% block=LEFT
    EM_Left = 0x07,
    //% block=OK
    EM_Ok = 0x15,
    //% block=RIGHT
    EM_Right = 0x09,
    //% block=DOWN
    EM_Down = 0x19,
    //% block=0
    EM_NUM0 = 0x16,
    //% block=1
    EM_NUM1 = 0x0c,
    //% block=2
    EM_NUM2 = 0x18,
    //% block=3
    EM_NUM3 = 0x5e,
    //% block=4
    EM_NUM4 = 0x08,
    //% block=5
    EM_NUM5 = 0x1c,
    //% block=6
    EM_NUM6 = 0x5a,
    //% block=7
    EM_NUM7 = 0x42,
    //% block=8
    EM_NUM8 = 0x52,
    //% block=9
    EM_NUM9 = 0x4a
};

enum REMOTE_MODE {
    //% block=普通红外遥控器
    Remote = 0,
    //% block=Emakefun红外遥控器
    EM_Remote = 1
};

//% color="#EE6A50" weight=10 icon="\uf013"
namespace Remote {
    /**
     * button pushed.
     */
    //% blockId=onPressEvent
    //% block="当普通红外遥控器按键|%btn|按下" shim=IrRemote::onPressEvent
    export function OnPressEvent(btn: RemoteButton, body: () => void): void {
        return;
    }

    /**
     * button pushed.
     */
    //% blockId=onPressEvent_EM
    //% block="当Eamkefun红外遥控器按键|%btn|按下" shim=IrRemote::onPressEvent_EM
    export function OnPressEvent_EM(btn: EM_RemoteButton, body: () => void): void {
        return;
    }
	
    /**
     * initialises local variables
     *  @param pin describe parameter here, eg: IrPins.P5 
     */
    //% blockId=IrRemote_init 
    //% block="Micro:bit V1 红外遥控器初始化引脚|%pin 遥控器 %mode" shim=IrRemote::IrRemote_init 
    export function IrRemote_init(pin: IrPins, mode: REMOTE_MODE): void {
        return;
    }
	
    /**
     * initialises local variables
     *  @param pin describe parameter here, eg: V2Pins.P0
     */
    //% blockId=IrRemote_init_V2 
    //% block="Micro:bit V2 红外遥控器初始化引脚|%pin 遥控器 %mode" shim=IrRemote::IrRemote_init_V2 
    export function IrRemote_init_V2(pin: V2Pins, mode: REMOTE_MODE): void {
        return;
    }
}
