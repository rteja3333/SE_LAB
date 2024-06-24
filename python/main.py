from my_package.model import ImageCaptioningModel
from my_package.data import Dataset, Download
from my_package.data.transforms import FlipImage, RescaleImage, BlurImage, CropImage, RotateImage
import numpy as np
from PIL import Image
import jsonlines


def experiment(annotation_file, captioner, transforms, outputs):
    '''
        Function to perform the desired experiments
        Arguments:
        annotation_file: Path to annotation file
        captioner: The image captioner
        transforms: List of transformation classes
        outputs: Path of the output folder to store the images
    '''

    #Create the instances of the dataset, download
    _dataset=Dataset(annotation_file,transforms)
    _download=Download()

    #Print image names and their captions from annotation file using dataset object
    #Download images to ./data/imgs/ folder using download object
    len=_dataset.__len__()
    # for i in range(0,len):
    #     obj=_dataset.__getann__(i)
    #     print(obj['file_name'])
    #     print(obj['captions'][0])
    #     print(obj['captions'][1])
    #     print(obj['captions'][2])
    #     print(obj['captions'][3])
    #     print(obj['captions'][4])
    #     path='/home/raviteja3333/Desktop/SE LAB/python/data/imgs/'
    #     path=path+obj['file_name']
    #     _download(path,obj['url'])


    
    #Transform the required image (roll number mod 10) and save it seperately

    t_img=_dataset.__transformitem__('/home/raviteja3333/Desktop/SE LAB/python/data/imgs/6.jpg')
    t_img.show()
    t_img=t_img.save('/home/raviteja3333/Desktop/SE LAB/python/outputs/t_img.jpg')


    #Get the predictions from the captioner for the above saved transformed image  
    pred=captioner('/home/raviteja3333/Desktop/SE LAB/python/outputs/t_img.jpg',3)
    print(pred)



def main():
    captioner = ImageCaptioningModel()
    experiment('/home/raviteja3333/Desktop/SE LAB/python/data/annotations.jsonl', captioner, [RotateImage(-45)], None) # Sample arguments to call experiment()


if __name__ == '__main__':
    main()


