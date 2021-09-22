import face_recognition
import os
import numpy as np
import cv2

ex_path = os.getcwd()

video_capture = cv2.VideoCapture(0)

# obama_image = face_recognition.load_image_file(os.path.join(ex_path, "Faces/Obama.jpg"))
# obama_face_encoding = face_recognition.face_encodings(obama_image)[0]

misha_image = face_recognition.load_image_file(os.path.join(ex_path, "Misha.jpg"))
misha_face_encoding = face_recognition.face_encodings(misha_image)[0]

facesPath = 'encoding.txt'
namesPath = 'names.txt'

with open(facesPath,'r') as f:
    known_face = list(np.array(i, dtype='float64') for i in [line.split(' ')[:-1] for line in f])
inArray = False

# with open('encoding.txt', 'w') as f:
#     for i in obama_face_encoding:
#         f.write(str(i) + ' ')
#     f.write('\n')
# with open('names.txt', 'w') as f:
#     f.write('Obama\n')


# def checkFace(File, Face):
#     with open(File, 'r') as f:
#         known_face = list(np.array(i, dtype='float64') for i in [line.split(' ')[:-1] for line in f])
#     inArray = False
#
#     for i in known_face:
#         try:
#             if (obama_face_encoding == i).all():
#                 inArray = True
#         except AttributeError:
#             if (obama_face_encoding) == i:
#                 inArray = True
#     return inArray


def saveFace(fileF, Face, fileN, Name):
    with open(fileN, 'a') as f:
        f.write(Name + '\n')
    with open(fileF, 'a') as f:
        for i in Face:
            f.write(str(i)+' ')
        f.write('\n')
    print('f =', f)

# print(face_recognition.compare_faces(known_face, obama_face_encoding))
print(face_recognition.compare_faces(known_face, misha_face_encoding))

# for i in face_recognition.compare_faces(known_face, obama_face_encoding):
#     if i:
#         inArray = True

# if not inArray:
#     name = input('Впишите имя ')
#     saveFace(facesPath, obama_face_encoding, namesPath, name)
# inArray = False

for i in face_recognition.compare_faces(known_face, misha_face_encoding):
    if i:
        inArray = True

if not inArray:
    name = input('Впишите имя ')
    saveFace(facesPath, misha_face_encoding, namesPath, name)
inArray = False

# Create arrays of known face encodings and their names
known_face_encodings, known_face_names = list(), list()


with open(facesPath, 'r') as f:
    known_face_encodings = list(np.array(i, dtype='float64') for i in [line.split(' ')[:-1] for line in f])
with open(namesPath, 'r') as f:
    known_face_names = f.read().split('\n')[:-1]
    print(f.read())

print(known_face_encodings)
print(known_face_names)
