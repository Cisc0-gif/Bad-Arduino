import speech_recognition
import pyttsx3
import engineio
import time

engineio = pyttsx3.init()
voices = engineio.getProperty('voices')
engineio.setProperty('rate', 130)
engineio.setProperty('voice',voices[0].id)

recognizer = speech_recognition.Recognizer()

def speak(text):
    engineio.say(text)
    engineio.runAndWait()

def listen():
  with speech_recognition.Microphone() as source:
    recognizer.adjust_for_ambient_noise(source)
    audio = recognizer.listen(source)
  try:
    return recognizer.recognize_sphinx(audio)
    # or: return recognizer.recognize_google(audio)
  except speech_recognition.UnknownValueError:
    print("Could not understand audio")
  except speech_recognition.RequestError as e:
    print("Recog Error; {0}".format(e))
  return ""

#voice recog, repeat back what you said
#while(1):
#  speak("Say something!")
#  speak("I heard you say " + listen())
 
#listen for keyword and respond with text/speak() 
while (1):
  print('start') ##
  if 'jarvis' in listen():
    print('voice detected') ##
    while(1):
      print('started 2nd loop') ##
      if 'news' in listen():
        speak('todays news')
      if 'time' in listen():
        speak(time.ctime())
      break

#manual input
#speak("What do you want me to say?")
#while(1):
#    phrase = input("--> ")
#    if (phrase == "exit"):
#        exit(0)
#    speak(phrase)
#    print(voices)

