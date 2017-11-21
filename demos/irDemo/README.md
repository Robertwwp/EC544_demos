# IR Demo

This is a simple example sending and receiving using the Sony IR protocol. All of
the Sony IR protocol is abstracted, thanks to the IRremote library. All one needs to do is to send bytes.

Here 6 commands are defined with a unique byte:

|Command | Byte  | LED Status     |
|:---:   |  :---:|           :---:|
| OFF    | 0xA90 | no LEDs on     |
| RED    | 0xB90 | red LED on     |
| GREEN  | 0xC90 | green LED on   |
| BLUE   | 0xD90 | blue LED on    |
| YELLOW | 0xE90 | yellow LED on  |
| HAZARD | 0xF90 | all LEDs on    |

```IRsendDemo.ino``` rotates through transmitting the different commands on button press and displays the current command sent with the RGBY LEDs.

```IRrecvDemo.ino``` detects and decodes the IR signal and displays the command received with the RGBY LEDs.

Notes: 
1. Pin connections are defined in the code.
2. Remember to download and install the IRremote library.
