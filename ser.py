import serial

arduino = serial.Serial(port='COM7', baudrate=9600)

while True:
    state = input('open or close')
    if state == 'open' or state == 'close':
        arduino.write(bytes(state, 'utf-8'))    
    
    