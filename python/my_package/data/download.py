from PIL import Image
import requests
from io import BytesIO


class Download(object):
    '''
        A class for helping in dowloading the required images from the given url to the specified path
    '''

    def __call__(self, path, url):
        '''
            Arguments:
            path: download path with the file name
            url: required image URL
        '''
        r=requests.get(url)
        with open(path,'wb') as f:
            f.write(r.content)

# path='/home/raviteja3333/Desktop/'
# path=path+'aa.jpeg'
# a=Download()
# a(path,"http://farm5.staticflickr.com/4088/4980393979_fb7325e0b6_z.jpg")

