#Imports
import jsonlines
from PIL import Image
import os
import numpy as np


class Dataset(object):
    '''
        A class for the dataset that will return data items as per the given index
    '''

    def __init__(self, annotation_file, transforms=None):
        '''
            Arguments:
            annotation_file: path to the annotation file
            transforms: list of transforms (class instances)
                        For instance, [<class 'RandomCrop'>, <class 'Rotate'>]
        '''
        self._file=jsonlines.open(annotation_file) 
        self._arr=np.array([annot for annot in self._file])
        self._transforms=transforms
        
     

    def __len__(self):
        '''
            return the number of data points in the dataset
        '''
        size=np.size(self._arr)
        return size

    
    def __getann__(self, idx):
        '''
            return the data items for the index idx as an object
        '''
        return self._arr[idx]
        
        

    def __transformitem__(self, path):
        '''
            return transformed PIL Image object for the image in the given path
        '''
        img=Image.open(path,'r')
        for i in self._transforms:
            transform=i
            img=transform(img)
        return img
            
            
# a=Dataset('/home/raviteja3333/Desktop/SE LAB/python/data/annotations.jsonl')


# print(a.__getann__(0)['captions'][1])
# print(a.__getann__(0)[1])
# print(a.__getann__(0)[2])
