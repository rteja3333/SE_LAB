#Imports
from PIL import Image

class RescaleImage(object):
    '''
        Rescales the image to a given size.
    '''

    def __init__(self, output_size):
        '''
            Arguments:
            output_size (tuple or int): Desired output size. If tuple, output is
            matched to output_size. If int, smaller of image edges is matched
            to output_size keeping aspect ratio the same.
        '''
        self.sizee=output_size

    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL image)

            Returns:
            image (numpy array or PIL image)

            Note: You do not need to resize the bounding boxes. ONLY RESIZE THE IMAGE.
        '''
        if not isinstance(image,Image.Image): # if given as numpy array, then convert into PIL Image
            img = Image.fromarray(image)
        if(isinstance(self.sizee, tuple)):
            res_img = image.resize(self.sizee)
        else:
            w,h=image.size
            if(w<h):
                w_=self.sizee
                h_=h*(w_/w)
            else:
                h_=self.sizee
                w_=w*(h_/h)
            res_img = image.resize([w_,h_])
        return res_img
# a = RescaleImage((500,500))
# img=Image.open('/home/raviteja3333/Desktop/vs/original_car.jpeg')
# b=a(img)
# b.show()
# #img.show()