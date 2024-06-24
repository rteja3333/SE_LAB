#Imports
import json
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
        self.transform=transforms
        with open(annotation_file,'r') as f:
            self.file=json.load(f)

    def __len__(self):
        '''
            return the number of data points in the dataset
        '''
        cnt=0
       
        for i in self.file:
            cnt=cnt+1
            print(cnt)
        return cnt
    
    def __getann__(self, idx):
        '''
            return the data items for the index idx as an object
        '''
        

    def __transformitem__(self, path):
        '''
            return transformed PIL Image object for the image in the given path
        '''
        img=Image.open(path)
        a=self.transform()
        t_img=a(img)
        return t_img
    
# a=Dataset('/home/raviteja3333/Desktop/SE LAB/python/my_package/data/annotations.jsonl',rotate)
# print((a.__len__))