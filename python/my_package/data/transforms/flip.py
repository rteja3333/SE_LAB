#Imports
from PIL import Image

class FlipImage(object):
    '''
        Flips the image.
    '''

    def __init__(self, flip_type='horizontal'):
        '''
            Arguments:
            flip_type: 'horizontal' or 'vertical' Default: 'horizontal'
        '''
        self.flip=flip_type
    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL image)

            Returns:
            image (numpy array or PIL image)
        '''
        if not isinstance(image,Image.Image): # if given as numpy array, then convert into PIL Image
            img = Image.fromarray(image)
        if(self.flip=='horizontal'):
            flip_img = image.transpose(Image.FLIP_LEFT_RIGHT)
        elif(self.flip=='vertical'):
            flip_img = image.transpose(Image.FLIP_TOP_BOTTOM)
        else:
            print("incorrent flip format")
            return
        return flip_img
# a = FlipImage('vertical)
# img=Image.open('/home/raviteja3333/Desktop/vs/original_car.jpeg')
# b=a(img)
# b.show()
# #img.show()





