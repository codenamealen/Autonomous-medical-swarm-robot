from flask import Flask, render_template
import serial
import time

app = Flask(__name__)

# Change if needed: /dev/ttyACM0 or /dev/ttyUSB0
arduino = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
time.sleep(2)  # wait for Arduino reset

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/forward')
def forward():
    arduino.write(b'F')
    return "Motor Forward"

@app.route('/backward')
def backward():
    arduino.write(b'B')
    return "Motor Backward"

@app.route('/stop')
def stop():
    arduino.write(b'S')
    return "Motor Stop"

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
