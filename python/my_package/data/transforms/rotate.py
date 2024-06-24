#Imports
from PIL import Image

class RotateImage(object):
    '''
        Rotates the image about the centre of the image.
    '''

    def __init__(self, degrees):
        '''
            Arguments:
            degrees: rotation degree.
        '''
        self.angle=degrees
    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL image)

            Returns:
            image (numpy array or PIL image)
        '''
        if not isinstance(image,Image.Image): # if given as numpy array, then convert into PIL Image
            img = Image.fromarray(image)
        rot_img= image.rotate(self.angle)
        return rot_img
# a = RotateImage(90)
# img=Image.open('/home/raviteja3333/Desktop/vs/original_car.jpeg')
# b=a(img)
# b.show()
# #img.show()