# Running Photon with the Xbee

## Hook Up
Photon 3.3V   --    XBee 3.3V
Photon TX     --    XBee RX
Photon RX     --    XBee TX
Photon GND    --    Photon GND

## XBee setup
XBee Routers - set to ZigBee Router API mode and API enable to 2.
XBee Coordinater - set to ZigBee Coordinator mode and API enable to 2. Make sure the Destination Address low to 'FFFF'.

## RSSI
Change the device ID and access token to your values. HTML will show the RSSI value of the associated XBee/Photon.
