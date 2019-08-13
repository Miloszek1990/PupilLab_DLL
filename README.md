# PupilLab_DLL
Pupil detector DLL written in C++ for LabView.

This is the souce code of PupilLab program. This program is able to detect and analyze the pupil from grayscale (0-255) image. Uniqueness of PupilLab is based on the fact that it can detect pupil from images with highly inhomogenous illumination.

Full project description can be find [here](https://github.com/Miloszek1990/PupilLab_DLL/blob/master/IEEE_ISPA2019_project_description.pdf) in the double reviewed *IEEE* paper prepared for *ISPA 2019* conference. 

Brifely, PupilLab is a set of C++ modules supported by OpenCV. It uses own developed method named *Adaptive Edge Detection* (AED) to detect the biggest contour in the image, which should be pupil. PupilLab is able to fit the circle thanks to Least Square method to obtained contour. If pupil is not the biggest contour or becouse of extra distortions it can't detected properly - then it is possible to use trained specially for this project Machine Learning model - Haar cascade classifier to detect pupil only region. Applying AED method to detected pupil only region solves problem of the biggest contour. Moreover, it is possible to use Partial Image Analysis (PIA) module to horizontal or vertical filtering of polluting contour pixels. 
