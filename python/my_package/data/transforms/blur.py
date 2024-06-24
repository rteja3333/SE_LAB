#Imports
from PIL import Image, ImageFilter

class BlurImage(object):
    '''
        Applies Gaussian Blur on the image.
    '''

    def __init__(self, radius):
        '''
            Arguments:
            radius (int): radius to blur
        '''
        self.r=radius
        
        

    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL Image)

            Returns:
            image (numpy array or PIL Image)
        '''
        if not isinstance(image,Image.Image): # if given as numpy array, then convert into PIL Image
            img = Image.fromarray(image)
        blurimg = image.filter(ImageFilter.GaussianBlur(radius = self.r))
        return blurimg
# a = BlurImage(0)
# img=Image.open('/home/raviteja3333/Desktop/vs/original_car.jpeg')
# b=a(img)
# b.show()
# #img.show()