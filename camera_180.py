import cv2
import serial

ser = serial.Serial('COM10', 9800, timeout=1)

# Load the cascade
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# To capture video from webcam. 
cap = cv2.VideoCapture(1)
# To use a video file as input 
# cap = cv2.VideoCapture('filename.mp4')

while True:
    # Read the frame
    _, img = cap.read()
    
    
    #resolucao camera xbox 480 x 640
    #print('Resolution: ' + str(img.shape[0]) + ' x ' + str(img.shape[1]))
    
    
    # Convert to grayscale
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # Detect the faces
    faces = face_cascade.detectMultiScale(gray, 1.1, 4)
    # Draw the rectangle around each face
    for (x, y, w, h) in faces:
        cv2.rectangle(img, (x, y), (x+w, y+h), (255, 0, 0), 2)
        
        
        if not (x < 260 and x > 220):        
            if (x < 480 / 2):
                ser.write(b'A')
            else:
                ser.write(b'B')    
        
    # Display
    cv2.imshow('img', img)
    # Stop if escape key is pressed
    k = cv2.waitKey(30) & 0xff
    if k==27:
        break

        
ser.close()
exit()
cap.release()